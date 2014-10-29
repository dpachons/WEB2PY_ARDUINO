int estado;           
int pulsador;
int estadopuerta;     
int pulsadorpuerta;
int control=0;       
int control1=0;  
int controlpuerta=0; 
int control1puerta=0; 
int lamparatoweb;     
int puertatoweb;
int incomingByte;
int temperatura;


void setup() 
  {
  Serial.begin(115200);
  pinMode(10, INPUT);//pulsador lampara//
  pinMode(9, INPUT);//pulsador lampara//
  pinMode(11, OUTPUT);//lampara//
  pinMode(12, OUTPUT);//puerta//
  }


void loop() {
  //controles para el boton de la lampara//
  estado = digitalRead(11);
  pulsador = digitalRead(10);
  if (estado==0 && pulsador==1 && control==0) {
    control=1;  
    digitalWrite(11,HIGH);
  }
  if (estado==1 && pulsador==0) {
    control1=1;
  }
  if (estado==1 && pulsador==1 && control1==1) {
    control1=0; 
    digitalWrite(11,LOW);
  }
  if (estado==0 && pulsador==0&& control1==0){
    control=0;
  }







  //controles para el boton de la puerta//
  pulsadorpuerta = digitalRead(9);
  if (pulsadorpuerta==1) {
   
    digitalWrite(12,HIGH);
  }
  if (pulsadorpuerta==0) {
    digitalWrite(12,LOW);
  }

  //captacion del valor de temperatura//
  temperatura= analogRead(2);

  //Comunicacion por puerto serie del estado de lampara y sus respectivas restricciones por si se quiere activar por web2py pero apagar por boton y viceversa//
  if (Serial.available() > 0) 
  {
    incomingByte = Serial.read();
    if (incomingByte == '1')
    {
      digitalWrite(11, HIGH);
      control=1;
    }
    if (incomingByte == '0')
    {
      digitalWrite(11, LOW);
      control1=0;
    }
  }

  if (digitalRead(11)==0)  {    
    lamparatoweb=0;  
  }
  if (digitalRead(11)==1)  {    
    lamparatoweb=1;  
  }
  if (digitalRead(12)==0)  {    
    puertatoweb=0;   
  }
  if (digitalRead(12)==1)  {    
    puertatoweb=1;   
  }

 String valores=("lampara= "+String(lamparatoweb)+", puerta= "+ String(puertatoweb)+", temperatura= "+ String(temperatura));
 Serial.println(valores);
 delay(80);

  



}







