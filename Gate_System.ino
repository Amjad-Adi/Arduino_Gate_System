#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
  
int pos = 0;
int Red_Led=4;
int Yellow_Led=7;
int Green_Led=8;
Servo servo_9;
LiquidCrystal_I2C lcd(0x27,16,2);
int inches = 0;

int cm = 0;
void setup()
{
  servo_9.write(90);
    Serial.begin(9600);
lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  servo_9.attach(3);
  servo_9.write(30);
  pinMode(Red_Led,OUTPUT);
     pinMode(Yellow_Led,OUTPUT);
    pinMode(Green_Led,OUTPUT);
}
int flag=0;
void loop()
{

// measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(12, 13);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  if(cm>=10 && cm<=14)
   Gate_System();
  else{
    if(flag!=1){
    flag=1;
    lcd.print("Gate1");	
    }
    digitalWrite(Red_Led,1);
      }
  delay(100); // Wait for 100 millisecond(s)
  
}


long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}


void Gate_System(){
  lcd.clear();
  digitalWrite(Red_Led,0);
  digitalWrite(Yellow_Led,1);
  lcd.print("Get ready!");
  delay(500);
  for (pos = 30; pos <= 120; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(10); // Wait for 15 millisecond(s)
  }

  delay(500);
    lcd.clear();
    lcd.print("Pass!");
  digitalWrite(Yellow_Led,0);
  digitalWrite(Green_Led,1);
  delay(2500);
    digitalWrite(Green_Led,0);
    for (pos = 120; pos >= 30; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(10); // Wait for 15 millisecond(s)
  }
  lcd.clear();
  flag=0;
}
