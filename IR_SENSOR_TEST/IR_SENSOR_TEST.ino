// https://github.com/guillaume-rico/SharpIR
// This library needs to be downloaded and installed manually.

#include <SharpIR.h>
// A is the 4 to 30 CM distance sensor
#define IR_PIN_A A0
// For Model SHARP GP2Y0A41SK0F
#define MODEL_A 430
SharpIR IR_SENSOR_A(IR_PIN_A, MODEL_A);

// B is the 100 to 550 CM distance sensor
#define IR_PIN_B A1
// For Model SHARP GP2Y0A710K0F
#define MODEL_B 100550
SharpIR IR_SENSOR_B(IR_PIN_B, MODEL_B);

void setup() {
  Serial.begin(9600);
}

void loop() {
  testIRSensors();
}

void testIRSensors() {
  for (int i = 0; i < 10; i++) {
    delay(500);   
    unsigned long startTime = millis();

    testIRSensorA();
    testIRSensorB();
  
    unsigned long endTime = millis() - startTime;
    Serial.print("Time taken to sample (ms): ");
    Serial.println(endTime); 
  }
}

void testIRSensorA() {
  Serial.print("Sensor A Distance (cm): ");
  Serial.println(IR_SENSOR_A.distance());
}

void testIRSensorB() {
  Serial.print("Sensor B Distance (cm): ");
  Serial.println(IR_SENSOR_B.distance());
}
