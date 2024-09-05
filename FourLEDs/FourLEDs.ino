/*
  Blinks each of the 4 LEDs consecutively.
*/


// Integer array that stores the digital pins that the LEDs are connected to.
int led_pins[4] = {2, 4, 7, 8};
// Keeps track of which LED to be turned on.
int index = 0;

void setup() {
    pinMode(led_pins[0], OUTPUT);
    pinMode(led_pins[1], OUTPUT);
    pinMode(led_pins[2], OUTPUT);
    pinMode(led_pins[3], OUTPUT);
}

void loop() {
    digitalWrite(led_pins[index], HIGH);
    delay(500);
    digitalWrite(led_pins[index], LOW);

    index++; // Increment LED index.
    index %= 4; // Start over for every 4th iteration.
}
