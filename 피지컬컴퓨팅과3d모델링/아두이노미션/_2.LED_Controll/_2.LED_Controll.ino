
void setup() {
  pinMode(8, OUTPUT);          // 8번핀을 출력모드로 설정합니다.
}

void loop() {
  digitalWrite(8, HIGH);     // 8번핀에 HIGH 신호를 출력합니다.
  delay(1000);                    // 1초간 대기합니다.
  digitalWrite(8, LOW);     // 8번핀에 LOW 신호를 출력합니다.
  delay(1000);                   // 1초간 대기합니다.
}

