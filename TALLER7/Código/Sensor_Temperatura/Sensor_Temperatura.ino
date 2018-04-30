#include <LiquidCrystal.h> // --> Librería para el Display.

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // --> Display. Utiliza los pines 7, 6, 5, 4, 3, 2.

const int Entrada = A0; // --> Entrada Analógica A0.
int LEDVERDE1 = 8; // --> LEDVERDE en el pin 8.
int LEDROJO1 = 9; // --> LEDROJO en el pin 9.

void setup(){
  Serial.begin(9600); // --> Es para la comunicación con el computador. Abre el puerto serie y lo configura con velocidad de 9600 bps.
  lcd.begin(16, 2); // --> Display 16x2.
  lcd.setCursor(0, 1); // --> Posición en X y Y.
  lcd.print("Temperatura"); // --> Imprime en el display en la posición 0X y 0Y la palabra Temperatura.

  // Modo entrada/salida de los pines.
  pinMode(LEDVERDE1, OUTPUT);
  pinMode(LEDROJO1, OUTPUT);
}

void loop(){
  int x = analogRead(Entrada); // --> Leyendo lo que llega a la entrada analógica A0.
  float formula = (x * 500.0)/1023; // -> Formula que calcula los grados centigrados.
  lcd.setCursor(0,0); // --> Posición X y Y.
  lcd.print(formula); // --> Imprime en el display en la posición 0X y 0Y lo que contiene la variable formula, en este caso. los grados centigrados.
  lcd.setCursor(6,0); // --> Posición X y Y.
  lcd.print("Grados"); // --> Imprime en el display en la posición 6X y 0Y la palabra Grados.
  lcd.setCursor(0,1); // --> Posición X y Y.

  // Si formula es mayor o igual a 30 grados centigrados... Y Si no...
  if(formula >= 30){
    digitalWrite(LEDROJO1,LOW); // --> Primero, apagará el Led rojo.
    digitalWrite(LEDVERDE1,HIGH); // --> Segundo, encenderá el Led verde.
    lcd.setCursor(12,1); // --> Posición X y Y.
    lcd.print("Alta"); // --> Imprime en el display en la posición 12X y 1Y la palabra Alta.
  }else{
    digitalWrite(LEDVERDE1,LOW); // --> Primero, apagará el Led verde.
    digitalWrite(LEDROJO1,HIGH); // --> Segundo, encenderá el Led rojo.
    lcd.setCursor(12,1); // --> Posición X y Y.
    lcd.print("Baja"); // --> Imprime en el display en la posición 12X y 1Y la palabra Baja.
  }
  delay(300); // --> Tiempo de espera por cada condición. 300 milisegundos.
}
