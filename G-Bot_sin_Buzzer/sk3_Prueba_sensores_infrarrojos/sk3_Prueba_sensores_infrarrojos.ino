
/* Test de sensores Infrarrojos 
 
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

int ir_der = 18;                         
int ir_izq = 2;
  
int led_azul      = A0;             
int led_verde     = 13;
int led_amarillo  = 3; 
int led_rojo      = A5;

void setup() {
  pinMode(ir_der,INPUT);              // Declaramos a los sensores infrarrojo como ENTRADA
  pinMode(ir_izq,INPUT);
 
  pinMode(led_azul, OUTPUT);           //Declaramos los leds como SALIDA
  pinMode(led_verde,OUTPUT);          
  pinMode(led_amarillo,OUTPUT);       
  pinMode(led_rojo,OUTPUT);           
}

void loop() {

if(digitalRead(ir_der)==LOW && digitalRead(ir_izq)==LOW) // LOW = Negro
 { 
  digitalWrite(led_azul,HIGH);
  digitalWrite(led_verde,HIGH);
    digitalWrite(led_amarillo,LOW);
    digitalWrite(led_rojo,LOW);
}else{
  digitalWrite(led_amarillo,HIGH);
  digitalWrite(led_rojo,HIGH);
    digitalWrite(led_azul,LOW);
    digitalWrite(led_verde,LOW);
}

 
}
