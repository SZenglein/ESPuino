#include <Arduino.h>
#include "settings.h"
#include "Log.h"
#include "Battery.h"
#include "Mqtt.h"
#include "Led.h"
#include "System.h"
#include <Wire.h>
#include <Arduino-MAX17055_Driver.h>


#ifdef MEASURE_BATTERY_MAX17055

float batteryLow = s_batteryLow;
float batteryCritical = s_batteryCritical;

MAX17055 sensor;

void Battery_InitImpl()
{
    bool POR = sensor.getPOR();
    sensor.init(delay, s_batteryCapacity, s_emptyVoltage, s_recoveryVoltage, s_batteryChemistry, s_vCharge, s_resistSensor);

    // if power was lost, restore model params
    if (POR){
        // TODO: read learned params from nvs
        uint16_t rComp0     = gPrefsSettings.getUShort("rComp0", 0xFF);
        uint16_t tempCo     = gPrefsSettings.getUShort("tempCo", 0xFF);
        uint16_t fullCapRep = gPrefsSettings.getUShort("fullCapRep", 0xFF);
        uint16_t cycles     = gPrefsSettings.getUShort("MAX17055_cycles", 0xFF);
        uint16_t fullCapNom = gPrefsSettings.getUShort("fullCapNom", 0xFF);

        if ((rComp0 & tempCo & fullCapRep & cycles & fullCapNom) == 0xFF) {
            sensor.restoreLearnedParameters(delay, rComp0, tempCo, fullCapRep, cycles, fullCapNom);
        }
    }
    
    float vBatteryLow = gPrefsSettings.getFloat("batteryLow", 999.99);
    if (vBatteryLow <= 999) {
        batteryLow = vBatteryLow;
        // TODO: Log
    }
    else
    {
        gPrefsSettings.putFloat("batteryLow", batteryLow);
    }    

    float vBatteryCritical = gPrefsSettings.getFloat("batteryCritical", 999.99);
    if (vBatteryCritical <= 999) {
        batteryCritical = vBatteryCritical;
        // TODO: Log
    }
    else
    {
        gPrefsSettings.putFloat("batteryCritical", batteryCritical);
    }
}

void Battery_CyclicImpl(){
    // TODO check with doc
    if (sensor.getCycles() & 0x020) {
        uint16_t rComp0;
        uint16_t tempCo;
        uint16_t fullCapRep;
        uint16_t cycles;
        uint16_t fullCapNom;
        sensor.getLearnedParameters(rComp0, tempCo, fullCapRep, cycles, fullCapNom);
        gPrefsSettings.putUShort("rComp0", rComp0);
        gPrefsSettings.putUShort("tempCo", tempCo);
        gPrefsSettings.putUShort("fullCapRep", fullCapRep);
        gPrefsSettings.putUShort("cycles",cycles);
        gPrefsSettings.putUShort("fullCapNom", fullCapNom);
    }
}

float Battery_GetVoltage(void)
{
    return sensor.getInstantaneousVoltage();
}

void Battery_PublishMQTT(){
#ifdef MQTT_ENABLE
    float voltage = Battery_GetVoltage();
    char vstr[6];
    snprintf(vstr, 6, "%.2f", voltage);
    publishMqtt((char *)FPSTR(topicBatteryVoltage), vstr, false);

    float soc = Battery_EstimateSOC();
    snprintf(vstr, 6, "%.2f", voltage);
    publishMqtt((char *)FPSTR(topicBatterySOC), vstr, false);
#endif
}

void Battery_LogStatus(void){
    float voltage = Battery_GetVoltage();
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f V", (char *)FPSTR(currentVoltageMsg), voltage);
    Log_Println(Log_Buffer, LOGLEVEL_INFO);

    float soc = Battery_EstimateSOC();
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f %%", (char *)FPSTR(currentChargeMsg), soc);
    Log_Println(Log_Buffer, LOGLEVEL_INFO);

    float instCurr = sensor.getInstantaneousCurrent();
    // TODO i18n 
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f mA", "Instantaneous Current", instCurr);
    Log_Println(Log_Buffer, LOGLEVEL_INFO);
}

float Battery_EstimateSOC(void) {
    return sensor.getSOC();
}

bool Battery_IsLow(void) {
    return sensor.getSOC() < batteryLow;
}

bool Battery_IsCritical(void) {
    return sensor.getSOC() < batteryCritical;
}

#endif

