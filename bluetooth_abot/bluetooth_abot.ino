#include <Servo.h>
Servo sr, sl;
void setup() {
  Serial.begin(9600);
  sr.attach(13);
  sl.attach(12);
}
void loop() {
  if (Serial.available()) {
    char b[2];  //pitch b[0], roll b[1]
    int p, r;
    Serial.readBytes(b, 2);
    p = b[0] * 3;  // 피치값 -90~0~90, 전 후진  // 1500-270 ~ 1500+270
    r = b[1];  // 롤 값 -90~0~90, 좌 우회전  // 1500-90 ~ 1500+90
    sr.write(1500 + p - r);
    sl.write(1500 - p - r);
    Serial.write('1');  // 읽었음을 확인하는 값
  }
}