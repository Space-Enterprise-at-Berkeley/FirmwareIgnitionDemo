#include "Thermocouples.h"

namespace Thermocouples {

	MAX31855_Class tc;

	void init() {
		tc.begin(21);
	}

	uint32_t sampleTC() {
		float reading = (float) tc.readProbe();
		Serial.println(reading);
		Comms::Packet packet = {.id = 110};
		Comms::packetAddFloat(&packet, reading);
		Comms::emitPacket(&packet);
		return 100 * 1000;
	}
}