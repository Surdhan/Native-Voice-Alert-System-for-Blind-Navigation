// Native Voice Alert System for Blind Navigation: Utilizing Ultrasonic Sensor HCSR04 with ISD1820 and Arduino nano
// by RG Innovations 
// This sketch can work with ATtiny85 and Arduino UNO, MEGA, etc...
// This example code is in the public domain.


#define trigPin 3 //HCSR05 Trigger set to pin 3
#define echoPin 2 // HCSR05 Echo set to Pin 5
#define LED_PIN 4 // LED light set to Pin 4
#define ISD_PIN 5 // ISD1820 module PE Pin
#define DISTANCE 10 // Distance value to check in CM

long duration, cm;

void setup() 
{ 
  pinMode(LED_PIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(LED_PIN, LOW);  
} 
 
 
void loop() 
{ 

  //sending the trigger pulse, starting with LOW for a clean pulse
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
//setting up the input pin, and receiving the duration in uS
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
// convert the pulse travel time into a distance
cm = microsecondsToCentimeters(duration);
  
      
      if (cm<=DISTANCE){
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(ISD_PIN, HIGH);
        delay (200);        
        digitalWrite(ISD_PIN, LOW);
        delay (4800);
        digitalWrite(LED_PIN, LOW);
      }
      
delay(100);

} 


long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s (29 us/cm)
return microseconds / 29 / 2;
}
