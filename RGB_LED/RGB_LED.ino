const int RED_LED = 11;
const int GREEN_LED = 10;
const int BLUE_LED = 9;

void setup() {
    Serial.begin(9600);
}

void loop() {

    Serial.print("Enter an intensity value from 0 to 255: ");
    while(!Serial.available()){}

    int value = Serial.parseInt();
    Serial.read(); // FIXME: Find a better solution for consuming newline.

    if (value < 0) {
      Serial.println("That's too low!");
      value = 0;  
    }
    else if (value > 255) {
      Serial.println("That's too high!");
      value = 255;
    }

    Serial.println("Setting value to: " + String(value));

    Serial.print("Enter a color: ");
    while(!Serial.available()){}

    String input_color = Serial.readStringUntil('\n');

    if (input_color == "red")
        analogWrite(RED_LED, value);

    if (input_color == "green")
        analogWrite(GREEN_LED, value);

    if (input_color == "blue")
        analogWrite(BLUE_LED, value);

    Serial.println("your chosen color was: " + input_color);
}
