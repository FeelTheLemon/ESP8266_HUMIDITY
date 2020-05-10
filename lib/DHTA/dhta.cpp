#include "dhta.h"

#include <Arduino.h>
#include <DHT.h>

#define HT_PIN 4

DHT dht;

float last_humidity = 0;
float last_temperature = 0;

float humidity = 0;
float temperature = 0;

unsigned int DHTMSP;
unsigned long dht_last_sample = 0;

void DHTA::init()
{
	dht.setup(HT_PIN, DHT::DHT_MODEL_t::DHT11);
	DHTMSP = dht.getMinimumSamplingPeriod();
}

#define kQ 0.2
void DHTA::handle()
{
	unsigned long now = millis();
	if (now - dht_last_sample > DHTMSP)
	{
		last_humidity = dht.getHumidity();
		last_temperature = dht.getTemperature();

		if (last_humidity > 0)
			humidity = humidity * (1 - kQ) + last_humidity * kQ;

		if (last_temperature > 0)
			temperature = temperature * (1 - kQ) + last_temperature * kQ;

		dht_last_sample = now;
	}
}

float DHTA::getHumidity()
{
	return humidity;
}

float DHTA::getTemperature()
{
	return temperature;
}

float DHTA::getLastHumidity()
{
	return last_humidity;
}

float DHTA::getLastTemperature()
{
	return last_temperature;
}