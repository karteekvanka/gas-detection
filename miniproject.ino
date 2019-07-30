#include <LiquidCrystal_I2C.h>       
LiquidCrystal_I2C lcd(0x27,16,2);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);

 int buzzer = 13;
int GASA0 = A0;
int gasvalue;

void setup() {
  
 lcd.init();                      
 lcd.backlight(); 
 mySerial.begin(9600);
 pinMode(buzzer, OUTPUT); 
 lcd.setCursor(3,0);
 lcd.print("welcome to"); 
 lcd.setCursor(1,1);
 lcd.print("mini project"); 
 delay(5000);     
}

void loop() {
  int analogSensor = analogRead(GASA0); 
  int gasvalue=(analogSensor-50)/10;
  
  lcd.setCursor(0,0);
  lcd.print("GAS Level:");
  lcd.setCursor(10,0);
  lcd.print(gasvalue);
  lcd.setCursor(12,0);
  lcd.print("%");
  
  
  if (gasvalue >= 10)
  {
    SendTextMessage();
    lcd.setCursor(0,1);
  lcd.print("DANGER");
  tone(buzzer, 1000, 200);
  }
  else
  {
  lcd.setCursor(0,1);
  lcd.print("NORMAL");
   noTone(buzzer);
  }
  delay(500);
  lcd.clear();
}


void SendTextMessage()
{
  Serial.println("AT+CMGF=1");   
  delay(1000);
  Serial.println("AT+CMGS=\"+919347467670\"\r"); 
  delay(1000);
  Serial.println(" Gas is Leaking!");
  delay(200);
  Serial.println((char)26);
  delay(1000);
  
}
