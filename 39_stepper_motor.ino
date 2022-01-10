/* Note: We can directly make the enable pin of the driver high by connecting it with 5V instead in the future version of the code.*/
// defines pins numbers
const int stepPin = 15  ; 
const int dirPin = 2; 
const int enPin = 18;
bool dir = true;
int numberOfRevolutions = 95;

void setup() {
  Serial.begin(9600);
  // Sets the three pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(dirPin,HIGH);
  digitalWrite(enPin,LOW);

  for(int x = 0; x < 3200; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(50); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(50);
  }
}
void loop() {
  for(int i = 0; i < numberOfRevolutions; i++){
    for(int x = 0; x < 3200; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(25); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(25);
    }
  }
  delay(1000);
  dir = !dir;
  digitalWrite(dirPin, dir);
}
