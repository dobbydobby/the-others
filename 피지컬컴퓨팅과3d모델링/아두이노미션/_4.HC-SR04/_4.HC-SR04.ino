int trig = 2;                  // trig에 2를 대입
int echo = 3;                             // echo에 3을 대입
void setup() {
  Serial.begin(9600);                   // 시리얼통신 시작, 통신속도는 9600
  pinMode(trig, OUTPUT);          // trig(2)핀을 출력모드로 설정
  pinMode(echo, INPUT);            //  echo(3)핀을 입력모드로 설정
}
void loop() {
  digitalWrite(trig, HIGH);                    //trig핀에 HIGH신호를 출력
  delayMicroseconds(10);                   // 10마이크로초 동안 대기
  digitalWrite(trig, LOW);                    // trig 핀에 LOW(0V)신호를 출력
  int distance = pulseIn(echo, HIGH) * 34 / 2 / 1000;
  Serial.print(distance);                       // distance를 시리얼 모니터에 출력
  Serial.println("cm");                           // 문자열 cm을 시리얼 모니터에 출력
  delay(100);
}


