/*
 Name:		DisplayOledTester.ino
 Created:	5/24/2024 5:26:46 PM
 Author:	Rob Antonisse


*/

#include <EEPROM.h>

//display 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


Adafruit_SSD1306 display(128, 64, &Wire, -1); //constructor display  takes program 9598bytes; memory  57bytes


// the setup function runs once when you press reset or power the board
void setup() {
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	display.clearDisplay();
	display.setCursor(10, 10);
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.print("www.wisselmotor.nl");
	display.display();
}

// the loop function runs over and over again until power down or reset
void loop() {
  
}
