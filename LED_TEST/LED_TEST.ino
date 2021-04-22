// Must match baud on the serial monitor
#define BAUD_RATE 9600

// https://github.com/lpasqualis/TimedBlink
// This library needs to be downloaded and installed manually.
#include <TimedBlink.h>
// The flashing crossing LED
#define LED_PIN LED_BUILTIN
TimedBlink led(LED_PIN);

void setup() {
	setupSerial();
	setupLED();
	setupTimer();
}

void loop() {
	loopLED();
}

void setupLED() {
	pinMode(LED_PIN, OUTPUT);
}

void setupTimer() {
	TCCR1A = 0;
	TCCR1B = 0;
	bitSet(TCCR1B, CS10);
	bitSet(TCCR1B, CS11);  // 64 prescaler
	bitSet(TIMSK1, TOIE1); // timer overflow interrupt
}

// This Routine runs once every ~1.005s seconds
ISR(TIMER1_OVF_vect) {
	led.blink();
}

void loopLED() {
	Serial.println("Started Flashing LED");
	Serial.println("-====-====-====-====-");
	led.blink(500, 500); // 500ms on, 500ms off
	delay(4000);
	led.blinkOff();
	Serial.println("Stopped Flashing LED");
	Serial.println("-====-====-====-====-");
	delay(4000);
}