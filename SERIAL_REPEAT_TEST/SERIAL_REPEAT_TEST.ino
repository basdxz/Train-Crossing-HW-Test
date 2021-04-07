// Must match baud on the serial monitor
#define BAUD_RATE 9600

void setup() {
	Serial.begin(BAUD_RATE);
	Serial.println("-====-====-====-====-");
	Serial.println("Serial Started at 9600 Baud");
	Serial.println("-====-====-====-====-");
}

void loop() {
	delay(500);
	Serial.println("Waiting for user string!");
	Serial.println("-====-====-====-====-");
	while (!Serial.available());
	Serial.print("User string was: ");
	Serial.print(Serial.readString()); // Expects a string to be sent, followed by a \n (enter key)
	Serial.println("-====-====-====-====-");
}