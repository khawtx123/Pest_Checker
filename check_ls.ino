#define DIR_PIN 12
#define STEP_PIN 13
#define EN_PIN 14
#define LS_PIN 27
#define stepsPerRevolution 3200
#define delay_time 900
int threshold = 5; 

void setup() {
  // put your setup code here, to run once:
}


void setup() {
  // put your setup code here, to run once:
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);
  pinMode(LS_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(DIR_PIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool limit = digitalRead(LS_PIN);                                                                                                                    
  Serial.println(limit);
}
