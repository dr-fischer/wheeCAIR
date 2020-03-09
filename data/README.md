# Directory Structure

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

# Location Codes

- **grsm-purchase:** Purchase Knob, Great Smoky Mountains National Park
- **mack:** Dillsboro, NC
- **wcu-nsb:** Natural Science Building, Western Carolina University, Cullowhee, NC (outdoor)
