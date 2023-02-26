#include <Servo.h>

Servo servo;

const int echo = 8;
const int trig = 7;

int mesafe;
int sure;

int a=0,i=0;
void setup()
{
  Serial.begin(9600);
  servo.attach(9);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = (sure / 29.1) / 2;

  if (mesafe <= 5) {
    for(int a=90;a>=0;a-=1){
      servo.write(a);
      delay(10);
    }
    a=0;
  //  servo.write(50);
    delay(5000);
  }
  else {
 if(a<90){
    kapat();
  }

//  servo.write(110);
  }

  if (mesafe > 200)
    mesafe = 200;
  Serial.print("mesafe");
  Serial.println(mesafe);
  delay(500);
}

void kapat(){
    
    for(i=0;i<=90;i+=1){
      
        servo.write(i);
        
        delay(10);
      }
      a=i;
}