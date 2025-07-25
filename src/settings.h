// clang-format off

#ifndef __ESPUINO_SETTINGS_H__
    	#define __ESPUINO_SETTINGS_H__
        #include "Arduino.h"
        #include "values.h"
#if __has_include("settings-override.h")
    	#include "settings-override.h"
#else
	//######################### INFOS ####################################
	// This is the general configfile for ESPuino-configuration.

	//################## HARDWARE-PLATFORM ###############################
	/* Make sure to also edit the configfile, that is specific for your platform.
	If in doubts (your develboard is not listed) use HAL 7

	!!!Only ESP32 with PSRAM are supported!!!

	1: Wemos Lolin32                        => REMOVED (because of missing PSRAM)
	2: ESP32-A1S Audiokit                   => REMOVED (because of stale development, lack of users and lack of GPIOs)
	3: Wemos Lolin D32                      => REMOVED (because of missing PSRAM)
	4: Wemos Lolin D32 pro                  => settings-lolin_D32_pro.h
	5: Lilygo T8 (V1.7)                     => settings-ttgo_t8.h
	6: ESPuino complete                     => settings-complete.h
	7: Lolin D32 pro SDMMC Port-Expander    => settings-lolin_d32_pro_sdmmc_pe.h
	8: AZDelivery ESP32 NodeMCU             => REMOVED (because of missing PSRAM)
	9: Lolin D32 SDMMC Port-Expander        => REMOVED (because of missing PSRAM)
	99: custom                              => settings-custom.h
	*/
	#ifndef HAL             // Will be set by platformio.ini. If using Arduino-IDE you have to set HAL according your needs!
		#define HAL 99       // HAL 1 = LoLin32, 2 = ESP32-A1S-AudioKit, 3 = Lolin D32, 4 = Lolin D32 pro; ... 99 = custom
	#endif


	//########################## MODULES #################################
	//#define PORT_EXPANDER_ENABLE          // When enabled, buttons can be connected via port-expander PCA9555 (https://forum.espuino.de/t/einsatz-des-port-expanders-pca9555/306)
	//#define I2S_COMM_FMT_LSB_ENABLE       // Enables FMT instead of MSB for I2S-communication-format. Used e.g. by PT2811. Don't enable for MAX98357a, AC101 or PCM5102A)
	#define MDNS_ENABLE                     // When enabled, you don't have to handle with ESPuino's IP-address. If hostname is set to "ESPuino", you can reach it via ESPuino.local
	//#define MQTT_ENABLE                   // Make sure to configure mqtt-server and (optionally) username+pwd
	#define FTP_ENABLE                      // Enables FTP-server; DON'T FORGET TO ACTIVATE AFTER BOOT BY PRESSING PAUSE + NEXT-BUTTONS (IN PARALLEL)!
	#define NEOPIXEL_ENABLE                 // Don't forget configuration of NUM_LEDS if enabled
	#define NEOPIXEL_REVERSE_ROTATION     // Some Neopixels are adressed/soldered counter-clockwise. This can be configured here.
	#define LANGUAGE DE                     // DE = deutsch; EN = english
	//#define STATIC_IP_ENABLE              // DEPRECATED: Enables static IP-configuration (change static ip-section accordingly)
	#define HEADPHONE_ADJUST_ENABLE         // Used to adjust (lower) volume for optional headphone-pcb (refer maxVolumeSpeaker / maxVolumeHeadphone) and to enable stereo (if PLAY_MONO_SPEAKER is set)
	#define PLAY_MONO_SPEAKER             // If only one speaker is used enabling mono should make sense. Please note: headphones is always stereo (if HEADPHONE_ADJUST_ENABLE is active)
	#define SHUTDOWN_IF_SD_BOOT_FAILS       // Will put ESP to deepsleep if boot fails due to SD. Really recommend this if there's in battery-mode no other way to restart ESP! Interval adjustable via deepsleepTimeAfterBootFails.
	//#define MEASURE_BATTERY_VOLTAGE         // Enables battery-measurement via GPIO (ADC) and voltage-divider
	#define MEASURE_BATTERY_MAX17055      // Enables battery-measurement via external fuel gauge (MAX17055)
	#define SHUTDOWN_ON_BAT_CRITICAL      // Whether to turn off on critical battery-level (only used if MEASURE_BATTERY_XXX is active)
	#define PLAY_LAST_RFID_AFTER_REBOOT   // When restarting ESPuino, the last RFID that was active before, is recalled and played
	#define USEROTARY_ENABLE                // If rotary-encoder is used (don't forget to review WAKEUP_BUTTON if you disable this feature!)
	//#define BLUETOOTH_ENABLE                // If enabled and bluetooth-mode is active, you can stream to your ESPuino or to a headset via bluetooth (a2dp-sink & a2dp-source). Note: This feature consumes a lot of resources and the available flash/ram might not be sufficient.
	//#define IR_CONTROL_ENABLE             // Enables remote control (https://forum.espuino.de/t/neues-feature-fernsteuerung-per-infrarot-fernbedienung/265)
	//#define PAUSE_WHEN_RFID_REMOVED       // Playback starts when card is applied and pauses automatically, when card is removed (https://forum.espuino.de/t/neues-feature-pausieren-wenn-rfid-karte-entfernt-wurde/541)
	#define DONT_ACCEPT_SAME_RFID_TWICE   // RFID-reader doesn't accept the same RFID-tag twice in a row (unless it's a modification-card or RFID-tag is unknown in NVS). Flag will be ignored silently if PAUSE_WHEN_RFID_REMOVED is active. (https://forum.espuino.de/t/neues-feature-dont-accept-same-rfid-twice/1247)
	//#define HALLEFFECT_SENSOR_ENABLE      // Support for hallsensor. For fine-tuning please adjust HallEffectSensor.h Please note: only user-support provided (https://forum.espuino.de/t/magnetische-hockey-tags/1449/35)

	//################## set PAUSE_WHEN_RFID_REMOVED behaviour #############################
	#ifdef PAUSE_WHEN_RFID_REMOVED
		#define ACCEPT_SAME_RFID_AFTER_TRACK_END           // Accepts same RFID after playback has ended (https://forum.espuino.de/t/neues-feature-pausieren-wenn-rfid-karte-entfernt-wurde/541/2)
	#endif

	//################## select SD card mode #############################
	#define SD_MMC_1BIT_MODE              // run SD card in SD-MMC 1Bit mode (using GPIOs 15 + 14 + 2 is mandatory!)
	//#define SINGLE_SPI_ENABLE             // If only one SPI-instance should be used instead of two (not yet working!)
	//#define NO_SDCARD                     // enable to start without any SD card, e.g. for a webplayer only. SD card Settings above will be ignored


	//################## select RFID reader ##############################
	//#define RFID_READER_TYPE_MFRC522_SPI // use MFRC522 via SPI
	//#define RFID_READER_TYPE_MFRC522_I2C  // use MFRC522 via I2C
	#define RFID_READER_TYPE_PN5180 // use PN5180 via SPI

	#ifdef RFID_READER_TYPE_MFRC522_I2C
		#define MFRC522_ADDR 0x28           // default I2C-address of MFRC522
	#endif

	#ifdef RFID_READER_TYPE_PN5180
		// #define PN5180_ENABLE_LPCD        // Wakes up ESPuino if RFID-tag was applied while deepsleep is active.
	#endif

	#if defined(RFID_READER_TYPE_MFRC522_I2C) || defined(RFID_READER_TYPE_MFRC522_SPI)
		constexpr uint8_t rfidGain = 0x07 << 4;      // Sensitivity of RC522. For possible values see reference: https://forum.espuino.de/uploads/default/original/1X/9de5f8d35cbc123c1378cad1beceb3f51035cec0.png
	#endif


	//############# Port-expander-configuration ######################
	#ifdef PORT_EXPANDER_ENABLE
		constexpr uint8_t expanderI2cAddress = 0x20;  // I2C-address of PCA9555 (0x20 is true if PCA's pins A0+A1+A2 are pulled to GND)
	#endif

	//################## BUTTON-Layout ##################################
	/* German documentation: https://forum.espuino.de/t/das-dynamische-button-layout/224
	Please note the following numbers as you need to know them in order to define actions for buttons.
	Even if you don't use all of them, their numbers won't change
		0: NEXT_BUTTON
		1: PREVIOUS_BUTTON
		2: PAUSEPLAY_BUTTON
		3: ROTARYENCODER_BUTTON
		4: BUTTON_4
		5: BUTTON_5

	Don't forget to enable/configure those buttons you want to use in your develboard-specific config (e.g. settings-custom.h)

	Single-buttons [can be long or short] (examples):
		BUTTON_0_SHORT => Button 0 (NEXT_BUTTON) pressed shortly
		BUTTON_3_SHORT => Button 3 (ROTARYENCODER_BUTTON) pressed shortly
		BUTTON_4_LONG => Button 4 (BUTTON_4) pressed long

	Multi-buttons [short only] (examples):
		BUTTON_MULTI_01 => Buttons 0+1 (NEXT_BUTTON + PREVIOUS_BUTTON) pressed in parallel
		BUTTON_MULTI_12 => Buttons 1+2 (PREV_BUTTON + PAUSEPLAY_BUTTON) pressed in parallel

	Actions:
		To all of those buttons, an action can be assigned freely.
		Please have a look at values.h to look up actions available (>=100 can be used)
		If you don't want to assign an action or you don't use a given button: CMD_NOTHING has to be set
	*/
	// *****BUTTON*****        *****ACTION*****
	#define BUTTON_0_SHORT    CMD_PREVTRACK
	#define BUTTON_1_SHORT    CMD_NEXTTRACK
	#define BUTTON_2_SHORT    CMD_PLAYPAUSE
	#define BUTTON_3_SHORT    CMD_PLAYPAUSE
	#define BUTTON_4_SHORT    CMD_SEEK_BACKWARDS
	#define BUTTON_5_SHORT    CMD_SEEK_FORWARDS

	#define BUTTON_0_LONG     CMD_SEEK_BACKWARDS
	#define BUTTON_1_LONG     CMD_SEEK_FORWARDS
	#define BUTTON_2_LONG     CMD_PLAYPAUSE
	#define BUTTON_3_LONG     CMD_SLEEPMODE
	#define BUTTON_4_LONG     CMD_VOLUMEUP
	#define BUTTON_5_LONG     CMD_VOLUMEDOWN

	#define BUTTON_MULTI_01   CMD_MEASUREBATTERY   //CMD_TOGGLE_WIFI_STATUS (disabled now to prevent children from unwanted WiFi-disable)
	#define BUTTON_MULTI_02   CMD_NOTHING // CMD_ENABLE_FTP_SERVER
	#define BUTTON_MULTI_03   CMD_NOTHING
	#define BUTTON_MULTI_04   CMD_NOTHING
	#define BUTTON_MULTI_05   CMD_NOTHING
	#define BUTTON_MULTI_12   CMD_TELL_IP_ADDRESS
	#define BUTTON_MULTI_13   CMD_NOTHING
	#define BUTTON_MULTI_14   CMD_NOTHING
	#define BUTTON_MULTI_15   CMD_NOTHING
	#define BUTTON_MULTI_23   CMD_NOTHING
	#define BUTTON_MULTI_24   CMD_NOTHING
	#define BUTTON_MULTI_25   CMD_NOTHING
	#define BUTTON_MULTI_34   CMD_NOTHING
	#define BUTTON_MULTI_35   CMD_NOTHING
	#define BUTTON_MULTI_45   CMD_NOTHING

	//#################### Various settings ##############################

	// Serial-logging-configuration
	#define SERIAL_LOGLEVEL LOGLEVEL_DEBUG              // Current loglevel for serial console

    // DEPRECATED: This is now done using dynamic network configuration.
    //              If left, it is used for the automatic migration exactly once
	// Static ip-configuration
	#ifdef STATIC_IP_ENABLE
		#define LOCAL_IP   192,168,2,100                // ESPuino's IP
		#define GATEWAY_IP 192,168,2,1                  // IP of the gateway/router
		#define SUBNET_IP  255,255,255,0                // Netmask of your network (/24 => 255.255.255.0)
		#define DNS_IP     192,168,2,1                  // DNS-server of your network; in private networks it's usually the gatewy's IP
	#endif

	// Buttons (better leave unchanged if in doubts :-))
	constexpr uint8_t buttonDebounceInterval = 50;                // Interval in ms to software-debounce buttons
	constexpr uint16_t intervalToLongPress = 700;                 // Interval in ms to distinguish between short and long press of buttons

	// Buttons active state: Default 0 for active LOW, 1 for active HIGH e.g. for TTP223 Capacitive Touch Switch Button (FinnBox)
	#define BUTTON_0_ACTIVE_STATE 0
	#define BUTTON_1_ACTIVE_STATE 0
	#define BUTTON_2_ACTIVE_STATE 0
	#define BUTTON_3_ACTIVE_STATE 0
	#define BUTTON_4_ACTIVE_STATE 0
	#define BUTTON_5_ACTIVE_STATE 0

	//#define CONTROLS_LOCKED_BY_DEFAULT			// If set the controls are locked at boot
	#define INCLUDE_ROTARY_IN_CONTROLS_LOCK			// If set the rotary encoder is locked if controls are locked

	// RFID-RC522
	#define RFID_SCAN_INTERVAL 100                      // Interval-time in ms (how often is RFID read?)

	// Automatic restart
	#ifdef SHUTDOWN_IF_SD_BOOT_FAILS
		constexpr uint32_t deepsleepTimeAfterBootFails = 20;      // Automatic restart takes place if boot was not successful after this period (in seconds)
	#endif

	// FTP
	// Nothing to be configured here...
	// Default user/password is esp32/esp32 but can be changed via webgui

	// timezone
	// see list of valid timezones: https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv
	// example for Europe/Berlin:	"CET-1CEST,M3.5.0,M10.5.0/3"
	// example for America/Toronto:	"EST5EDT,M3.2.0,M11.1.0"
	constexpr const char timeZone[] = "CET-1CEST,M3.5.0,M10.5.0/3"; // Europe/Berlin

	// ESPuino will create a WiFi if joing existing WiFi was not possible. Name and password can be configured here.
	constexpr const char accessPointNetworkSSID[] = "ESPuino";     // Access-point's SSID
	constexpr const char accessPointNetworkPassword[] = "";        // Access-point's Password, at least 8 characters! Set to an empty string to spawn an open WiFi.

	// Bluetooth
	constexpr const char nameBluetoothSinkDevice[] = "ESPuino";        // Name of your ESPuino as Bluetooth-device

	// Where to store the backup-file for NVS-records
	constexpr const char backupFile[] = "/backup.txt"; // File is written every time a (new) RFID-assignment via GUI is done

	//#################### Settings for optional Modules##############################
	// (optinal) Neopixel
	#ifdef NEOPIXEL_ENABLE
		#define NUM_INDICATOR_LEDS		24          	// number of Neopixel LEDs (formerly NUM_LEDS)
		#define NUM_CONTROL_LEDS		0		// optional control leds (https://forum.espuino.de/t/statische-ws2812-leds/1703)
                #define CONTROL_LEDS_COLORS		{}		// Colors for the control LEDs. Make sure it lists at least NUM_CONTROL_LEDS colors, e.g. for three control LEDs define: CONTROL_LEDS_COLORS {CRGB::Yellow, CRGB::Blue, 0xFFFFFF} (predefined colors: http://fastled.io/docs/3.1/struct_c_r_g_b.html)
		#define CHIPSET					WS2812B     	// type of Neopixel
		#define COLOR_ORDER				GRB
		#define NUM_LEDS_IDLE_DOTS		4           	// count of LEDs, which are shown when Idle
		#define OFFSET_PAUSE_LEDS		false		// if true the pause-leds are centered in the mid of the LED-Strip
		#define PROGRESS_HUE_START		85          	// Start and end hue of mulitple-LED progress indicator. Hue ranges from basically 0 - 255, but you can also set numbers outside this range to get the desired effect (e.g. 85-215 will go from green to purple via blue, 341-215 start and end at exactly the same color but go from green to purple via yellow and red)
		#define PROGRESS_HUE_END		-1
		#define DIMMABLE_STATES			50		// Number of dimmed values between two full LEDs (https://forum.espuino.de/t/led-verbesserungen-rework/1739)
		//#define LED_OFFSET 0 // shifts the starting LED in the original direction of the neopixel ring
	#endif

	#if defined(MEASURE_BATTERY_VOLTAGE) || defined(MEASURE_BATTERY_MAX17055)
		#define BATTERY_MEASURE_ENABLE                 // Don't change. Set automatically if any method of battery monitoring is selected.
		constexpr uint8_t s_batteryCheckInterval = 10; // How often battery is measured (in minutes) (can be changed via GUI!)
	#endif

	#ifdef MEASURE_BATTERY_VOLTAGE
		// (optional) Default-voltages for battery-monitoring via Neopixel; can be changed later via WebGUI
		constexpr float s_warningLowVoltage = 3.4;                      // If battery-voltage is <= this value, a cyclic warning will be indicated by Neopixel (can be changed via GUI!)
		constexpr float s_warningCriticalVoltage = 3.1;                 // If battery-voltage is <= this value, assume battery near-empty. Set to 0V to disable.
		constexpr float s_voltageIndicatorLow = 3.0;                    // Lower range for Neopixel-voltage-indication (0 leds) (can be changed via GUI!)
		constexpr float s_voltageIndicatorHigh = 4.2;                   // Upper range for Neopixel-voltage-indication (all leds) (can be changed via GUI!)
	#endif

	#ifdef MEASURE_BATTERY_MAX17055
		constexpr float s_batteryLow = 10.0;            // low percentage
		constexpr float s_batteryCritical = 0.99;        // critical percentage

		constexpr uint16_t s_batteryCapacity = 6000;    // design cap of battery (mAh)
		constexpr uint16_t s_emptyVoltage = 300;        // empty voltage in 10mV
		constexpr uint16_t s_recoveryVoltage = 336;     // recovery voltage in 10mV
		constexpr uint8_t  s_batteryChemistry = 0x60;   // 0 = Li-Ion, 0x20 = NCR, 0x60 = LiFePO4
		constexpr float s_resistSensor = 0.01;          // current sense resistor, currently non-default values might lead to problems
		constexpr bool s_vCharge = false;                   // true if charge voltage is greater than 4.275V
	#endif

	// enable I2C if necessary
	#if defined(RFID_READER_TYPE_MFRC522_I2C) || defined(PORT_EXPANDER_ENABLE) || defined(MEASURE_BATTERY_MAX17055)
		#define I2C_2_ENABLE
	#endif

	// (optinal) Headphone-detection (leave unchanged if in doubts...)
	#ifdef HEADPHONE_ADJUST_ENABLE
		constexpr uint16_t headphoneLastDetectionDebounce = 1000; // Debounce-interval in ms when plugging in headphone
	#endif

	// Seekmode-configuration
	constexpr uint8_t jumpOffset = 30;                            // Offset in seconds to jump for commands CMD_SEEK_FORWARDS / CMD_SEEK_BACKWARDS

	// (optional) Topics for MQTT
	#ifdef MQTT_ENABLE
		#define DEVICE_HOSTNAME "ESP32-ESPuino"         // Name that is used for MQTT
		constexpr const char topicSleepCmnd[] = "Cmnd/ESPuino/Sleep";
		constexpr const char topicSleepState[] = "State/ESPuino/Sleep";
		constexpr const char topicRfidCmnd[] = "Cmnd/ESPuino/Rfid";
		constexpr const char topicRfidState[] = "State/ESPuino/Rfid";
		constexpr const char topicTrackState[] = "State/ESPuino/Track";
		constexpr const char topicTrackControlCmnd[] = "Cmnd/ESPuino/TrackControl";
		constexpr const char topicCoverChangedState[] = "State/ESPuino/CoverChanged";
		constexpr const char topicLoudnessCmnd[] = "Cmnd/ESPuino/Loudness";
		constexpr const char topicLoudnessState[] = "State/ESPuino/Loudness";
		constexpr const char topicSleepTimerCmnd[] = "Cmnd/ESPuino/SleepTimer";
		constexpr const char topicSleepTimerState[] = "State/ESPuino/SleepTimer";
		constexpr const char topicState[] = "State/ESPuino/State";
		constexpr const char topicCurrentIPv4IP[] = "State/ESPuino/IPv4";
		constexpr const char topicLockControlsCmnd[] ="Cmnd/ESPuino/LockControls";
		constexpr const char topicLockControlsState[] ="State/ESPuino/LockControls";
		constexpr const char topicPlaymodeState[] = "State/ESPuino/Playmode";
		constexpr const char topicRepeatModeCmnd[] = "Cmnd/ESPuino/RepeatMode";
		constexpr const char topicRepeatModeState[] = "State/ESPuino/RepeatMode";
		constexpr const char topicLedBrightnessCmnd[] = "Cmnd/ESPuino/LedBrightness";
		constexpr const char topicLedBrightnessState[] = "State/ESPuino/LedBrightness";
		constexpr const char topicWiFiRssiState[] = "State/ESPuino/WifiRssi";
		constexpr const char topicSRevisionState[] = "State/ESPuino/SoftwareRevision";
		#ifdef BATTERY_MEASURE_ENABLE
		constexpr const char topicBatteryVoltage[] = "State/ESPuino/Voltage";
		constexpr const char topicBatterySOC[]     = "State/ESPuino/Battery";
		#endif
	#endif

	// !!! MAKE SURE TO EDIT PLATFORM SPECIFIC settings-****.h !!!
	#if (HAL == 4)
		#include "settings-lolin_d32_pro.h"                 // Contains all user-relevant settings for Wemos Lolin D32 pro
	#elif (HAL == 5)
		#include "settings-ttgo_t8.h"                       // Contains all user-relevant settings for Lilygo TTGO T8 1.7
	#elif (HAL == 6)
		#include "settings-complete.h"                      // Contains all user-relevant settings for ESPuino complete
	#elif (HAL == 7)
		#include "settings-lolin_d32_pro_sdmmc_pe.h"        // Pre-configured settings for ESPuino Lolin D32 pro with SDMMC + port-expander (https://forum.espuino.de/t/espuino-minid32pro-lolin-d32-pro-mit-sd-mmc-und-port-expander-smd/866)
	#elif (HAL == 99)
		#include "settings-custom.h"                        // Contains all user-relevant settings custom-board
	#endif

	#endif //settings_override
#endif
