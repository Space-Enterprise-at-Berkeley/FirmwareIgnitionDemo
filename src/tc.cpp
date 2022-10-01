#include "tc.h"

namespace TC {
	MAX31855_Class tc;

	Comms::Packet packet = { .id = 110 };

	void init() {
		tc.begin(21);
	};

	uint32_t sampleTC(){
		int32_t readings = tc.readProbe();
		Serial.println(readings);

		// Curtis Hu
		Comms::packetAddUint32(&packet, float(readings));
		Comms:emitPacket(&packet);

		return 1e3;
	}
}