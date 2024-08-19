const int LED_0 = 2;

const int RED_LED = 11;
const int GREEN_LED = 10;
const int BLUE_LED = 9;

const int BUTTON_0 = 12;
const int BUTTON_1 = 13;

int button_0_state = 0;
int button_1_state = 0;

const int PRESSURE_SENSOR = A1;

void setup() {
    Serial.begin(9600);

    pinMode(LED_0, OUTPUT);
    pinMode(BUTTON_0, INPUT_PULLUP);
    pinMode(BUTTON_1, INPUT_PULLUP);
}

void loop() {
    // Serial.println("==============================================");
    button_0_state = digitalRead(BUTTON_0);
    button_1_state = digitalRead(BUTTON_1);
    // Serial.println("Button 0 state is: " + String(button_0_state));    
    // Serial.println("Button 1 state is: " + String(button_1_state));    

    int detected_pressure = analogRead(PRESSURE_SENSOR); // FIXME: consider declaring these outside the loop.
    int normalized_pressure = detected_pressure / 4; // Floor division from integer division.
    // Serial.println("Detected Pressure: " + String(detected_pressure)); // FIXME: find a better solution to print integers with strings.
    // Serial.println("Normalized Pressure: " + String(normalized_pressure)); 

    // First two buttons control RED and BLUE.
    if (button_0_state == 0) {
        analogWrite(RED_LED, 255);
    }
    else {
        analogWrite(RED_LED, 0);
    }

    if (button_1_state == 0) {
        analogWrite(BLUE_LED, 255);
    }
    else {
        analogWrite(BLUE_LED, 0);
    }

    // Force sensing resistor controls brightness of GREEN.
    analogWrite(GREEN_LED, normalized_pressure);
}

