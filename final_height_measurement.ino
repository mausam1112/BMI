#include<LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); //Interface pins of the LCD
const int trig_pin=9;
const int echo_pin=10;
float gross,cm,duration;  //input to be taken
int inch,feet;

void setup() {
lcd.begin(20,4);
lcd.setCursor(0,0);
lcd.print("Height Measurement");
lcd.setCursor(0,1); 
lcd.print("Your height is:"); //set the cursor to column 0 and line 0
pinMode(9,OUTPUT);
pinMode(10,INPUT);
}


void loop() {
digitalWrite(9,HIGH);
delayMicroseconds(20);
digitalWrite(9,LOW);
delayMicroseconds(20);
duration = pulseIn(echo_pin, HIGH); //To receive the reflected signal from the ultrasonic sensor.
gross= duration*0.034/2;
cm =209-gross;
feet= cm/30.48;
cm= cm-feet*30.48;
inch= cm/2.54;
lcd.setCursor(0,2);
lcd.print(feet);
lcd.print(" feet ");
lcd.print(inch);
lcd.print(" inch");
lcd.setCursor(12,3);
lcd.print("By Sudip");

delay(1000);
}
