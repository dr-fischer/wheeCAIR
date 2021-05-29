String deviceID = "MACK"; 

#include "wheeCAIR_serial.h"

void setup() {
  setSyncProvider(getTeensy3Time);
  pinMode(33, OUTPUT);
  turnSensorsOn(); 
  pinMode(LED_BUILTIN, OUTPUT);
  createFileName(year(), month(), day()).toCharArray(dataFileName, 16);
  setBMESamplingParameters();
  Serial.begin(9600);
  checkConnection();
}

void loop() {
  bme.performReading();
  float pavg = performPMReading(30); // enter number of averages, n; actual number of averages is n-15
  dataString = printData(deviceID, bme.temperature, bme.humidity, bme.pressure, bme.gas_resistance, pavg);
  delay(100);
  Serial.println(dataString);
  delay(1000);
  writeFile(dataFileName, dataString);
  delay(500);
}
