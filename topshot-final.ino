int solenoidPin = 7;    // ouput - to transistor base, solenoid driver
int vibratorPin = 6; // output - vibrator motor 
int triggerPin = 4; // input - trigger 


int trigger;
int vibrator;
int solenoid;



void setup() {

  pinMode(solenoidPin, OUTPUT);
  pinMode(vibratorPin, OUTPUT); 
  pinMode(triggerPin, INPUT);       
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(solenoidPin, LOW);

}


void loop() {

  trigger = digitalRead(triggerPin);

  if(trigger == HIGH )
  {
  digitalWrite(vibratorPin, HIGH);    // test  
  SolenoidPulse(solenoidPin,130); // 130ms on/off cycle
  } else {
   digitalWrite(vibratorPin, LOW);    // test  
  }
}

void SolenoidPulse(int pin, int pulse)
{
  int wait = pulse / 2;
  digitalWrite(pin, HIGH);    // Solenoid ON
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(wait);                      //Wait 
  digitalWrite(pin, LOW);     //Solenoid OFF
  digitalWrite(LED_BUILTIN, LOW);
  delay(wait);                      //Wait 
}


