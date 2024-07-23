// C++ code
//

const uint8_t MOTION_SENSOR_PIN = 2;
const uint8_t LED_PIN = 13;


uint8_t motionState = LOW;
uint8_t LEDState = LOW;


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOTION_SENSOR_PIN, INPUT);
  Serial.begin(9600);
}
void loop()
{
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
  motionState = LOW;
}