//Written by APSC 101 Team F8

#include <Servo.h>
#define TRIGGER_PIN 5
#define ECHO_PIN 6
#define MAX_DISTANCE 200 // maximum distance set to 200 cm
#define YES 1
#define NO 0
#define THRESHOLD 4 // server activates when the distance between the sensor and target is 4cm apart

Servo myservo;  

// defines variables
long duration;
int distance;
int pos = 0;    // variable to store the servo position
int grabbing = 1;
int releasing = 0;
int counter = 0;

void setup() {
  Serial. begin(9600);  // set data transmission rate to communicate with computer
  pinMode(ECHO_PIN, INPUT) ;  
  pinMode(TRIGGER_PIN, OUTPUT) ;
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(180);

}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);  // Clears the trigPin
  delayMicroseconds(20);
  digitalWrite(TRIGGER_PIN, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(20);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration*0.034/2;  // Calculating the distance
  
  if (distance > MAX_DISTANCE)   
    {distance = MAX_DISTANCE ;}

  ///*
  if (grabbing == 1) {
    Serial.print("Grabbing Mode \n");
    if (distance <= THRESHOLD) {
      
      for (counter = 180; counter > 90; counter--) {
        myservo.write(counter);
        Serial.print("Counter: ");
        Serial.println(counter);
        Serial.print("\n");
      }
      //myservo.write(90);
      delay(3000);
      Serial.print("Grabbing item \n");
      grabbing = NO;
      while (releasing == NO) {
        digitalWrite(TRIGGER_PIN, LOW);  // Clears the trigPin
        delayMicroseconds(20);
        digitalWrite(TRIGGER_PIN, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
        delayMicroseconds(20);
        digitalWrite(TRIGGER_PIN, LOW);
        duration = pulseIn(ECHO_PIN, HIGH);
        distance = duration*0.034/2;
        if (distance > THRESHOLD) {
          releasing = YES;
        }
        //Serial.print("Releasing is");
        //Serial.println(releasing);
      }
    }
  }

  if (releasing == 1) {
    Serial.print("Releasing Mode \n");
    if (distance <= THRESHOLD) {
      
      myservo.write(180);
      delay(3000);
      Serial.print("Releasing Item \n");
      releasing = NO;
      while (grabbing == NO) {
        digitalWrite(TRIGGER_PIN, LOW);  // Clears the trigPin
        delayMicroseconds(20);
        digitalWrite(TRIGGER_PIN, HIGH);  // Sets the trigPin on HIGH state for 10 micro seconds
        delayMicroseconds(20);
        digitalWrite(TRIGGER_PIN, LOW);
        duration = pulseIn(ECHO_PIN, HIGH);
        distance = duration*0.034/2;
        if (distance > THRESHOLD) {
          delay(200);
          grabbing = YES;
        }
      
      }
    }
    
  }
  
    
  Serial.print("Distance: ") ;  // Prints the distance on the Serial Monitor
  Serial.println(distance);
  Serial.print("\n");
}
