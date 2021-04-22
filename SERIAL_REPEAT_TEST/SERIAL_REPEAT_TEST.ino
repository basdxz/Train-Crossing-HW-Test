// Must match baud on the serial monitor
#define BAUD_RATE 9600
#define TEST_MESSAGE "raise"
#define TEST_RESPONSE "barrier raised!"

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
	Serial.print("Testing string is: ");
	Serial.println(TEST_MESSAGE);
	Serial.println("-====-====-====-====-");
	Serial.println("Waiting for user string");
	Serial.println("-====-====-====-====-");
	while (!Serial.available());
	Serial.print("User string was: \"");
	String message = Serial.readString(); // Expects a string to be sent, followed by a \n (enter key)
	message = message.substring(0, message.length() - 1);
	Serial.print(message);
	Serial.println("\"\n-====-====-====-====-");
	if (message == TEST_MESSAGE) {
		Serial.println(TEST_RESPONSE);
		Serial.println("-====-====-====-====-");
	}
}