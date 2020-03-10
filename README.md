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

# Data

## Directory Structure

The generalized directory structure is:

`./data/location-code/year/YYYYMMDD_sensorCode.txt`

### Directory Map

```
WheeCAIR
       |----- data
       |         |----- location (see codes below)
       |                       |----- year > date_sensorName.txt
       |                                 | > .jmd or .jl Julia data processing code
       |                                 |----- met > meteorology data (if available)
       |                                 |----- datasheets > datasheets completed at deployment
       |----- firmware > code used program sensors
       |----- hardware > hardware info
```

### Location Codes:
  - **grsm-purchase:** Great Smoky Mountains National Park - Purchase Knob
  - **mack:** Dillsboro, NC
  - **wcu-nsb:** Western Carolina University - Natural Science Building (co-located with PM10 inlet)
