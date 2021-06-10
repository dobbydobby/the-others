void setup() {
  pinMode(5, OUTPUT);  // 디지털 3번핀을 출력모드로 설정.
  pinMode(6, INPUT);  // 디지털 6번핀을 입력모드로 설정.
  pinMode(7, INPUT);  // 디지털 7번핀을 입력모드로 설정.
  pinMode(8, INPUT);  // 디지털 8번핀을 입력모드로 설정.
  pinMode(9, INPUT);  // 디지털 9번핀을 입력모드로 설정.
  pinMode(10, INPUT);  // 디지털 10번핀을 입력모드로 설정.
  pinMode(11, INPUT);  // 디지털 11번핀을 입력모드로 설정.
  pinMode(12, INPUT);  // 디지털 12번핀을 입력모드로 설정.
  pinMode(13, INPUT);  // 디지털 13번핀을 입력모드로 설정.
}

void loop() {
  if (digitalRead(13) == HIGH) {    // 만약 13번핀에 HIGH신호가 입력되면
    tone (5, 523.3);             // 3번핀에 주파수 신호 361.6을 출력
  }
  else if (digitalRead(12) == HIGH) {   // 그게아니라 12번에 HIGH 신호가 입력되면
    tone (5, 493.9);            // 3번핀에 주파수 신호 393.7을 출력
  }
  else if (digitalRead(11) == HIGH) {      // 이하 생략
    tone (5, 440.0);
  }
  else if (digitalRead(10) == HIGH) {
    tone (5, 392.0);
  }
  else if (digitalRead(9) == HIGH) {
    tone (5, 349.2);
  }
  else if (digitalRead(8) == HIGH) {
    tone (5, 329.6);
  }
  else if (digitalRead(7) == HIGH) {
    tone (5, 290.1);
  }
  else if (digitalRead(6) == HIGH) {
    tone (5, 261.6);
  }
  else {
    noTone(5);
  }
}

