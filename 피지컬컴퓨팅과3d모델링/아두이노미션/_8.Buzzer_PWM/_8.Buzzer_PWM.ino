void setup() {
  pinMode(5, OUTPUT);                                // 5번핀을 출력모드로 설정
}
void loop() {
  tone(5, 1046.5);                                             //도
  delay(200); noTone(5); delay(200);
  tone(5, 1244.5);                                             //레
  delay(200); noTone(5); delay(200);
  tone(5, 1318.5);                                             //미
  delay(200); noTone(5); delay(200);
  tone(5, 1397.0);                                             //파
  delay(200); noTone(5); delay(200);
}
