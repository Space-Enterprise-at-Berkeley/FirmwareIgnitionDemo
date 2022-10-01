#include "Thermocouples.h"

namespace Thermocouples {

    MAX31855_Class tc;

    Comms::Packet packet = {.id = 10};

    void init() {
        tc.begin(21);
    }

    uint32_t sampleTC() {
        int32_t reading = tc.readProbe();
        Serial.println(reading); //test to debug readings and ensure readings are correct
        Comms::packetAddFloat(&packet, float(reading));
        Comms::emitPacket(&packet);

        return 1e3; //run ecery millisecond (1e3 microseconds)

    }

}