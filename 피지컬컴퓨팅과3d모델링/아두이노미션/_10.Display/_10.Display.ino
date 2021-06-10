#include <LiquidCrystal.h>        // LiquidCrystal.h 라이브러리를 포함합니다.

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // LCD가 연결된 핀을 설정합니다.

void setup() {
  lcd.begin(16, 2);                      // LCD의 크기를 설정합니다.
  lcd.print("hello, world!");            // LCD에 문자 "hello, World!"를 출력합니다.
}

void loop() {
  lcd.noDisplay();      // 화면을 끕니다.
  delay(500);           // 0.5초 대기
  lcd.display();        // 화면을 켭니다.
  delay(500);           // 0.5초 대기
}

