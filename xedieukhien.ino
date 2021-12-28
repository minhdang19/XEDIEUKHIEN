int pump = 4;
int in4 = 5;
int in3 = 6;
int in2 = 9;
int in1 = 10;
int vel = 200;
char estado = 'g';
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
} 

void loop() { 

if(Serial.available()>0){
estado = Serial.read();
Serial.println(estado);
}
if(estado=='F'){ // tien
analogWrite(in1, 0); 
analogWrite(in2, vel); 
analogWrite(in3, 0); 
analogWrite(in4, vel); 
}
if(estado=='B'){ // lui
analogWrite(in1, vel); 
analogWrite(in2, 0);
analogWrite(in3, vel); 
analogWrite(in4, 0); 
}
if(estado=='R'){ // phai
analogWrite(in1, 0); 
analogWrite(in2, vel); 
analogWrite(in3, vel); 
analogWrite(in4, 0); 
}
if(estado=='S'){ // ngung lai
analogWrite(in1, 0); 
analogWrite(in2, 0); 
analogWrite(in3, 0); 
analogWrite(in4, 0); 
}
if(estado=='L'){ // trai
analogWrite(in1, vel); 
analogWrite(in2, 0);
analogWrite(in3, 0);
analogWrite(in4, vel); 
} 
if(estado=='I'){ // tien phai
analogWrite(in1, 0); 
analogWrite(in2, vel);
analogWrite(in3, 0);
analogWrite(in4,0); 
}
if(estado=='G'){//tien trai
analogWrite(in1, 0); 
analogWrite(in2, 0);
analogWrite(in3, 0);
analogWrite(in4, vel); 
}
if(estado=='H'){ // lui trai
analogWrite(in1, 0); 
analogWrite(in2, 0);
analogWrite(in3, vel);
analogWrite(in4, 0); 
}
if(estado=='J'){ // lui phai
analogWrite(in1, vel); 
analogWrite(in2, 0);
analogWrite(in3, 0);
analogWrite(in4, 0); 
}
if(estado=='W'){
  digitalWrite(pump,HIGH);
}
if(estado=='w'){
  digitalWrite(pump,LOW);}
}
