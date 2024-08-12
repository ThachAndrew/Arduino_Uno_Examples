
const int LED_0 = 13;
const int onTime = 1000;
const int offTime = 200;

void setup() {
    Serial.begin(9600);
    pinMode(LED_0, OUTPUT);
}

void loop() {
    digitalWrite(LED_0, HIGH);
    Serial.println("On for " + String(onTime) + " ms.");
    delay(onTime);
    digitalWrite(LED_0, LOW);
    Serial.println("Off for " + String(offTime) + "ms.");
    delay(offTime);
}

