// Must match baud on the serial monitor
#define BAUD_RATE 9600

// https://github.com/netlabtoolkit/VarSpeedServo
// This library needs to be downloaded and installed manually.

#include <VarSpeedServo.h>
// Must be PWM Data pin
#define SERVO_PIN_A 9
VarSpeedServo servo_A;
// Must be PWM Data pin
#define SERVO_PIN_B 10
VarSpeedServo servo_B;

void setup() {
	setupSerial();
	setupServos();
	testServos();
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

void setupServos() {
	unsigned long startTime = millis();
	
	Serial.println("Setup servo A and reset to 0 deg");
	servo_A.attach(SERVO_PIN_A);
	servo_A.write(0, 255, true);
	
	Serial.println("Setup servo B and reset to 0 deg");
	servo_B.attach(SERVO_PIN_B);
	servo_B.write(0, 255, true);
	
	unsigned long endTime = millis() - startTime;
	Serial.print("Time taken to Setup servos (ms): ");
	Serial.println(endTime);
	
	Serial.println("-====-====-====-====-");
}

void testServos() {
	Serial.println("Starting servo test");
	for (int i = 0; i < 4; i++) {
		delay(500);   
		unsigned long startTime = millis();
		
		testServoA();
		testServoB();
		
		unsigned long endTime = millis() - startTime;
		Serial.print("Time taken for test run (ms): ");
		Serial.println(endTime);
		Serial.println("-====-====-====-====-");
	}
	Serial.println("Finished servo test");
	Serial.println("-====-====-====-====-");
}

void testServoA() {
	Serial.println("Moving servo A to 180 deg");
	servo_A.write(180, 255, true);
	Serial.println("Moving servo A back to 0 deg");
	servo_A.write(0, 30, true);
	Serial.println("-====-====-====-====-");
}

void testServoB() {
	Serial.println("Moving servo B to 180 deg");
	servo_B.write(180, 255, true);
	Serial.println("Moving servo B back to 0 deg");
	servo_B.write(0, 30, true);
	Serial.println("-====-====-====-====-");
}