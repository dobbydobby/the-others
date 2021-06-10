int message;    //message라는 변수 선언

void setup() {
  Serial.begin(9600);   //시리얼통신 시작하여 통신속도 9600으로 설정
  pinMode(5, OUTPUT);   //디지털 5번핀을 출력모드로
  pinMode(6, OUTPUT);   //디지털 6번핀을 출력모드로
  pinMode(7, OUTPUT);   //디지털 7번핀을 출력모드로
  digitalWrite(5, LOW);   //디지털 5번 핀에 LOW신호 출력
  digitalWrite(6, LOW);   //디지털 5번 핀에 LOW신호 출력
  digitalWrite(7, LOW);   //디지털 5번 핀에 LOW신호 출력
}

void loop() {
  if(Serial.available() >0) {   //만약 시리얼통신으로 데이터가 수신되면
    message = Serial.read();    //수신받은 데이터를 변수 message 에 넣고
    switch(message){    //switch(case)함수의 매개변수로 사용
      case 0: digitalWrite(5, LOW); break;    //데이터 0을 받으면 5번핀에 LOW
      case 1: digitalWrite(5, HIGH);  break;    //데이터 1을 받으면 5번핀에 HIGH
      case 2: digitalWrite(6, LOW); break;    //데이터 2를 받으면 6번핀에 LOW
      case 3: digitalWrite(6, HIGH); break;   //데이터 3을 받으면 6번핀에 HIGH
      case 4: digitalWrite(7, LOW); break;    //데이터 4를 받으면 7번핀에 LOW
      case 5: digitalWrite(7, HIGH); break;   //데이터 5를 받으면 7번핀에 HIGH
      }
    }
}
