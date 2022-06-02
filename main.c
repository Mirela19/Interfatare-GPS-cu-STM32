#include <LiquidCrystal.h>                          
#include <LiquidCrystal.h>                   
#include <TinyGPS++.h>         

const int rs = PB11, en = PB10, d4 = PB0, d5 = PB1, d6 = PC13, d7 = PC14;  
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

TinyGPSPlus gps;               

void setup()
{
  Serial1.begin(9600);        
  lcd.begin(16,2);            
  lcd.print("Proiect");
  lcd.setCursor(0,1);
  lcd.print("GPS CU STM32");
  delay(4000);
  lcd.clear();      
}

void loop()
{
  GPSDelay(1000);
  unsigned long start;
  double lat_val, lng_val;
  bool loc_valid;
  lat_val = gps.location.lat();        
  loc_valid = gps.location.isValid(); 
  lng_val = gps.location.lng();        
 
  if (!loc_valid)                   
  {
    lcd.print("Asteapta");
    Serial.print("Latitudine : ");
    Serial.println("*****");
    Serial.print("Longitudine : ");
    Serial.println("*****");
    delay(4000);
    lcd.clear();
  }
  else                              
  {
    lcd.clear();
    
    Serial.println("Coordonatele ");
   
    Serial.print("Latitudine : ");
    Serial.println(lat_val, 6);  
   
    lcd.setCursor(0,0);
    lcd.print("LAT:");
    lcd.print(lat_val,6);        

    Serial.print("Longitudine : ");
    Serial.println(lng_val, 6);   

    lcd.setCursor(0,1);
    lcd.print("LONG:");
    lcd.print(lng_val,6);          

    delay(4000);
  }
}

static void GPSDelay(unsigned long ms)          
{
  unsigned long start = millis();
  do
  {
    while (Serial1.available()) 
    gps.encode(Serial1.read());
  } while (millis() - start < ms);
}

