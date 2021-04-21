// Must match baud on the serial monitor
#define BAUD_RATE 9600

// https://github.com/olikraus/U8g2_Arduino
// These libraries need to be downloaded and installed manually.
#include <U8x8lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
U8X8_SH1107_128X128_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
    setupSerial();
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