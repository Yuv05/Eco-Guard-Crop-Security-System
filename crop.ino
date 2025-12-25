#define PIR_PIN 2
#define TRIG_PIN 3
#define ECHO_PIN 4
#define RELAY_PIN 8

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);  // LED OFF at start
  Serial.begin(9600);
  Serial.println("System Ready...");
}

void loop() {
  int pirState = digitalRead(PIR_PIN);

  if (pirState == HIGH) {   // Motion detected
    delay(200);             // PIR stabilization
    if (digitalRead(PIR_PIN) == HIGH) {
      
      long distance = measureDistance();
      Serial.print("Distance: ");
      Serial.println(distance);

      if (distance > 0 && distance < 100) {  // intruder range
        Serial.println("INTRUDER DETECTED → LIGHT ON");
        digitalWrite(RELAY_PIN, HIGH);        // LED ON
      } else {
        digitalWrite(RELAY_PIN, LOW);         // LED OFF
      }
    }
  } else {
    digitalWrite(RELAY_PIN, LOW);             // No motion → OFF
  }

  delay(300);
}

// Ultrasonic distance function
long measureDistance() {
  digitalWrite
