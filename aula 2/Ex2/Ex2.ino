#define LED 10   //Pino do led
#define BUTTON 3 // Pino do Botão
#define BUTTON_ANALOG A0
#define DIF_MILLIS 500  //Delay do "pisca pisca"

bool estado_led;  //Guarda o valor de output para o led
volatile bool estado_piscapisca; //Guarda o valor de permissão para ativar o "pisca pisca"
int valor_analog_botao;
long millis_atual;  //millis lido no momento atual
long millis_inicioCiclo;  //millis lido no inicio de um ciclo de "pisca pisca"

void setup() {
  //Define os pinModes
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

  //Estado inicial do led e "pisca pisca"
  estado_led = false;
  estado_piscapisca = false;
  valor_analog_botao = 0;
  millis_atual = 0;
  millis_inicioCiclo = 0;

  //Define params de comunicação serie
  Serial.begin(9600);

  //Interrupção
  attachInterrupt(digitalPinToInterrupt(BUTTON), mudaEstado, FALLING);
}

 
void loop() {
  millis_atual = millis(); //guarda o millis atual
  valor_analog_botao = analogRead(BUTTON_ANALOG);
  Serial.println(valor_analog_botao); //Envia pela porta serie a leitura do pino analogico
  
  if(estado_piscapisca == true ){ //"pisca pisca" ativado
    
    if((millis_atual - millis_inicioCiclo) > DIF_MILLIS){ //Se o millis atual for maior que o millis de inicio de ciclo troca o estado do led
      estado_led = !estado_led; //troca o estado do led
      millis_inicioCiclo = millis(); //guarda o millis de inicio de ciclo
    }
    
  } else {  //"pisca pisca" desativado
    
    estado_led = LOW; //Desliga o led
    millis_inicioCiclo = 0; //passa o millis de inicio de ciclo para não haver conflitos com ordens de mudança muito rápidas
    
  }
  
  //Escreve o valor do estado do led
  digitalWrite(LED, estado_led);
  
}

void mudaEstado(){
  estado_piscapisca = !estado_piscapisca;
}

