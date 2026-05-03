#include <ESP32Servo.h> // ESP32 전용 라이브러리

Servo SV;

int trig = 5;  
int echo = 18;
int servoPin = 19; 

void setup() {
    Serial.begin(115200); // 디버깅용 시리얼 통신
    SV.attach(servoPin); 
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

void loop() { 
    digitalWrite(trig, LOW); // 초음파 센서 초기화
    delayMicroseconds(2);
    digitalWrite(trig, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long duration = pulseIn(echo, HIGH);
    long distance = duration * 0.034 / 2;

    if (distance > 0 && distance <= 10) { // 비정상 거리(0) 제외
        SV.write(100); 
        delay(3000);
    } 
    else {
        SV.write(50);
    }
    delay(100); // CPU 부하를 줄이기 위한 짧은 대기
}