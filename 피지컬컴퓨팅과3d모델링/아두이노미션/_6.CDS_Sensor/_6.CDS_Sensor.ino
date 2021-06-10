int cds = 0;            // 변수 csd를 선언하고 0을 대입

void setup() {
  Serial.begin(9600);     // 시리얼 통신을 시작 (통신속도는 9600)
}

void loop() {
  cds = analogRead(A0);    // 변수 cds에 아날로그 A0에 입력되는 신호를 대입
  Serial.println(cds);    // 시리얼 모니터에 변수 cds 출력
  delay(100);              // 0.1초 대기
}

