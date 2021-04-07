// Must match baud on the serial monitor
#define BAUD_RATE 9600

void setup() {
	setupSerial();
	testSerialRead();
}

void loop() {
}

void setupSerial() {
	Serial.begin(BAUD_RATE);
	Serial.println("-====-====-====-====-");
	Serial.print("Serial Started at ");
	Serial.print(BAUD_RATE);
	Serial.println(" Baud");
	Serial.println("-====-====-====-====-");
}

void testSerialRead() {
	Serial.println("Testing serial read");
	Serial.println("-====-====-====-====-");
	Serial.println("Waiting for user string");
	Serial.println("-====-====-====-====-");
	while (!Serial.available());
	Serial.print("User string was: ");
	Serial.print(Serial.readString()); // Expects a string to be sent, followed by a \n (enter key)
	Serial.println("-====-====-====-====-");
}