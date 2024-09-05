/*
  Converts user integer input for to display as binary on 4 LEDs.
  Implements buttons (with debounce) which decrements/increments the display.
*/


// Integer array that stores the digital pins that the LEDs are connected to.
int led_pins[4] = {2, 4, 7, 8};
// Keeps track of which LED to be turned on.
int index = 0;
int user_input; //FIXME: Consider moving this variable to a different scope.

int last_state_button_0 = HIGH;
int last_state_button_1 = HIGH;

// Displays a number as 4 digit LED binary.
void displayBinaryLED(int num) {
    for (int i = 0; i < 4; ++i)
        digitalWrite(led_pins[i], bitRead(num, i));

}

void setup() {
    Serial.begin(9600);
    pinMode(led_pins[0], OUTPUT);
    pinMode(led_pins[1], OUTPUT);
    pinMode(led_pins[2], OUTPUT);
    pinMode(led_pins[3], OUTPUT);

    pinMode(12, INPUT_PULLUP);
    pinMode(13, INPUT_PULLUP);

    Serial.print("What number do you want displayed? ");
    while(!Serial.available()) {}

    user_input = Serial.parseInt();
}

void loop() {
    displayBinaryLED(user_input);

    // Remember last state so the button debounce knows when it was lifted.
    if (last_state_button_0 == LOW && digitalRead(12) == HIGH) {
        last_state_button_0 = HIGH;
    }

    // Button debounce, to counteract a "held button" performing unintentional control.
    if (last_state_button_0 == HIGH && digitalRead(12) == LOW) {
        user_input--;
        last_state_button_0 = LOW;
    }

    if (last_state_button_1 == LOW && digitalRead(13) == HIGH) {
        last_state_button_1 = HIGH;
    }

    if (last_state_button_1 == HIGH && digitalRead(13) == LOW) {
        user_input++;
        last_state_button_1 = LOW;
    }
}
