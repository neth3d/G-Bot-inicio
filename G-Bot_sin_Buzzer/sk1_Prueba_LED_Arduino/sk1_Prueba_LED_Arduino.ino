
/*Este primer programa verifica que la placa Arduino funciona correctamente
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

int led = 13;             //Este es el LED interno de la placa Arduino Nano

void setup() {
  
  pinMode(led,OUTPUT);    //Declaramos a LED como SALIDA

}

void loop() {

 digitalWrite(led,HIGH);    // Le indicamos a LED que se ENCIENDA
 
 delay(1500);               // LED permanece ENCENDIDO durante 1.5 segundos
 
 digitalWrite(led,LOW);     // Le indicamos a LED que se APAGUE
 
 delay(1000);               // LED permanece APAGADO durante 1 segundo

}
