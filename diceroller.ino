#define PIN_STATUS_LED 0
#define PIN_SERVO 2
#define PIN_PICTURE 1
#define PIN_COUNT 4

// Empirically, the shape of a histogram or roll results for a d20 seems to
// settle at/above 2k rolls, so stopping at 3k should produce good results.
// For a d6 it settles around 500-1000.
#define AUTO_STOP_COUNT_LONG 3000
#define AUTO_STOP_COUNT_SHORT 1000

// Usable range is around [-30, 200].
#define ANGLE_SHAKE -30
#define ANGLE_UPRIGHT 195

#define DELAY_PREPARE_MS  1000
#define DELAY_SETTLE_MS   2000
#define DELAY_PICTURE_MS  1000
#define MOVE_INTERVAL_MS  20

#define SERVO_UPDATE_INTERVAL_MS 20

uint16_t servoMicros;
uint16_t rollCount;
uint16_t maxRollCount;

void setup() {
  pinMode(PIN_SERVO, OUTPUT);
  setServoAngle(ANGLE_UPRIGHT);
  pinMode(PIN_PICTURE, OUTPUT);
  pinMode(PIN_STATUS_LED, OUTPUT);
  pinMode(PIN_COUNT, INPUT_PULLUP);

  maxRollCount = digitalRead(PIN_COUNT) ?
      AUTO_STOP_COUNT_LONG : AUTO_STOP_COUNT_SHORT;
  rollCount = 0;
}

void loop() {
  for (int angle = ANGLE_UPRIGHT; angle > ANGLE_SHAKE; angle -= 20) {
    setServoAngle(angle);
    refreshServo();
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

  if (++rollCount > maxRollCount) {
    cli(); // stop interrupts
    while (true);
  }
}

// Set the new servo angle and refresh it / wait for it to catch up.
void moveServo(int newAngle) {
  setServoAngle(newAngle);
  for (int i = 0; i < 10; i++) {
    refreshServo();
    delay(MOVE_INTERVAL_MS);
  }
}

void setServoAngle(int angle) {
  servoMicros = max(0, map(angle, 0, 180, 1000, 2000));
}

void refreshServo() {
  digitalWrite(PIN_SERVO, HIGH);
  delayMicroseconds(servoMicros);
  digitalWrite(PIN_SERVO, LOW);
}
