#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() 
{
  pinMode(23, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
boolean on=false;
unsigned long start,finished,elapsed,over;
float m,s,ms;
void displayResult()
{
  //Serial.println("c");
  //lcd.clear();
  lcd.init();
  lcd.backlight();
  elapsed = start;
  //h=int(elapsed/360000);
  //over=elapsed%360000;
  m = int(elapsed / 60000);
  over = elapsed % 60000;
  s = int(over / 1000);
  ms = over % 1000;
  //lcd.setCursor(0,0);
  //lcd.print("0");
  lcd.print(m,0);
  //Serial.println(m);
  //lcd.setCursor(2,0);
  lcd.print(":");
  //lcd.setCursor(3,0);
  lcd.print(s,0);
  lcd.print(":");
  lcd.print(ms,0);
  //delay(500);
}
int i=1;
void loop()
{
  // put your main code here, to run repeatedly:
  if(digitalRead(23)==0)
  {
    //Serial.println(digitalRead(23));
    //delay(1000);
    //Serial.println("go");
    if(on==true)
    {
      //Serial.println("a");
      on=false;
    }
    else
    {
      //Serial.println("w");
      on=true;
    }
  }
  if(on==true)
  {
    //Serial.println("x");
    //digitalWrite(2, HIGH);
    start=millis();
    //lcd.print(start);
    i=0;
  }
  if(on==false&&i==0)
  {
    //Serial.println("b");
    //digitalWrite(2,LOW);
    //Serial.println(start);
    //delay(200);
    displayResult();
  }
  /*Serial.println(start);
  delay(1200);
  Serial.println(finished);
  delay(1200);
  Serial.println(finished-start);*/
  //delay(500);
}
