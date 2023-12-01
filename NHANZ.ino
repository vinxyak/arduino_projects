#include <LiquidCrystal_I2C.h>
#include <Wire.h>
float Vout;
float Temp;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600); 
  pinMode(5,OUTPUT); //defining pin 5 as output to LED
  lcd.init();
  lcd.backlight();

}
void loop(){
  Vout=analogRead(A0) ; //taking input from LM35 sensor 
  Temp= (Vout*0.488)/10; //converting the adc value
  int PWMvalue=map(Temp,-55,150,0,99); //mapping the value assuming the temp range is between 0 and 99
  while(1)
  {
  analogWrite(5,PWMvalue*2.5); //giving output adjusting the brightness of LED proportional to the temp 
  lcd.setCursor(0, 0);
  lcd.print("Temperature in Degree Celsius = "); //displaying in LCD display
  lcd.print(Temp);
  delay(500);
  }
}