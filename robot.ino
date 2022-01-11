int pump = 4;
int in4 = 5;
int in3 = 6;
int in2 = 9;
int in1 = 10;
int vel = 160;
char estado = 'g';
// khai báo 3 cảm biến  
int leftSensor = 13;
int middleSensor = 12;
int rightSensor = 11;
void tien() 
  {
    analogWrite(in1, 0); 
    analogWrite(in2, vel); 
    analogWrite(in3, 0); 
    analogWrite(in4, vel);         
  } 
 
  void lui() 
  { 
    analogWrite(in1, vel); 
    analogWrite(in2, 0);
    analogWrite(in3, vel); 
    analogWrite(in4, 0); 
  } 
   
  void phai() 
  { 
    analogWrite(in1, 0); 
    analogWrite(in2, vel); 
    analogWrite(in3, vel); 
    analogWrite(in4, 0); 
   } 
   void tienphai()
   {
    analogWrite(in1, 0); 
    analogWrite(in2, vel);
    analogWrite(in3, 0);
    analogWrite(in4,0);
   }
   void luiphai()
   {
    analogWrite(in1, vel); 
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
   }
   
  void trai() 
  {     
    analogWrite(in1, vel); 
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, vel);  
  } 
  void tientrai()
  {
    analogWrite(in1, 0); 
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, vel);
  }
  void luitrai()
  {
    analogWrite(in1, 0); 
    analogWrite(in2, 0);
    analogWrite(in3, vel);
    analogWrite(in4, 0);
  }
   
  void dung() 
  { 
    analogWrite(in1, LOW);
    analogWrite(in2, LOW);
    analogWrite(in3, LOW);
    analogWrite(in4, LOW);    }
void setup() { 
Serial.begin(9600);
pinMode(pump, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
analogWrite(in1, 0); 
analogWrite(in3, 0); 
analogWrite(in2, 0); 
analogWrite(in4, 0); 
digitalWrite(pump,LOW);
// cam bien do line
pinMode(leftSensor,INPUT);
pinMode(middleSensor,INPUT);
pinMode(rightSensor,INPUT);
} 
void loop() { 
if(Serial.available()>0){
estado = Serial.read();
Serial.println(estado);}
if(estado=='F'){ // tien
tien(); 
}
if(estado=='B'){ // lui
lui(); 
}
if(estado=='R'){ // phai
phai(); 
}
if(estado=='L'){ // trai
trai(); 
} 
if(estado=='I'){ // tien phai
tienphai(); 
}
if(estado=='G'){//tien trai
tientrai(); 
}
if(estado=='H'){ // lui trai
luitrai(); 
}
if(estado=='J'){ // lui phai
luiphai(); 
}
if(estado=='W'){
  digitalWrite(pump,HIGH);
}
if(estado=='w'){
  digitalWrite(pump,LOW);}
if(estado=='S'){
  //cảm biến giữa trên vạch
  if((digitalRead(leftSensor) == 0) && (digitalRead(middleSensor) == 1) && (digitalRead(rightSensor) == 0)) 
  { 
    analogWrite(in1, 0); 
    analogWrite(in2, 100); 
    analogWrite(in3, 0); 
    analogWrite(in4, 100); 
  } 
  // cảm biến trái và giữa đang ngoài vạch   
  if((digitalRead(leftSensor) == 1) && (digitalRead(middleSensor) == 1) && (digitalRead(rightSensor) == 0)) 
  { analogWrite(in1, 100); 
    analogWrite(in2, 0);
    analogWrite(in3, 0); 
    analogWrite(in4, 100);  
  } 
  // cảm biến trái ở ngoài vạch   
  if((digitalRead(leftSensor) == 1) && (digitalRead(middleSensor) == 0) && (digitalRead(rightSensor) == 0)) 
  { analogWrite(in1, 100); 
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 100); 
  } 
  // cảm biến giữa và phải ở ngoài vạch   
  if((digitalRead(leftSensor) == 0) && (digitalRead(middleSensor) == 1) && (digitalRead(rightSensor) == 1)) 
  { analogWrite(in1, 0); 
    analogWrite(in2, 100); 
    analogWrite(in3, 100); 
    analogWrite(in4, 0); 
  } 
  // cảm biến phải ở ngoài vạch 
  if((digitalRead(leftSensor) == 0) && (digitalRead(middleSensor) == 0) && (digitalRead(rightSensor) == 1)) 
  { analogWrite(in1, 0); 
    analogWrite(in2, 100); 
    analogWrite(in3, 100); 
    analogWrite(in4, 0); 
  } 
  // cả 3 cảm biến ở ngoài vạch   
  if((digitalRead(leftSensor) == 0) && (digitalRead(middleSensor) == 0) && (digitalRead(rightSensor) == 0)) 
  {     dung(); 
  } 
  // cả 3 cảm biến ở trên vạch   
  if((digitalRead(leftSensor) == 1) && (digitalRead(middleSensor) == 1) && (digitalRead(rightSensor) == 1)) 
  { analogWrite(in1, 0); 
    analogWrite(in2, 100); 
    analogWrite(in3, 0); 
    analogWrite(in4, 100); 
  } 
}
}
