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
int pinLed=8;
int pinTimon = A0;
int pinAcelerador = A1;
boolean posicionIz = false;
boolean posicionPalanca = false;
boolean reversaPalanca = false;
boolean implementoPalanca = false;
boolean stateOn,stateStart;
int posicionTimon;

void setup() {
  pinMode(pinEncendido,INPUT);
  pinMode(pinArranque,INPUT);
  pinMode(pinImplementoUp,INPUT);
  pinMode(pinImplementoDown,INPUT);
  pinMode(pinAdelante,INPUT);
  pinMode(pinReversa,INPUT);
  pinMode(pinTimon,INPUT);
  pinMode(pinAcelerador,INPUT);
  pinMode(pinLed,OUTPUT);
  leftServo.attach(SERVO1_PWM);
  rightServo.attach(SERVO2_PWM);
  Serial.begin(9600);
}

void loop() {
  
  while(digitalRead(pinEncendido)==LOW && digitalRead(pinArranque)==LOW){
    Serial.write(0);
    leftServo.write(120);
    rightServo.write(70);
    digitalWrite(pinLed,LOW);
    delay(200);
  }
  
  while(digitalRead(pinEncendido)==HIGH && digitalRead(pinArranque)==LOW){
    stateOn=true;
    Serial.write(1);  
    digitalWrite(pinLed,HIGH);
    delay(200);
  }
  
  while(digitalRead(pinEncendido)==LOW && digitalRead(pinArranque)==HIGH){
    stateStart=true;
    posicionTimon = analogRead(pinTimon);
    int palancaAdelante = digitalRead(pinAdelante);
    int palancaReversa = digitalRead(pinReversa);
    int posicionImplementoUp = digitalRead(pinImplementoUp);
    int posicionImplementoDown = digitalRead(pinImplementoDown);
    int aceleracion = analogRead(pinAcelerador);
    digitalWrite(pinLed,HIGH);
    if(posicionTimon>=340 && posicionTimon<520 && palancaAdelante == LOW && palancaReversa == LOW){
      Serial.write(2);
      
    }
    if(palancaAdelante == HIGH && palancaReversa == LOW){
      if(aceleracion < 512){
        Serial.write(8);
      }
      if(aceleracion >= 512){
        if(posicionTimon>335 && posicionTimon<530){
          //tractor sin giro
          Serial.write(5);
          leftServo.write(120);
          rightServo.write(30);
        }
        if(posicionTimon>0 && posicionTimon<=334){
          //girar a la derecha
          Serial.write(4);
          leftServo.write(40);
          rightServo.write(10);
        }
        if(posicionTimon>=530 && posicionTimon<1023){
          //girar a la izquierda
          Serial.write(3);
          leftServo.write(150);
          rightServo.write(30);
        }
      }
    }
    
    if(palancaAdelante == LOW && palancaReversa == HIGH){
      if(aceleracion > 512){
        Serial.write(6);
      }
      if(aceleracion <= 512){
        //if(posicionTimon>=340 && posicionTimon<520){
          Serial.write(9);
        //}
        /*if(posicionTimon>0 && posicionTimon<=335){
          Serial.write(3);
        }
        if(posicionTimon>=530 && posicionTimon<1023){
          Serial.write(4);
        }*/
      }
    }
    if(posicionImplementoUp == HIGH && posicionImplementoDown == LOW){
      Serial.write(10);
    }

    if(posicionImplementoDown == HIGH && posicionImplementoUp == LOW){
      Serial.write(7);
    }
    delay(100);
    leftServo.write(130);
    rightServo.write(0);
    delay(100);
  }
}
