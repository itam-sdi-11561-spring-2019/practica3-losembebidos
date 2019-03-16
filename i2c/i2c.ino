#include "Wire.h" //añadimos libreria para emplear protocolo i2c

int esclavo_1 = 8;

int pin0 = 9;//1A en puente H
int pin1 = 10;//2A en puente H

void setup() {
  Serial.begin(9600);
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  Wire.available(); //- an ́aloga a la funci ́on deSerial
  Wire.begin(esclavo_1); //- funcion que se debe llamar una vez con el numero del esclavo
  Wire.onReceive(recibeTransmision); //- registra la funci ́on que se va a llamar al recibir una transmisíon
  Wire.onRequest(enviaTransmision); //- registra la funci ́on que se va a llamar al tener una solicitud de transmisi ́on
  
  
  
  //Wire.write(data); //- an ́aloga a la funci ́on deSerial
}


int c = 0;
int d = 1000;
void loop() {
  //Serial.println(c);
  //c++;
  /*
  //Prueba de funcionamiento del puente H
  //freno pasivo  
  digitalWrite(pin0,LOW);
  digitalWrite(pin1,LOW);
  delay(d);
 //rota en sentido de las manecillas
  digitalWrite(pin0,LOW);
  digitalWrite(pin1,HIGH);
  delay(d);
  //freno activo
  digitalWrite(pin0,HIGH);
  digitalWrite(pin1,HIGH);
  delay(d);
  //rota en sentido contrario de las manecillas
  digitalWrite(pin0,HIGH);
  digitalWrite(pin1,LOW);
  delay(d);
  */
  
}

void recibeTransmision(){
  int b1=0;
  int b0=0;
  int x = Wire.read(); //- an ́aloga a la funci ́on deSerial
  Serial.println("Valor obtenido");
  Serial.println(x);
  if(x==1){
    b1=0;
    b0=0;
  }else{
    if(x==2){
      b1=0;
      b0=1;
    }else{
      if(x==3){
        b1=1;
        b0=0;
      }else{
        b1 = 1;
        b0=1;
      }
    }
  }
  if(b1==b0){//se activan los frenos
    if(b0==0){
      //freno pasivo
      digitalWrite(pin0,LOW);
      digitalWrite(pin1,LOW);  
    }else{
      //freno activo
      digitalWrite(pin0,HIGH);
      digitalWrite(pin1, HIGH);
    }
  }else{//se activan las rotaciones
    if(b0==1){
      //rota en sentido de las manecillas
      digitalWrite(pin0,LOW);
      digitalWrite(pin1,HIGH);
    }else{
      //rota en sentido contrario de las manecillas
      digitalWrite(pin0,HIGH);
      digitalWrite(pin1,LOW);
    }
  }
  delay(2000);
}

void enviaTransmision(){
  
}

