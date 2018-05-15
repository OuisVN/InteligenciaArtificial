int VMAX = 250;
int VMIN = 200;

int LEDS = 6;
int ESTADO = 'c';

int IZQ_A = 8;               
int IZQ_B = 9;               
int DER_A = 4;               
int DER_B = 5;

int ENB = 3; 
int ENA = 10;  

int VACTUAL = VMIN;            

void setup(){
	Serial.begin(9600);       
	pinMode(DER_A, OUTPUT);
	pinMode(DER_B, OUTPUT);
	pinMode(IZQ_A, OUTPUT);
	pinMode(IZQ_B, OUTPUT);
	pinMode(LEDS, OUTPUT);        
} 
 
void loop(){ 
  
	if(Serial.available()>0){
		ESTADO = recibirDatos();
	}
	
	Serial.println(ESTADO);
	switch(ESTADO){
		case 'r':                 
			VACTUAL = VMAX;
			break;
		case 'l':                 
			VACTUAL = VMIN;
			break;
		case 'q':                 
			digitalWrite(LEDS,HIGH);
			break;
		case 'w':                 
			digitalWrite(LEDS,LOW);
			break;
		case 'a':
			irAdelante();
			break;
		case 'b':
			pararIzq();
			break;
		case 'c':
			parar();
			break;
		case 'd':                
			pararDer();
			break;
		case 'e':                
			retrocederDer();
			retrocederIzq();
			break;
		default:
			break;
	}
}

int recibirDatos(){
  return Serial.read();
}

void irAdelante(){
	digitalWrite(DER_A, LOW);
	digitalWrite(DER_B, HIGH);
	analogWrite(ENB, 150);
	digitalWrite(IZQ_A, HIGH);
	digitalWrite(IZQ_B, LOW);
	analogWrite(ENA, 150);
}
 
void parar(){
	analogWrite(ENB, 0);
	analogWrite(ENA, 0);
}

void retrocederDer(){   
	digitalWrite(DER_A, HIGH);
	digitalWrite(DER_B, LOW);
	analogWrite(ENB, 150);
	digitalWrite(IZQ_A, HIGH);
	digitalWrite(IZQ_B, LOW);
	analogWrite(ENA, 150);  
}

void retrocederIzq(){
	analogWrite(IZQ_A, 0);
	analogWrite(IZQ_B, VACTUAL);
}

void pararDer(){
	digitalWrite(DER_A, LOW);
	digitalWrite(DER_B, HIGH);
	analogWrite(ENB, 150);
	analogWrite(ENA, 0);
}

void pararIzq(){
	digitalWrite(DER_A, LOW);
	digitalWrite(DER_B, HIGH);
	analogWrite(ENB, 0);
	digitalWrite(IZQ_A, HIGH);
	digitalWrite(IZQ_B, LOW);
	analogWrite(ENA, 150);
}