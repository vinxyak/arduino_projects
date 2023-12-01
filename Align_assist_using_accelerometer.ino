const int groundpin = 18; 
const int powerpin = 19;  
const int xpin = A3;      
const int ypin = A2; 
const int zpin = A1;
int LED1=3;
int LED2=5;

void setup() {
  Serial.begin(9600);
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}
void loop() {
  Serial.print(analogRead(xpin));
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  Serial.print("\t");
  Serial.print(analogRead(zpin));
  Serial.println();
  if((analogRead(xpin)>=(330) && analogRead(xpin)<=(350)) && (analogRead(ypin)>=(330) && analogRead(ypin)<=(350)))
  {
    analogWrite(LED1, 255);
    delay(250);
  }
  else
  {
    analogWrite(LED1, LOW);
    analogWrite(LED2, 255);
    delay(250);
  }
  delay(100);
}
