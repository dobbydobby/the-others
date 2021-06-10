int a = 30;                                      // 정수형 변수 a를 만들고 30을 대입

void setup() {
  Serial.begin(9600);               // 시리얼통신을 시작. 통신속도는 9600
}

void loop() {
  Serial.println(a);                                       // 시리얼모니터에 a를 출력
  Serial.println("Hellow, World!");            // 시리얼모니터에 “~”를 출력
  delay(1000);                                            // 1초 대기
}
