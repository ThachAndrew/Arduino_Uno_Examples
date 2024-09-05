/*
  Converts user integer input for to display as binary on 4 LEDs.
*/


// Integer array that stores the digital pins that the LEDs are connected to.
int led_pins[4] = {2, 4, 7, 8};
// Keeps track of which LED to be turned on.
int index = 0;
int user_input;

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

    Serial.print("What number do you want displayed? ");
    while(!Serial.available()) {}

    user_input = Serial.parseInt();
}

void loop() {
    displayBinaryLED(user_input);
}
