// Must match baud on the serial monitor
#define BAUD_RATE 9600

void setup() {
	setupSerial();
}

void loop() {
	testSerial();
}

void setupSerial() {
	Serial.begin(BAUD_RATE);
	Serial.println("-====-====-====-====-");
	Serial.print("Serial Started at ");
	Serial.print(BAUD_RATE);
	Serial.println(" Baud");
	Serial.println("-====-====-====-====-");
}

void testSerial() {
	Serial.print("Current time is (ms): ");
	Serial.println(millis());
	Serial.println("-====-====-====-====-");
	delay(500);
}