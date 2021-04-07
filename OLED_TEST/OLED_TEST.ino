// Must match baud on the serial monitor
#define BAUD_RATE 9600

// https://github.com/adafruit/Adafruit_SSD1327
// https://github.com/adafruit/Adafruit-GFX-Libraryc
// https://github.com/adafruit/Adafruit_BusIO
// These libraries need to be downloaded and installed manually.
#include <Adafruit_SSD1327.h>
// Used for software SPI
#define OLED_CLK 13
#define OLED_MOSI 11
// Used for software or hardware SPI
#define OLED_CS 10
#define OLED_DC 8
// Used for I2C or SPI
#define OLED_RESET -1
// I2C must be used to connect the OLED screen
Adafruit_SSD1327 display(96, 96, &Wire, OLED_RESET, 1000000);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] = {
	B00000000, B11000000,
	B00000001, B11000000,
	B00000001, B11000000,
	B00000011, B11100000,
	B11110011, B11100000,
	B11111110, B11111000,
	B01111110, B11111111,
	B00110011, B10011111,
	B00011111, B11111100,
	B00001101, B01110000,
	B00011011, B10100000,
	B00111111, B11100000,
	B00111111, B11110000,
	B01111100, B11110000,
	B01110000, B01110000,
	B00000000, B00110000};

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
    if (!display.begin(0x3D)) {
        Serial.println("Unable to initialize OLED test");
        Serial.println("-====-====-====-====-");
        Serial.println("Please reset the board");
        Serial.println("-====-====-====-====-");
        while (1) yield();
    }
	
	Serial.println("OLED initialized!");
	Serial.println("-====-====-====-====-");
}

void testOLED() {
	unsigned long startTime = millis();
	
    Serial.println("Started OLED draw test");
    Serial.println("-====-====-====-====-");
    testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);
	Serial.println("Finnished OLED draw test");
    Serial.println("-====-====-====-====-");
	
	unsigned long endTime = millis() - startTime;
	Serial.print("Time taken for test OLED (ms): ");
	Serial.println(endTime);
	Serial.println("-====-====-====-====-");
}

void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) {
    uint8_t icons[NUMFLAKES][3];
    randomSeed(1337); // whatever seed

    // initialize
    for (uint8_t f = 0; f < NUMFLAKES; f++) {
        icons[f][XPOS] = random(display.width());
        icons[f][YPOS] = 0;
        icons[f][DELTAY] = random(5) + 1;

        Serial.print("x: ");
        Serial.print(icons[f][XPOS], DEC);
        Serial.print(" y: ");
        Serial.print(icons[f][YPOS], DEC);
        Serial.print(" dy: ");
        Serial.println(icons[f][DELTAY], DEC);
		Serial.println("-====-====-====-====-");
    }

    while (1) {
        // draw each icon
        for (uint8_t f = 0; f < NUMFLAKES; f++) {
            display.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, f + 1);
        }
        display.display();
        delay(200);

        // then erase it + move it
        for (uint8_t f = 0; f < NUMFLAKES; f++) {
            display.drawBitmap(icons[f][XPOS], icons[f][YPOS], logo16_glcd_bmp, w, h, SSD1327_BLACK);
            // move it
            icons[f][YPOS] += icons[f][DELTAY];
            // if its gone, reinit
            if (icons[f][YPOS] > display.height()) {
                icons[f][XPOS] = random(display.width());
                icons[f][YPOS] = 0;
                icons[f][DELTAY] = random(5) + 1;
            }
        }
    }
}