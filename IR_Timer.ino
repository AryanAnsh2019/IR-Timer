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
boolean on = false;
unsigned long start, finished, elapsed, over;
float m, s, ms;
int i=1,temp;
void displayResult()
{
  lcd.clear();
  elapsed = start-temp;
  m = int(elapsed / 60000);
  over = elapsed % 60000;
  s = int(over / 1000);
  ms = over % 1000;
  lcd.print(m, 0);
  lcd.print(":");
  lcd.print(s, 0);
  lcd.print(":");
  lcd.print(ms, 0);
}
int in = 1, j;
void loop()
{
  lcd.clear();
  if (digitalRead(23) == 0)
  {
    if (on == true)
    {
      on = false;
    }
    else
    {
      on = true;
      lcd.setCursor(1,0);
      lcd.print("Starting timer");
      delay(1000);
      for (j = 10; j >= 0; j--)
      {
        lcd.clear();
        lcd.setCursor(7, 1);
        lcd.print(j);
        delay(1000);
      }
    }
    delay(200);
  }
  if (on == true)
  {
    start = millis();
    if(in==1)
    {
      temp=start;
      in=2;
    }
    displayResult();
    i = 0;
  }
  if (on == false && i == 0)
  {
    Serial.println("Hi");
    displayResult();
    ESP.restart();
  }
  delay(200);
}
