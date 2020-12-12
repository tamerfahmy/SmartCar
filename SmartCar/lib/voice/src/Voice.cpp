#include <stdint.h>
#include <arduino.h>
#include "OSConstants.h"
#include "voice.h"
#include "SoftwareSerial.h"

namespace Modules
{
    Voice::Voice()
    {
    }

    Voice::~Voice()
    {
    }

    bool Voice::init()
    {
        mySoftwareSerial = new SoftwareSerial(V_RX, V_TX);
        mySoftwareSerial->begin(9600);

        player = new DFRobotDFPlayerMini();

        // Use softwareSerial to communicate with mp3.
        if (!player->begin(*mySoftwareSerial))
        {
            Serial.println("Voice init failed");
        }
        else
        {
            //Set serial communication time out 500ms
            player->setTimeOut(500);
            player->volume(V_VOLUME);
            player->EQ(V_EQ);
            player->outputDevice(DFPLAYER_DEVICE_SD);

            initialized = true;
        }

        return initialized;
    }

    void Voice::test()
    {
        if (!initialized)
            Serial.println("Failed initializing Voice");
        else
        {
            player->playLargeFolder(V_TEST(0), V_TEST(1)); // Play the test sound
        }
    }
} // namespace Modules

struct sound
{
    int8_t folder;
    int8_t file;
};
