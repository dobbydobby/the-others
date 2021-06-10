int relay2= 6;    //Led

void setup() {

  

  Serial.begin(9600);
  pinMode(relay2, OUTPUT);
   

}

void loop() {
  sun(10, 10);    //10초켜지고 10초 꺼지고 만약1분을 하고싶으면 차후에 60으로 수정
  

}
void sun(int on_sec, int off_sec)
{
  
  digitalWrite (relay2, HIGH);
  delay(28800000);
  digitalWrite(relay2, LOW);
  }
