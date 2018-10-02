#define LED 4
#define BUTTON 5

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}


void loop() {

 bool valor;
 

  valor = digitalRead (BUTTON);

  if(valor){
    digitalWrite(LED, HIGH);      
  }else { 
    digitalWrite(LED, LOW); 
  }                         
}
