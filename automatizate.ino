/********************************************************************
 *
 *	El sensor mide la resistencia devuelve valores entre 0 y 1023,
 *	siendo 0 la menor resistencia y 1023 la mayor.
 *	sensor  | humedad aprox.
 *	 200  ---->  80%
 *	 300  ---->  70%
 *	 400  ---->  60%
 *	 500  ---->  50%
 *
 *******************************************************************/

int sensorPin = A0;    // select the input pin for the potentiometer
byte sensorValue = 0;   // variable to store the value coming from the sensor
int pinRele = 13;
int valorReferencia = 300;

void setup() {
  pinMode(pinRele, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // read the value from the sensor:
  evaluarHumedad();
  //controlarValvula();

}

void evaluarHumedad(){
  sensorValue = leerSensor();
  if (sensorValue < valorReferencia && valvulaCerrada()){
    abrirValvula();
  }else if (sensorValue > valorReferencia && valvulaAbierta()){
    cerrarValvula();
  }
  delay(1000);
}

int leerSensor(){
  sensorValue = (1023 - analogRead(sensorPin));
  imprimir();
  return sensorValue;
}

void imprimir(){
  Serial.print("humedad = " );
  Serial.println(sensorValue);
}

void abrirValvula(){
  digitalWrite(pinRele, HIGH);
  Serial.println("valvula ABIERTA");
}

void cerrarValvula(){
  digitalWrite(pinRele, LOW);
  Serial.println("valvula CERRADA");
}

boolean valvulaAbierta(){
  return (digitalRead(pinRele) == HIGH);
}

boolean valvulaCerrada(){
  return (digitalRead(pinRele) == LOW);
}

// void controlarValvula(){  
//   if(valvulaCerrada()){
//   	abrirValvula();
//   }else if (valvulaAbierta()){
//   	abrirValvula();
//   }
// }