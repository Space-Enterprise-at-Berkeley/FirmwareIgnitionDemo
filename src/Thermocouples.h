#pragma once

#include <Arduino.h>
#include <MAX31855.h>
#include "Comms.h"

namespace Thermocouples {
    
    void init();
    uint32_t sampleTC();

}