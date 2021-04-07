// Must match baud on the serial monitor
#define BAUD_RATE 9600

// https://github.com/guillaume-rico/SharpIR
// This library needs to be downloaded and installed manually.
#include <SharpIR.h>
// A is the 4 to 30 CM distance sensor
#define IR_PIN_A A0
// For Model SHARP GP2Y0A41SK0F
#define MODEL_A 430
SharpIR irSensor_A(IR_PIN_A, MODEL_A);
// B is the 100 to 550 CM distance sensor
#define IR_PIN_B A1
// For Model SHARP GP2Y0A710K0F
#define MODEL_B 100550
SharpIR irSensor_B(IR_PIN_B, MODEL_B);

void setup() {
	setupSerial();
	testIRSensors();
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

void testIRSensors() {
	Serial.println("Starting IR distance sensors test");
	Serial.println("-====-====-====-====-");
	for (int i = 0; i < 10; i++) {
		delay(500);   
		unsigned long startTime = millis();

		testIRSensorA();
		testIRSensorB();
  
		unsigned long endTime = millis() - startTime;
		Serial.print("Time taken to sample distance (ms): ");
    	Serial.println(endTime);
		Serial.println("-====-====-====-====-");
	}
	Serial.println("Finished IR distance sensors test");
	Serial.println("-====-====-====-====-");
}

void testIRSensorA() {
	Serial.print("Sensor A distance (cm): ");
	Serial.println(irSensor_A.distance());
}

void testIRSensorB() {
	Serial.print("Sensor B distance (cm): ");
	Serial.println(irSensor_B.distance());
}