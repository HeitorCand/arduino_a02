#include <ESP32Servo.h>

#define vermelho 27
#define amarelo 26
#define verde 25
#define servo 18

Servo myservo;
int pos = 0; 

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  myservo.setPeriodHertz(50);
  myservo.attach(servo, 500, 2400); 
}

void loop() {
  // Luz amarela piscando
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, HIGH);
  digitalWrite(verde, LOW);
  delay(2000);

  // Luz vermelha acesa, cancela abaixando
  digitalWrite(amarelo, LOW);
  digitalWrite(vermelho, HIGH);
  delay(1000); // Pequena pausa antes de abaixar a cancela

  for (pos = 90; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }

  delay(6000); // Tempo com a cancela abaixada e luz vermelha acesa

  // Luz verde acesa, cancela subindo
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, HIGH);

  for (pos = 0; pos <= 90; pos += 1) { 
    myservo.write(pos);
    delay(15);
  }

  delay(4000); // Tempo com a luz verde acesa para passagem (2 + 2)
}
