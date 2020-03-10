String deviceID = "MACK"; // change length of array in 3 places

#include "wheeCAIR.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(33, OUTPUT);
  turnSensorsOn();
  alarm.setRtcTimer(0, 0, 10); // h, m, s
  pinMode(LED_BUILTIN, OUTPUT);
  sdCard.spiClockPin(chipSelect);
  createFileName(year(), month(), day()).toCharArray(dataFileName, 16);
  setBMESamplingParameters();
  Serial.begin(9600);
  checkConnection();
  turnSensorsOff();
}

void loop() {
  // put your main code here, to run repeatedly:
  Snooze.hibernate(config_teensy35); 
  turnSensorsOn();
  bme.performReading();
  float pavg = performPMReading();
  dataString = printData(deviceID, bme.temperature, bme.humidity, bme.pressure, bme.gas_resistance, pavg);
  delay(100);
//  Serial.println(dataString);
  delay(1000);
//  Serial.println(dataFileName);
  writeFile(dataFileName, dataString);
  delay(500);
  turnSensorsOff();
}
