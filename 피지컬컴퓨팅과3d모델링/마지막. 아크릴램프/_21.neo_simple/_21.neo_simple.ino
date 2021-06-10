#include <SoftwareSerial.h>        // 소프트웨어 시리얼 라이브러리를 포함
#include <Adafruit_NeoPixel.h>   // 네오픽셀 라이브러리를 포함
#define PIN 7
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(2, PIN, NEO_GRB + NEO_KHZ800);
SoftwareSerial bluetooth(2, 3);    // 디지털 2,3번 핀을 시리얼 통신 핀으로 설정
void setup() {
  pixels.begin(); 
  pixels.show();
  bluetooth.begin(9600);
}
byte r = 0, g = 0, b = 0;
void loop() {
  if (bluetooth.available() > 2) {       // 만약 2개가 넘는 데이터를 받는다면
    r = bluetooth.read();                    // r, g, b에 각각의 데이터를 대입
    g = bluetooth.read();
    b = bluetooth.read();
    bluetooth.flush();                         // 데이터가 전송완료될 때까지 대기
    pixels.setPixelColor(0, pixels.Color(r, g, b));     // 1번째 네오픽셀 설정
    pixels.setPixelColor(1, pixels.Color(r, g, b));     // 2번째 네오픽셀 설정
    pixels.show();
  }
}
