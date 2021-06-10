int val = 0;                           // 정수형 변수 val을 만들고 0을 대입합니다.

void setup() {
  pinMode(2, INPUT);          // 디지털 2번핀을 입력모드로 설정합니다.
  pinMode(3, OUTPUT);      // 디지털 3번핀을 입력모드로 설정합니다.
  Serial.begin(9600);          // 시리얼 통신을 시작하며, 통신속도는 9600
}

void loop() {
  val = digitalRead(2);
  if (val == HIGH) {                      // 만약 val과 HIGH가 같아진다면
    digitalWrite(3, HIGH);       // 디지털 3번핀에 HIGH신호를 출력합니다.
  }
  else {
    digitalWrite(3, LOW);         // 디지털 3번핀에 LOW신호를 출력합니다.
  }
  Serial.println(val);                     // 시리얼 모니터에 val값을 출력합니다.
}



