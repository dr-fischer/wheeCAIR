# Directory Structure

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

# Location Codes

- **grsm-purchase:** Purchase Knob, Great Smoky Mountains National Park
- **mack:** Dillsboro, NC
- **wcu-nsb:** Natural Science Building, Western Carolina University, Cullowhee, NC (outdoor)
