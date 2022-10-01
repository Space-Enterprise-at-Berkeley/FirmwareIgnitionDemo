#include "Actuator.h"

namespace Actuator{

    uint8_t hbridgepin1 = 4;
    uint8_t hbridgepin2 = 5;

    void driveForward(){
        digitalWrite(hbridgepin1, HIGH);
        digitalWrite(hbridgepin2, LOW);
    }

    void driveBack(){
        digitalWrite(hbridgepin1, LOW);
        digitalWrite(hbridgepin2, HIGH);
    }

    void stop(){
        digitalWrite(hbridgepin1, LOW);
        digitalWrite(hbridgepin2, LOW);
    }

    void packetHandler(Comms::Packet packet, uint8_t ip){
        uint8_t state = Comms::packetGetUint32(&packet, 0);

        if (state == 0){
            driveForward();
        } else if (state == 1){
            driveBack();
        } else{
            stop();
        }
    }

    void init(){
        Comms::registerCallback(170, packetHandler);
    }
}