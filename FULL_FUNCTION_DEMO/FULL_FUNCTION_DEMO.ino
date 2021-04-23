// Must match baud on the serial monitor
#define BAUD_RATE 9600
#define RAISE_MESSAGE "raise"
#define LOWER_MESSAGE "lower"

// Connect through a 100 Ohm resistor
#define BUZZER_PIN 5

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
#define SERVO_DEG_LOWERED_A 90
#define SERVO_DEG_RAISED_A 90
VarSpeedServo servo_A;
// Must be PWM Data pin
#define SERVO_PIN_B 10
#define SERVO_DEG_LOWERED_B 0
#define SERVO_DEG_RAISED_B 0
VarSpeedServo servo_B;

// https://github.com/olikraus/U8g2_Arduino
// These libraries need to be downloaded and installed manually.
#include <U8g2lib.h>
U8G2_SH1107_SEEED_128X128_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);

// The flashing crossing LED
#define LED_PIN LED_BUILTIN
void setup() {
	setupSerial();
	setupBuzzer();
	setupServos();
	setupOLED();
	setupLED();
}

void loop() {
	if (isTrainPresent()) {
		trainLoop();
	} else {
		Serial.println("Barrier is currently raised!");
		Serial.println("-====-====-====-====-");
		if (checkSerialMessageLower())
			trainLoop();
		delay(1000);
	}
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

void setupServos() {
	Serial.println("Setup servo A and reset to 0 deg");
	servo_A.attach(SERVO_PIN_A);
	servo_A.write(0, 255, true);
	Serial.println("Setup servo B and reset to 0 deg");
	servo_B.attach(SERVO_PIN_B);
	servo_B.write(0, 255, true);
	Serial.println("-====-====-====-====-");
}

void setupOLED() {
    u8g2.begin();
	Serial.println("OLED initialized!");
	Serial.println("-====-====-====-====-");
}

void setupLED() {
	pinMode(LED_PIN, OUTPUT);
}

bool checkSerialMessageLower() {
	if (!Serial.available())
		return false;
	String message = Serial.readString(); // Expects a string to be sent, followed by a \n (enter key)
	message = message.substring(0, message.length() - 1);
	
	return message == LOWER_MESSAGE;
}

bool checkSerialMessageRaise() {
	if (!Serial.available())
		return false;
	String message = Serial.readString(); // Expects a string to be sent, followed by a \n (enter key)
	message = message.substring(0, message.length() - 1);
	
	return message == RAISE_MESSAGE;
}

bool isTrainPresent() {
	return usSensor.dist() < 10; // Train trigger distance of 10cm
}

void trainLoop() {
	lowerBarrier();
	while(1) {
		Serial.println("Barrier Lowered!");
		Serial.println("-====-====-====-====-");
		angryFiveSecondDelay();
		if (checkSerialMessageRaise() || !isTrainPresent())
			break;
	}
	raiseBarrier();
	Serial.println("Barrier Raised!");
	Serial.println("-====-====-====-====-");
}

void lowerBarrier() {
	servo_A.write(SERVO_DEG_LOWERED_A, 255, true);
	servo_B.write(SERVO_DEG_LOWERED_B, 255, true);
}

void raiseBarrier() {
	servo_A.write(SERVO_DEG_RAISED_A, 255, true);
	servo_B.write(SERVO_DEG_RAISED_B, 255, true);
}

// Blinks the LED and Plays the buzzewr
void angryFiveSecondDelay() {
	// This will repeat five times.
	for (int i = 0; i < 5; i++) {
		tone(BUZZER_PIN, 600, 250); // 600 Hz tone for 250 ms
		digitalWrite(LED_PIN, HIGH);
		delay(500);
		digitalWrite(LED_PIN, LOW);
		delay(500);
	}
}