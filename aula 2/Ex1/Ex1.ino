#define LED 10   //Pino do led
#define BUTTON A0 // Pino do Botão
#define BUTTON_ANALOG A0
#define DIF_MILLIS 500  //Delay do "pisca pisca"

bool estado_led;  //Guarda o valor de output para o led
bool estado_piscapisca; //Guarda o valor de permissão para ativar o "pisca pisca"
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
  
  Serial.begin(9600);
}

 
void loop() {
  millis_atual = millis(); //guarda o millis atual
  Serial.println(analogRead(BUTTON)); //Envia pela porta serie a leitura do pino analogico
  
  //Verifica se carregaram no botão para alterar os estado de "pisca pisca"
  if(digitalRead(BUTTON)){
      estado_piscapisca = !estado_piscapisca;  
      delay(250); //dá um delay para o utilizador tirar o dedo do botão
  }

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
