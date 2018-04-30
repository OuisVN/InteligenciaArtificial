#include <LiquidCrystal.h> // --> Librería para el Display.

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // --> Display. Utiliza los pines 7, 6, 5, 4, 3, 2.

int LEDVERDE1 = 8; // --> LEDVERDE en el pin 8.
int LEDROJO1 = 9; // --> LEDROJO en el pin 9.
int ECHO = 10; // --> ECHO en el pin 10. (Hace parte del sensor de proximidad).
int TRING = 11; // --> TRING en el pin 11. (Hace parte del sensor de proximidad).
int PULSADOR1 = 12; // --> SWITCH o PULSADOR en el pin 12.

void setup(){
  Serial.begin(9600); // --> Es para la comunicación con el computador. Abre el puerto serie y lo configura con velocidad de 9600 bps.
  lcd.begin(16, 2); // --> Display 16x2.
  lcd.setCursor(0, 1); // --> Posición en X y Y.

  // Modo entrada/salida de los pines.
  pinMode(LEDVERDE1, OUTPUT); // --> Salida.
  pinMode(LEDROJO1, OUTPUT); // --> Salida.
  pinMode(TRING, OUTPUT); // --> Salida.
  pinMode(ECHO, INPUT); // --> Entrada.
  pinMode(PULSADOR1, INPUT); // --> Entrada.
}

void loop(){
  int opcion = 0; // --> Variable tipo booleana. 0-1
  int valor = digitalRead(PULSADOR1); // Guardamos lo que lea del pulsador.
  
  digitalWrite(TRING ,LOW); // --> Para estabilidad del sensor de proximidad.
  delayMicroseconds(10); // --> Retrasamos 10 microsegundos el sensor.
  digitalWrite(TRING, HIGH); // --> Le damos el chispazo de arranque.
  delayMicroseconds(10); // --> Retrasamos 10 microsegundos el sensor.
  
  long tiempo = pulseIn(ECHO, HIGH); // --> Teniendo en cuenta lo anterior, se calculará el tiempo respecto al inicio y finalización del chispazo para poder usarlo en la formula siguiente.
  long distancia= (0.017*tiempo); // --> Calculamos la distancia en centimetros.

  // Si distancia es igual a 10 CM... Y Si no...
  if(opcion == 0 && distancia == 10){
    digitalWrite(LEDVERDE1, HIGH); // --> LEDVERDE encendido.
    digitalWrite(LEDROJO1, LOW); // --> LEDROJO apagado.
    lcd.setCursor(0,0); // --> Posición X y Y.
    lcd.print("Bienvenido"); // --> Mostramos en el display el mensaje de Bienvenido en la posición 0X y 0Y.
    lcd.setCursor(0,1); // --> Posición X y Y.
    lcd.print("COSTO: 10.000"); // Mostramos en el display el mensaje de COSTO: 10.000 en la posición 0X y 1Y.
  }else{
    digitalWrite(LEDVERDE1, LOW); // --> LEDVERDE apagado.
    digitalWrite(LEDROJO1, HIGH); // --> LEDROJO encendido.
  }

  // Si el pulsador esta presionado cambiará el valor de la variable opcion de 0 a 1.
  if (valor == HIGH){
    opcion = 1;
  }

  // Si opcion es igual a 1, eso quiere decir que el carro ya pago y puede irse.
  if(opcion == 1){
    lcd.clear(); // --> Borramos lo que haya en el display.
    lcd.setCursor(0,0); // --> Posición X y Y.
    lcd.print("Hasta Luego"); // --> Mostramos en el display el mensaje de Hasta Luego en la posición 0X y 0Y.
  }

  // Si opcion es igual a 1 y la distancia es igual a 20, eso quiere decir que el carro ya se ha ido y puede continuar con otra persona.
  if(opcion == 1 && distancia == 20){
    lcd.clear(); // --> Borramos lo que haya en el display.
    opcion = 0;
  }
  
  delay(500); // --> Retrasamos los mensajes 500 milisegundos.
}
