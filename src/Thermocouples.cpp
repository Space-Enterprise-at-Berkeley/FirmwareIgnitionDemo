#include "Thermocouples.h";
#include "Comms.h";

namespace Thermocouples{
    
    MAX31855_Class tc;

    Comms::Packet packet = {.id = 110};

    void init(){
        tc.begin(21);
    }

    uint32_t sampleTC(){
        int32_t reading = tc.readProbe();

        packet.len = 0;
        Comms::packetAddFloat(&packet,float(reading));

        return 1e3;
    }
}