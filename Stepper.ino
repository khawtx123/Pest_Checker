#define DIR_PIN 12
#define STEP_PIN 13
#define EN_PIN 14
#define LS_PIN 27
#define delay_time 900

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
  while (1) {
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delay_time);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delay_time);
    limit = digitalRead(LS_PIN);

    if (limit == HIGH) {
      break; 
    }
    
  }

  digitalWrite(EN_PIN, HIGH);
  delay(2000);
}
