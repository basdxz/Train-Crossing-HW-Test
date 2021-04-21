// Must match baud on the serial monitor
#define BAUD_RATE 9600

// Connect through a 100 Ohm resistor
#define BUZZER_PIN 5

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

// https://github.com/gamegine/HCSR04-ultrasonic-sensor-lib
// This library needs to be downloaded and installed manually.
#include <HCSR04.h>
// Connect to pin marked as TRIG
#define SONIC_TRIGGER_PIN 2
// Connect to pin marked as ECHO
#define SONIC_ECHO_PIN 3
HCSR04 usSensor(SONIC_TRIGGER_PIN, SONIC_ECHO_PIN);

// https://github.com/netlabtoolkit/VarSpeedServo
// This library needs to be downloaded and installed manually.
#include <VarSpeedServo.h>
// Must be PWM Data pin
#define SERVO_PIN_A 9
VarSpeedServo servo_A;
// Must be PWM Data pin
#define SERVO_PIN_B 10
VarSpeedServo servo_B;

// https://github.com/olikraus/U8g2_Arduino
// These libraries need to be downloaded and installed manually.
#include <U8x8lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
U8X8_SH1107_128X128_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
void setup() {
	// Serial Comms
	setupSerial();
	testSerialRead();
	// Buzzer buzzing
	setupBuzzer();
	testBuzzer();
	// IR Distance read outs (Disabled)
	//testIRSensors();
	// US Distance read outs
	testUSSensor();
	// Servo Movement
	setupServos();
	testServos();
	// OLED Graphics Display
	setupOLED();
	testOLED();
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
	delay(500);
	Serial.println("Testing serial read");
	Serial.println("-====-====-====-====-");
	Serial.println("Waiting for user string");
	Serial.println("-====-====-====-====-");
	while (!Serial.available());
	Serial.print("User string was: ");
	Serial.print(Serial.readString()); // Expects a string to be sent, followed by a \n (enter key)
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

void setupOLED() {
    u8x8.begin();
	Serial.println("OLED initialized!");
	Serial.println("-====-====-====-====-");
}

void testOLED() {
	unsigned long startTime = millis();
	
    Serial.println("Started OLED draw test");
    Serial.println("-====-====-====-====-");
    u8x8.setFont(u8x8_font_chroma48medium8_r);
	u8x8.drawString(0,0,"Hello World!");
	Serial.println("Finnished OLED draw test");
    Serial.println("-====-====-====-====-");
	
	unsigned long endTime = millis() - startTime;
	Serial.print("Time taken for test OLED (ms): ");
	Serial.println(endTime);
	Serial.println("-====-====-====-====-");
}