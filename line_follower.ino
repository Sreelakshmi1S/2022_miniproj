#include <AFMotor.h>

//defining pins and variables
#define lefts A0
#define rights A1

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //Setting the motor speed
  motor1.setSpeed(150);
  motor4.setSpeed(150);
  //Declaring PIN input types
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  //Begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  //Printing values of the sensors to the serial monitor
  Serial.println(analogRead(lefts));
  Serial.println(analogRead(rights));
  //line detected by both
  if(analogRead(lefts)<=350 && analogRead(rights)<=350){
    //Forward
    motor1.run(FORWARD);
    motor4.run(FORWARD);
  }
  //line detected by left sensor
  else if(analogRead(lefts)<=350 && !analogRead(rights)<=350){
    //turn left
    motor1.run(FORWARD);
    motor4.run(BACKWARD);
    
  }
  //line detected by right sensor
  else if(!analogRead(lefts)<=350 && analogRead(rights)<=350){
    //turn right
    motor1.run(BACKWARD);
    motor4.run(FORWARD);
   
  }
  //line detected by none
  else if(!analogRead(lefts)<=350 && !analogRead(rights)<=350){
    //stop
    motor1.run(RELEASE);
    motor4.run(RELEASE);
   
  }
  
}
