#include <MatrixServoExtension.h>

MatrixServo Servo;
int channel, angle;
void setup()
{
    Serial.begin(115200);
    Serial.print("Starting...\n");
    if (Servo.begin())
    {
        Serial.println("Servo Extension Activated");
    }
    else
    {
        Serial.println("Servo Extension activation failed");
    }
}

void loop()
{
    Serial.println("===============================================================");

    channel = 1;
    angle = 180;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(500);

    Servo.ChannelRelease(channel);
    Serial.println("channel " + (String)channel + " release");
    delay(500);
}