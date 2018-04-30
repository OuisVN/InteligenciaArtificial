#include <LiquidCrystal.h> // --> Librería para el Display.

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // --> Display. Utiliza los pines 7, 6, 5, 4, 3, 2.

// Semáforo número 1.
#define LEDROJO1 8
#define LEDAMARILLO1 9
#define LEDVERDE1 10

// Semáforo número 2.
#define LEDROJO2 11
#define LEDAMARILLO2 12
#define LEDVERDE2 13

// Pulsadores.
#define PULSADOR1 7
#define PULSADOR2 6

// Variables Globales
bool activo1 = true; // --> Indica si el semáforo 1 esta activo.
int tiempoCambio = 1500; // --> Tiempo de cambio LED a LED.
int tiempoEspera = 1500; // --> Tiempo de espera hasta hacer el cambio.

void setup(){
  Serial.begin(9600); // --> Es para la comunicación con el computador. Abre el puerto serie y lo configura con velocidad de 9600 bps.
  lcd.begin(16, 2); // --> Display 16x2.
  lcd.setCursor(0, 0); // --> Posición en X y Y.
  lcd.print("SEMAFORO"); // --> Imprime en el display en la posición 0X y 0Y la palabra SEMAFORO.
  
  // Modo entrada/salida de los pines.
  pinMode(LEDVERDE1, OUTPUT); // --> Salida.
  pinMode(LEDAMARILLO1, OUTPUT); // --> Salida.
  pinMode(LEDROJO1, OUTPUT); // --> Salida.
  pinMode(LEDVERDE2, OUTPUT); // --> Salida.
  pinMode(LEDAMARILLO2, OUTPUT); // --> Salida.
  pinMode(LEDROJO2, OUTPUT); // --> Salida.
  pinMode(PULSADOR1, INPUT); // --> Salida.
  pinMode(PULSADOR2, INPUT); // --> Salida.
  
  // Apagamos todos los LEDS
  digitalWrite(LEDROJO1, LOW);
  digitalWrite(LEDAMARILLO1, LOW);
  digitalWrite(LEDVERDE1, LOW);  
  digitalWrite(LEDROJO2, LOW);
  digitalWrite(LEDAMARILLO2, LOW);
  digitalWrite(LEDVERDE2, LOW);
  
  // Semáforo 1, en verde - Semáforo 2, en rojo.
  digitalWrite(LEDVERDE1, HIGH);
  digitalWrite(LEDROJO2, HIGH);
}

void loop(){
  if (activo1){
    // Está encendido el semáforo 1, comprobamos el pulsador 2.
    int valor2 = digitalRead(PULSADOR2);
    // Si pulsador esta pulsado (HIGH) pondrá en verde semáforo 2.
    if (valor2 == HIGH){
      encenderSemaforo2();
      activo1 = false;
    }
  }
  else
  {
    // Está encendido el semáforo 2, comprobamos el pulsador 1.
    int valor1 = digitalRead(PULSADOR1);
    // Si pulsador esta pulsado (HIGH) pondrá en verde semáforo 1.
    if (valor1 == HIGH){
      encenderSemaforo1();
      activo1 = true;
    }
  }
}

void encenderSemaforo2(){
  delay(tiempoEspera);
  // Primera Ronda. Apagamos verde y colocamos semáforo en amarillo.
  digitalWrite(LEDVERDE1, LOW);
  digitalWrite(LEDAMARILLO1, HIGH);
  
  delay(tiempoCambio);
  // Segunda Ronda. Apagamos amarillo y colocamos semáforo en rojo.
  digitalWrite(LEDAMARILLO1, LOW);
  digitalWrite(LEDROJO1, HIGH);
  
  delay(tiempoCambio);
  // Tercera Ronda. Apagamos rojo y colocamos semáforo en verde.
  digitalWrite(LEDROJO2, LOW);
  digitalWrite(LEDVERDE2, HIGH);
}

void encenderSemaforo1(){
  delay(tiempoEspera);
  // Primera Ronda. Apagamos verde y colocamos semáforo en amarillo.
  digitalWrite(LEDVERDE2, LOW);
  digitalWrite(LEDAMARILLO2, HIGH);
  
  delay(tiempoCambio);
  // Segunda Ronda. Apagamos amarillo y colocamos semáforo en rojo.
  digitalWrite(LEDAMARILLO2, LOW);
  digitalWrite(LEDROJO2, HIGH);
  
  delay(tiempoCambio);
  // Tercera Ronda. Apagamos rojo y colocamos semáforo en verde.
  digitalWrite(LEDROJO1, LOW);
  digitalWrite(LEDVERDE1, HIGH);
}
