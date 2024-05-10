#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
LiquidCrystal lcd(8,9,10,11,12,13);

#define ldr1 A0
#define ldr2 A1
#define ldr3 A2
#define ldr4 A3
#define voltage A4
#define temp A5

#define ma1 7
#define ma2 6
#define mb1 5
#define mb2 4

int value1=0;
int value2=0;
int value3=0;
int value4=0;
int value5=0;
int value6=0;
int power;

void forward()
{
   digitalWrite(ma1, HIGH);
   digitalWrite(ma2, LOW);
   digitalWrite(mb1, LOW);
   digitalWrite(mb2, LOW);
}

void backward()
{
   digitalWrite(ma1, LOW);
   digitalWrite(ma2, HIGH);
   digitalWrite(mb1, LOW);
   digitalWrite(mb2, LOW); 
}

void left()
{
   digitalWrite(ma1, LOW);
   digitalWrite(ma2, LOW);
   digitalWrite(mb1, HIGH);
   digitalWrite(mb2, LOW);
}

void right()
{
   digitalWrite(ma1, LOW);
   digitalWrite(ma2, LOW);
   digitalWrite(mb1, LOW);
   digitalWrite(mb2, HIGH);
}

void Stop()
{
   digitalWrite(ma1, LOW);
   digitalWrite(ma2, LOW);
   digitalWrite(mb1, LOW);
   digitalWrite(mb2, LOW);
}

void setup() 
{
// put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
pinMode(ldr1,INPUT);
pinMode(ldr2,INPUT);
pinMode(ldr3,INPUT);
pinMode(ldr4,INPUT);
pinMode(voltage,INPUT);
pinMode(temp,INPUT);
pinMode(ma1,OUTPUT);
pinMode(ma2,OUTPUT);
pinMode(mb1,OUTPUT);
pinMode(mb2,OUTPUT);
lcd.print("solar tracking sys");
lcd.setCursor(0,1);
lcd.print("charger by arduino");
delay(2000);
lcd.clear();
}

void loop() 
{
// put your main code here, to run repeatedly:
lcd.clear();
value1=analogRead(A0);
value2=analogRead(A1);
value3=analogRead(A2);
value4=analogRead(A3);
value5=analogRead(A4);
value6=analogRead(A5);
// Serial.print("ldr1=");
// Serial.println(value1);
// Serial.print("ldr2=");
// Serial.println(value2);
// Serial.print("ldr3=");
// Serial.println(value3);
// Serial.print("ldr4=");
// Serial.println(value4);
power = voltage * 5;
Serial.println(value5);
Serial.print(",");
Serial.println(value6);
delay(100);
lcd.print("voltage");
lcd.setCursor(0,1);
lcd.print(value5);
delay(2000);
lcd.clear();
lcd.print("current");
lcd.setCursor(0,1);
lcd.print(value6);
delay(2000);
lcd.clear();
if((value1 < 100)&&(value2 < 200))
{
  
  lcd.clear();
  lcd.print("ldr is detect");
  forward();
  delay(500);
  Stop();
  lcd.setCursor(0,1);
  lcd.print("north side");
  //Serial.println("north side");
  delay(2000);
  
  lcd.clear();
 }
if((value3 < 400)&&(value4 < 200))
{
  
  lcd.clear();
  lcd.print("ldr is detect");
  backward();
  delay(500);
  Stop();
  lcd.setCursor(0,1);
  lcd.print("south side");
  //Serial.println("south side");
  delay(2000);
  
  lcd.clear();
}
if((value2 < 200)&&(value3 < 400))
{
  
  lcd.clear();
  lcd.print("ldr is detect");
  left();
  delay(500);
  Stop();
  lcd.setCursor(0,1);
  lcd.print("east side");
  //Serial.println("east side");
  delay(2000);
  lcd.clear();
}
if((value1 < 100)&&(value4 < 200))
{
  
  lcd.clear();
  lcd.print("ldr is detect"); 
  right();
  delay(500);
  Stop();
  lcd.setCursor(0,1);
  lcd.print("west side");
  //Serial.println("west side");
  delay(2000);
  lcd.clear();
}

}
