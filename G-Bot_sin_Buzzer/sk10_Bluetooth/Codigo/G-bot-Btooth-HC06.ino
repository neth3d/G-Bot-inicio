#include <SoftwareSerial.h>  // libreria que permite establecer pines digitales
        // para comunicacion serie

SoftwareSerial GbotBT(12, 11);  // pin 11 como RX, pin 12 como TX
char dato = 0;
const int AIA = 6;
const int AIB = 5;
const int BIA = 10;
const int BIB = 9;
byte velocidad = 180;

void setup(){
  
  GbotBT.begin(9600);    // comunicacion serie entre Arduino y el modulo a 38400 bps para el modulo HC 05 y 9600 para el HC 06
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  /* Garantizamos que el robot comienza detenido */
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

}



void loop(){
if (GbotBT.available())       // si hay informacion disponible desde modulo
   dato=GbotBT.read();        //Lo guardamos en la variable dato
                              
   if(dato=='1')              //Si el dato es 1 avanza
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 235);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidad);
  
}

if(dato=='2')                  //Si el dato es 2 gira hacia la izquierda
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocidad);
  analogWrite(BIA, velocidad);
  analogWrite(BIB, 0);
}
if(dato=='3')                  //Si el dato es 3 gira hacia la derecha
{
  analogWrite(AIA, velocidad);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidad);
}
if(dato=='4')                 //si el dato es 4 va hacia atras
{
  analogWrite(AIA, velocidad);
  analogWrite(AIB, 0);
  analogWrite(BIA, velocidad);
  analogWrite(BIB, 0);
}
if(dato=='5')                 //si el dato es 5 se detiene
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}
if(dato=='6')                 //funcion de ejemplo extra: si el dato es 6 avanza x tiempo y establecemos el dato a 5 (si dato=5 se detiene)
{
  analogWrite(AIA, 0);
  analogWrite(AIB, velocidad);
  analogWrite(BIA, 0);
  analogWrite(BIB, velocidad);
  delay(500);
  dato='5';
  
}

/* 
   Te invitamos a seguir desarrollando!  :)
   
   if(dato==' ?????? ')                 
{
  ??? 
  ???
  ???
  
 }
 
*/


}
