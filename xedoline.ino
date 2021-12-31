// khai báo 3 cảm biến  int leftSensor = 2;  int middleSensor = 3;  int rightSensor = 4;  // khai báo chân L298  int in1 = 5;  int in2 = 6; 
 int in3 = 9;  int in4 = 10;  void chaythang() 
  {     analogWrite(in1, 100);     analogWrite(in2, LOW);       analogWrite(in3, 100);     analogWrite(in4, LOW);  
  } 
 
  void chaylui() 
  { 
    analogWrite(in1, LOW);     analogWrite(in2, 100);       analogWrite(in3, LOW);     analogWrite(in4, 100);  
  } 
   
  void rephai() 
  { 
    analogWrite(in1, LOW);     analogWrite(in2, LOW);       analogWrite(in3, 100);     analogWrite(in4, LOW); 
   } 
   
  void retrai() 
  {     analogWrite(in1, 100);     analogWrite(in2, LOW);      analogWrite(in3, LOW);     analogWrite(in4, LOW);  
  } 
   
  void dunglai() 
  { 
    analogWrite(in1, LOW);     analogWrite(in2, LOW);      analogWrite(in3, LOW);     analogWrite(in4, LOW);    } 
 
 void setup() 
 { 
  Serial.begin(9600);   pinMode(leftSensor,INPUT);   pinMode(middleSensor,INPUT);   pinMode(rightSensor,INPUT);   pinMode(in1,OUTPUT);   pinMode(in2,OUTPUT);   pinMode(in3,OUTPUT);   pinMode(in4,OUTPUT); 
 } 
 
void loop() 
{ 
  // cảm biến giữa ở trên vạch     if((digitalRead(leftSensor) == 0) && (digitalRead(middleSensor) == 1) && (digitalRead(rightSensor) == 0)) 
  { 
    chaythang(); 
  } 
  // cảm biến trái và giữa đang ở trên vạch   if((digitalRead(leftSensor) == 1) && (digitalRead(middleSensor) == 1) && (digitalRead(rightSensor) == 0)) 
  {     retrai(); 
  } 
  // cảm biến trái ở trên vạch   if((digitalRead(leftSensor) == 1) && (digitalRead(middleSensor) == 0) && (digitalRead(rightSensor) == 0)) 
  {     retrai(); 
  } 
  // cảm biến giữa và phải ở trên vạch   if((digitalRead(leftSensor) == 0) && (digitalRead(middleSensor) == 1) && (digitalRead(rightSensor) == 1)) 
  {     rephai(); 
  } 
  // cảm biến phải ở trên vạch 
  if((digitalRead(leftSensor) == 0) && (digitalRead(middleSensor) == 0) && (digitalRead(rightSensor) == 1)) 
  {     rephai(); 
  } 
  // cả 3 cảm biến ở ngoài vạch   if((digitalRead(leftSensor) == 0) && (digitalRead(middleSensor) == 0) && (digitalRead(rightSensor) == 0)) 
  {     dunglai(); 
  } 
  // cả 3 cảm biến ở trên vạch   if((digitalRead(leftSensor) == 1) && (digitalRead(middleSensor) == 1) && (digitalRead(rightSensor) == 1)) 
  {     chaythang(); 
  } 
} 
