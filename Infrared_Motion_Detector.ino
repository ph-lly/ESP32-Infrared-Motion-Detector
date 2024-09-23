/**********************************************************************
  Filename    : Infrared Motion Detector
  Description : LCD Monitor displays message if Infrared Motion Sensor detects motion
  Author      : IT 225 Group (Kendrick, Phillip, Kaleb)
  Modification: 2024/04/23
**********************************************************************/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 12                    //Define SDA pins
#define SCL 13                    //Define SCL pins

int sensorPin = 14; // the number of the infrared motion sensor pin
LiquidCrystal_I2C lcd(0x27,16,2); // initialize lcd
void setup() {
  pinMode(sensorPin, INPUT);  // initialize the sensor pin as input
  Wire.begin(SDA, SCL);           // attach the IIC pin
  if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init();                     // LCD driver initialization
  lcd.backlight();                // Open the backlight
  lcd.setCursor(0,0);             // Move the cursor to row 0, column 0
}

void loop() {
  if(digitalRead(sensorPin)==HIGH){
    lcd.print("Motion Detected!"); //Prints Motion Detected! to the screen
    delay(10000); //delay to keep Motion Detected displayed on the screen for 10 seconds to let the user know
  }
  else{
    lcd.clear(); // Clears the display
    delay(1000); //check every second so delay for one second
  }
}

bool i2CAddrTest(uint8_t addr) { //boolean to check IIC's address
  Wire.begin();
  Wire.beginTransmission(addr);
  if (Wire.endTransmission() == 0) {
    return true;
  }
  return false;
}

