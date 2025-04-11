#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>
Servo servo;
MPU6050 mpu;

const int threshold = 122;
int previousGesture = -1;

void setup() {
Serial.begin(9600);
servo.attach(9);
pinMode(9, OUTPUT);
Wire.begin();
mpu.initialize();
}
void loop() {

int gesture = detectGesture();

    if (gesture != previousGesture) {
      
      if (gesture == 1) {
        Serial.println("Detected Gesture: Gesture 1");
        servo.write(45);
      // Perform an action for Gesture 1
      } else if (gesture == 2) {
        Serial.println("Detected Gesture: Gesture 2");
        servo.write(115);
      // Perform an action for Gesture 2
      } 
    }
// Add more gesture cases as needed
previousGesture = gesture;

}

int detectGesture() {
      int16_t ax, ay, az;
      int16_t gx, gy, gz;
      int pitch;
      mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
      pitch = map(ay, -17000, 17000, 0, 255);
      // Perform gesture recognition here based on sensor data
      // Define conditions to recognize specific gestures
      if (pitch >= threshold) {
      return 1; // Gesture 1
      } else if (pitch < threshold) {
      return 2; // Gesture 2
      }
      // Add more gesture conditions as needed
      return 0; // No gesture detected
}
