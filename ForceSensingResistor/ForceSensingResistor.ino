const int PRESSURE_SENSOR = A1;

void setup() {   
    Serial.begin(9600);
} 

void loop() {
    int reading = analogRead(PRESSURE_SENSOR);
    Serial.println("Analog Reading is: " + String(reading));  
    delay(10);
}
