float Vout;
float Temp;
void setup() {
  
  Serial.begin(9600); 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() {
  Vout=analogRead(A0) ;
  Temp= (Vout*500)/1023 ;
 
  int PWMvalue=map(Temp,31,40,100,255);
  if(Temp>=30)
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW );
  
    analogWrite(5,PWMvalue);
    
   }
  else{
    analogWrite(5,0);
    }
  Serial.print("Temperature in Degree Celsius = ");
  Serial.print(Temp);
  Serial.print("\t");
  Serial.print("PWMValue = ");
  Serial.print(PWMvalue);
  Serial.print("\t");
  Serial.println();
  delay(1000);
}
