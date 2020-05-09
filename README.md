# TEA5767_Encoder_Serial  
Simple FM Radio using TEA5767 and Rotary Encoder.(Serial Output)  
## Wiring:  
  
### TEA5767------------------>Arduino  
SDA-------------SDA  
SCL-------------SCL  
VCC-------------3.3V  
GND-------------GND  
10K Pull-Up Resistors between SDA to 3.3V and SCl to 3.3V. 
  
### Rotary Encoder ---------->Arduino  
+----------------5V  
GND--------------GND  
SW---------------10  
DT---------------9  
CLK--------------8  
10K Pull-Up Resistor between SW and 5V.  

## Usage:
1. Use rotary encoder to tune into desired station.    
2. Push rotary encoder switch to select the staion.  
