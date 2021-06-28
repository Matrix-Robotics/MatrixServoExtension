#include <MatrixServoExtension.h>

MatrixServo Servo;
int channel, angle;
void setup()
{
    Serial.begin(115200);
    Serial.print("Starting...\n");
    if (Servo.begin()){
        Serial.println("Servo Extension Activated");
    }
    else{
        Serial.println("Servo Extension activation failed");
    }
}

void loop()
{
    Serial.println("===============================================================");
    
    channel = 1;
    angle = 0;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(250);

    channel = 2;
    angle = 60;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(250);

    channel = 3;
    angle = 120;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(250);

    channel = 4;
    angle = 180;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(250);

    channel = 5;
    angle = 0;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(250);

    channel = 6;
    angle = 60;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(250);

    channel = 7;
    angle = 120;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(250);

    channel = 8;
    angle = 180;
    Servo.setAngle(channel, angle);
    Serial.println("set channel " + (String)channel + " to " + (String)angle);
    delay(250);
}