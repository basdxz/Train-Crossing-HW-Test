// Must match baud on the serial monitor
#define BAUD_RATE 9600
// Connect through a 100 Ohm resistor
#define BUZZER_PIN 5

void setup(){
	setupSerial();
	setupBuzzer();
	testBuzzer();
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

void setupBuzzer(){
	pinMode(BUZZER_PIN, OUTPUT);
}

void testBuzzer() {
	Serial.println("Starting buzzer test");
	Serial.println("-====-====-====-====-");
	for (int i = 1; i <= 5; i++) {
		int freq = 200 * i;
		tone(BUZZER_PIN, freq, 250); // 200 * i Hz tone for 250 ms
		Serial.print("Buzz at ");
		Serial.print(freq);
		Serial.println(" Hz");
		Serial.println("-====-====-====-====-");
		delay(500);
	}
	Serial.println("Finished buzzer test");
	Serial.println("-====-====-====-====-");
}