#include "thermocouples.h"

namespace Thermocouples{

    MAX31855_Class tc; 

    Comms::Packet packet = [.id = 110} //make your packets 

    void init() {
        tc.begin(21);
    }
    uint32_t sampleTC(){
        int32_t reading = tc.readProbe();

        packet.len=0;
        Comms::packetAddUint32(&packet, reading);
        Comms::emitPacket(&packet); //sending stuff to dashboard

        return 1e3;
    }
}