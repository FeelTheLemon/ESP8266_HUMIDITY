#include <Arduino.h>
#include <ota.h>
#include <wifi.h>
#include <web.h>
#include <dhta.h>

#define LED_BUILTIN 2

void setup()
{
	// put your setup code here, to run once:
	WiFiE::init();
	OTA::init();
	WEB::init();
	DHTA::init();
	pinMode(LED_BUILTIN, OUTPUT);
}

char light = 0;
void blink()
{
	light = !light;
	digitalWrite(LED_BUILTIN, light);
}

void loop()
{
	WiFiE::handle();
	OTA::handle();
	WEB::handle();
	DHTA::handle();
	blink();
}