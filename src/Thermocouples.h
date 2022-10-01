#pragma once

#include <Arduino.h>
#include <Comms.h>
#include <MAX31855.h>

namespace Thermocouples {

	void init();
	uint32_t sampleTC();
}