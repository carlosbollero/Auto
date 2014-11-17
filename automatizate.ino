int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int pinRele = 13;

void setup() {
  pinMode(pinRele, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // read the value from the sensor:
  leerSensor();
  controlarValvula();

}

int leerSensor(){
  sensorValue = (1023 - analogRead(sensorPin));
  imprimirValor();
  delay(1000);
  return sensorValue;
}

void imprimirValor(){
  Serial.print("humedad = " );
  Serial.println(sensorValue);
}

void evaluarHumedad(){
  if (sensorValue < 300 && valvulaCerrada()){
    abrirValvula();
  }else if (sensorValue > 300 && valvulaAbierta()){
    cerrarValvula();
  }
}


void controlarValvula(){  
  while(sensorValue < 300){
    evaluarHumedad();
  }
  evaluarHumedad();
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
