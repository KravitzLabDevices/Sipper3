/********************************************************
  Include these libraries
********************************************************/
#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
#include <SdFat.h>
SdFat SD;             //Quick way to make SdFat work with standard SD.h sketches
#include <Adafruit_GFX.h>
#include <TimeLib.h> //include the Arduino Time library
#include <FlashStorage.h>
#include "Adafruit_FreeTouch.h"
#include "ArduinoLowPower.h"

/********************************************************
  Initialize FreeTouch
********************************************************/
Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A1, OVERSAMPLE_64, RESISTOR_20K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A2, OVERSAMPLE_64, RESISTOR_20K, FREQ_MODE_NONE);
int sensitivity = 5;  //modify this to change sensitivity to touch
int baseline1 ;
int baseline2 ;

/********************************************************
  Initialize RTC
********************************************************/
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

/********************************************************
  Feather pins being used
********************************************************/
#define RED_LED 13
#define GREEN_LED 8
#define LeftSip A1
#define RightSip A2
#define VBATPIN A7
#define cardSelect 4
#define buzzer A0

/********************************************************
  Initialize variables
********************************************************/
int Sip = 1; //device number
int LeftCount = 0;
int RightCount = 0;
int LeftDuration = 0;
int RightDuration = 0;
unsigned long StartTime;
float measuredvbat;
int wakecounter = 0;

/********************************************************
  Setup SD card
********************************************************/
void dateTime(uint16_t* date, uint16_t* time) {
  DateTime rnow = rtc.now();
  // return date using FAT_DATE macro to format fields
  *date = FAT_DATE(rnow.year(), rnow.month(), rnow.day());

  // return time using FAT_TIME macro to format fields
  *time = FAT_TIME(rnow.hour(), rnow.minute(), rnow.second());
}

File logfile;         // Create file object
char filename[21];    // Array for file name data logged to named in setup
