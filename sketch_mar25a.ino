
 // C++ code
//
int TPin = 3;
int EPin = 2;
int M1 = 10;
int M2 = 11;
int M3 = 12;
int M4 = 13;
int MS1;
int MS2;
int MS3;
int MS4;
float duration;
float distance;

void setup()
{
  pinMode(TPin, OUTPUT);
  pinMode(EPin, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(TPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TPin, LOW);
  duration = pulseIn(EPin, HIGH);
  // distance = speed * time 
  distance = (duration/2) * 0.034;
  Serial.print("detected distance is ");
  Serial.println(distance);
  delay(1000);
  
  // Motion Detectors
  MS1 = digitalRead(5);
  MS2 = digitalRead(6);
  MS3 = digitalRead(7);
  MS4 = digitalRead(8);
  
  // Code for Motor 1
  if(distance>30 && distance<=95){
    digitalWrite(M1, HIGH);
    Serial.println("Motor 1st is running at a speed of 1000 rpm.");
  }
  else{
    digitalWrite(M1, LOW);
  }
  if(MS1==1){
    digitalWrite(M1, LOW);
    Serial.println("Motor 1 is stopped.");
  }
  
  // Code for Motor 2
  if(distance>95 && distance<=160){
    digitalWrite(M2, HIGH);
    Serial.println("Motor 2nd is running at a speed of 2000 rpm.");
  }
  else{
    digitalWrite(M2, LOW);
  }
  if(MS2==1){
    digitalWrite(M2, LOW);
    Serial.println("Motor 2 is stopped.");
  }
  
  // Code for Motor 3
  if(distance>160 && distance<=225){
    digitalWrite(M3, HIGH);
    Serial.println("Motor 3rd is running at a speed of 3000 rpm.");
  }
  else{
    digitalWrite(M3, LOW);
  }
  if(MS3==1){
    digitalWrite(M3, LOW);
    Serial.println("Motor 3 is stopped.");
  }
  
  // Code for Motor 4
  if(distance>225 && distance<=290){
    digitalWrite(M4, HIGH);
    Serial.println("Motor 4rth is running at a speed of 4000 rpm.");
  }
  else{
    digitalWrite(M4, LOW);
  }
  if(MS4==1){
    digitalWrite(M4, LOW);
    Serial.println("Motor 4 is stopped.");
  }
}  




 


 
