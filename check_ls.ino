#define EN_PIN 5   // Check with stepper driver
#define DIR_PIN 6  // Check with stepper driver
#define STEP_PIN 7 // Check with stepper driver

#define LS_PIN 1
#define LED_PIN 4

#define delay_time 20
#define delay_time_ceil 70

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
  Serial.println(limit);
}
