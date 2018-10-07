#include <Servo.h>
#define POT A0

Servo servo;
int ang_pot;
float ang;

void setup(){
    Serial.begin(9600);
    servo.attach(9);
}

void loop(){
    ang_pot = analogRead(POT); //Lê o valor do potenciometro
    ang = map(ang_pot,0,1023,0,180); //Converte o valor da porta analogica num angulo
    servo.write(ang); //Envia o angulo para o servo
}