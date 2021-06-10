#include <DHT.h>    //DHT22 헤더파일
#include <LiquidCrystal_I2C.h>    //Lcd 헤더파일

#define DHTPIN 9    //DHT22 핀설정
#define DHTTYPE DHT22   //DHT22 (AM2302)
DHT dht(DHTPIN, DHTTYPE);   //DHT 타입 설정
LiquidCrystal_I2C lcd(0x27, 16, 2);   //Lcd 설정

//---변수정의---
float hum;    //습도변수
float temp;   //온도변수
int IN1= 2;   //샤플로펌프1
int IN2= 3;   //샤플로펌프2
int ena=1;  
int relay= 8;   //팬
int relay2= 6;    //Led
int relay3= 5;   //열선
int Moisture;
int count = 1;
int i1, i2;
byte t[8] = {   //Lcd에 사용할 특수문자 만들기
  B01000,
  B10100,
  B01000,
  B00000, 
  B00000,
  B00000,
  B00000,
  B00000
  };

//------각각 함수 만들기
void pump(void);
void fan(void);
void screen(void);
void sun(int on_sec, int off_sec);
void lcd_print(void);
void heating(int lowTemp);

//----각각 핀당 출력지정
void setup() {
  pinMode(IN1, OUTPUT);   //IN1 핀 출력설정
  pinMode(IN2, OUTPUT);   //IN2 핀 출력설정
  Serial.begin(9600);   //시리얼 보드레이트 설정
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  dht.begin();
  lcd.init();
  lcd. backlight();
  lcd.createChar(0, t);
  delay(2000);
}

//----loop문에서 각 센서값을 읽어들이기, 각각의 함수실행

void loop() {
  Moisture = analogRead(A0);    
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  pump();
  fan();
  heating(21);    //heating의 관호안의 숫자 이하로 떨어지면 동작
  sun(10, 10);    //10초켜지고 10초 꺼지고 만약1분을 하고싶으면 차후에 60으로 수정
  screen();   //Serial 모니터 출력 없어도 됨
  lcd_print();

}

//-------워터펌프 제어함수
void pump(void)
{
  if(Moisture > 700){   //건조할때
    digitalWrite(IN1, HIGH);    
    digitalWrite(IN2, LOW);
    //digitalWrite(ena, 255);   //ena모터의 토크를 225로 회전
  }
  else{    //그외 정지
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
   // digitalWrite(ena, 255);
    }  
  }

//-----DV쿨링팬 제어 함수
void fan(void)
{
  if(temp > 25){    //온도가28도 이상일떼 realy에 HIGH신호를 주어 동작
    digitalWrite(relay, HIGH);
    }else{    //그외 정지
      digitalWrite(relay, LOW);
      }
  }

//----열선 제어 함수
void heating(int lowTemp)
{
  if(temp < lowTemp) digitalWrite(relay3, LOW);   //온도 값이 lowTemp 루프에서 heating안의 숫자이하가 되면 릴레이에 LOW 신호를 주어 동작
  else digitalWrite(relay3, HIGH);    //그외엔 HIGH
  }

//Led제어 함수
void sun(int on_sec, int off_sec)
{
  if(count==1){
    i1 = on_sec;
    i2 = off_sec;
    count--;
    }
    if(i1 > 0){
      i2 = off_sec;
      i1 = on_sec;
      }
      delay(1000);
  }

void screen(void)
{
  Serial.print(" Moisture : ");
  Serial.print(Moisture);
  Serial.print("Humidity: ");
  Serial.print(hum,0);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temp, 1);
  Serial.println(" C");
  }

void lcd_print(void)
{
  int mos = 100 - map(Moisture, 0, 1024, 0, 100);
  lcd.setCursor(0,0);
  lcd.print("Temp ; ");
  lcd.print(temp, 1);
  lcd.write(byte(0));
  lcd.setCursor(0,1);
  lcd.print("Moistue : ");
  lcd.print(Moisture);
  lcd.print("%");
  }
