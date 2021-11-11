#pragma once


extern uint8_t batteryCheckInterval;


void Battery_Init(void);
void Battery_Cyclic(void);

// Implementation specific tasks
void Battery_CyclicImpl(void);
void Battery_InitImpl(void);

float Battery_EstimateSOC(void);
float Battery_GetVoltage(void);
bool Battery_IsLow(void);
bool Battery_IsCritical(void);

void Battery_PublishMQTT(void);
void Battery_LogStatus(void);