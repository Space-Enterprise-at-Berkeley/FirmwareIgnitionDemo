#include <Arduino.h>
#include <Comms.h>
#include <Thermocouples.h>

Task taskTable[] = {
    {Thermocouples::sampleTC, 0, true},
};

#define TASK_COUNT (sizeof(taskTable) / sizeof (struct Task))

int main() {

    Serial.begin(9600);

    while(1) {
        for(uint32_t i = 0; i < TASK_COUNT; i++) { // for each task, execute if next time >= current time
            uint32_t ticks = micros(); // current time in microseconds
            if (taskTable[i].nexttime - ticks > UINT32_MAX / 2 && taskTable[i].enabled) {
                taskTable[i].nexttime = ticks + taskTable[i].taskCall();
            }
        }
        Comms::processWaitingPackets();
    }
    return 0;
}
