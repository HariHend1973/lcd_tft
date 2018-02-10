#include <Adafruit_GFX.h> // Hardware-specific library
#include <MCUFRIEND_kbv.h>
#include <SPI.h>

MCUFRIEND_kbv tft;
String kutu = "KUTUKUPRET";
String value1, value2;

#define BLACK   0xFFFF
#define BLUE    0xFFE0
#define RED     0x07FF
#define GREEN   0xF810
#define CYAN    0xF800
#define MAGENTA 0x07E0
#define YELLOW  0x001F
#define WHITE   0x0000

#define BOXSIZE_W  480 //480
#define BOXSIZE_H  320 // 290
#define FILL_W     478
#define FILL_H     318
#define LANDSCAPE  1

static const unsigned char PROGMEM logo_wifi[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 
0x00, 0x50, 0x00, 0x00, 0x16, 0x00, 
0x00, 0xbc, 0x00, 0x00, 0x2d, 0x00, 
0x01, 0xd4, 0x00, 0x00, 0x36, 0x80, 
0x00, 0xb8, 0x00, 0x00, 0x1b, 0x00, 
0x03, 0xd0, 0x00, 0x00, 0x0d, 0xc0, 
0x02, 0xb0, 0x00, 0x00, 0x0b, 0x40, 
0x05, 0xc1, 0x40, 0x01, 0x06, 0xc0, 
0x06, 0xa0, 0x90, 0x05, 0x45, 0xa0, 
0x0b, 0xc2, 0x40, 0x04, 0x82, 0xe0, 
0x0d, 0x45, 0x40, 0x02, 0x43, 0x50, 
0x06, 0x82, 0x40, 0x01, 0x51, 0xf0, 
0x0b, 0x85, 0x00, 0x00, 0x80, 0xa0, 
0x0d, 0x04, 0x85, 0x50, 0xa1, 0x70, 
0x07, 0x82, 0x02, 0x40, 0x91, 0xa0, 
0x0d, 0x09, 0x09, 0x21, 0x40, 0xf0, 
0x0b, 0x85, 0x04, 0x90, 0x21, 0xa0, 
0x0d, 0x04, 0x82, 0x41, 0x51, 0x70, 
0x06, 0x82, 0x09, 0x10, 0x91, 0xa0, 
0x0b, 0x8a, 0x80, 0xa0, 0x40, 0xf0, 
0x0d, 0x04, 0x80, 0x01, 0x51, 0x50, 
0x07, 0xc2, 0x40, 0x02, 0x83, 0xb0, 
0x0d, 0x41, 0x50, 0x04, 0x41, 0x60, 
0x05, 0xa2, 0x80, 0x02, 0x87, 0xa0, 
0x06, 0xc0, 0x40, 0x02, 0x85, 0x60, 
0x01, 0xb1, 0x40, 0x00, 0x0d, 0xc0, 
0x03, 0x68, 0x00, 0x00, 0x17, 0x40, 
0x00, 0xf0, 0x00, 0x00, 0x1a, 0x80, 
0x01, 0xac, 0x00, 0x00, 0x2f, 0x00, 
0x00, 0x78, 0x00, 0x00, 0x35, 0x00, 
0x00, 0x58, 0x00, 0x00, 0x1a, 0x00, 
0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char PROGMEM logo_disk[] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x15, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 
0x2a, 0xaa, 0xaa, 0xaa, 0xa8, 0x00, 0x00, 
0x1f, 0xfb, 0xff, 0xff, 0xee, 0x00, 0x00, 
0x2f, 0xf9, 0xbb, 0xbb, 0xbd, 0x00, 0x00, 
0x1f, 0xf6, 0xee, 0xed, 0xef, 0x40, 0x00, 
0x2f, 0xf9, 0xff, 0xfa, 0xef, 0xa0, 0x00, 
0x1f, 0x77, 0xbb, 0x6b, 0xaf, 0xa0, 0x00, 
0x2f, 0xf9, 0xef, 0xf9, 0xee, 0xe8, 0x00, 
0x1f, 0xf5, 0xfd, 0xb6, 0xef, 0xf0, 0x00, 
0x2e, 0xdb, 0x6f, 0xf9, 0xbf, 0xfa, 0x00, 
0x1f, 0xfb, 0xfb, 0x6d, 0xef, 0xdc, 0x00, 
0x2f, 0xf9, 0xbf, 0xfb, 0xed, 0xfe, 0x00, 
0x1f, 0xf5, 0xed, 0xb6, 0xaf, 0xfd, 0x00, 
0x2d, 0xbb, 0x7f, 0xff, 0xef, 0xdd, 0x00, 
0x1f, 0xfa, 0xa2, 0x24, 0xbf, 0x7d, 0x00, 
0x2f, 0xfe, 0xdd, 0xdb, 0x7d, 0xfe, 0x00, 
0x1f, 0xff, 0xff, 0xff, 0xef, 0xfd, 0x00, 
0x2e, 0xdf, 0xff, 0xff, 0xff, 0xfc, 0x00, 
0x1f, 0xfb, 0xbb, 0xbd, 0xff, 0xef, 0x00, 
0x2f, 0xff, 0xff, 0xf7, 0xfd, 0xfc, 0x00, 
0x1f, 0xff, 0xff, 0xff, 0xdf, 0xfe, 0x00, 
0x2e, 0xaa, 0xaa, 0xbe, 0xf7, 0x5d, 0x00, 
0x1f, 0x55, 0x55, 0x42, 0x94, 0xbd, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x00, 
0x1f, 0x7f, 0xff, 0xff, 0xff, 0xb6, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xdd, 0x00, 
0x1f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xbd, 0x00, 
0x1f, 0x7a, 0xaa, 0xaa, 0xaf, 0xdd, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xbe, 0x00, 
0x1f, 0x7f, 0xff, 0xff, 0xff, 0xfd, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xac, 0x00, 
0x1f, 0xff, 0xff, 0xff, 0xff, 0xdf, 0x00, 
0x2e, 0xfa, 0x49, 0x24, 0x8b, 0xbc, 0x00, 
0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xbc, 0x00, 
0x1f, 0x7f, 0xff, 0xff, 0xff, 0xde, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xbd, 0x00, 
0x1f, 0x79, 0x24, 0x92, 0x4f, 0xfd, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x00, 
0x1f, 0x7f, 0xff, 0xff, 0xff, 0xdd, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xbe, 0x00, 
0x1f, 0x7f, 0xff, 0xff, 0xff, 0xfd, 0x00, 
0x2e, 0xff, 0xff, 0xff, 0xff, 0xbd, 0x00, 
0x12, 0xd5, 0x55, 0x55, 0x55, 0x44, 0x00, 
0x2a, 0xaa, 0xaa, 0xaa, 0xaa, 0xb6, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  
};

/*
static const unsigned char PROGMEM logo_clock[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x01, 0x50, 0x00, 0x00, 0x00, 
0x01, 0x54, 0x00, 0x00, 0x2a, 0xa0, 0x00, 
0x04, 0x02, 0x0a, 0xa8, 0x00, 0x08, 0x00, 
0x01, 0x50, 0xa4, 0xa5, 0x55, 0x40, 0x00, 
0x08, 0x0a, 0x92, 0x49, 0x20, 0x2a, 0x00, 
0x05, 0x42, 0x49, 0x24, 0x95, 0x00, 0x00, 
0x10, 0x29, 0x2b, 0xf5, 0x48, 0xaa, 0x00, 
0x0a, 0x8a, 0xbf, 0xde, 0x24, 0x00, 0x00, 
0x20, 0x24, 0xff, 0xff, 0xd2, 0xaa, 0x00, 
0x0a, 0x93, 0xde, 0x3f, 0xe9, 0x01, 0x00, 
0x00, 0x57, 0x7f, 0x3f, 0xf4, 0xa8, 0x00, 
0x15, 0x2b, 0xff, 0x3f, 0xfa, 0x45, 0x00, 
0x01, 0x4f, 0xfb, 0x3d, 0xbd, 0x20, 0x00, 
0x2a, 0x3f, 0xff, 0x3f, 0xfe, 0x94, 0x00, 
0x01, 0x5f, 0xff, 0x37, 0xfe, 0x48, 0x00, 
0x05, 0x3f, 0x6e, 0x3f, 0xf7, 0x20, 0x00, 
0x02, 0x7f, 0xff, 0x3f, 0xbf, 0xa8, 0x00, 
0x04, 0xfd, 0xff, 0x3e, 0xff, 0x90, 0x00, 
0x02, 0x7f, 0xff, 0x2f, 0xff, 0xa4, 0x00, 
0x09, 0xf7, 0xed, 0x3f, 0xfd, 0x90, 0x00, 
0x04, 0xdf, 0xff, 0x3f, 0xf7, 0xc8, 0x00, 
0x02, 0xff, 0xbe, 0x1d, 0xdf, 0xd4, 0x00, 
0x09, 0x7f, 0xfe, 0x1f, 0xff, 0xa0, 0x00, 
0x04, 0xfe, 0xfe, 0x5f, 0xff, 0xd4, 0x00, 
0x02, 0xff, 0xfa, 0x07, 0x7f, 0x88, 0x00, 
0x0a, 0xf7, 0xef, 0xc7, 0xfd, 0xd0, 0x00, 
0x01, 0x7f, 0xfb, 0xc1, 0xf7, 0xa8, 0x00, 
0x0a, 0x7f, 0x77, 0xf1, 0xff, 0x88, 0x00, 
0x01, 0x7d, 0xef, 0xf8, 0x7f, 0xa4, 0x00, 
0x05, 0x77, 0xdf, 0xf8, 0xff, 0x50, 0x00, 
0x00, 0xbf, 0xbf, 0x6f, 0xf7, 0x10, 0x00, 
0x05, 0x1f, 0x7f, 0xff, 0xfe, 0xa0, 0x00, 
0x00, 0xbe, 0xff, 0xff, 0xfd, 0x10, 0x00, 
0x02, 0x4f, 0xff, 0xff, 0xbc, 0xa0, 0x00, 
0x00, 0x97, 0xfd, 0xbd, 0xf5, 0x20, 0x00, 
0x00, 0x45, 0xff, 0xff, 0xf2, 0x40, 0x00, 
0x00, 0x2b, 0xef, 0xf7, 0xd4, 0x80, 0x00, 
0x00, 0x50, 0x7f, 0xff, 0x49, 0x00, 0x00, 
0x00, 0x0a, 0xaf, 0x7d, 0x24, 0x00, 0x00, 
0x00, 0x04, 0x92, 0xd2, 0x92, 0x00, 0x00, 
0x00, 0x2a, 0x49, 0x24, 0x51, 0x00, 0x00, 
0x00, 0x01, 0x24, 0x92, 0x88, 0x40, 0x00, 
0x00, 0x50, 0x52, 0x49, 0x42, 0x00, 0x00, 
0x00, 0x80, 0x0a, 0xa4, 0x01, 0x40, 0x00, 
0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
*/

String commandString;

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    tft.reset();
    uint16_t identifier = tft.readID();
    Serial.print("ID = 0x");
    Serial.println(identifier, HEX);
    if (identifier == 0xEFEF) identifier = 0x9486;
    tft.begin(identifier);
    //  tft.fillScreen(BLACK);
    tft.setRotation(LANDSCAPE);
    tft.fillScreen(BLACK);
    tft.drawRect(0, 0, BOXSIZE_W, BOXSIZE_H, WHITE);
    tft.fillRect(1, 1, FILL_W, FILL_H, BLUE);

    //tft.fillRect(465, 20, 5, 50, YELLOW); // THERMOMETER
    // wifi icon
    tft.drawBitmap(8 , 130,  logo_wifi, 48, 48, WHITE);
    tft.setCursor(155, 145);
    tft.setTextSize(3);
    tft.setTextColor(YELLOW, BLUE);
    tft.print(" dBm");
    //tft.drawLine(1, 172, 480, 172, WHITE);

    // disk icon
    tft.drawBitmap(10 , 175,  logo_disk, 50, 50, WHITE);
    tft.setCursor(170,198);
    tft.setTextSize(3);
    tft.setTextColor(YELLOW, BLUE);
    tft.print(" Free");
    //tft.drawLine(1, 225, 480, 225, WHITE);

    // clock icon
    //tft.drawBitmap(10 , 225,  logo_clock, 50, 50, YELLOW);
    
    // line reference
    tft.drawLine(1, 75, 480, 75, WHITE);
    //thermometer
    tft.fillRoundRect(10, 45, 25, 25, 10, YELLOW);
    tft.drawRect(16, 20, 13, 30, YELLOW);
    tft.fillRect(16, 38, 13, 10, YELLOW);
    tft.setTextColor(YELLOW, BLUE);
    tft.setTextSize(5);
    tft.setCursor(165,35);
    //tft.print((char)247);
    // degree symbol
    tft.fillCircle(150, 45, 8, YELLOW);
    tft.fillCircle(150, 45, 5, BLUE);
    tft.print("C");
    
    //antena
    tft.fillRect(414, 20, 3, 5, GREEN); // ant
    tft.fillRect(417, 20, 3, 50, GREEN); // ant center
    tft.fillRect(420, 20, 3, 5, GREEN); // ant

    // cpu
    tft.setTextColor(BLACK, CYAN);
    tft.setTextSize(3);
    tft.setCursor(13,80);
    tft.print(" CPU ");

    // tx/rx
    tft.setTextColor(BLACK, CYAN);
    tft.setTextSize(3);
    tft.setCursor(13,110);
    tft.print(" TX/RX ");

    // clock
    tft.fillRoundRect(5, 228, 471, 87, 5, MAGENTA);
}

//char *msg[] = { "PORTRAIT", "LANDSCAPE", "PORTRAIT_REV", "LANDSCAPE_REV" };
//uint8_t aspect;

void loop()
{
    // put your main code here, to run repeatedly:
    while (Serial.available()) {      
      // read the bytes incoming from the client:
      char newChar = Serial.read();

      if (newChar == 0x0D)  //If a 0x0D is received, a Carriage Return, then evaluate the command
      {
         if (commandString == "off"){
           //display.clearDisplay();
           //display.display();
           //Serial.println(commandString);
           commandString = "";
           return;
         } else {
           processCommand(commandString);
         }
      } 
      else
      {
           commandString += newChar;
           //Serial.println(newChar);
      }
    }
}

void processCommand(String command)
{
    Serial.println(command);

    if (command == "sinyal100")
    {
        // digitalWrite(led, LOW); // off
        //display.clearDisplay();
        // erase old draw  using black rectangle
        tft.fillRect(413, 19, 58, 52, BLUE);
        //draw signal
        tft.fillRect(414, 20, 3, 5, GREEN); // ant
        tft.fillRect(417, 20, 3, 50, GREEN); // ant center
        tft.fillRect(420, 20, 3, 5, GREEN); // ant
        tft.fillRect(425, 60, 5, 10, GREEN); // 20
        tft.fillRect(435, 50, 5, 20, GREEN); // 40
        tft.fillRect(445, 40, 5, 30, GREEN); // 60
        tft.fillRect(455, 30, 5, 40, GREEN); // 80
        tft.fillRect(465, 20, 5, 50, GREEN); //100
        //Serial.println(command);
        commandString = "";
        return;
    }
    else if (command == "sinyal80")
    {
        // digitalWrite(led, LOW); // off
        //display.clearDisplay();
        // erase old draw  using black rectangle
        //tft.fillRect(413, 19, 58, 52, BLUE);
        tft.fillRect(465, 20, 5, 50, BLUE); //100
        //draw signal
        tft.fillRect(414, 20, 3, 5, GREEN); // ant
        tft.fillRect(417, 20, 3, 50, GREEN); // ant center
        tft.fillRect(420, 20, 3, 5, GREEN); // ant
        tft.fillRect(425, 60, 5, 10, GREEN); // 20
        tft.fillRect(435, 50, 5, 20, GREEN); // 40
        tft.fillRect(445, 40, 5, 30, GREEN); // 60
        tft.fillRect(455, 30, 5, 40, GREEN); // 80
        //tft.fillRect(465, 20, 5, 50, GREEN); //100
        //Serial.println(command);
        commandString = "";
        return;
    }
    else if (command == "sinyal60")
    {
        // digitalWrite(led, LOW); // off
        //display.clearDisplay();
        // erase old draw  using black rectangle
        //tft.fillRect(413, 19, 58, 52, BLUE);
        tft.fillRect(455, 30, 5, 40, BLUE); // 80
        tft.fillRect(465, 20, 5, 50, BLUE); //100
        //draw signal
        tft.fillRect(414, 20, 3, 5, GREEN); // ant
        tft.fillRect(417, 20, 3, 50, GREEN); // ant center
        tft.fillRect(420, 20, 3, 5, GREEN); // ant
        tft.fillRect(425, 60, 5, 10, GREEN); // 20
        tft.fillRect(435, 50, 5, 20, GREEN); // 40
        tft.fillRect(445, 40, 5, 30, GREEN); // 60
        //tft.fillRect(455, 30, 5, 40, GREEN); // 80
        //tft.fillRect(465, 20, 5, 50, GREEN); //100
        //Serial.println(command);
        commandString = "";
        return;
    }
    else if (command == "sinyal40")
    {
        // digitalWrite(led, LOW); // off
        //display.clearDisplay();
        // erase old draw  using black rectangle
        //tft.fillRect(413, 19, 58, 52, BLUE);
        tft.fillRect(445, 40, 5, 30, BLUE); // 60
        tft.fillRect(455, 30, 5, 40, BLUE); // 80
        tft.fillRect(465, 20, 5, 50, BLUE); //100
        //draw signal
        tft.fillRect(414, 20, 3, 5, GREEN); // ant
        tft.fillRect(417, 20, 3, 50, GREEN); // ant center
        tft.fillRect(420, 20, 3, 5, GREEN); // ant
        tft.fillRect(425, 60, 5, 10, GREEN); // 20
        tft.fillRect(435, 50, 5, 20, GREEN); // 40
        //tft.fillRect(445, 40, 5, 30, GREEN); // 60
        //tft.fillRect(455, 30, 5, 40, GREEN); // 80
        //tft.fillRect(465, 20, 5, 50, GREEN); //100
        //Serial.println(command);
        commandString = "";
        return;
    }
    else if (command == "sinyal20")
    {
        // digitalWrite(led, LOW); // off
        //display.clearDisplay();
        // erase old draw  using black rectangle
        //tft.fillRect(413, 19, 58, 52, BLUE);
        tft.fillRect(435, 50, 5, 20, BLUE); // 40
        tft.fillRect(445, 40, 5, 30, BLUE); // 60
        tft.fillRect(455, 30, 5, 40, BLUE); // 80
        tft.fillRect(465, 20, 5, 50, BLUE); //100
        // draw signal
        tft.fillRect(414, 20, 3, 5, GREEN); // ant
        tft.fillRect(417, 20, 3, 50, GREEN); // ant center
        tft.fillRect(420, 20, 3, 5, GREEN); // ant
        tft.fillRect(425, 60, 5, 10, GREEN); // 20
        //tft.fillRect(435, 50, 5, 20, GREEN); // 40
        //tft.fillRect(445, 40, 5, 30, GREEN); // 60
        //tft.fillRect(455, 30, 5, 40, GREEN); // 80
        //tft.fillRect(465, 20, 5, 50, GREEN); //100
        //Serial.println(command);
        commandString = "";
        return;
    }
    else if (command == "sinyal0")
    {
        // digitalWrite(led, LOW); // off
        //display.clearDisplay();
        // erase old draw  using black rectangle
        //tft.fillRect(413, 19, 58, 52, BLUE);
        tft.fillRect(425, 60, 5, 10, BLUE); // 20
        tft.fillRect(435, 50, 5, 20, BLUE); // 40
        tft.fillRect(445, 40, 5, 30, BLUE); // 60
        tft.fillRect(455, 30, 5, 40, BLUE); // 80
        tft.fillRect(465, 20, 5, 50, BLUE); //100
        //draw signal
        tft.fillRect(414, 20, 3, 5, GREEN); // ant
        tft.fillRect(417, 20, 3, 50, GREEN); // ant center
        tft.fillRect(420, 20, 3, 5, GREEN); // ant
        //tft.fillRect(425, 60, 5, 10, GREEN); // 20
        //tft.fillRect(435, 50, 5, 20, GREEN); // 40
        //tft.fillRect(445, 40, 5, 30, GREEN); // 60
        //tft.fillRect(455, 30, 5, 40, GREEN); // 80
        //tft.fillRect(465, 20, 5, 50, GREEN); //100
        //Serial.println(command);
        commandString = "";
        return;
    }
    else if ((command == "kutukupret") && (command.length() <= 15))
    {
        // digitalWrite(led, LOW); // off
        // erase old string using fillrect
        tft.fillRect(1, 155, 478, 45, BLUE);
        tft.setCursor(16, 160);
        tft.setTextSize(5);
        //tft. setTextColor(RED, YELLOW);
        tft. setTextColor(RED);
        tft.print("KUTUKUPRET");
        tft.println((char)247);
        commandString = "";
        command = "";
        return;
    }
    else if(command.indexOf(" ") > -1)
    {
          for (int i = 0; i < command.length(); i++) {
            if (command.substring(i, i+1) == " ") {
              value1 = command.substring(0, i);
              value2= command.substring(i+1);
              break;
            }
          }
          if (value1 == "clock")
          {
              // erase old value2 first using filled rectangle, mask with background color
              //tft.fillRoundRect(6, 229, 469, 85, 5, MAGENTA);
              // write new value2
              tft.setCursor(30,250);
              tft.setTextSize(7);
              tft.setTextColor(BLUE, MAGENTA);
              if (value2.length() == 8)
              {
                  tft.print(" " + value2);
              }
              //Serial.println(command);
              commandString = "";
              value1 = "";
              value2 = "";
              return;
          }
           else if (value1 == "temper")
           {
              // erase old value2 first using filled rectangle
              //tft.fillRect(43, 33, 150, 40, BLUE);
              // write new value2
              tft.setTextColor(YELLOW, BLUE);
              tft.setTextSize(5);
              tft.setCursor(45,35);
              if (value2.length() == 2)
              {
                  tft.print(" " + value2);
              }
              else if (value2.length() == 3)
              {
                  tft.print(value2);
              }
              //tft.display();
              //Serial.println(command);
              commandString = "";
              value1 = "";
              value2 = "";
              return;
          }
           else if (value1 == "proc")
           {
              // erase old value2 first using filled rectangle, mask with background color
              tft.fillRect(110, 79, 100, 25, BLACK);
              // write new value2
              tft.drawRect(110, 79, 100, 25, RED);
              tft.fillRect(110, 79, value2.toInt(), 25, RED);
              tft.setCursor(210,80);
              tft.setTextSize(3);
              tft.setTextColor(WHITE, BLUE);
              if (value2.length() == 2)
              {
                  tft.print("   " + value2);
              }
              else if (value2.length() == 3)
              {
                  tft.print("  " + value2);
              }
              else if (value2.length() == 4)
              {
                  tft.print(" " + value2);
              }
              //Serial.println(command);
              commandString = "";
              value1 = "";
              value2 = "";
              return;
          }
           else if (value1 == "txrx")
           {
              // erase old value2 first using filled rectangle, mask with background color
              //tft.fillRect(140, 109, 339, 25, BLUE);
              // write new value2
              tft.setCursor(140, 110);
              tft.setTextSize(3);
              tft.setTextColor(WHITE, BLUE);
              if (value2.length() == 2)
              {
                  tft.print("          " + value2);
              }
              else if (value2.length() == 3)
              {
                  tft.print("         " + value2);
              }
              else if (value2.length() == 4)
              {
                  tft.print("        " + value2);
              }
              else if (value2.length() == 5)
              {
                  tft.print("       " + value2);
              }
              else if (value2.length() == 6)
              {
                  tft.print("      " + value2);
              }
              else if (value2.length() == 7)
              {
                  tft.print("     " + value2);
              }
              else if (value2.length() == 8)
              {
                  tft.print("    " + value2);
              }
              else if (value2.length() == 9)
              {
                  tft.print("   " + value2);
              }
              else if (value2.length() == 10)
              {
                  tft.print("  " + value2);
              }
              else if (value2.length() == 11)
              {
                  tft.print(" " + value2);
              }
              //Serial.println(command);
              commandString = "";
              value1 = "";
              value2 = "";
              return;
          }
          else if (value1 == "wifi")
          {
              // erase old value2 first using filled rectangle, mask with background color
              //tft.fillRect(60, 143, 418, 28, BLUE);
              // write new value2
              tft.setCursor(60,145);
              tft.setTextSize(3);
              tft.setTextColor(YELLOW, BLUE);
              if (value2.length() == 2)
              {
                  tft.print("   " + value2);
              }
              else if (value2.length() == 3)
              {
                  tft.print("  " + value2);
              }
              else if (value2.length() == 4)
              {
                  tft.print(" " + value2);
              }
              //Serial.println(command);
              commandString = "";
              value1 = "";
              value2 = "";
              return;
          }
          else if (value1 == "disk")
          {
              // erase old value2 first using filled rectangle, mask with background color
              //tft.fillRect(65, 195, 414, 30, BLUE);
              // write new value2
              tft.setCursor(60,198);
              tft.setTextSize(3);
              tft.setTextColor(YELLOW, BLUE);
              if (value2.length() == 2)
              {
                  tft.print("    " + value2);
              }
              else if (value2.length() == 3)
              {
                  tft.print("   " + value2);
              }
              else if (value2.length() == 4)
              {
                  tft.print("  " + value2);
              }
              else if (value2.length() == 5)
              {
                  tft.print(" " + value2);
              }
              //Serial.println(command);
              commandString = "";
              value1 = "";
              value2 = "";
              return;
          }        
          else
          {
              //Serial.println(command);
              value1 = "";
              value2 = "";              
              commandString = "";
              return;                
          }
    }
    else
    {
        //Serial.println(command);
        commandString = "";
        return;      
    }
}
