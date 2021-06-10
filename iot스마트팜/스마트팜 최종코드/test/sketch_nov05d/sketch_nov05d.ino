#include<DHT.h>;
#define DHTPIN 9
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

float hum;    //습도변수
float temp;   //온도변수
int IN1 = 2;    //샤플로펌프
int IN2 = 3;    //샤플로펌프
int relay=12; 
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  delay(2000);
}

void loop() {
  int moisture = analogRead(A0);    // 토양수분센서로 센서값 읽기
  hum = dht.readHumidity();   //습도읽기
  temp = dht.readTemperature();   //온도읽기
  
  if (moisture > 700) {   //건조할 때
    
    if(temp > 27){   
      digitalWrite(IN1, HIGH);    //샤플로 펌프 동작
      digitalWrite(IN2, LOW);   
      digitalWrite(relay, LOW);
      Serial.print("Moisture;");
      Serial.println(moisture);
      Serial.print("Humidity: ");
      Serial.print(hum,0);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(temp, 1);
      Serial.println(" C");
      delay(1000);
      }
    else{
      digitalWrite(IN1, HIGH);    //샤플로 펌프 동작
      digitalWrite(IN2, LOW);   
      digitalWrite(relay, HIGH);    //쿨링팬 동작
      Serial.print("Moisture;");
      Serial.println(moisture);
      Serial.print("Humidity: ");
      Serial.print(hum,0);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(temp, 1);
      Serial.println(" C");
      delay(1000);      
      }    

    
    }
    else if(moisture <= 700){   //수분이 있을때
      if(temp > 27){
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(relay, LOW);    //쿨링팬 동작
      Serial.println(moisture);
      Serial.print("Humidity: ");
      Serial.print(hum,0);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(temp, 1);
      Serial.println(" C");      
      delay(1000);
      }
      else{
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(relay, HIGH);    //쿨링팬 동작
      Serial.println(moisture);
      Serial.print("Humidity: ");
      Serial.print(hum,0);
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.print(temp, 1);
      Serial.println(" C");      
      delay(1000);        
        }
      }

}
