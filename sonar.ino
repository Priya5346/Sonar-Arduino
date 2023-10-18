int trigPin1=2;
int echoPin1=3;

int trigPin2=4;
int echoPin2=5;

int trigPin3=6;
int echoPin3=7;

int trigPin4=8;
int echoPin4=9;

int trigPin5=10;
int echoPin5=11;

//int Buzzer = 13; // Connect buzzer pin to 13
int ledPin= 12;  //Connect LEd pin to 12

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
  //pinMode(Buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  long duration1, distance1;
  int var1=0,var2=0,var3=0,var4=0,var5=0,sum,count=0;

  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

  if (distance1 >= 500 || distance1 <= 0){
    // Serial.println("Out of range");
    var1=0;
  }
  else {
    // Serial.print ( "Sensor1  ");
    // Serial.print (distance1);
    // Serial.println("cm");
    var1=distance1;
    count++;
  }
  //delay(20);
  long duration2, distance2;
   digitalWrite(trigPin2, LOW);  // Added this line
   delayMicroseconds(2); // Added this line
   digitalWrite(trigPin2, HIGH);
   delayMicroseconds(10); // Added this line
   digitalWrite(trigPin2, LOW);
   duration2 = pulseIn(echoPin2, HIGH);
   distance2= (duration2/2) / 29.1;

   if (distance2 >= 500 || distance2 <= 0){
    // Serial.println("Out of range");
    var2=0;
  }
  else {
    // Serial.print("Sensor2  ");
    // Serial.print(distance2);
    // Serial.println("cm");
    var2=distance2;
    count++;
  }
  //delay(20);
  long duration3, distance3;
  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3= (duration3/2) / 29.1;

   if (distance3 >= 500 || distance3 <= 0){
    // Serial.println("Out of range");
    var3=0;
  }
  else {
    // Serial.print("Sensor3  ");
    // Serial.print(distance3);
    // Serial.println("cm");
    var3=distance3;
    count++;
  }
  //delay(20);

  long duration4, distance4;
  digitalWrite(trigPin4, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4= (duration4/2) / 29.1;

   if (distance4 >= 500 || distance4 <= 0){
    // Serial.print("Out of range");
    var4=0;
  }
  else {
    // Serial.print("Sensor4  ");
    // Serial.print(distance4);
    // Serial.print("cm");
    var4=distance4;
    count++;
  }
  //delay(20);


  long duration5, distance5;
  digitalWrite(trigPin5, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin5, LOW);
  duration5 = pulseIn(echoPin5, HIGH);
  distance5= (duration5/2) / 29.1;

   if (distance5 >= 500 || distance5 <= 0){
    // Serial.println("Out of range");
    var5=0;
  }
  else {
    // Serial.print("Sensor5  ");
    // Serial.print(distance5);
    // Serial.println("cm");
    var5=distance5;
    count++;
  }
  //delay(20);

  if(count==0){
    sum=0;
  }
  else{
   sum=(var1+var2+var3+var4+var5)/count;
  }
  Serial.print("Distance is ");
  Serial.print(sum);
  Serial.println("cm");
  
  if (sum >=0 && sum <= 10) 
        {
        //tone(Buzzer,400);              // play tone of 400Hz for 500 ms
        digitalWrite(ledPin,HIGH);
        }
  else {
        //digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);
  }
}
