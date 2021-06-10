void setup() {
  pinMode(3, OUTPUT);             // 디지털 3번핀을 출력모드로 설정
}

void loop() {
  for (int i = 10; i < 255; i + 10) {     // for 반복문 (초기식; 조건식; 증감식)
    analogWrite(3, i);                         // 3번핀에 i만큼의 신호 출력
    delay(100);                                   // 0.1초 대기
  }
}
