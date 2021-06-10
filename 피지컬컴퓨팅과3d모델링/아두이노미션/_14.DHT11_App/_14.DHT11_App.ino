#include "DHT.h"                           // DHT.h 라이브러리를 포함합니다.
#define DHTPIN 2                         //  DHTPIN을 2로 설정합니다.
#define DHTTYPE DHT11            // DHTTYPE를 DHT11로 설정합니다.
DHT dht(DHTPIN, DHTTYPE);

void setup()  {
  Serial.begin(9600);                    // 시리얼 통신을 시작하며, 통신속도는 9600
}

void loop()  {
  delay(3000);                                             // 3초 대기
  int h = dht.readHumidity();                    // 변수 h를 선언하며 습도값을 대입
  int t = dht.readTemperature();             // 변수 t를 선언하며  온도값을   대입
  Serial.print("Humidity: ");                      // 시리얼 프린터에 출력 (이하생략)
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");
}
