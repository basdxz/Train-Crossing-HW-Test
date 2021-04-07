# Train-Crossing-HW-Test

![image](https://user-images.githubusercontent.com/5740991/113876901-178bac80-97b0-11eb-9599-59670538ccd8.png)

General use instructions:

1. Clone the git repository using: git clone https://github.com/basdxz/Train-Crossing-HW-Test
2. Go into the directory and copy the libraries directory into "C:\Users\<LOCAL_USER>\Documents\Arduino\libraries" and override any differences.
3. Open FULL_HW_TEST.ino in the Arduino IDE
4. Adjust pin numbers, in particular: BUZZER_PIN, IR_PIN_A, IR_PIN_B, SERVO_PIN_A and SERVO_PIN_B
5. Select the appropriate COM port
6. Upload the code to the Arduino Uno
7. Open the serial monitor and watch the test

What to do if things go wrong:

Each peripheral has it's own collection of tests, pick the test of the component that doesn't work and upload it.
Troubleshoot the Hardware/Software using the provided test.
