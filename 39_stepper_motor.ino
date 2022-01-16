/* Note: We can directly make the enable pin of the driver high by connecting it with 5V instead in the future version of the code.*/
// defines pins numbers
const int stepPin = 15  ; 
const int dirPin = 2; 
const int enPin = 18;
bool dir = true;
//bool lastDir = true;
int numberOfRevolutions = 95; // reducing from 95 to 5 for development purpose.

const byte optoOne = 13; // The first opto-coupler has been connected with the GPIO-13.
const byte optoTwo = 12; // The second opto-coupler has been connected with the GPIO-12.
const byte inOrOut = 14; // Button to get the battery out if it is in and to get it in if it is out.
bool rotate = false;

void setup() {
  Serial.begin(9600);
  // Sets the three pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  pinMode(inOrOut,INPUT_PULLUP);
  digitalWrite(dirPin,HIGH);
  digitalWrite(enPin,LOW);

  attachInterrupt(digitalPinToInterrupt(optoOne),stopAndReverse,RISING);
  attachInterrupt(digitalPinToInterrupt(optoTwo),stopAndForward,RISING);
  attachInterrupt(digitalPinToInterrupt(inOrOut),start,FALLING);  
}

void stopAndReverse(){
  dir = false;
  digitalWrite(dirPin,dir);
  rotate = false;
  //numberOfRevolutions = 0;
}

void stopAndForward(){
  dir = true;
  digitalWrite(dirPin,dir);
  rotate = false;
  //numberOfRevolutions = 0;
}

void start(){
  //dir = !dir;
  //digitalWrite(dirPin,dir);
  rotate = true;
}

void loop(){
  //if(numberOfRevolutions == 0){
    for(int i = 0; i < numberOfRevolutions; i++){
      for(int x = 0; x < 3200; x++) {
        if(rotate == true){
          digitalWrite(stepPin,HIGH); 
          delayMicroseconds(50); 
          digitalWrite(stepPin,LOW); 
          delayMicroseconds(50);
        }
        else{
          break;
        }
      }
      if(rotate == true && i == (numberOfRevolutions - 1)){
        dir = !dir;
        digitalWrite(dirPin,dir);
        rotate = false;
      }
      if(rotate == false) break;
     }
  //}
}
