/* Sensores IR con Motores 
 
 Fecha de Prueba 21/08/2019. Copyleft NeTH3D 

 *** Esquema de conexiones  ***
----------------------------------------
 * Sensor Ultrasonido *
    Echo    ----> Pin 7
    Trigger ----> Pin 8
---------------------------------------- 
 Sensor IR izquierdo ----> Pin 2
 Sensor IR derecho   ----> Pin 18 (A4)
----------------------------------------
 
 Led rojo         ----> Pin 19 (A5)
 Led verde        ----> Pin 13
 Led amarillo     ----> Pin 3
 Led blanco/azul  ----> Pin 14 (A0)
----------------------------------------
*   Driver Motores  *
 
    AIB ----> Pin 5
    AIA ----> Pin 6   
    BIB ----> Pin 9  
    BIA ----> Pin 10 
----------------------------------------*/

int ir_der=18;
int ir_izq=2;

const int AIA = 6;  
const int AIB = 5;  
const int BIA = 10; 
const int BIB = 9;  


byte velocidad = 180;  

int led_blanco =  A0;
int led_verde =   13;
int led_amarillo = 3;
int led_rojo =    A5;


void setup() {
 
  pinMode(ir_der,INPUT);
  pinMode(ir_izq,INPUT);


  pinMode(AIA, OUTPUT);           // fijar los pines como salidas
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  pinMode(led_blanco, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);

  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);  
  
  parpadeo_inicial();
  
  delay(2000);

}

void loop() {

if(digitalRead(ir_der)==HIGH && digitalRead(ir_izq)==HIGH){  // si lee blanco avanza
  avanzar();
}else{                     
  izquierda();
}

  

}


void avanzar()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocidad);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidad);
}
 
void retroceder()
{
  analogWrite(AIA, velocidad);
  analogWrite(AIB, 0);
  analogWrite(BIA, velocidad);
  analogWrite(BIB, 0);
}
 
void derecha()
{
  analogWrite(AIA, velocidad);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidad);
}
 
void izquierda()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocidad);
  analogWrite(BIA, velocidad);
  analogWrite(BIB, 0);
}



/* Funcion para el juego de luces iniciales */
void parpadeo_inicial() {
  digitalWrite(led_amarillo, HIGH);
  delay(250);
  digitalWrite(led_rojo, HIGH);
  delay(250);
  digitalWrite(led_blanco, HIGH);
  delay(250);
  digitalWrite(led_verde, HIGH);
  delay(250);

  digitalWrite(led_amarillo, LOW);
  digitalWrite(led_rojo, LOW);
  digitalWrite(led_blanco, LOW);
  digitalWrite(led_verde, LOW);
  delay(100);

  for (int i = 0; i < 6; i++) {
    digitalWrite(led_amarillo, HIGH);
    delay(80);
    digitalWrite(led_amarillo, LOW);
    delay(80);
    digitalWrite(led_rojo, HIGH);
    delay(80);
    digitalWrite(led_rojo, LOW);
    delay(80);
    digitalWrite(led_blanco, HIGH);
    delay(80);
    digitalWrite(led_blanco, LOW);
    delay(80);
    digitalWrite(led_verde, HIGH);
    delay(100);
    digitalWrite(led_verde, LOW);
    delay(80);
  }

  digitalWrite(led_amarillo, HIGH);
  digitalWrite(led_rojo, HIGH);
  digitalWrite(led_blanco, HIGH);
  digitalWrite(led_verde, HIGH);
  delay(500);
  digitalWrite(led_amarillo, LOW);
  digitalWrite(led_rojo, LOW);
  digitalWrite(led_blanco, LOW);
  digitalWrite(led_verde, LOW);
  delay(100);

}

