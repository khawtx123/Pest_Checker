#define EN_PIN 5   // Check with stepper driver
#define DIR_PIN 6  // Check with stepper driver
#define STEP_PIN 7 // Check with stepper driver

#define LS_PIN 1  // Limit Switch Pin
#define LED_PIN 4 // LED Switch Pin

#define delay_time 20       // Adjust Ramp up to this freq, -> higher -> faster sweeper ramps up 
#define delay_time_ceil 70 // Adjust Ramp up from this freq, -> higher -> slower sweeper ramps up 

#define sweeper_stop_time 2000 // Adjust for sweeper off time

void setup() {
  // put your setup code here, to run once:
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);  
  pinMode(EN_PIN, OUTPUT);
  pinMode(LS_PIN, INPUT); 
  Serial.begin(9600);
  digitalWrite(DIR_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(EN_PIN, LOW);
  bool limit = digitalRead(LS_PIN);

  if (limit) {
    int i = delay_time_ceil;
    while(delay_time < i) {   // Ramp Up 
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(i);
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(i);
      limit = digitalRead(LS_PIN); 
      i = 0.5*i*log(i); //Non-linear func for gradual increase in pwm freq
    }

  }

  digitalWrite(EN_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  delay(sweeper_stop_time);
  digitalWrite(LED_PIN, LOW);
}
