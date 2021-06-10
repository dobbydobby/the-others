int message;                 // message라는 변수를 선언
void setup() {
  Serial.begin(9600);       // 시리얼 통신을 시작하며 통신속도는 9600
  pinMode(5, OUTPUT);        // 디지털 5번핀을 출력모드로 설정
  pinMode(6, OUTPUT);        // 디지털 6번핀을 출력모드로 설정
  pinMode(7, OUTPUT);        // 디지털 7번핀을 출력모드로 설정
  digitalWrite(5, LOW);      // 디지털 5번핀에 LOW 신호를 출력
  digitalWrite(6, LOW);      // 디지털 6번핀에 LOW 신호를 출력
  digitalWrite(7, LOW);      // 디지털 7번핀에 LOW 신호를 출력
}
void loop() {
  if (Serial.available() > 0) {               // 만약 시리얼 통신으로 데이터가 수신되면
    message = Serial.read();                  // 수신받은 데이터를 변수 message에 대입하고
    switch (message) {                        // switch (case)함수의 매개 변수로 사용
      case 0: digitalWrite(5, LOW); break;    // 데이터 0을 받으면 5번에 LOW
      case 1: digitalWrite(5, HIGH); break;   // 데이터 1을 받으면 5번에 HIGH
      case 2: digitalWrite(6, LOW); break;    // 데이터 2을 받으면 6번에 LOW
      case 3: digitalWrite(6, HIGH); break;   // 데이터 3을 받으면 6번에 HIGH
      case 4: digitalWrite(7, LOW); break;    // 데이터 4을 받으면 7번에 LOW
      case 5: digitalWrite(7, HIGH); break;   // 데이터 5을 받으면 7번에 HIGH
    }
  }
}
