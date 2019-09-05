
/* Test de los leds del chasis del Robot 
 
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

int led_azul      = A0;             
int led_verde     = 13;
int led_amarillo  = 3;
int led_rojo      = A5;

int t_on  = 300;  // Tiempo que permanece Encendido el LED

int t_off = 80;  // Tiempo que permanece Apagado el LED


void setup() {
  
  pinMode(led_azul,OUTPUT);    //Declaramos a LED como SALIDA
  pinMode(led_verde,OUTPUT);    //Declaramos a LED como SALIDA
  pinMode(led_amarillo,OUTPUT);    //Declaramos a LED como SALIDA
  pinMode(led_rojo,OUTPUT);    //Declaramos a LED como SALIDA

/* Aseguramos que todos comienzan apagados */
  digitalWrite(led_azul,LOW);
  digitalWrite(led_verde,LOW);
  digitalWrite(led_amarillo,LOW);
  digitalWrite(led_rojo,LOW);

}

void loop() {

 digitalWrite(led_azul,HIGH);    // Le indicamos a LED que se ENCIENDA
 
 delay(t_on);                    // LED permanece ENCENDIDO durante X segundos
 
 digitalWrite(led_azul,LOW);     // Le indicamos a LED que se APAGUE
 
 delay(t_off);                   // LED permanece APAGADO durante X segundos

 digitalWrite(led_verde,HIGH);    
  delay(t_on);               
 digitalWrite(led_verde,LOW);     
  delay(t_off);               

 digitalWrite(led_amarillo,HIGH);    
  delay(t_on);               
 digitalWrite(led_amarillo,LOW);     
  delay(t_off);               

 digitalWrite(led_rojo,HIGH);    
  delay(t_on);               
 digitalWrite(led_rojo,LOW);     
  delay(t_off);               

}
