
#include <RH_ASK.h>

#include <SPI.h> // Not actualy used but needed to compile

#include <LiquidCrystal_I2C.h>

//String msg;

LiquidCrystal_I2C lcd(0x27, 16, 2);

RH_ASK driver;

#define buzzer 2

void setup()

{

    Serial.begin(9600);  // Debugging only

    pinMode(buzzer, OUTPUT);

    lcd.begin();

    lcd.clear(); 

    if (!driver.init())

         Serial.println("init failed");

}

void loop()

{

    uint8_t buf[17];

    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking

    {

      int i;

      digitalWrite(buzzer, HIGH);

      delay(1000);

      digitalWrite(buzzer, LOW);

      // Message with a good checksum received, dump it.

      Serial.print("Message: ");

      Serial.println((char*)buf);

      lcd.clear(); 

      lcd.setCursor(0,0);

      lcd.print("T1:");

      lcd.print((char*)buf);            

    }

}
