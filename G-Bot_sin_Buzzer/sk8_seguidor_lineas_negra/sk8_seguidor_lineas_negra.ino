/* Seguidor de linea NEGRA

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


int ir_der = 18;
int ir_izq = 2;

int valor_ir_izq = 0;
int valor_ir_der = 0;

const int AIA = 6;
const int AIB = 5;
const int BIA = 10;
const int BIB = 9;

/* Valores para que el robot avance lo mas recto posible */
byte vel_izq = 123;
byte vel_der = 170;

byte vel_giro = 120;


int led_rojo = A5;
int led_verde = 13;
int led_amarillo = 3;
int led_blanco = A0;

void setup() {

  Serial.begin(9600);

  pinMode(ir_der, INPUT);
  pinMode(ir_izq, INPUT);

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);

  pinMode(led_rojo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_blanco, OUTPUT);

  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);

  parpadeo_inicial();


  delay(2000);
}




void loop() {

  valor_ir_izq = digitalRead(ir_izq);    // valor de la entrada que lee el infrarrojo izquierdo
  valor_ir_der = digitalRead(ir_der);  // derecho

  // 1 = blanco | 0 = negro

  if (valor_ir_izq != 1 && valor_ir_der != 1) { // Hacia delante

    avanzar();
  }

  if (valor_ir_izq == 1 && valor_ir_der == 0) { // Giro derecha
    derecha();

  }

  if (valor_ir_izq == 0 && valor_ir_der == 1) { // Giro izquierda
    izquierda();

  }

  if (valor_ir_izq != 0 && valor_ir_der != 0) { // STOP


    retroceder();


  }

}


void avanzar()
{
  /*Motor derecho*/
  analogWrite(AIA, 0);
  analogWrite(AIB, vel_der);

  /*Motor izquierdo*/
  analogWrite(BIA, 0);
  analogWrite(BIB, vel_izq);
}

void retroceder()
{
  analogWrite(AIA, vel_giro);
  analogWrite(AIB, 0);
  analogWrite(BIA, vel_giro);
  analogWrite(BIB, 0);
}

void derecha()
{
  analogWrite(AIA, vel_giro);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, vel_giro);
}

void izquierda()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, vel_giro);
  analogWrite(BIA, vel_giro);
  analogWrite(BIB, 0);
}

void pausa()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}


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

  for (int i = 0; i < 5; i++) {
    digitalWrite(led_amarillo, HIGH);
    delay(70);
    digitalWrite(led_amarillo, LOW);
    delay(70);
    digitalWrite(led_rojo, HIGH);
    delay(70);
    digitalWrite(led_rojo, LOW);
    delay(70);
    digitalWrite(led_blanco, HIGH);
    delay(80);
    digitalWrite(led_blanco, LOW);
    delay(70);
    digitalWrite(led_verde, HIGH);
    delay(70);
    digitalWrite(led_verde, LOW);
    delay(70);
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


