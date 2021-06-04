#include <TimeLib.h>
#include <Snooze.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include <hpma115s0.h>
#include <SD.h>

bool my_status;
float p25;
float p10;
String dataString;
char dataFileName[16];
const int chipSelect = BUILTIN_SDCARD;

Sd2Card  card;
Adafruit_BME680 bme; // I2C
HPMA115S0 my_hpm(Serial1);

SnoozeAlarm alarm;
SnoozeSPI sdCard;
SnoozeBlock config_teensy35(alarm, sdCard);

String fillDigits(int digits) {
  if (digits < 10) {
    String digitsout = "0" + String(digits);
    return digitsout;
  }
  else return digits;
}

String createFileName(int y, int m, int d) {
    return String(fillDigits(y)) + String(fillDigits(m)) + String(fillDigits(d)) + ".txt";
}

void setBMESamplingParameters() {
  if (!bme.begin(0x76)) {
    return;
  }
  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}

time_t getTeensy3Time() {
  return Teensy3Clock.get();
}

void turnSensorsOn() {
  digitalWrite(33, HIGH); // turn on relay
  delay(5000); // wait to stabilize
  setSyncProvider(getTeensy3Time);

  Serial1.begin(9600);
  while (!Serial1) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial1.flush();
  my_status = my_hpm.stop_autosend();
  delay(500);
  my_status = my_hpm.start_measurement();  
  delay(500); 
}

void turnSensorsOff() {
  my_status = my_hpm.stop_measurement();
  Serial1.end();
  delay(500);
  digitalWrite(33, LOW);
}

void blink() {
    digitalWriteFast(LED_BUILTIN, HIGH);
    delay(250);
    digitalWriteFast(LED_BUILTIN, LOW);
    delay(250);
}



// ---------------------------

String printTime(int h, int m, int s) {
  return fillDigits(h) + ":" + fillDigits(m) + ":" + fillDigits(s);
}

String printDate(int y, int m, int d) {
  return String(y) + "-" + fillDigits(m) + "-" + fillDigits(d);
}

String printDateTime(String d, String t) {
  return d + ' ' + t;
}

String printData(String ID, float t, float h, float p, float g, float pm25) {
  return String(ID) + '\t' + printDateTime(printDate(year(), month(), day()), printTime(hour(), minute(), second())) + '\t' + String(t) + '\t' + String(h) + '\t' + String(p/100.0) + '\t' + String(g/1000.0)+ '\t' + String(pm25);
}

//////

float performPMReading(int n) {
    float pavg = 0.0;
    float psum = 0.0;
    
    for (int i = 1; i < n; i++) {
      my_status = my_hpm.read(&p25, &p10);
      if (i > 15) {         // throw away first points while it warms up
          psum = psum + p25;
          pavg = (psum)/(float(i)-15.0);
        }   
          delay(1000);    
    }
    if (pavg > 0) {
      return pavg;
    }
    else {
      return -999;
    }
}

void writeFile(char filename[16], String dataString) {
    File dataFile = SD.open(filename, FILE_WRITE);
    if (dataFile) {
        dataFile.println(dataString);
        delay(500);
        dataFile.close();
//        Serial.println("if");
     }
     else {
//      Serial.println("else");
      delay(1000);
      return;
     }
}

void checkConnection() {
  if (my_status == 1){
//    Serial.println("Autosend disabled");
    for (int i = 1; i < 6; i++){
      blink();
    }
    
    delay(3000);
  }
  else{
//    Serial.println("Autosend Error");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(5000);  
    digitalWrite(LED_BUILTIN, LOW);
  }

   if (!SD.begin(chipSelect)) {
    return;
  }
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
        // don't do anything more:
        while (1) {
            blink();
            blink();
        }
    }
    for (int i = 1; i < 3; i++){
      blink();
    }
}
