void setup() {
  Serial.begin(9600);
  Serial.println("Serial Started at 9600 Baud");
}

void loop() {
  delay(500);
  Serial.print("Current time is (ms): ");
  Serial.println(millis());
}
