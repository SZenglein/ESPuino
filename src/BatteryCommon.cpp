#include <Arduino.h>
#include "settings.h"
#include "Log.h"
#include "Battery.h"
#include "Mqtt.h"
#include "Led.h"
#include "System.h"

#ifdef BATTERY_MEASURE_ENABLE
uint8_t batteryCheckInterval = s_batteryCheckInterval;

void Battery_Init(void) {
    uint32_t vInterval = gPrefsSettings.getUInt("vCheckIntv", 17777);
    if (vInterval != 17777)
    {
        batteryCheckInterval = vInterval;
        snprintf(Log_Buffer, Log_BufferLength, "%s: %u Minuten", (char *)FPSTR(voltageCheckIntervalFromNVS), vInterval);
        Log_Println(Log_Buffer, LOGLEVEL_INFO);
    }
    else
    {
        gPrefsSettings.putUInt("vCheckIntv", batteryCheckInterval);
    }

    Battery_InitImpl();
}

// Measures battery as per interval or after bootup (after allowing a few seconds to settle down)
void Battery_Cyclic(void)
{
    static uint32_t lastBatteryCheckTimestamp = 0;
    if ((millis() - lastBatteryCheckTimestamp >= batteryCheckInterval * 60000) || (!lastBatteryCheckTimestamp && millis() >= 10000))
    {
        float voltage = Battery_GetVoltage();

        Battery_CyclicImpl();

        if (Battery_IsLow())
        {
            snprintf(Log_Buffer, Log_BufferLength, "%s: (%.2f V)", (char *)FPSTR(batteryLowMsg), voltage);
            Log_Println(Log_Buffer, LOGLEVEL_ERROR);
            Led_Indicate(LedIndicatorType::VoltageWarning);
        }

        Battery_PublishMQTT();
        Battery_LogStatus();

        if (Battery_IsCritical()) 
        {   
            snprintf(Log_Buffer, Log_BufferLength, "%s: (%.2f V)", (char *)FPSTR(batteryCriticalMsg), voltage);
            Log_Println(Log_Buffer, LOGLEVEL_ERROR);
            System_RequestSleep();
        }

        lastBatteryCheckTimestamp = millis();
    }
}
#else // BATTERY Measure disabled, add dummy methods 
void Battery_Cyclic(void){}
void Battery_Init(void) {}
#endif