#include <Servo.h>

#define SERVO1_PWM 10
#define SERVO2_PWM 9

Servo leftServo;
Servo rightServo;

int pinEncendido = 2;
int pinArranque = 3;
int pinImplementoUp = 4;
int pinImplementoDown = 7;
int pinAdelante = 5;
int pinReversa = 6;
int pinTimon = A0;
int pinAcelerador = A1;
boolean posicionIz = false;
boolean posicionPalanca = false;
boolean reversaPalanca = false;

void setup() {
  pinMode(pinEncendido,INPUT);
  pinMode(pinArranque,INPUT);
  pinMode(pinImplementoUp,INPUT);
  pinMode(pinImplementoDown,INPUT);
  pinMode(pinAdelante,INPUT);
  pinMode(pinReversa,INPUT);
  pinMode(pinTimon,INPUT);
  pinMode(pinAcelerador,INPUT);
  Serial.begin(9600);
  leftServo.attach(SERVO1_PWM);
  rightServo.attach(SERVO2_PWM);
}

void loop() {
    int palancaEncendido = digitalRead(pinEncendido);
    int palancaArranque = digitalRead(pinArranque);
    Serial.print(palancaEncendido);
    Serial.print(" ");
    Serial.print(palancaArranque);
    Serial.print(" ");
    int posicionTimon = analogRead(pinTimon);
    Serial.print(" ");
    int palancaAdelante = digitalRead(pinAdelante);
    int palancaReversa = digitalRead(pinReversa);
    int aceleracion = analogRead(pinAcelerador);
    int Implementoup = digitalRead(pinImplementoUp);
    int Implementodown = digitalRead(pinImplementoDown);
    Serial.print(Implementoup);
    Serial.print(" ");
    Serial.print(Implementodown);
    Serial.print(" ");
    Serial.print(palancaAdelante);
    Serial.print(" ");
    Serial.print(palancaReversa);
    Serial.print(" ");
    Serial.print(aceleracion);
    Serial.print(" ");
    Serial.println(posicionTimon);
}
