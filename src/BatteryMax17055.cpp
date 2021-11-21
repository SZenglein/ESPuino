#include <Arduino.h>
#include "Battery.h"
#include "settings.h"

#ifdef MEASURE_BATTERY_MAX17055
#include "Log.h"
#include "Mqtt.h"
#include "Led.h"
#include "System.h"
#include <Wire.h>
#include <Arduino-MAX17055_Driver.h>


float batteryLow = s_batteryLow;
float batteryCritical = s_batteryCritical;
uint16_t cycles = 0;

MAX17055 sensor;

void Battery_InitImpl()
{
    bool POR = sensor.getPOR();
    sensor.init(delay, s_batteryCapacity, s_emptyVoltage, s_recoveryVoltage, s_batteryChemistry, s_vCharge, s_resistSensor);
    cycles = gPrefsSettings.getUShort("MAX17055_cycles", 0x0000);
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f", (char *)"Cycles saved in NVS:", cycles/100.0);
    Log_Println(Log_Buffer, LOGLEVEL_DEBUG);

    // if power was lost, restore model params
    if (POR){
        // TODO i18n 
        Log_Println("Battery detected power loss - loading fuel gauge parameters.", LOGLEVEL_NOTICE);
        uint16_t rComp0     = gPrefsSettings.getUShort("rComp0", 0x0000);
        uint16_t tempCo     = gPrefsSettings.getUShort("tempCo", 0x0000);
        uint16_t fullCapRep = gPrefsSettings.getUShort("fullCapRep", 0x0000);
        uint16_t fullCapNom = gPrefsSettings.getUShort("fullCapNom", 0x0000);

        Log_Println("Loaded MAX17055 attery model parameters from NVS:", LOGLEVEL_DEBUG);
        snprintf(Log_Buffer, Log_BufferLength, "%s: 0x%.4x", (char *)"rComp0", rComp0);
        Log_Println(Log_Buffer, LOGLEVEL_DEBUG);
        snprintf(Log_Buffer, Log_BufferLength, "%s: 0x%.4x", (char *)"tempCo", tempCo);
        Log_Println(Log_Buffer, LOGLEVEL_DEBUG);
        snprintf(Log_Buffer, Log_BufferLength, "%s: 0x%.4x", (char *)"fullCapRep", fullCapRep);
        Log_Println(Log_Buffer, LOGLEVEL_DEBUG);
        snprintf(Log_Buffer, Log_BufferLength, "%s: 0x%.4x", (char *)"fullCapNom", fullCapNom);
        Log_Println(Log_Buffer, LOGLEVEL_DEBUG);
        
        if ((rComp0 & tempCo & fullCapRep & cycles & fullCapNom) != 0x0000) {
            Log_Println("Successfully loaded fuel gauge parameters.", LOGLEVEL_NOTICE);
            sensor.restoreLearnedParameters(delay, rComp0, tempCo, fullCapRep, cycles, fullCapNom);
        } else {
            Log_Println("Failed loading fuel gauge parameters.", LOGLEVEL_NOTICE);
        }
    } else {
        Log_Println("Battery continuing normal operation", LOGLEVEL_DEBUG);
    }

    Log_Println("MAX17055 init done. Battery configured with the following settings:", LOGLEVEL_DEBUG);
    float val = sensor.getCapacity();
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f mAh", (char *)"Design Capacity", val);
    Log_Println(Log_Buffer, LOGLEVEL_DEBUG);
    val = sensor.getEmptyVoltage() / 100.0;
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f V", (char *)"Empty Voltage", val);
    Log_Println(Log_Buffer, LOGLEVEL_DEBUG);
    uint16_t modelCfg = sensor.getModelCfg();
    snprintf(Log_Buffer, Log_BufferLength, "%s: 0x%.4x", (char *)"ModelCfg Value", modelCfg);
    Log_Println(Log_Buffer, LOGLEVEL_DEBUG);
    uint16_t cycles = sensor.getCycles();
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f", (char *)"Cycles", cycles/100.0);
    Log_Println(Log_Buffer, LOGLEVEL_DEBUG);
    
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
    // It is recommended to save the learned capacity parameters every time bit 6 of the Cycles register toggles 
    if (cycles + 0x0040 < sensor.getCycles()) {
        Log_Println("Battery Cycle passed 64%, store MAX17055 learned parameters", LOGLEVEL_DEBUG);
        uint16_t rComp0;
        uint16_t tempCo;
        uint16_t fullCapRep;
        uint16_t cycles;
        uint16_t fullCapNom;
        sensor.getLearnedParameters(rComp0, tempCo, fullCapRep, cycles, fullCapNom);
        gPrefsSettings.putUShort("rComp0", rComp0);
        gPrefsSettings.putUShort("tempCo", tempCo);
        gPrefsSettings.putUShort("fullCapRep", fullCapRep);
        gPrefsSettings.putUShort("MAX17055_cycles", cycles);
        gPrefsSettings.putUShort("fullCapNom", fullCapNom);
        cycles = sensor.getCycles();
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

    float avgCurr = sensor.getAverageCurrent();
    // TODO i18n 
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f mA", "Average Current", avgCurr);
    Log_Println(Log_Buffer, LOGLEVEL_INFO);


    float temperature = sensor.getTemperature();
    // TODO i18n
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f °C", "Temperature", temperature);
    Log_Println(Log_Buffer, LOGLEVEL_INFO);

    // pretty useless because of low resolution
    // float maxCurrent = sensor.getMaxCurrent();
    // // TODO i18n
    // snprintf(Log_Buffer, Log_BufferLength, "%s: %.4f mA", "Max current to battery since last check", maxCurrent);
    // Log_Println(Log_Buffer, LOGLEVEL_INFO);
    // float minCurrent = sensor.getMinCurrent();
    // // TODO i18n
    // snprintf(Log_Buffer, Log_BufferLength, "%s: %.4f mA", "Min current to battery since last check", minCurrent);
    // Log_Println(Log_Buffer, LOGLEVEL_INFO);
    // sensor.resetMaxMinCurrent();

    float cycles = sensor.getCycles() / 100.0;
    // TODO i18n 
    snprintf(Log_Buffer, Log_BufferLength, "%s: %.2f", "Battery Cycles", cycles);
    Log_Println(Log_Buffer, LOGLEVEL_INFO);
}

float Battery_EstimateSOC(void) {
    return sensor.getSOC();
}

bool Battery_IsLow(void) {
    float soc = sensor.getSOC();
    if (soc > 100.0) {
        Log_Println("Battery percentage reading invalid, try again.", LOGLEVEL_DEBUG);
        soc = sensor.getSOC();
    }

    return soc < batteryLow;
}

bool Battery_IsCritical(void) {
    float soc = sensor.getSOC();
    if (soc > 100.0) {
        Log_Println("Battery percentage reading invalid, try again.", LOGLEVEL_DEBUG);
        soc = sensor.getSOC();
    }

    return soc < batteryCritical;
}

#endif

