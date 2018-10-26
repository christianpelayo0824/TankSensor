
int trigPin = 8;
int echoPin = 9;
int lowPin = 11;
int medPin = 12;
int highPin = 13;

int distance;
int duration;

void setup() {
   Serial.begin(9600);
   
   //INDICATOR PINS
   pinMode(lowPin, OUTPUT);
   pinMode(medPin, OUTPUT);
   pinMode(highPin, OUTPUT);

  //ULTRA SONIC PINS
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (((duration/2) / 29.1) - 16) * -1 ;

 if(distance <= 5) {
    digitalWrite(lowPin, HIGH);
    digitalWrite(medPin, LOW);
    digitalWrite(highPin, LOW);
    Serial.println("LOW");
 }
 if(distance >= 5 && distance <= 10) {
    digitalWrite(lowPin, LOW);
    digitalWrite(medPin, HIGH);
    digitalWrite(highPin, LOW);
    Serial.println("MED");
 }
 if(distance >= 10 && distance <= 13 ) {
    digitalWrite(lowPin, LOW);
    digitalWrite(medPin, LOW);
    digitalWrite(highPin, HIGH);
    Serial.println("HIGH");
 }
 
  
  
  Serial.println(distance);
}
