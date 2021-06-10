int val = 0;

void setup() {
  Serial.begin(9600);            // 시리얼 통신을 시작하며 속도는 9600으로 설정
  pinMode(2, INPUT);            // 디지털 2번핀을 입력모드로 설정
}
void loop() {
  val = digitalRead(2);          // 변수 val에 디지털 2번핀에 입력되는 값을 대입
  Serial.println(val);             // 시리얼 모니터에 변수 val 값 출력
  delay(300);                        // 0.3초 대기
}
