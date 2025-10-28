#define EN_PIN 5   // Check with stepper driver
#define DIR_PIN 6  // Check with stepper driver
#define STEP_PIN 7 // Check with stepper driver

#define LS_PIN 1
#define LED_PIN 4

#define delay_time 30 // Adjust this for sweeper speed
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
  digitalWrite(EN_PIN, LOW);
  bool limit = digitalRead(LS_PIN);

  if (limit) {
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(delay_time);
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(delay_time);
      limit = digitalRead(LS_PIN); 
  }

  digitalWrite(EN_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  delay(sweeper_stop_time);
  digitalWrite(LED_PIN, LOW);
}
