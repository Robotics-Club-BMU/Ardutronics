#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#define WATERPIN 2
#define SENSOR A1
#define MAXDRYNESS 500
#define WATERPOSTDELAY 1000
int ch=0;
double temp;
int sensorInput;
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
void setup()
{ 
  digitalWrite(WATERPIN, LOW);
  pinMode(WATERPIN, OUTPUT);
  Serial.begin(9600); 
  lcd.begin(16,2);
}

void loop() {
     
 Soil_Moisture();
  sensorInput = analogRead(A4);    
  temp = (double)sensorInput / 1024;      
  temp = temp * 5;                 
  temp = temp - 0.5;               
  temp = temp * 100;              
  Serial.print("Current Temperature: ");
  lcd.clear();
  Serial.println(temp);
  lcd.print("surr temp");
  lcd.print(temp);
  delay(2000);
  lcd.setCursor(0,1);
  lcd.blink();
  lcd.clear();
}

 void Soil_Moisture()
  {
    int SensorValue = analogRead(SENSOR); 
    Serial.print("\nSoilMoisture=\n");
    Serial.print(SensorValue);
   Serial.print("\n");
     
  if(ch%2==0) //SensorValue >= MAXDRYNESS
  {
     Serial.println("Soil dry, start watering\n");
    lcd.clear();
    lcd.print("Soil dry");
    lcd.setCursor(0,1);
    lcd.print("alert sms sent");
    Serial.println("Alert sms sent\n");
    delay(2000);
    lcd.clear();
    lcd.print("watering started on plant ");
    Serial.println("plant watering started \n");
    digitalWrite(8, HIGH);
   digitalWrite(2, HIGH);
       delay(5000);
     digitalWrite(WATERPIN, LOW);
    ch++;
     lcd.clear();
     
  }
   else //SensorValue < MAXDRYNESS
   {
     Serial.println("\nSoil is good\n");
     lcd.print("Soil is good");
     delay(3000);
     lcd.clear();
     digitalWrite(8,LOW);
     delay(WATERPOSTDELAY);
     ch++;
   }
     
   
    delay(2000);
  }
 