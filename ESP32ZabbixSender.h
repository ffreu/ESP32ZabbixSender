#ifndef _ESP32ZabbixSender_H_
#define _ESP32ZabbixSender_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <WiFi.h>
#define ZABBIXMAXLEN 300 // max 256byte packet
#define ZABBIXMAXITEM 50 // max 50 items
#define ZABBIXTIMEOUT 1000 // 1000ms

class ESP32ZabbixSender {
public:
	ESP32ZabbixSender(void);
	void Init(IPAddress ZabbixServerAddr, uint16_t ZabbixServerPort, String ZabbixItemHostName);
	int Send(void);
	void ClearItem(void);
	void AddItem(String key, String value);

private:
	int createZabbixPacket(void);
	struct zabbixCell {
		String key;
		String val;
	};
	WiFiClient zClient;
	IPAddress zAddr;
	uint16_t zPort;
	String zItemHost;
	uint8_t zabbixPacket[ZABBIXMAXLEN];
	zabbixCell zabbixItemList[ZABBIXMAXITEM];
	int zabbixItemSize;
};

#endif
