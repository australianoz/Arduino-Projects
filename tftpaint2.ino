// This sketch has been Refurbished by BUHOSOFT
// Original code provided by Smoke And Wires
// http://www.smokeandwires.co.nz
// This code has been taken from the Adafruit TFT Library and modified
//  by us for use with our TFT Shields / Modules
// For original code / licensing please refer to
// https://github.com/adafruit/TFTLCD-Library

// adapted sketch by niq_ro from http://arduinotehniq.blogspot.com/
// ver. 1m5 - 13.11.2014, Craiova - Romania
// Rewritten be Christophe DEMION
// ver. 1m6 - 19.02.2015, St Just St Rambert - FRANCE
// rev Added #define 16 bit Colours, all tested (not all worth it but hey! who can do less can do more!)
// All tft.setRotation corrected
// Englisied some variables


// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
// #define LCD_CS A3 // Chip Select goes to Analog 3
// #define LCD_CD A2 // Command/Data goes to Analog 2
// #define LCD_WR A1 // LCD Write goes to Analog 1
// #define LCD_RD A0 // LCD Read goes to Analog 0

// #define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
// For the Arduino Uno, Duemilanove, Diecimila, etc.:
//   D0 connects to digital pin 8  (Notice these are
//   D1 connects to digital pin 9   NOT in order!)
//   D2 connects to digital pin 2
//   D3 connects to digital pin 3
//   D4 connects to digital pin 4
//   D5 connects to digital pin 5
//   D6 connects to digital pin 6
//   D7 connects to digital pin 7
// For the Arduino Mega, use digital pins 22 through 29
// (on the 2-row header at the end of the board).

//#define DEBUG
#include <Adafruit_GFX.h>    // Core graphics library
#include <TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4


#define YP A1 // Y+ is on Analog1
#define XM A2 // X- is on Analog2
#define YM 7 // Y- is on Digital7
#define XP 6 // X+ is on Digital6

#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// Color definitions
// Comment out the colours you don't need, it'll save some space

#define WHITE			0xFFFF
#define SNOW			0xFFDE
#define GHOSTWHITE		0xF7BF
#define IVORY			0xFFFD
#define MINTCREAM		0xF7FE
#define AZURE			0xEFFF
#define FLORALWHITE		0xFFDD
#define ALICEBLUE		0xEFBF
#define LAVENDERBLUSH	        0xFF7E
#define SEASHELL		0xFFBD
#define WHITESMOKE		0xF7BE
#define HONEYDEW		0xEFFD
#define LIGHTYELLOW		0xFFFB
#define LIGHTCYAN		0xDFFF
#define OLDLACE			0xFFBC
#define CORNSILK		0xFFBB
#define LINEN			0xF77C
#define LEMONCHIFFON	        0xFFD9
#define LIGHTGOLDENRODYELLOW	0xF7D9
#define BEIGE			0xF7BB
#define LAVENDER		0xE73E
#define MISTYROSE		0xFF1B
#define PAPAYAWHIP		0xFF7A
#define ANTIQUEWHITE	        0xF75A
#define BLANCHEDALMOND	        0xFF59
#define BISQUE			0xFF18
#define MOCCASIN		0xFF16
#define GAINSBORO		0xDEDB
#define PEACHPUFF		0xFED6
#define PALETURQUOISE	        0xAF7D
#define NAVAJOWHITE		0xFEF5
#define PINK			0xFDF9
#define WHEAT			0xF6F6
#define PALEGOLDENROD    	0xEF34
#define LIGHTGREY		0xD69A
#define LIGHTPINK		0xFDB7
#define POWDERBLUE		0xAEFC
#define THISTLE			0xD5FA
#define LIGHTBLUE		0xAEBC
#define KHAKI			0xEF31
#define VIOLET			0xEC1D
#define PLUM			0xDCFB
#define LIGHTSTEELBLUE    	0xAE1B
#define AQUAMARINE		0x7FFA
#define LIGHTSKYBLUE	        0x867E
#define SILVER			0xBDF7
#define SKYBLUE			0x867D
#define PALEGREEN		0x97D2
#define ORCHID			0xD37A
#define BURLYWOOD		0xDDB0
#define HOTPINK			0xFB56
#define LIGHTSALMON		0xFCEE
#define TAN			0xCD91
#define LIGHTGREEN		0x8F71
#define YELLOW			0xFFE0
#define FUCHSIA			0xF81F
#define MAGENTA			0xF81F
#define AQUA			0x07FF
#define CYAN			0x07FF
#define DARKGRAY		0xA554
#define DARKSALMON		0xE4AE
#define SANDYBROWN		0xF50B
#define LIGHTCORAL		0xEBEF
#define TURQUOISE		0x3EF9
#define SALMON			0xF3ED
#define CORNFLOWERBLUE	        0x64BD
#define MEDIUMTURQUOISE	        0x4699
#define MEDIUMORCHID	        0xB2BA
#define DARKKHAKI		0xBDAD
#define PALEVIOLETRED	        0xDB72
#define MEDIUMPURPLE	        0x937B
#define MEDIUMAQUAMARINE	0x6674
#define GREENYELLOW		0xAFE5
#define ROSYBROWN		0xBC71
#define DARKSEAGREEN	        0x8DD1
#define GOLD			0xFEA0
#define MEDIUMSLATEBLUE	        0x7B3D
#define CORAL			0xFBE9
#define DEEPSKYBLUE		0x05FF
#define DODGERBLUE		0x1C7F
#define TOMATO			0xFB08
#define DEEPPINK		0xF892
#define ORANGE			0xFD20
#define ORANGEPINK      0xFBE0
#define GOLDENROD		0xD523
#define DARKTURQUOISE	        0x0679
#define CADETBLUE		0x5CF3
#define YELLOWGREEN		0x9665
#define LIGHTSLATEGRAY	        0x7432
#define DARKORCHID		0x9199
#define BLUEVIOLET		0x815B
#define MEDIUMSPRINGGREEN	0x07D2
#define PERU			0xCC27
#define SLATEBLUE		0x62D9
#define DARKORANGE		0xFC40
#define ROYALBLUE		0x3B5B
#define INDIANRED		0xCACB
#define GRAY			0x7BEF
#define SLATEGRAY		0x6BF1
#define CHARTREUSE		0x7FE0
#define SPRINGGREEN		0x07EF
#define STEELBLUE		0x4416
#define LIGHTSEAGREEN	        0x1D94
#define LAWNGREEN		0x7FC0
#define DARKVIOLET		0x901A
#define MEDIUMVIOLETRED	        0xC0B0
#define MEDIUMSEAGREEN	        0x3D8D
#define CHOCOLATE		0xCB43
#define DARKGOLDENROD	        0xB421
#define ORANGERED		0xFA20
#define DIMGRAY			0x634C
#define LIMEGREEN		0x2E65
#define CRIMSON			0xD887
#define SIENNA			0x9A85
#define OLIVEDRAB		0x6C64
#define DARKMAGENTA		0x8811
#define DARKCYAN		0x0451
#define DARKSLATEBLUE	        0x41F1
#define SEAGREEN		0x2C4A
#define OLIVE			0x7BE0
#define PURPLE			0x780F
#define TEAL			0x03EF
#define RED			0xF800
#define LIME			0x07E0
#define BLUE			0x001F
#define BROWN			0xA144
#define FIREBRICK		0xA903
#define DARKOLIVEGREEN	        0x5345
#define SADDLEBROWN		0x8A22
#define FORESTGREEN		0x1C43
#define INDIGO			0x480F
#define DARKSLATEGRAY	        0x2A69
#define MEDIUMBLUE		0x0019
#define MIDNIGHTBLUE	        0x10CD
#define DARKRED			0x8800
#define DARKBLUE		0x0011
#define MAROON			0x7800
#define GREEN			0x03E0
#define NAVY			0x000F
#define DARKGREEN		0x0300
#define BLACK			0x0000

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);;

#define BOXSIZE 40
#define PENRADIUS 3
int oldcolor, currentcolor;
int ics;

void setup(void) {
#ifdef DEBUG
  Serial.begin(9600);
  Serial.println(F("Paint!"));
#endif // DEBUG
  tft.reset();

  uint16_t identifier = tft.readID();

if(identifier == 0x9325) {
#ifdef DEBUG
    Serial.println(F("Found ILI9325 LCD driver"));
#endif // DEBUG
  } else if(identifier == 0x9328) {
#ifdef DEBUG
    Serial.println(F("Found ILI9328 LCD driver"));
#endif // DEBUG
  } else if(identifier == 0x7575) {
#ifdef DEBUG
    Serial.println(F("Found HX8347G LCD driver"));
#endif // DEBUG
  } else if(identifier == 0x9341) {
#ifdef DEBUG
    Serial.println(F("Found ILI9341 LCD driver"));
#endif // DEBUG
  } else if(identifier == 0x8357) {
#ifdef DEBUG
    Serial.println(F("Found HX8357D LCD driver"));
#endif // DEBUG
  } else if(identifier == 0x0154) {
#ifdef DEBUG
    Serial.println(F("Found S6D0154 LCD driver"));
#endif // DEBUG
    } else {
    #ifdef DEBUG
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.print(F("I try use ILI9341 LCD driver "));
    Serial.println(F("If using the Adafruit 2.8\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Adafruit_TFT.h)."));
    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    #endif // DEBUG
    identifier = 0x9341;
  }


  tft.begin(identifier);

  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 320, 240, BLACK);
  tft.setRotation(1);
  tft.setCursor(30, 100);
  tft.setTextColor(RED);  tft.setTextSize(3);
  tft.println("LCD driver chip: ");
  tft.setCursor(100, 150);
  tft.setTextColor(BLUE);
  tft.println(identifier, HEX);

delay(2000);
tft.fillRect(0, 0, 320, 240, BLACK);

tft.setRotation(2);
  tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
  tft.fillRect(0, BOXSIZE, BOXSIZE, BOXSIZE, YELLOW);
  tft.fillRect(0, BOXSIZE*2, BOXSIZE, BOXSIZE, GREEN);
  tft.fillRect(0, BOXSIZE*3, BOXSIZE, BOXSIZE, CYAN);
  tft.fillRect(0, BOXSIZE*4, BOXSIZE, BOXSIZE, BLUE);
  tft.fillRect(0, BOXSIZE*5, BOXSIZE, BOXSIZE, MAGENTA);
  tft.fillRect(0, BOXSIZE*6, BOXSIZE, BOXSIZE, SILVER);
  tft.fillRect(0, BOXSIZE*7, BOXSIZE, BOXSIZE,  ORANGE);
//tft.fillRect(BOXSIZE, BOXSIZE, BOXSIZE, BOXSIZE, WHITE);

  tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
  currentcolor = RED;


 number (WHITE);
  pinMode(13, OUTPUT);
}

#define MINPRESSURE 10
#define MAXPRESSURE 1000

void loop()
{
  digitalWrite(13, HIGH);
  // Recently Point was renamed TSPoint in the TouchScreen library
  // If you are using an older version of the library, use the
  // commented definition instead.
  // Point p = ts.getPoint();
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);

  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  //pinMode(XP, OUTPUT);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  //pinMode(YM, OUTPUT);

  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!

  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {
#ifdef DEBUG
    Serial.print("X = "); Serial.print(p.x);
    Serial.print("\tY = "); Serial.print(p.y);
    Serial.print("\tPressure = "); Serial.println(p.z);
#endif // DEBUG
if (p.y < (TS_MINY-5)) erase();
    // scale from 0->1023 to tft.width
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);
#ifdef DEBUG
    Serial.print("("); Serial.print(p.x);
    Serial.print(", "); Serial.print(p.y);
    Serial.println(")");
#endif // DEBUG
    if (p.x < BOXSIZE) {
       oldcolor = currentcolor;

       if (p.y < BOXSIZE) {
         currentcolor = RED;
         tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
//         text (currentcolor);
       } else if (p.y < BOXSIZE*2) {
         currentcolor = YELLOW;
         tft.drawRect(0, BOXSIZE, BOXSIZE, BOXSIZE, WHITE);
//         text (currentcolor);
       } else if (p.y < BOXSIZE*3) {
         currentcolor = GREEN;
         tft.drawRect(0, BOXSIZE*2, BOXSIZE, BOXSIZE, WHITE);
//         text (currentcolor);
       } else if (p.y < BOXSIZE*4) {
         currentcolor = CYAN;
         tft.drawRect(0, BOXSIZE*3, BOXSIZE, BOXSIZE, WHITE);
//         text (currentcolor);
       } else if (p.y < BOXSIZE*5) {
         currentcolor = BLUE;
         tft.drawRect(0, BOXSIZE*4, BOXSIZE, BOXSIZE, WHITE);
//         text (currentcolor);
       } else if (p.y < BOXSIZE*6) {
         currentcolor = MAGENTA;
         tft.drawRect(0,BOXSIZE*5, BOXSIZE, BOXSIZE, WHITE);
//         text (currentcolor);
       } else if (p.y < BOXSIZE*7) {
         currentcolor = SILVER;
         tft.drawRect(0,BOXSIZE*6, BOXSIZE, BOXSIZE, WHITE);
//         text (currentcolor);
       } else if (p.y < BOXSIZE*8) {
         currentcolor = ORANGE;
         tft.drawRect(0,BOXSIZE*7, BOXSIZE, BOXSIZE, WHITE);
         erase();
       }

//text (currentcolor);
//number (currentcolor);
       if (oldcolor != currentcolor) {
          if (oldcolor == RED) tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
          if (oldcolor == YELLOW) tft.fillRect(0, BOXSIZE, BOXSIZE, BOXSIZE, YELLOW);
          if (oldcolor == GREEN) tft.fillRect(0, BOXSIZE*2, BOXSIZE, BOXSIZE, GREEN);
          if (oldcolor == CYAN) tft.fillRect(0, BOXSIZE*3, BOXSIZE, BOXSIZE, CYAN);
          if (oldcolor == BLUE) tft.fillRect(0, BOXSIZE*4, BOXSIZE, BOXSIZE, BLUE);
          if (oldcolor == MAGENTA) tft.fillRect(0, BOXSIZE*5, BOXSIZE, BOXSIZE, MAGENTA);
          if (oldcolor == SILVER) tft.fillRect(0, BOXSIZE*6, BOXSIZE, BOXSIZE, SILVER);
          if (oldcolor == ORANGE) tft.fillRect(0, BOXSIZE*7, BOXSIZE, BOXSIZE, ORANGE);
     number (currentcolor);
     }

    }
   // if (((p.y-PENRADIUS) > BOXSIZE) && ((p.y+PENRADIUS) < tft.height())) {
/*
if (((p.y-PENRADIUS) > 5) && ((p.y+PENRADIUS) < tft.height())) {
   tft.fillCircle(p.x, p.y, PENRADIUS, currentcolor);
    }
*/
if (((p.x-PENRADIUS) > BOXSIZE) && ((p.x+PENRADIUS) < tft.width())) {
   tft.fillCircle(p.x, p.y, PENRADIUS, currentcolor);
    }

  }
}

void text (int colour)
{
tft.setRotation(2);

          tft.setCursor(5, 220);
          tft.setTextSize(2);
          tft.println("DEMION");
tft.setRotation(0);
}

void number (int colour)
{
// number for "buttons"
 tft.setRotation(1);
 tft.setTextColor(colour);
 tft.setTextSize(3);
 tft.drawLine(0, 0, 40, 40, colour);
 tft.drawLine(0, 40, 40, 0, colour);
// tft.setCursor(15, 10);
// tft.println("1");
 tft.setCursor(55, 10);
 tft.println("1");
 tft.setCursor(95, 10);
 tft.println("2");
 tft.setCursor(135, 10);
 tft.println("3");
 tft.setCursor(175, 10);
 tft.println("4");
 tft.setCursor(215, 10);
 tft.println("5");
 tft.setCursor(255, 10);
 tft.println("6");
 tft.setCursor(295, 10);
 tft.println("7");

 tft.setRotation(2);
}

void erase ()
{
    #ifdef DEBUG
      Serial.println("erase");
    #endif // DEBUG
      // press the bottom of the screen to erase
 //     tft.fillRect(0, BOXSIZE, tft.width(), tft.height()-BOXSIZE, BLACK);
   tft.fillRect(0, 0, 240, 320, BLACK);
   tft.setRotation(2);
  tft.fillRect(0, 0, BOXSIZE, BOXSIZE, RED);
  tft.fillRect(0, BOXSIZE, BOXSIZE, BOXSIZE, YELLOW);
  tft.fillRect(0, BOXSIZE*2, BOXSIZE, BOXSIZE, GREEN);
  tft.fillRect(0, BOXSIZE*3, BOXSIZE, BOXSIZE, CYAN);
  tft.fillRect(0, BOXSIZE*4, BOXSIZE, BOXSIZE, BLUE);
  tft.fillRect(0, BOXSIZE*5, BOXSIZE, BOXSIZE, MAGENTA);
  tft.fillRect(0, BOXSIZE*6, BOXSIZE, BOXSIZE, SILVER);
  tft.fillRect(0, BOXSIZE*7, BOXSIZE, BOXSIZE,  ORANGE);
//tft.fillRect(BOXSIZE, BOXSIZE, BOXSIZE, BOXSIZE, WHITE);

  tft.drawRect(0, 0, BOXSIZE, BOXSIZE, WHITE);
  currentcolor = RED;
     number (WHITE);
    }
