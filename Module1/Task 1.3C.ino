// C++ code
//

const uint8_t MOTION_SENSOR_PIN = 2;
const uint8_t LED_PIN = 13;
const uint8_t TRIG_PIN = 7;
const uint8_t ECHO_PIN = 3;

long duration;
int distance;


uint8_t motionState = LOW;
uint8_t LEDState = LOW;

void handleLED() {
  LEDState = !LEDState;
  digitalWrite(LED_PIN,LEDState);
  Serial.println("There is motion and light is on");
  
}

void Calculate_Distance(){
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echoPin
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance
  distance = duration * 0.034 / 2;
  
  Serial.println("Distance: ");
  Serial.print(distance);
}



void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOTION_SENSOR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), handleLED, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ECHO_PIN),Calculate_Distance,CHANGE);
  Serial.begin(9600);
}

void loop()
{
  
  
  
  
  
  /*
  motionState = digitalRead(MOTION_SENSOR_PIN);
  
  if(motionState == HIGH)
  {
    Serial.println("Motion exist");
    Serial.println("LED is On");
    LEDState =HIGH;
    digitalWrite(LED_PIN, HIGH);
  }
  else if(motionState == LOW && LEDState==HIGH)
  {
    Serial.println("LED Goes Off");
    digitalWrite(LED_PIN, LOW);
    LEDState=LOW;
  }
  motionState = LOW;*/
}