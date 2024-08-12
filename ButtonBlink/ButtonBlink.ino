
const int LED_0 = 13;
const int BUTTON_0 = 2;
int button_state = 0;

void setup() {
    Serial.begin(9600);
    pinMode(LED_0, OUTPUT);
    pinMode(BUTTON_0, INPUT);
}

void loop() {
    button_state = digitalRead(BUTTON_0);
    Serial.println("Button state is: " + String(button_state));

    if (button_state == 1) {
        digitalWrite(LED_0, HIGH);
    }

    if (button_state == 0) {
        digitalWrite(LED_0, LOW);
    }
}

