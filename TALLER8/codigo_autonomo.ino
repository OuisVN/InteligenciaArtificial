#include <Servo.h>

Servo SERVO1;
int VELOCIDAD_MAX = 250;
int VELOCIDAD_MIN = 200;

int IZQ_A 		= 8;               
int IZQ_B 		= 9;               
int DER_A 		= 4;               
int DER_B 		= 5;
int ENB 		= 3; 
int ENA 		= 10;
int VELOCIDAD 	= 150;                       
int BUZZER 		= 2;              
int LEDS 		= 6;
int ESTADO 		= 'c';                 

int ANGULO_DERECHO 		= 15;
int ANGULO_CENTRO 		= 90;
int ANGULO_IZQUIERDO 	= 165;

int PECHO 		= 11;
int PTRIG 		= 12;
int duracion, distancia, DisDer, DisIzq, DisEcoDer, DisEcoIzq, DisFrenteEco;


void setup(){ 
	Serial.begin(9600);  
	SERVO1.attach(13);     
	pinMode(DER_A, OUTPUT);
	pinMode(DER_B, OUTPUT);
	pinMode(IZQ_A, OUTPUT);
	pinMode(IZQ_B, OUTPUT);
	pinMode(BUZZER, OUTPUT);
	pinMode(LEDS, OUTPUT);
	pinMode(PECHO, INPUT);
	pinMode(PTRIG,OUTPUT);
} 

void loop(){
	if(Serial.available()>0){
		ESTADO = Recibir_Datos();
	}
	Serial.println(ESTADO);
	
	switch(ESTADO){
		case 'r':
			VELOCIDAD = VELOCIDAD_MAX;
			break;
		case 'l':
			VELOCIDAD = VELOCIDAD_MIN;
			break;
		case 'p':
			digitalWrite(BUZZER,HIGH);
			break;
		case 'z':
			digitalWrite(BUZZER,LOW);
			break;
		case 'q':
			digitalWrite(LEDS,HIGH);
			break;
		case 'w':
			digitalWrite(LEDS,LOW);
			break;
		case 'a':
			Avanzar();
			break;
		case 'b':
			Parar_Izq();
			break;
		case 'c':
			Parar();
			break;
		case 'd':
			Parar_Der();
			break;
		case 'e':
			Retroceder_Der();
			Retroceder_Izq();
			break;
		case 'f':
			sensorProximidad();
			break;
		default:
			break;
	}
}

int Recibir_Datos(){
	return Serial.read();
}

void Avanzar(){
	digitalWrite(DER_A, LOW);
	digitalWrite(DER_B, HIGH);
	analogWrite(ENB, 150);
	digitalWrite(IZQ_A, HIGH);
	digitalWrite(IZQ_B, LOW);
	analogWrite(ENA, 150);
}

void Parar(){
	analogWrite(ENB, 0);
	analogWrite(ENA, 0);
}

void Retroceder_Der(){
	digitalWrite(DER_A, HIGH);
	digitalWrite(DER_B, LOW);
	analogWrite(ENB, 150);
	digitalWrite(IZQ_A, HIGH);
	digitalWrite(IZQ_B, LOW);
	analogWrite(ENA, 150);
}

void Retroceder_Izq(){
	analogWrite(IZQ_A, 0);
	analogWrite(IZQ_B, VELOCIDAD);
}

void Parar_Der(){
	digitalWrite(DER_A, LOW);
	digitalWrite(DER_B, HIGH);
	analogWrite(ENB, 150);
	analogWrite(ENA, 0);
}

void Parar_Izq(){
	SERVO1.write(ANGULO_DERECHO);
	digitalWrite(DER_A, LOW);
	digitalWrite(DER_B, HIGH);
	analogWrite(ENB, 0);
	digitalWrite(IZQ_A, HIGH);
	digitalWrite(IZQ_B, LOW);
	analogWrite(ENA, 150);
}

void sensorProximidad(){
	digitalWrite(PTRIG, HIGH);
	delay(0.01);
	digitalWrite(PTRIG, LOW);

	duracion = pulseIn(PECHO, HIGH);
	distancia = (duracion / 2) / 29;
	delay(10);
	
	if(distancia <= 15 && distancia >= 2){
		digitalWrite(LEDS, HIGH);
		SERVO1.write(ANGULO_DERECHO);
		analogWrite(DER_B, 0);
		analogWrite(IZQ_B, 0);
		analogWrite(DER_A, 0);
		analogWrite(IZQ_A, 0);
		delay(700);
		digitalWrite(PTRIG, HIGH);
		delay(0.01);
		digitalWrite(PTRIG, LOW);

		duracion = pulseIn(PECHO, HIGH);
		DisEcoDer = (duracion / 2) / 29;
		delay(10);
		DisDer = DisEcoDer;
		delay(500);

		SERVO1.write(ANGULO_IZQUIERDO);
		analogWrite(DER_B, 0);
		analogWrite(IZQ_B, 0);
		analogWrite(DER_A, 0);
		analogWrite(IZQ_A, 0);
		delay(700);
		digitalWrite(PTRIG, HIGH);
		delay(0.01);
		digitalWrite(PTRIG, LOW);

		duracion = pulseIn(PECHO, HIGH);
		DisEcoIzq = (duracion / 2) / 29;
		delay(10);
		DisIzq = DisEcoIzq;
		delay(500);

		if(DisDer > DisIzq){
			SERVO1.write(ANGULO_CENTRO);
			delay(400);
			analogWrite(DER_A, LOW);
			analogWrite(IZQ_A, LOW);
			analogWrite(DER_B, HIGH);
			analogWrite(IZQ_B, HIGH);
			delay(300);
			analogWrite(DER_B, LOW);
			analogWrite(IZQ_B, HIGH);
			analogWrite(IZQ_A, LOW);
			analogWrite(DER_A, HIGH);
			delay(500);
			analogWrite(DER_B, 0);
			analogWrite(IZQ_B, 0);
			analogWrite(DER_A, 0);
			analogWrite(IZQ_A, 0);
			delay(200);
		}

		if(DisDer < DisIzq){
			SERVO1.write(ANGULO_CENTRO);
			delay(400);
			analogWrite(DER_A, LOW);
			analogWrite(IZQ_A, LOW);
			analogWrite(DER_B, HIGH);
			analogWrite(IZQ_B, HIGH);
			delay(300);
			analogWrite(DER_B, HIGH);
			analogWrite(IZQ_B, LOW);
			analogWrite(DER_A, LOW);
			analogWrite(IZQ_A, HIGH);
			delay(500);
			analogWrite(DER_B, 0);
			analogWrite(IZQ_B, 0);
			analogWrite(DER_A, 0);
			analogWrite(IZQ_A, 0);
			delay(200);
		}
	}else{
		digitalWrite(LEDS, LOW);
		analogWrite(DER_B, LOW);
		analogWrite(IZQ_B, LOW);
		analogWrite(DER_A, HIGH);
		analogWrite(IZQ_A, HIGH);
	}
}