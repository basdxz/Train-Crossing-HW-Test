// Must match baud on the serial monitor
#define BAUD_RATE 9600

#define BUZZER_PIN 5 // Connect through a 100 Ohm resistor

void setup(){
	Serial.begin(BAUD_RATE);
	setupBuzzer();
}

void setupBuzzer(){
	pinMode(BUZZER_PIN, OUTPUT);
	testBuzzer();
}

void loop() {
}

void testBuzzer() {
	Serial.println("-====-====-====-====-");
	Serial.println("Starting buzzer test");
	Serial.println("-====-====-====-====-");
	for (int i = 0; i < 5; i++) {
		tone(BUZZER_PIN, 200, 200); // 200Hz tone for 200 ms
		Serial.println("Buzz!");
		Serial.println("-====-====-====-====-");
		delay(500);
	}
	Serial.println("Finished buzzer test");
	Serial.println("-====-====-====-====-");
}