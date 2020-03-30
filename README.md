# WheeCAIR
Cullowhee Clean Air Sensor

# Hardware

**Table S.1: Bill of Materials for wheeCAIR sensor**  

| Item                                      | PN                     | Price   | Qty | Supplier |
| ----------------------------------------- | ---------------------- | ------- | --- | -------- |
| Sensor, BME 680                           | 1597-1653-ND           | $20.910 | 1   | digikey  |
| Sensor, PM, Honeywell                     | 785-HPMA115SO-XXX      | $26.340 | 1   | mouser   |
| Micro SD                                  | SDSDQM-B35A            | $4.500  | 1   | Amazon   |
| Teensy 3.5                                | 1568-1443-ND           | $26.250 | 1   | digikey  |
| USB Cable                                 | WM25438-ND             | $3.710  | 1   | digikey  |
| Case                                      | Lowes                  | $7.150  | 1   | Lowes    |
| Case Port                                 | Lowes                  | $1.690  | 0.5 | Lowes    |
| Breadboard                                | 1738-1326-ND           | $2.990  | 1   | digikey  |
| Wire, Hookup, Assortment, 10x25'          | 485-3174               | $29.950 | 0.1 | mouser   |
| Pin headers, Breakaway, 36 position, 0.1" | WM50014-36-ND          | $0.901  | 2   | digikey  |
| LED, RGB                                  | 1830-1014-ND           | $0.829  | 1   | digikey  |
| Resistor, 220 ohm                         | CF12JT220RCT-ND        | $0.072  | 1   | digikey  |
| Thermistor                                | BC2301-ND              | $0.660  | 1   | digikey  |
| Resistor, 1k                              | S1KQTR-ND              | $0.004  | 1   | digikey  |
| Capacitor, Electrolytic, 1000uF           | P19639TB-ND            | $0.310  | 1   | digikey  |
| Relay                                     | TLP222AF-ND            | $1.013  | 1   | digikey  |
| Header, 5 Position, 0.1                   | S6103-ND               | $0.443  | 1   | digikey  |
| Header, 24 Position, 0.1                  | S7022-ND               | $1.244  | 2   | digikey  |
| Retainer, Coin Cell, 12 MM, SMD           | 36-3000CT-ND           | $0.767  | 1   | digikey  |
| Terminal, 4 Position, 3.5 mm              | WM7860-ND              | $1.121  | 2   | digikey  |
| Terminal, 2 Position, 3.5 mm              | WM7877-ND              | $0.718  | 1   | digikey  |
| Batteries, AA, Duracell Procell, 2900 mAh | PC1500BKD              | $0.520  | 6   | Grainger |
| Batteries, Coin Cell, CR1220              | P033-ND                | $0.828  | 1   | digikey  |
| Wire, PicoBlade, Pre-crimped, black       | 0500798000-10-B8-ND    | $0.676  | 1   | digikey  |
| Wire, PicoBlade, Pre-crimped, yellow      | 0500798000-10-Y8-ND    | $0.676  | 1   | digikey  |
| Wire, PicoBlade, Pre-crimped, red         | 0500798000-10-R8-ND    | $0.676  | 1   | digikey  |
| Wire, PicoBlade, Pre-crimped, violet      | 0500798000-10-V8-ND    | $0.676  | 1   | digikey  |
| PCB, Custom                               | WheeCAir v1.0 (custom) | $6.820  | 1   | OSH Park |

*Prices are accurate as of December 2019.*

# Firmware

The wheeCAIR sensor is programmed using the Arduino IDE and Teensyduino addon (both freely availble).  Place the firmware files in a `wheeCAIR` folder and open `wheeCAIR.ino` with the Arduino IDE.

## Function Descriptions

The following functions are available for programming your sensors.  You will need to use all of them, and you might use some twice.  Combine them according to the flow chart provided.

Remember, most functions take the form of `function(argument);`, where the argument is used in completing the function.  Some functions do not require an argument, and others require multiple.  The arguments are provided below where needed and should be used verbatim.

- `alarm.setRtcTimer(0, 0, 0);`: Set the hibernation interval on the Teensy in Hours, Minutes, and Seconds.

- `createFileName(year(), month(), day()).toCharArray(dataFileName, 16);`: Generate a file name following a standard format of `YYYYMMDD.txt`; this is used to store the data on the SD card.

- `initializeSensors();`: Turn the sensors on and go through initialization procedure; no argument necessary.

- `initializeSDCard();`: Start the SD card reader on the Teensy; no argument necessary.

- `Serial.Begin(9600);`: Start the serial port at 9600 bits per second (baud).

- `Serial.println(dataString);`: Print the data to the serial port of the computer; useful for debugging.

- `Snooze.hibernate(teensySleep);`: Put the Teensy into hibernation mode for the time specified in `alarm.setRtcTimer(H, M, S);`.

- `setSyncProvider(getTeensy3Time);`: Update/set the time on the Teensy's real time clock (RTC).  Must be done after every hibernation.

- `String dataString = makeMeasurement(30);`: Create a string called `dataString`, make measurement for *n* (e.g. 30) seconds, and store the data in `dataString`.

- `turnOffSensors();`: Turn the sensors off before hibernating the Teensy; no argument necessary.

- `wakeSensors();`: Turn on the sensors after hibernating the Teensy; no argument necessary.

- `writeFile(dataFileName, dataString);`: Stores the `dataString` from the sensors to the `dataFileName` file on the SD card.


# Data

## Directory Structure

The generalized directory structure is:

`./data/location-code/year/YYYYMMDD_sensorCode.txt`

### Directory Map

```
WheeCAIR
       |----- data
       |         |----- [location] (see codes below)
       |                       |----- [year] > [date_sensorName].txt
       |                                 |   > [location-year].jmd or .jl - Julia data processing code
       |                                 |   > [location-year].html - HTML formatted lab notebook
       |                                 |----- datasheets > datasheets completed at deployment
       |                                 |----- img > Webcam/weather images (if available)
       |                                 |----- met > meteorology data (if available)
       |                                 |----- plots > PDFs of key figures
       |----- firmware > code used program sensors
       |----- hardware > hardware info
       |----- docs > html to serve (notebooks)
```

### Location Codes:
  - **grsm-purchase:** Great Smoky Mountains National Park - Purchase Knob
  - **mack:** Dillsboro, NC
  - **wcu-nsb:** Western Carolina University - Natural Science Building (co-located with PM10 inlet)
