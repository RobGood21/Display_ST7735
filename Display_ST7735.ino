/*
 Name:		Display_ST7735.ino
 Created:	5/4/2024 10:30:09 AM
 Author:	Rob Antonisse

 Color displays, onderzoek hoe deze te gebruiken



*/

//volgens voorbeeld

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
// For the breakout, you can use any 2 or 3 pins
// These pins will also work for the 1.8" TFT shield
#define TFT_CS     10
#define TFT_RST    8 //8  you can also connect this to the Arduino reset   // in which case, set this #define pin to 0!
#define TFT_DC     9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Option 2: use any pins but a little slower!
//#define TFT_SCLK 12   // set these to be whatever pins you like!
//#define TFT_MOSI 11   // set these to be whatever pins you like!
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


//defines
#define clear tft.fillScreen(ST7735_BLACK);
#define groen 0x1ba8  //dit is een kleur   0x2287 0x0402
#define rood 0xf020
#define wit 0xFFFF
#define geel 0xfff5
#define zwart 0x0000

//timers
unsigned long ptime = 0;

unsigned int timercount = 0; //teller die de tijd afteld
unsigned int time = 0; //gewenste tijd in 10ms eenheden
byte dpfase = 0;

void setup() {
	Serial.begin(9600);
	// Use this initializer if you're using a 1.8" TFT
	tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
	tft.fillScreen(ST7735_BLUE);


}

void loop() {

	if (millis() - ptime > 10) { //timer op 10ms
		ptime = millis();
		dp_exe();
	}
}

byte _H1 = 38; byte _h1 = 52; byte _H2 = 69; byte _h2 = 76;




void dp_exe() {




	if (time - timercount == 0) { //timer afgelopen

	//Serial.print(dpfase);

		timercount = 0; //reset timer

		switch (dpfase) {
		case 0: //zwart scherm

			time = 200;
			tft.fillScreen(zwart);
			clear;
			tft.setRotation(3);
			break;

		case 1:
			time = 500;
			tft.setTextSize(1);	
			tft.setCursor(30, 50);
			tft.print("www.wisselmotor.nl");
			break;

		case 2:
			time = 200;
			clear;
			break;

		case 3:
			time = 500;			
			tft.setCursor(50, 50);
			tft.println("presents:");
			break;

			// geel donkergroen geel
		case 4: //rgba(188, 240, 66, 0.8)
			time = 5;
			clear;
			tft.fillRect(0, 0, 160, 35, geel);
			break;
		case 5:
			tft.fillRect(0, 35, 160, 58, groen); // red, green,blue, helderheid
			break;
		case 6:
			tft.fillRect(0, 95, 160, 30, geel);
			break;
		case 7:
			kader();
			time = 20;
			break;


		case 11:
			tft.setFont(0);
			time = 5;
			//tft.setCursor(4, 40);
			//tft.setTextSize(2);
			//tft.print("WisselAandrijving");
			//drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y),
			//  x positie, y positie, teken ascii,kleur,Achtergrond kleur (0=transparent) ,breedte, hoogte  van de letters
			tft.drawChar(10, _H1, 87, 0xFFFFFFFF, groen, 3, 4); //87=W
			break;

		case 12:
			//time = 50;
			tft.drawChar(24, _h1, 105, wit, groen, 2, 2); //105=i
			break;
		case 13:
			tft.drawChar(33, _h1, 115, wit, groen, 2, 2); //115=s
			break;
		case 14:
			tft.drawChar(44, _h1, 115, wit, groen, 2, 2); //115=s
			break;
		case 15: //e=101
			tft.drawChar(55, _h1, 101, wit, groen, 2, 2);
			break;
		case 16: //l=108
			tft.drawChar(65, _h1, 108, wit, groen, 2, 2);
			break;
		case 17: //A=65;97
			tft.drawChar(25, _H2, 65, wit, groen, 3, 3);
			break;
		case 18:
			tft.drawChar(40, _h2, 97, wit, groen, 2, 2);
			break;
		case 19: //n=110
			tft.drawChar(50, _h2, 110, wit, groen, 2, 2);
			break;
		case 20: //d=100
			tft.drawChar(60, _h2, 100, wit, groen, 2, 2);
			break;
		case 21: //r=114
			tft.drawChar(71, _h2, 114, wit, groen, 2, 2);
			break;
		case 22: //i=105
			tft.drawChar(81, _h2, 105, wit, groen, 2, 2);
			break;
		case 23: //j=106
			tft.drawChar(91, _h2, 106, wit, groen, 2, 2);
			break;
		case 24: //v=118
			tft.drawChar(101, _h2, 118, wit, groen, 2, 2);
			break;
		case 25: //i=105
			tft.drawChar(111, _h2, 105, wit, groen, 2, 2);
			break;
		case 26: //n=110
			tft.drawChar(121, _h2, 110, wit, groen, 2, 2);
			break;
		case 27: //g=103,71
			tft.drawChar(132, _h2, 71, wit, groen, 2, 2);
			break;

			//Versie V
		case 30:
			time = 50;
			break;
		case 31:
			time = 20;
			tft.fillCircle(123, 35, 30, rood);
			break;
		case 32:
			tft.setCursor(40, 15);
			tft.setTextSize(2);
			tft.setTextColor(zwart);
			tft.print("Versie");
			break;
		case 33:
			time = 20;
			tft.drawChar(110, 20, 52, geel, rood, 5);
			break;
			//wat is het?
		case 40:
			time = 100;
			tft.fillScreen(groen);
			kader();

			tft.setCursor(10, 25);
			tft.setTextSize(2);
			tft.setTextColor(wit);
			tft.println("Wissels \n aandrijven \n met een \n Arduino en \n Stappenmotor");
			break;

			//eigenschappen

		case 45:
			time = 200;
			tft.fillScreen(groen);
			kader();
			tft.setCursor(10, 60);
			tft.println("Betrouwbaar");
			break;

		case 46:
			tft.fillScreen(groen);
			kader();
			tft.setCursor(50, 60);
			tft.println("Stil");
			break;

		case 47:
			tft.fillScreen(groen);
			kader();
			tft.setCursor(8, 30);
			tft.println("Realistische\n beweging \n van de \n wisseltongen");
			break;

		case 50:
			time = 1;
			//	tft.fillScreen(groen);
			//	kader();
			//	titel(-5);
			break;

			//functies
		case 51:
			time = 200;
			tft.fillScreen(groen);
			kader();
			tft.setCursor(8, 10);
			tft.setTextSize(2);
			tft.setTextColor(wit);
			tft.println("Arduino \n en shield \n voor 4x");
			titel(20);
			break;

		case 52:
			tft.fillScreen(groen);
			kader();
			tft.setCursor(0, 35);
			tft.setTextSize(2);
			tft.setTextColor(wit);
			tft.println(" Voor analoog\n en digitaal\n modelspoor");
			break;
			break;


		case 53:
			tft.fillScreen(groen);
			kader();
			tft.setCursor(0, 25);
			tft.setTextSize(2);
			tft.setTextColor(wit);
			tft.println(" Drukknoppen\n en\n signaal leds\n voor\n analoog");
			break;

		case 54:
			tft.fillScreen(groen);
			kader();
			tft.setCursor(0, 35);
			tft.setTextSize(2);
			tft.setTextColor(wit);
			tft.println(" DCC decoder\n voor\n digitaal");
			break;

		case 55:
			logo();
			break;


		case 56:
			tft.fillScreen(groen);
			kader();
			tft.setCursor(0, 20);
			tft.setTextSize(2);
			tft.setTextColor(wit);

			tft.println(" Handleiding\n en info");
			web();
			break;

		case 100:
			time = 10000;
			break;
		}
		dpfase++;
		if (dpfase > 100)dpfase = 0;
	}

	timercount++;
}

//diverse vormen
void kader() {
	tft.drawRect(0, 0, 160, 128, rood);
	tft.drawRect(1, 1, 158, 126, rood);
}

void logo() {
	tft.fillRect(0, 0, 160, 35, geel);
	tft.fillRect(0, 35, 160, 58, groen);
	tft.fillRect(0, 95, 160, 30, geel);
	kader();
	titel(0);
	tft.fillCircle(123, 35, 30, rood);
	tft.setCursor(40, 15);
	tft.setTextSize(2);
	tft.setTextColor(zwart);
	tft.print("Versie");
	tft.drawChar(110, 20, 52, geel, rood, 5);
}



void web() {
	byte xos = 10;
	byte y = 70;
	tft.drawChar(xos + 0, y, 119, wit, groen, 2, 2);
	//tft.drawChar(8, 55, 119, wit, groen, 2, 2);
	//tft.drawChar(16, 55, 119, wit, groen, 2, 2);
	//tft.drawChar(26, 55, 119, wit, groen, 2, 2);
	tft.drawChar(xos + 10, y, 105, wit, groen, 2, 2);
	tft.drawChar(xos + 20, y, 115, wit, groen, 2, 2);
	tft.drawChar(xos + 30, y, 115, wit, groen, 2, 2);
	tft.drawChar(xos + 40, y, 101, wit, groen, 2, 2);
	tft.drawChar(xos + 50, y, 108, wit, groen, 2, 2);
	tft.drawChar(xos + 60, y, 109, wit, groen, 2, 2); //m=109
	tft.drawChar(xos + 70, y, 111, wit, groen, 2, 2); //o=111
	tft.drawChar(xos + 80, y, 116, wit, groen, 2, 2); //t=116
	tft.drawChar(xos + 90, y, 111, wit, groen, 2, 2);//o=111
	tft.drawChar(xos + 102, y, 114, wit, groen, 2, 2);//r=114
	tft.drawChar(xos + 106, y, 46, wit, groen, 2, 2); //.=46
	tft.drawChar(xos + 116, y, 110, wit, groen, 2, 2);//n=110
	tft.drawChar(xos + 126, y, 108, wit, groen, 2, 2);//l=108
}

void titel(signed int offset) {

	_H1 += offset; _h1 += offset; _H2 += offset; _h2 += offset;

	tft.drawChar(10, _H1, 87, wit, groen, 3, 4); //87=W
	tft.drawChar(24, _h1, 105, wit, groen, 2, 2); //105=i
	tft.drawChar(33, _h1, 115, wit, groen, 2, 2); //115=s
	tft.drawChar(44, _h1, 115, wit, groen, 2, 2); //115=s
	tft.drawChar(55, _h1, 101, wit, groen, 2, 2);
	tft.drawChar(65, _h1, 108, wit, groen, 2, 2);
	tft.drawChar(25, _H2, 65, wit, groen, 3, 3);
	tft.drawChar(40, _h2, 97, wit, groen, 2, 2);
	tft.drawChar(50, _h2, 110, wit, groen, 2, 2);
	tft.drawChar(60, _h2, 100, wit, groen, 2, 2);
	tft.drawChar(71, _h2, 114, wit, groen, 2, 2);
	tft.drawChar(81, _h2, 105, wit, groen, 2, 2);
	tft.drawChar(91, _h2, 106, wit, groen, 2, 2);
	tft.drawChar(101, _h2, 118, wit, groen, 2, 2);
	tft.drawChar(111, _h2, 105, wit, groen, 2, 2);
	tft.drawChar(121, _h2, 110, wit, groen, 2, 2);
	tft.drawChar(132, _h2, 71, wit, groen, 2, 2);

	_H1 -= offset; _h1 -= offset; _H2 -= offset; _h2 -= offset;
}

