#include <MatrixServoExtension.h>

MatrixServo Servo;

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
    
    Serial.print("Voltage=");
    Serial.println(Servo.getVbat());

    delay(250);
}