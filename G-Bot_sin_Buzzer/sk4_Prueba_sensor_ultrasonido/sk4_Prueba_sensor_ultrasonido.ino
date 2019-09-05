

 /* Test sensor Ultrasonido

  Fecha de Prueba 21/08/2019. Copyleft NeTH3D

 *** Esquema de conexiones  ***
  ----------------------------------------
   Sensor Ultrasonido
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
    Driver Motores

    AIB ----> Pin 5
    AIA ----> Pin 6
    BIB ----> Pin 9
    BIA ----> Pin 10
  ----------------------------------------*/

const int EchoPin = 7;
const int TriggerPin = 8;

int led_blanco =  A0;
int led_verde =   13;
int led_amarillo = 3;
int led_rojo =    A5;

void setup() {

  Serial.begin(9600); // inicia el puerto USB para mostrar datos por monitor serial

  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);


  pinMode(led_blanco, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);

  parpadeo_inicial();


  delay(2000);     // Tiempo prudente para comenzar ejecucion
}

void loop() {
  
  int cm = ping(TriggerPin, EchoPin);
  digitalWrite(led_rojo, LOW);
 
  if(cm<20){
    digitalWrite(led_rojo, HIGH);
  }
  Serial.print("Distancia: ");
  Serial.println(cm);
  delay(100);

}
  
  int ping(int TriggerPin, int EchoPin) {

  long duration, distanceCm;

  digitalWrite(TriggerPin, LOW);           //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);         //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH);     //medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
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
