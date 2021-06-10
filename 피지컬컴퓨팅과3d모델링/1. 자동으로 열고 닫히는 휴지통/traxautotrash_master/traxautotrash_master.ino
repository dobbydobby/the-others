#include <Servo.h>

Servo SV; //서보모터 객체 생성

int trig = 8; //tring핀에 연결된 8(데이터핀) trig 변수에 저장
int echo = 9; //ehco핀에 연결된 9(데이터핀) echo 변수에 저장

void setup(){
  SV.attach(10);  //서보모터 핀번호를 10으로 설정
  pinMode(trig, OUTPUT); //trig 출력으로 설정
  pinMode(echo, INPUT); //echo 입력으로 설정
  }
  
void loop(){
  digitalWrite(trig, HIGH); //초음파 내보내기
  delayMicroseconds(10);   //10에서 2로 바꿈
  digitalWrite(trig, LOW);  //초음파 멈추기 
  long duration = pulseIn (echo, HIGH);
  //echo핀에 초음파가 들어왔을 때의 시간을 측정하여 duration 변수에 저장 
  
  long distance = (340*duration)/2/10000;
  //거리를 계산하여 distance 변수에 저장
  
  if (distance <= 10) {
    //초음파센서와의 거리가 10cm 이하라면
    SV.write(100); //100도로 회전
    delay(3000);    //3초대기
    }else {//초음파 센서와의 거리가 10 cm보다 크다면
    SV.write(10); //10도로 회전
   }
  } 
