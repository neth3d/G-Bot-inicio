/*

  Una vez subido el código a nuestro arduino nano, debemos entrar en el modo de configuración del módulo Bluetooth.
  Veremos como en el módulo Bluetooth parpadea continuamente un led rojo. Ahora deberemos desconectar el cable VCC del modulo bluetooth y
  respetar el siguiente procedimiento:
  mantener apretado el boton ubicado en el modulo bluetooth y mientras lo mantenemos conectar nuevamente el VCC. Veremos como el led rojo ahora parpadea mas pausado.
  Esto nos indica que estamos en modo de configuración y en condiciones de utilizar los comandos.
  
  
  Sin desconectar el cable usb de programación, desde el IDE Arduino, podemos entrar desde el menú Herramientas al Monitor Serie
  o con el atajo ctrl+shift+M para utilizar los comandos
  Una vez se nos abra la ventana del Monitor Serie, se debe configurar la terminal con los siguientes parámetros:
  
  -tildar autoscroll 
  -ambos NL & CR
  -9600

  Lista de Comandos:

Para preguntar

AT+NAME?  //indica nombre del dispositivo
AT+PSWD?  //indica Contraseña del dispositivo 
AT+UART?  //indica parametro de comunicacion del dispositivo
AT+ROLE?  //indica rol del dispositivo ( Maestro [1] o Esclavo [0] )
AT+ORGL?  //restaura a valores de fabrica
AT+RESET? //Vuelve a modo usuario

Para Cambiar

AT+NAME=    
AT+PSWD= " "
AT+UART=
AT+ROLE=
*/


#include <SoftwareSerial.h>  // libreria que permite establecer pines digitales
        // para comunicacion serie

SoftwareSerial miBT(12, 11);  // pin 12 como RX, pin 11 como TX

void setup(){
  Serial.begin(9600);   // comunicacion de monitor serial a 9600 bps
  Serial.println("Listo");  // escribe Listo en el monitor
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps
}

void loop(){
if (miBT.available())       // si hay informacion disponible desde modulo
   Serial.write(miBT.read());   // lee Bluetooth y envia a monitor serial de Arduino

if (Serial.available())     // si hay informacion disponible desde el monitor serial
   miBT.write(Serial.read());   // lee monitor serial y envia a Bluetooth
}
