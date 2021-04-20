// Must match baud on the serial monitor
#define BAUD_RATE 9600

// https://github.com/gamegine/HCSR04-ultrasonic-sensor-lib
// This library needs to be downloaded and installed manually.
#include <HCSR04.h>
// Connect to pin marked as TRIG
#define SONIC_TRIGGER_PIN 2
// Connect to pin marked as ECHO
#define SONIC_ECHO_PIN 3
HCSR04 usSensor(SONIC_TRIGGER_PIN, SONIC_ECHO_PIN);

void setup() {
	setupSerial();
	testUSSensor();
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

void testUSSensor() {
	Serial.println("Starting ultra sonic sensor test");
	Serial.println("-====-====-====-====-");
	for (int i = 0; i < 10; i++) {
		delay(500);   
		unsigned long startTime = millis();

		Serial.print("Sonic Sensor distance (cm): ");
		Serial.println(usSensor.dist());
  
		unsigned long endTime = millis() - startTime;
		Serial.print("Time taken to sample distance (ms): ");
    	Serial.println(endTime);
		Serial.println("-====-====-====-====-");
	}
	Serial.println("Finished ultra sonic distance sensor test");
	Serial.println("-====-====-====-====-");
}