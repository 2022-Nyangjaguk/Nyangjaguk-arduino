
int trig = 8;
int echo = 9;

// #define RedLight 5;

int RedLight = 5;
int YellowLight = 4;
int GreenLight = 3;

void setup() {
  Serial.begin(9600); // 초음파 센서 동작 상태 확인을 위한 시리얼 통신 설정

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(RedLight, OUTPUT);
  pinMode(YellowLight, OUTPUT);
  pinMode(GreenLight, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);

  // 초음파 속도는 초당 340미터를 이동하거나 29마이크로초 당 1센치 이동
  // 따라서 초음파의 이동 거리 = duration(왕복에 걸린 시간) / 29 / 2
  float distance = duration / 29.0 / 2.0;

  Serial.print(distance);
  Serial.print("cm\n");

  if(distance < 8) {
    digitalWrite(YellowLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(RedLight, HIGH);

    Serial.println("쓰레기가 거의 찼습니다!");
  }
  else if(distance < 16) {
    digitalWrite(RedLight, LOW);
    digitalWrite(GreenLight, LOW);
    digitalWrite(YellowLight, HIGH);

    Serial.println("쓰레기가 반 이상 찼습니다!");
  }
  else {
    digitalWrite(RedLight, LOW);
    digitalWrite(YellowLight, LOW);
    digitalWrite(GreenLight, HIGH);

    Serial.println("쓰레기가 거의 차지 않았습니다");
  }
  delay(10000);
}
