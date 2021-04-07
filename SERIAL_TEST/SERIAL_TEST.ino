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
	Serial.print("Current time is (ms): ");
	Serial.println(millis());
	Serial.println("-====-====-====-====-");
}