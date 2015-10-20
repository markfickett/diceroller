#include <Adafruit_SoftServo.h>

#define PIN_STATUS_LED 0
#define PIN_SERVO 2
#define PIN_PICTURE 1

// Usable range is around [-30, 200].
#define ANGLE_SHAKE -30
#define ANGLE_UPRIGHT 195

#define DELAY_PREPARE_MS  1000
#define DELAY_SETTLE_MS   2000
#define DELAY_PICTURE_MS  1000
#define MOVE_INTERVAL_MS  20

#define SERVO_UPDATE_INTERVAL_MS 20

Adafruit_SoftServo servo;

void setup() {
  servo.attach(PIN_SERVO);
  servo.write(ANGLE_UPRIGHT);
  pinMode(PIN_PICTURE, OUTPUT);
  pinMode(PIN_STATUS_LED, OUTPUT);
}

void loop() {
  for (int angle = ANGLE_UPRIGHT; angle > ANGLE_SHAKE; angle -= 20) {
    servo.write(angle);
    servo.refresh();
    delay(MOVE_INTERVAL_MS);
  }
  moveServo(ANGLE_SHAKE);
  digitalWrite(PIN_STATUS_LED, HIGH);
  delay(DELAY_PREPARE_MS);
  digitalWrite(PIN_STATUS_LED, LOW);

  moveServo(ANGLE_UPRIGHT);
  delay(DELAY_SETTLE_MS);

  digitalWrite(PIN_STATUS_LED, HIGH);
  digitalWrite(PIN_PICTURE, HIGH);
  delay(DELAY_PICTURE_MS); // No servo updates: avoid shaking.
  digitalWrite(PIN_PICTURE, LOW);
  digitalWrite(PIN_STATUS_LED, LOW);
}

// Set the new servo angle and refresh it / wait for it to catch up.
void moveServo(int newAngle) {
  servo.write(newAngle);
  for (int i = 0; i < 10; i++) {
    servo.refresh();
    delay(MOVE_INTERVAL_MS);
  }
}
