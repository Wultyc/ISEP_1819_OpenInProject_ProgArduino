#define LED 10 
#define BUTTON 4
#define ANALOG A0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valor = analogRead(ANALOG);

  Serial.println(valor);

}
