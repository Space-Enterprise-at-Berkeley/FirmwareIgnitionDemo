#include "Thermocouple.h"
#include "Comms.h"

namespace Thermocouple {
    
    MAX31855_Class tc;

    Comms::Packet packet = {.id = 110};

    void init() {
        tc.begin(21);
    }

    uint32_t sampleTC(){

        int32_t reading = tc.readProbe();
        //Serial.println(reading);
        packet.len=0;
        Comms::packetAddFloat(&packet,float(reading));
        Comms::emitPacker(&packet);

        return 1e3;
    }

    }