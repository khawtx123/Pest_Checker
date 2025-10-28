#define EN_PIN 5
#define DIR_PIN 6
#define STEP_PIN 7

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

  if (limit) {
    int i = delay_time_ceil;
    while(delay_time < i) {   // Ramp Up 
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(i);
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(i);
      limit = digitalRead(LS_PIN); 
      i = 0.5*i*log(i);
    }

  }

  digitalWrite(EN_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
  digitalWrite(LED_PIN, LOW);
}
