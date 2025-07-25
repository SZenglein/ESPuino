
#include "settings.h"

#if (LANGUAGE == DE)
	#include "Log.h"

const char tryConnectMqttS[] = "Versuche Verbindung zu MQTT-Broker aufzubauen: %s";
const char mqttOk[] = "MQTT-Session aufgebaut.";
const char sleepTimerEOP[] = "Sleep-Timer: Nach dem letzten Track der Playlist.";
const char sleepTimerEOT[] = "Sleep-Timer: Nach dem Ende des laufenden Tracks.";
const char sleepTimerStop[] = "Sleep-Timer wurde deaktiviert.";
const char sleepTimerEO5[] = "Sleep Timer: Nach Ende des Titels oder, wenn früher, Ende der Playlist";
const char sleepTimerAlreadyStopped[] = "Sleep-Timer ist bereits deaktiviert.";
const char sleepTimerSetTo[] = "Sleep-Timer gesetzt auf %u Minute(n)";
const char allowButtons[] = "Alle Tasten werden freigegeben.";
const char lockButtons[] = "Alle Tasten werden gesperrt.";
const char noPlaylistNotAllowedMqtt[] = "Playmode kann nicht auf 'Keine Playlist' gesetzt werden via MQTT.";
const char playmodeChangedMQtt[] = "Playmode per MQTT angepasst.";
const char noPlaymodeChangeIfIdle[] = "Playmode kann nicht verändert werden, wenn keine Playlist aktiv ist.";
const char noValidTopic[] = "Kein gültiges Topic: %s";
const char freePtr[] = "Ptr-Freigabe: %s (0x%04x)";
const char freeMemory[] = "Freier Speicher: %u Bytes";
const char writeEntryToNvs[] = "[%u] Schreibe Eintrag in NVS: %s => %s";
const char freeMemoryAfterFree[] = "Freier Speicher nach Aufräumen: %u Bytes";
const char releaseMemoryOfOldPlaylist[] = "Gebe Speicher der alten Playlist frei (Freier Speicher: %u Bytes)";
const char dirOrFileDoesNotExist[] = "Datei oder Verzeichnis existiert nicht: %s";
const char unableToAllocateMemForPlaylist[] = "Speicher für Playlist konnte nicht allokiert werden!";
const char unableToAllocateMem[] = "Speicher konnte nicht allokiert werden!";
const char fileModeDetected[] = "Dateimodus erkannt.";
const char fileInvalid[] = "Ungültige Datei: %s";
const char nameOfFileFound[] = "Gefundenes File: %s";
const char reallocCalled[] = "Speicher reallokiert.";
const char unableToAllocateMemForLinearPlaylist[] = "Speicher für lineare Playlist konnte nicht allokiert werden!";
const char numberOfValidFiles[] = "Anzahl gültiger Files/Webstreams: %u";
const char newLoudnessReceivedQueue[] = "Neue Lautstärke empfangen via Queue: %u";
const char newEqualizerReceivedQueue[] = "Neue Equalizer-Einstellungen empfangen via Queue: %i, %i, %i";
const char newCntrlReceivedQueue[] = "Kontroll-Kommando empfangen via Queue: %u";
const char newPlaylistReceived[] = "Neue Playlist mit %d Titel(n) empfangen";
const char repeatTrackDueToPlaymode[] = "Wiederhole Titel aufgrund von Playmode.";
const char repeatPlaylistDueToPlaymode[] = "Wiederhole Playlist aufgrund von Playmode.";
const char cmndStop[] = "Kommando: Stop";
const char cmndPause[] = "Kommando: Pause";
const char cmndResumeFromPause[] = "Kommando: Fortsetzen";
const char cmndNextTrack[] = "Kommando: Nächster Titel";
const char cmndPrevTrack[] = "Kommando: Vorheriger Titel";
const char cmndFirstTrack[] = "Kommando: Erster Titel von Playlist";
const char cmndLastTrack[] = "Kommando: Letzter Titel von Playlist";
const char cmndDoesNotExist[] = "Dieses Kommando existiert nicht.";
const char lastTrackAlreadyActive[] = "Es wird bereits der letzte Track gespielt.";
const char trackStartAudiobook[] = "Titel wird im Hörspielmodus von vorne gespielt.";
const char trackStart[] = "Titel wird von vorne gespielt.";
const char trackChangeWebstream[] = "Im Webradio-Modus kann nicht an den Anfang gesprungen werden.";
const char endOfPlaylistReached[] = "Ende der Playlist erreicht.";
const char trackStartatPos[] = "Titel wird abgespielt ab Position %u";
const char waitingForTaskQueues[] = "Task Queue für RFID existiert noch nicht, warte...";
const char rfidScannerReady[] = "RFID-Tags koennen jetzt gescannt werden...";
const char rfidTagDetected[] = "RFID-Karte erkannt: %s";
const char rfid15693TagDetected[] = "RFID-Karte (ISO-15693) erkannt: ";
const char rfidTagReceived[] = "RFID-Karte empfangen";
const char dontAccepctSameRfid[] = "Aktuelle RFID-Karte erneut aufgelegt - abgelehnt! (%s)";
const char rfidTagUnknownInNvs[] = "RFID-Karte ist im NVS nicht hinterlegt.";
const char goToSleepDueToIdle[] = "Gehe in Deep Sleep wegen Inaktivität...";
const char goToSleepDueToTimer[] = "Gehe in Deep Sleep wegen Sleep Timer...";
const char goToSleepNow[] = "Gehe jetzt in Deep Sleep!";
const char maxLoudnessReached[] = "Maximale Lautstärke bereits erreicht!";
const char minLoudnessReached[] = "Minimale Lautstärke bereits erreicht!";
const char errorOccured[] = "Fehler aufgetreten!";
const char noMp3FilesInDir[] = "Verzeichnis beinhaltet keine mp3-Files.";
const char modeSingleTrack[] = "Modus: Einzelner Track";
const char modeSingleTrackLoop[] = "Modus: Einzelner Track in Endlosschleife";
const char modeSingleTrackRandom[] = "Modus: Einzelner Track eines Ordners zufällig";
const char modeSingleAudiobook[] = "Modus: Hoerspiel";
const char modeSingleAudiobookLoop[] = "Modus: Hoerspiel in Endlosschleife";
const char modeAllTrackAlphSorted[] = "Modus: Spiele alle Tracks (sortiert) des Ordners '%s'";
const char modeAllTrackRandom[] = "Modus: Spiele alle Tracks (zufällig sortiert) des Ordners '%s'";
const char modeAllTrackAlphSortedLoop[] = "Modus: Alle Tracks eines Ordners sortiert in Endlosschleife";
const char modeAllTrackRandomLoop[] = "Modus: Alle Tracks eines Ordners zufällig in Endlosschleife";
const char modeWebstream[] = "Modus: Webstream";
const char modeWebstreamM3u[] = "Modus: Webstream (lokale .m3u-Datei)";
const char webstreamNotAvailable[] = "Aktuell kein Webstream möglich, da keine WLAN-Verbindung vorhanden!";
const char modeInvalid[] = "Ungültiger Abspielmodus %d!";
const char modeRepeatNone[] = "Repeatmodus: Kein Repeat";
const char modeRepeatTrack[] = "Repeatmodus: Aktueller Titel";
const char modeRepeatPlaylist[] = "Repeatmodus: Gesamte Playlist";
const char modeRepeatTracknPlaylist[] = "Repeatmodus: Track und Playlist";
const char modificatorAllButtonsLocked[] = "Modifikator: Alle Tasten werden per RFID gesperrt.";
const char modificatorAllButtonsUnlocked[] = "Modifikator: Alle Tasten werden per RFID freigegeben.";
const char modificatorSleepd[] = "Modifikator: Sleep-Timer wieder deaktiviert.";
const char modificatorSleepTimer15[] = "Modifikator: Sleep-Timer per RFID aktiviert (15 Minuten).";
const char modificatorSleepTimer30[] = "Modifikator: Sleep-Timer per RFID aktiviert (30 Minuten).";
const char modificatorSleepTimer60[] = "Modifikator: Sleep-Timer per RFID aktiviert (60 Minuten).";
const char modificatorSleepTimer120[] = "Modifikator: Sleep-Timer per RFID aktiviert (2 Stunden).";
const char ledsDimmedToNightmode[] = "LEDs wurden auf Nachtmodus gedimmt.";
const char ledsDimmedToInitialValue[] = "LEDs wurden auf initiale Helligkeit gedimmt.";
const char ledsBrightnessRestored[] = "LED Helligkeit wieder hergestellt.";
const char modificatorNotallowedWhenIdle[] = "Modifikator kann bei nicht aktivierter Playlist nicht angewendet werden.";
const char modificatorSleepAtEOT[] = "Modifikator: Sleep-Timer am Ende des Titels aktiviert.";
const char modificatorSleepAtEOP[] = "Modifikator: Sleep-Timer am Ende der Playlist aktiviert.";
const char modificatorAllTrackAlphSortedLoop[] = "Modifikator: Alle Titel (sortiert) in Endlosschleife.";
const char modificatorAllTrackRandomLoop[] = "Modifikator: Alle Titel (zufällige Reihenfolge) in Endlosschleife.";
const char modificatorCurTrackLoop[] = "Modifikator: Aktueller Titel in Endlosschleife.";
const char modificatorCurAudiobookLoop[] = "Modifikator: Aktuelles Hörspiel in Endlosschleife.";
const char modificatorPlaylistLoopActive[] = "Modifikator: Alle Titel in Endlosschleife aktiviert.";
const char modificatorPlaylistLoopDeactive[] = "Modifikator: Alle Titel in Endlosschleife deaktiviert.";
const char modificatorTrackActive[] = "Modifikator: Titel in Endlosschleife aktiviert.";
const char modificatorTrackDeactive[] = "Modifikator: Titel in Endlosschleife deaktiviert.";
const char modificatorNotAllowed[] = "Modifikator konnte nicht angewendet werden.";
const char modificatorLoopRev[] = "Modifikator: Endlosschleife beendet.";
const char modificatorDoesNotExist[] = "Ein Karten-Modifikator existiert nicht vom Typ %d!";
const char errorOccuredNvs[] = "Es ist ein Fehler aufgetreten beim Lesen aus dem NVS!";
const char statementsReceivedByServer[] = "Vom Server wurde Folgendes empfangen";
const char apReady[] = "Access-Point geöffnet";
const char httpReady[] = "HTTP-Server gestartet.";
const char unableToMountSd[] = "SD-Karte konnte nicht gemountet werden.";
const char unableToCreateQueue[] = "Konnte Queue %s nicht anlegen";
const char initialBrightnessfromNvs[] = "Initiale LED-Helligkeit wurde aus NVS geladen: %u";
const char wroteInitialBrightnessToNvs[] = "Initiale LED-Helligkeit wurde ins NVS geschrieben.";
const char restoredInitialBrightnessForNmFromNvs[] = "LED-Helligkeit für Nachtmodus wurde aus NVS geladen: %u";
const char wroteNmBrightnessToNvs[] = "LED-Helligkeit für Nachtmodus wurde ins NVS geschrieben.";
const char wroteFtpUserToNvs[] = "FTP-User wurde ins NVS geschrieben.";
const char restoredFtpUserFromNvs[] = "FTP-User wurde aus NVS geladen: %s";
const char wroteFtpPwdToNvs[] = "FTP-Passwort wurde ins NVS geschrieben.";
const char restoredFtpPwdFromNvs[] = "FTP-Passwort wurde aus NVS geladen: %s";
const char restoredMaxInactivityFromNvs[] = "Maximale Inaktivitätszeit wurde aus NVS geladen: %u Minuten";
const char wroteMaxInactivityToNvs[] = "Maximale Inaktivitätszeit wurde ins NVS geschrieben.";
const char restoredInitialLoudnessFromNvs[] = "Initiale Lautstärke wurde aus NVS geladen: %u";
const char wroteInitialLoudnessToNvs[] = "Initiale Lautstärke wurde ins NVS geschrieben.";
const char restoredMaxLoudnessForSpeakerFromNvs[] = "Maximale Lautstärke für Lautsprecher wurde aus NVS geladen: %u";
const char restoredMaxLoudnessForHeadphoneFromNvs[] = "Maximale Lautstärke für Kopfhörer wurde aus NVS geladen: %u";
const char wroteMaxLoudnessForSpeakerToNvs[] = "Maximale Lautstärke für Lautsprecher wurde ins NVS geschrieben.";
const char wroteMaxLoudnessForHeadphoneToNvs[] = "Maximale Lautstärke für Kopfhörer wurde ins NVS geschrieben.";
const char maxVolumeSet[] = "Maximale Lautstärke wurde gesetzt auf: %u";
const char wroteMqttFlagToNvs[] = "MQTT-Flag wurde ins NVS geschrieben.";
const char restoredMqttActiveFromNvs[] = "MQTT-Flag (aktiviert) wurde aus NVS geladen: %u";
const char restoredMqttDeactiveFromNvs[] = "MQTT-Flag (deaktiviert) wurde aus NVS geladen: %u";
const char wroteMqttClientIdToNvs[] = "MQTT-ClientId wurde ins NVS geschrieben.";
const char restoredMqttClientIdFromNvs[] = "MQTT-ClientId wurde aus NVS geladen: %s";
const char wroteMqttServerToNvs[] = "MQTT-Server wurde ins NVS geschrieben.";
const char restoredMqttServerFromNvs[] = "MQTT-Server wurde aus NVS geladen: %s";
const char wroteMqttUserToNvs[] = "MQTT-User wurde ins NVS geschrieben.";
const char restoredMqttUserFromNvs[] = "MQTT-User wurde aus NVS geladen: %s";
const char wroteMqttPwdToNvs[] = "MQTT-Passwort wurde ins NVS geschrieben.";
const char restoredMqttPwdFromNvs[] = "MQTT-Passwort wurde aus NVS geladen: %s";
const char restoredMqttPortFromNvs[] = "MQTT-Port wurde aus NVS geladen: %u";
const char mqttWithPwd[] = "Verbinde zu MQTT-Server mit User und Passwort";
const char mqttWithoutPwd[] = "Verbinde zu MQTT-Server ohne User und Passwort";
const char ssidNotFoundInNvs[] = "SSID wurde im NVS nicht gefunden.";
const char wifiStaticIpConfigNotFoundInNvs[] = "Statische WLAN-IP-Konfiguration wurde im NVS nicht gefunden.";
const char wifiHostnameNotSet[] = "Keine Hostname-Konfiguration im NVS gefunden.";
const char mqttConnFailed[] = "Verbindung fehlgeschlagen, versuche in Kürze erneut: rc=%i (%d / %d)";
const char restoredHostnameFromNvs[] = "Hostname aus NVS geladen: %s";
const char currentVoltageMsg[] = "Aktuelle Batteriespannung: %.2f V";
const char currentChargeMsg[] = "Aktuelle Batterieladung: %.2f %%";
const char batteryCurrentMsg[] = "Stromverbrauch (Batterie): %.2f mA";
const char batteryTempMsg[] = "Temperatur der Batterie: %.2f°C";
const char batteryCyclesMsg[] = "Gesehene Batteriezyklen: %.2f";
const char batteryLowMsg[] = "Batterieladung niedrig";
const char batteryCriticalMsg[] = "Batterieladung kritisch. Gehe in Deepsleep...";
const char sdBootFailedDeepsleep[] = "Bootgang wegen SD fehlgeschlagen. Gehe in Deepsleep...";
const char wifiEnabledMsg[] = "WLAN wird aktiviert.";
const char wifiDisabledMsg[] = "WLAN wird deaktiviert.";
const char voltageIndicatorLowFromNVS[] = "Unterer Spannungslevel (Batterie) fuer Neopixel-Anzeige aus NVS geladen: %.2fV";
const char voltageIndicatorHighFromNVS[] = "Oberer Spannungslevel (Batterie) fuer Neopixel-Anzeige aus NVS geladen: %.2fV";
const char batteryCheckIntervalFromNVS[] = "Zyklus für Batteriemessung fuer Neopixel-Anzeige aus NVS geladen: %u Minuten";
const char warningLowVoltageFromNVS[] = "Spannungslevel (Batterie) fuer Niedrig-Warnung via Neopixel aus NVS geladen: %.2fV";
const char warningCriticalVoltageFromNVS[] = "Spannungslevel (Batterie) fuer Kritisch-Warnung via Neopixel aus NVS geladen: %.2fV";
const char batteryLowFromNVS[] = "Batterieladestand fuer Niedrig-Warnung via Neopixel aus NVS geladen: %.2f %%";
const char batteryCriticalFromNVS[] = "Batterieladestand fuer Kritisch-Warnung via Neopixel aus NVS geladen: %.2f %%";
const char unableToRestoreLastRfidFromNVS[] = "Letzte RFID konnte nicht aus NVS geladen werden";
const char restoredLastRfidFromNVS[] = "Letzte RFID wurde aus NVS geladen: %s";
const char failedOpenFileForWrite[] = "Öffnen der Datei für den Schreibvorgang fehlgeschlagen";
const char fileWritten[] = "Datei geschrieben: %s => %zu bytes in %lu ms (%lu kiB/s)";
const char writeFailed[] = "Schreibvorgang fehlgeschlagen";
const char writingFile[] = "Schreibe Datei: %s";
const char failedToOpenFileForAppending[] = "Öffnen der Datei zum Schreiben der JSON-Datei fehlgeschlagen";
const char listingDirectory[] = "Verzeichnisinhalt anzeigen";
const char failedToOpenDirectory[] = "Öffnen des Verzeichnisses fehlgeschlagen";
const char notADirectory[] = "Kein Verzeichnis";
const char sdMountedMmc1BitMode[] = "Versuche SD-Karte im SD_MMC-Modus (1 Bit) zu mounten...";
const char sdMountedSpiMode[] = "Versuche SD-Karte im SPI-Modus zu mounten...";
const char restartWebsite[] = "<p>Der ESPuino wird neu gestartet...<br />Zur letzten Seite <a href=\"javascript:history.back()\">zur&uuml;ckkehren</a>.</p>";
const char shutdownWebsite[] = "Der ESPuino wird ausgeschaltet...";
const char mqttMsgReceived[] = "MQTT-Nachricht empfangen: [Topic: %s] [Command: %s]";
const char trackPausedAtPos[] = "Titel pausiert bei Position: %u (%u)";
const char freeHeapWithoutFtp[] = "Freier Heap-Speicher vor FTP-Instanzierung: %u";
const char freeHeapWithFtp[] = "Freier Heap-Speicher nach FTP-Instanzierung: %u";
const char ftpServerStarted[] = "FTP-Server gestartet";
const char freeHeapAfterSetup[] = "Freier Heap-Speicher nach Setup-Routine";
const char tryStaticIpConfig[] = "Statische IP-Konfiguration wird durchgeführt...";
const char staticIPConfigFailed[] = "Statische IP-Konfiguration fehlgeschlagen";
const char wakeUpRfidNoCard[] = "ESP32 wurde vom Kartenleser aus dem Deepsleep aufgeweckt. Allerdings wurde keine bekannte Karte gefunden. Gehe zurück in den Deepsleep...";
const char lowPowerCardSuccess[] = "Kartenerkennung via 'low power' erfolgreich durchgeführt";
const char rememberLastVolume[] = "Lautstärke vor dem letzten Shutdown wird wiederhergestellt. Dies überschreibt die Einstellung der initialen Lautstärke aus der GUI.";
const char unableToStartFtpServer[] = "Der FTP-Server konnte nicht gestartet werden. Entweder weil er ist bereits gestartet oder kein WLAN verfügbar ist.";
const char unableToTellIpAddress[] = "IP-Adresse kann nicht angesagt werden, da keine WLAN-Verbindung besteht.";
const char unableToTellTime[] = "Uhrzeit kann nicht angesagt werden, da keine WLAN-Verbindung besteht.";
const char newPlayModeStereo[] = "Neuer Modus: stereo";
const char newPlayModeMono[] = "Neuer Modus: mono";
const char portExpanderFound[] = "Port-expander gefunden";
const char portExpanderNotFound[] = "Port-expander nicht gefunden";
const char portExpanderInterruptEnabled[] = "Interrupt für Port-Expander aktiviert";
const char playlistGen[] = "Playlist-Generierung";
const char bootLoopDetected[] = "Bootschleife erkannt! Letzte RFID wird nicht aufgerufen.";
const char noBootLoopDetected[] = "Keine Bootschleife erkannt. Wunderbar :-)";
const char importCountNokNvs[] = "Anzahl der ungültigen Import-Einträge: %u";
const char errorReadingTmpfile[] = "Beim Lesen der temporären Importdatei ist ein Fehler aufgetreten!";
const char errorWritingTmpfile[] = "Beim Schreiben der temporären Importdatei ist ein Fehler aufgetreten!";
const char eraseRfidNvs[] = "NVS-RFID-Zuweisungen werden gelöscht...";
const char fwStart[] = "Starte Firmware-update via OTA...";
const char fwEnd[] = "Firmware-update beendet";
const char otaNotSupported[] = "Firmware-update wird von diesem ESPuino nicht unterstuetzt!";
const char otaNotSupportedWebsite[] = "<p>Firmware-update wird von diesem ESPuino nicht unterstuetzt!<br />Zur letzten Seite <a href=\"javascript:history.back()\">zur&uuml;ckkehren</a>.</p>";
const char noPlaylist[] = "Keine Playlist aktiv.";
const char rfidTagRemoved[] = "RFID-Karte wurde entfernt";
const char rfidTagReapplied[] = "RFID-Karte erneut aufgelegt";
const char ftpEnableTooLate[] = "FTP kann nur innerhalb der ersten 30s aktiviert werden. Kinderschutz :-)";
const char dateTimeRTC[] = "Datum/Uhrzeit (Interne RTC): %02d.%02d.%4d, %02d:%02d:%02d";
const char syncingViaNtp[] = "Synchronisiere Uhrzeit via NTP...";
const char ntpGotTime[] = "Datum/Uhrzeit empfangen von NTP-Server: %02d.%02d.%4d, %02d:%02d:%02d";
const char ntpFailed[] = "NTP: Datum/Uhrzeit (noch) nicht verfügbar";
const char sdInfo[] = "SD-Kartengröße / freier Speicherplatz: %llu MB / %llu MB";
const char paOn[] = "Lautsprecher eingeschaltet";
const char paOff[] = "Lautsprecher ausgeschaltet";
const char hpOn[] = "Kopfhörer eingeschaltet";
const char hpOff[] = "Kopfhörer ausgeschaltet";
const char webTxCanceled[] = "Der Webtransfer wurde aufgrund von Inaktivität beendet.";
const char webSaveSettingsError[] = "Einstellungen konnten nicht gespeichert werden für '%s'";
const char tryToPickRandomDir[] = "Versuche ein zufälliges Unterverzeichnis zu finden aus: %s";
const char pickedRandomDir[] = "Zufällig ausgewähltes Unterverzeichnis: %s";
const char wrongWakeUpGpio[] = "Der gewählte GPIO ist nicht vom Typ RTC und unterstützt daher das Aufwecken des ESP32 nicht! (GPIO: %u)";
const char currentlyPlaying[] = "'%s' wird abgespielt (%d von %d)";
const char secondsJumpForward[] = "%d Sekunden nach vorne gesprungen";
const char secondsJumpBackward[] = "%d Sekunden zurück gesprungen";
const char JumpToPosition[] = "Sprung zu Position %u/%u";
const char wroteLastTrackToNvs[] = "Schreibe '%s' in NVS für RFID-Card-ID %s mit Abspielmodus %d und letzter Track %u";
const char wifiConnectionInProgress[] = "Versuche mit WLAN '%s' zu verbinden...";
const char wifiConnectionSuccess[] = "Verbunden mit WLAN '%s' (Signalstärke: %d dBm, Kanal: %d, MAC-Adresse: %s)";
const char wifiCurrentIp[] = "Aktuelle IP: %s";
const char jsonErrorMsg[] = "deserializeJson() fehlgeschlagen: %s";
const char jsonbufferOverflow[] = "JSON-Puffer zu klein für Daten";
const char wifiDeleteNetwork[] = "Lösche gespeichertes WLAN %s";
const char wifiNetworkLoaded[] = "SSID %d von NVS geladen: %s";
const char wifiTooManyNetworks[] = "Anzahl der WLAN-Netze in NVS ist %d, aber es sind maximal %d erlaubt.";
const char wifiAddTooManyNetworks[] = "Kein Platz, weiteres WLAN zu speichern!";
const char wifiAddNetwork[] = "Füge WLAN hinzu: %s";
const char wifiUpdateNetwork[] = "Ändere Passwort für WLAN %s";
const char wifiScanResult[] = "WLAN '%s'gefunden (Signalstärke: %d dBm, Kanal: %d, MAC-Adresse: %s)";
const char cantConnectToWifi[] = "WLAN-Verbindung fehlgeschlagen.";
const char wifiSetLastSSID[] = "Schreibe letzte erfolgreiche SSID in NVS für WLAN Schnellstart: %s";
const char mDNSStarted[] = "mDNS gestartet: http://%s.local";
const char mDNSFailed[] = "mDNS Start fehlgeschlagen, Hostname: %s";
const char restartAfterOperationModeChange[] = "Operation Mode geändert. ESPuino wird neu gestartet...";
#endif
