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
#define zwart 		tft.fillScreen(ST7735_BLACK);


//timers
unsigned long ptime = 0;
unsigned int timercount = 0; //teller die de tijd afteld
unsigned int time = 0; //gewenste tijd in 10ms eenheden
byte dpfase = 0;







void setup() {
	Serial.begin(9600);
	//Serial.print("Hello! ST7735 TFT Test");

	// Use this initializer if you're using a 1.8" TFT
	tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
	//tft.fillScreen(ST7735_BLACK);

	// Use this initializer (uncomment) if you're using a 1.44" TFT
	//tft.initR(INITR_144GREENTAB);   // initialize a ST7735S chip, black tab

	//Serial.println("Initialized");

	//uint16_t time = millis();
   // tft.fillScreen(ST7735_GREEN);
	//tft.fillScreen(ST77XX_RED);
	//time = millis() - time;

	//Serial.println(time, DEC);
	//delay(500);

	//// large block of text
	//tft.fillScreen(ST7735_BLACK);
	//tft.println("Hallo");


	//testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST7735_WHITE);
	//delay(1000);

	//// tft print function!
	//tftPrintTest();
	//delay(4000);

	//// a single pixel
	//tft.drawPixel(tft.width() / 2, tft.height() / 2, ST7735_GREEN);
	//delay(500);

	//// line draw test
	//testlines(ST7735_YELLOW);
	//delay(500);

	//// optimized lines
	//testfastlines(ST7735_RED, ST7735_BLUE);
	//delay(500);

	//testdrawrects(ST7735_GREEN);
	//delay(500);

	//testfillrects(ST7735_YELLOW, ST7735_MAGENTA);
	//delay(500);

	//tft.fillScreen(ST7735_BLACK);
	//testfillcircles(10, ST7735_BLUE);
	//testdrawcircles(10, ST7735_WHITE);
	//delay(500);

	//testroundrects();
	//delay(500);

	//testtriangles();
	//delay(500);

	//mediabuttons();
	//delay(500);

   // Serial.println("done");
  //  delay(1000);
}




void loop() {
	if (millis() - ptime > 10) { //timer op 10ms
		ptime = millis();
		dp_exe();
	}
}

void dp_exe() {

	if (time - timercount == 0) { //timer afgelopen
		timercount = 0; //reset timer
		switch (dpfase) {
		case 0:
			//dpfase = 1;
			time =300;
			//eerste beweging op de display
			tft.setRotation(3);
			//tft.fillScreen(ST7735_BLACK);
			zwart;
			tft.setCursor(30, 50);
			tft.print("www.wisselmotor.nl");

			break;
		case 1:
			//dpfase = 2;
			time = 300;
				zwart;
				tft.setCursor(50, 50);
			tft.println("presents:");
			break;
		case 2:
			//dpfase = 3;
				time = 100;
			//tft.fillScreen(ST7735_BLACK);
			break;
		case 3:
			time = 100;

			break;
		}
		dpfase++;
		if (dpfase > 10)dpfase = 0;
	}

	timercount++;
}
void dp_fase() {

}