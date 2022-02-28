#include <Arduino.h>
#include "settings.h"
#include "Power.h"
#include "Port.h"



void Power_Init(void) {
    #if (POWER >= 0 && POWER <= 39)
        pinMode(POWER, OUTPUT);     // Only necessary for GPIO. For port-expander it's done (previously) via Port_init()
    #endif
    #if (POWER_MAIN >= 0 && POWER_MAIN <= 39)
        pinMode(POWER_MAIN, OUTPUT);     // Only necessary for GPIO. For port-expander it's done (previously) via Port_init()
    #endif
    Port_Write(POWER_MAIN, POWER_ON, false);
}

// Switch on peripherals. Please note: meaning of POWER_ON is HIGH per default. But is LOW in case of INVERT_POWER is enabled.
void Power_PeripheralOn(void) {
    Port_Write(POWER, POWER_ON, false);
    delay(50);  // Give peripherals some time to settle down
}

// Switch off peripherals. Please note: meaning of POWER_OFF is LOW per default. But is HIGH in case of INVERT_POWER is enabled.
void Power_PeripheralOff(void) {
    Port_Write(POWER, POWER_OFF, false);
}

// Switch off main power supply.
void Power_Off(void) {
    Power_PeripheralOff();
    Port_Write(POWER_MAIN, POWER_OFF, false);
}