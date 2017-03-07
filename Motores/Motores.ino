#include <Servo.h>

#define SERVO1_PWM 10
#define SERVO2_PWM 9

Servo servo_1;
Servo servo_2;

void setup() {
  Serial.begin(9600);
  Serial.println("Simple Motor Shield sketch");
  servo_1.attach(SERVO1_PWM);
  servo_2.attach(SERVO2_PWM);
}

void loop() {
  servo_1.write(130);  
  delay(1000);
  servo_2.write(0);
  delay(1000);

  servo_2.write(65);
  delay(1000);
  servo_1.write(50);
  delay(1000);
}
