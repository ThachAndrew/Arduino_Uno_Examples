void setup() {   
    Serial.begin(9600);
} 

void loop() {
    int reading = analogRead(A0);
    Serial.println("Analog Reading is: " + String(reading));  
    delay(10);
}
