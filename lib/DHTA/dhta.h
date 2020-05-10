#ifndef __DHTA_H__
#define __DHTA_H__

#include <stdint.h>

namespace DHTA
{
	void init();
	void handle();

	float getHumidity();
	float getTemperature();
	float getLastHumidity();
	float getLastTemperature();
}
#endif //__DHTA_H__