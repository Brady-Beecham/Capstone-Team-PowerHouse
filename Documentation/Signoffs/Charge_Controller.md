# Charge Controller Subsystem

The purpose of the charge controller subsystem is to maximize the power output of the solar panel and send power to the system, specifically the Power Controller subsystem. The charge controller will send the power controller 12 V at 50 mA regardless of the output of the solar panel. If the power received from the panel is more than what is required by the system, the excess power will be used to charge the two backup batteries. Otherwise, the backup batteries will supplement the solar panel output until the required system power is met. 

# Constraints
| No. | Constraints | Origin |
| --- | ----------- | ------ |
| 1.  | Controller shall maximize the output power from the solar panel. | System Requirements |
| 2.  | Controller shall output 12 V with a 10% tolerance to the Power Controller. | System Requirements |
| 3.  | Controller shall prevent the batteries from discharging more than 50% of their maximal capacity. | Extend Life of Batteries    |
| 4.  | Controller shall prevent the batteries from being charged more than 95% of their maximal capacity.  | Extend Life of Batteries    |

1. The subsystem shall maximize the output power from the solar panel. Solar panels can only generate power when they are placed in sunlight. Sunlight, while abundant, only lasts for half of a day on a clear summer day. The other half of the day, or on a rainy day, no power is generated from the solar panel. While the solar panels are able to generate power from the sun, the power needs to be maximized to make up for being unable to generate power at other times. 
2. The subsystem shall output 12 V at 50 mA with a 10% tolerance to the Power Controller. 50 mA is required to power all of the subsystems. 12 V is used to match the voltage of the backup batteries. 
3. The subsystem shall prevent the batteries from discharging more than 50% of their maximum capacity. This constraint is to prevent the batteries from deep discharge. Deep discharge prematurley ages the battery. To ensure the batteries are able to be used for as long as possible, deep discharge protection is necessary.
4. The subsystem shall prevent the batteries from charging more than 95% of their maximum capacity. This constraint is to prevent the batteries from overcharging. Overcharging can cause the overheating and long term damage to the batteries. To ensure the batteries are able to be used for as long as possible, overcharge protection is necessary. 

*Figure 1. Charge Controller Schematic*

![ChargeControllerSchematic](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/c2b2df89-f01d-4235-8380-fac168b3c779)

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/9747e6d6-a8f2-4858-9b76-fd6fab358187)

*Figure 2. Panel Dimensions*    


 ![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/fd162e54-20aa-4a76-92f4-9bdce27a9ec5)
 ![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/bf5d8d58-b88e-4fcc-ba54-afad7f79ded0) 

 *Figure 3. Single Battery Dimensions*

# Analysis
## Solar Panel


## Battery
Two MightyMax ML12-12 batteries will be used. The battery type is Sealed Lead Acid AGM. The sealed lead acid has a depth of discharge of 50%, and the battery's efficiency is 85 %. The two batteries will be connected in parallel to increase the global capacity of the battery, which is rated by amps per hour. The temperature factor is 1.19.

The batteries will be located outdoors; therefore, the discharge capacity according to the temperature should be considered. The discharge capacity for the battery being outdoors for 20 hours at a temperature of -15 C will reduce the battery capacity to 65%.

```math
Battery\ Capacity (Ah) = \ \frac{Daily\ Electrical\ Load\ \times\ Days\ of\ Autonomy\ \times\ Temperature\ Compensation\ }{Load\ Subsystem\ Efficiency\ \times\ Depth\ of\ Discharge\ \times\ Voltage}
```
```math
```
```math
=>Battery\ Capacity (Ah)= \ \frac{ 22.5 \times\ 3 \times\ 1.19 }{ 0.85 \times\ 0.5 \times\ 12}
```
```math
```
```math
Battery\  Capacity (Ah) =\ 15.75\ Ah
```
For a battery capacity of 15.75 Ah, increasing the battery capacity is considered a good practice when choosing battery capacity for a solar power system. Also, considering the depth of discharge and other loss power factors, the desired battery capacity will be 24 Ah, which means we will need two batteries with 12 V and 12 Ah in parallel. Since connecting a battery in parallel will increase the battery capacity, the battery capacity will increase to 24 Ah, and the battery voltage will remain the same at 12 V. 


## Arduino Nano
U6 is the Arduino Nano. It will receive inputs from U2, U4, U5, and a voltage read from a voltage divider. It will output to U1, U3, U5, Q1, and Q2. 

The input from U2, a current sensor to read output current from the solar panel,  and the voltage divider, to read output voltage from solar panel, will be used for the Maximum Power Point Tracking algorithm. The algorithm will send digital signals to U1, the digital potentiometer, to adjust the resistance of the solar panel output. This change of resistance will change the amount of power being output from the solar panel. The algorithm will continually change the resistance trying to find the maximum power output from the solar panel. 


## Current Sensors
U2 can output up to a maximum of 8 V. The Arduino is only able to read up to a maximum of 5 V. A voltage divider will be used on the output of the current sensor to change the output to have a maximum voltage of 5 V. 

Analysis of resistors required to divide 8 V down to 5 V (U2 and U4):

```math
Vout\ =Vin\times\frac{R1}{R1 + R2}
```
```math
5\ = 8\times\frac{10,000}{10,000 + R2} = 6 kΩ
```
R1 is arbitrarily chosen to be 10 kΩ. R2 is calculated to be 6 kΩ.

## Solar Output Voltage
To read the voltage being output from the solar panel, a voltage divider will be used to change the maximum output voltage of the solar panel, 18 V, to a voltage that the arduino can handle, 4.5 V. 

Analysis of resistors required to divide 18 V down to 4.5 V
```math
{\rm V}_{out}\ =Vin\times\frac{R3}{R3 + R4}
```
```math
5\ = 18\times\frac{10,000}{10,000 + R4} = 30 kΩ
```
R3 is arbitrarily chosen to be 10 kΩ. R4 is calculated to be 30 kΩ. 

## LT3120 MPPC BuckBoost Converter
The Maximal Power Point Control Buck-Boost will be activated at 5 V and output a steady 12 V. 

### Datasheet Provided Values
```math
C_{Vin}\ = 100 uF
```
```math
C_{BST1}\ = 0.22 uF
```
```math
C_{BST2}\ = 0.22 uF
```
```math
C_{BST3}\ = 22 uF
```
```math
C_{VCC}\ = 4.7 uF (LowESRCeramicCapacitor)
```
```math
V_{FB} = 1.25 V 
```
### Desired Input and Output
```math
V_{IN(max)} = 18 V
```
```math
V_{IN(min)} = 5 V
```
```math
V_{OUT} = 12 V
```
### Output Voltage Programming
R_FB2 is nominally chosen to be 10 kΩ
```math
V_{OUT} = 0.795\times(1+\frac{R_{FB1}}{ R_{FB2}})
```
```math
=>R_{FB1}\ = 12\times\frac{10,000}{0.795} - 10,000
```
```math
```
```math
R_{FB1}\ = 141 kΩ
```
```math
R_{FB1}\ = 10 kΩ
```
### Programming Custon Vin Enable thresholds:
The input voltage threshold is desired to be at 5 V. TODO: EXPLAIN WHY--------------------------------------------
```math
V_{th(rising)} = 1.205 \times\ \frac{R_{EN1} + R_{EN2}}{R_EN2}
```
R_en2 is arbitrarily set to 10 kΩ
```math
=>R_{EN1} = 5 \times\ \frac{10,000}{1.205} - 10,000
```
```math
```
```math
R_{EN1} = 31,493 Ω = 30 kΩ
```
```math
R_{EN2} = 10 kΩ
```
### Programming Custom Vin Hysteresis:
```math
V_{HYST}\ = ((R_{HY} \times\ R_{EN1}) + (R_{HY}\times\ R_{EN2}) + (R_{EN1}\times\ R_{EN2})) \times\ \frac{0.25 \times\ 10^{-6}}{R_{EN2}} + (0.09 \times\ \frac{R_{EN1} + R_{EN2}}{R_{EN2}})
```
V_hyst is set to be 1 V
```math
=>1\ = ((R_{HY} \times\ 30,000) + (R_{HY}\times\ 10,000) + (30,000\times\ 10,000)) \times\ \frac{0.25 \times\ 10^{-6}}{10,000} + (0.09 \times\ \frac{30,000 + 10,000}{10,000})
```
```math
```
```math
R_{HY}\ = 632,500 Ω = 630 kΩ
```
### MPPC Programming
Vmppc should be 75% of the solar panel's open circuit voltage, 16.8 V. R_mppc2 should be between 50 kΩ and 250 kΩ.
R_mppc2 is arbitrarily chosen to be 100 kΩ.
```math
V_{MPPC}\ = 0.795\times(1+\frac{R_{MPPC1}}{ R_{MPPC2}})
```
```math
=>R_{MPPC1}\ = 16.8\times\frac{100,000}{0.795} - 100,000
```
```math
```
```math
R_{MPPC1}\ = 2,014,150 Ω = 2 MΩ
```
```math
R_{MPPC2}\ = 100 kΩ
```

MPPC requires compensation to maintain stability of the input voltage regulation loop.
C_mppc and R_mppc3 are a zero-pole pair.

```math
C_{MPPC}\ = \frac{1}{2π \times\ R_{MPPC2} \times\ 360}
```
```math
=>C_{MPPC}\ = \frac{1}{2π \times\ 100,000 \times\ 360}
```
```math
```
```math
C_{MPPC}\ = 4.42 nF
```
```math
```
```math
R_{MPPC3}\ = \frac{C_{Vin}}{2π \times\ C_{MPPC}}
```
```math
=>R_{MPPC3}\ = \frac{100 \times\ 10^{-6}}{2π \times\ 4.42 \times\ 10^{-9}}
```
```math
```
```math
R_{MPPC3}\ = 3.6 kΩ
```
### Programming Switching Frequency:
```math
F_{sw}= \frac{100 \times\ 10^{9}}{8 + (1.2 \times\ R_{RT})}
```
Switching frequency is chosen to be 1 MHz
```math
=>1,000,000= \frac{100 \times\ 10^{9}}{8 + (1.2 \times\ R_{RT})}
```
```math
```
```math
R_{RT} = 76.6 kΩ = 80 kΩ
```

### Inductor Selection:

The LT3120 Datasheet recommends inductors between the values of 1.5 uH and 15 uH for best performance.

A 15 uH inductor is chosen as the minimum voltage input, 5, is close enough to 12 to not cause a detrimental amount of ripple current in boost mode.

Inductor Ripple Current in Buck Mode:

```math
I_{Δ}= \frac{V_{OUT}}{L} \times\ \frac{V_{IN(max)} - V_{OUT}}{V_{IN(max)}} \times\ (\frac{1}{F_{sw}} - 70\times\ 10^{-9})
```
```math
=>I_{Δ}= \frac{12}{15\times\ 10^{-6}} \times\ \frac{18 - 12}{18} \times\ (\frac{1}{1,000,000} - 70\times\ 10^{-9})
```
```math
```
```math
I_{Δ}= 205 mA
```

Inductor Ripple Current in Boost Mode:

```math
I_{Δ}= \frac{V_{OUT}}{L} \times\ \frac{V_{OUT} - V_{IN(min)}}{V_{IN(min)}} \times\ (\frac{1}{F_{sw}} - 70\times\ 10^{-9})
```
```math
=>I_{Δ}= \frac{12}{15\times\ 10^{-6}} \times\ \frac{12- 5}{5} \times\ (\frac{1}{1,000,000} - 70\times\ 10^{-9})
```
```math
```
```math
I_{Δ}= 1.04 A
```
### Output Capacitor Selection:

The LT3120 Datasheet recommends a low ESR output capacitor to minimize output voltage ripple

I_load = 7.15 A

C_out is chosen to be 150 uF

Output Ripple Voltage in Buck Mode:

```math
V_{Δ}= \frac{I_{LOAD} \times\ 70 \times\ 10^{-9}}{ C_{OUT}}
```
```math
=>V_{Δ}= \frac{7.15 \times\ 70 \times\ 10^{-9}}{ 150 \times\ 10^{-6}}
```
```math
```
```math
V_{Δ}= 3.34 mV
```

Output Ripple Voltage in Boost Mode:

```math
V_{Δ}= \frac{I_{LOAD}}{(F_{SW} \times\ C_{OUT})} \times\ (V_{OUT} - V_{IN(min)} + \frac{70 \times\ 10^{-9} \times\ F_{SW} \times\ V_{IN(min)}}{V_{OUT}})
```
```math
=>V_{Δ}= \frac{7.15}{1,000,000 \times\ 150 \times\ 10^{-6}} \times\ (12 - 5 + \frac{70 \times\ 10^{-9} \times\ 1,000,000 \times\ 5}{12})
```
```math
```
```math
V_{Δ}= 29.2 mV
```
### Frequency Compensation Network:

R_Load = Vout / I_Load = 1.67 Ohms

Gcs = 13.6 A / V (Datasheet)

Eff = 80% (Datasheet)

Lowest Frequency for f_{RHPZ}

```math
f_{RHPZ} = \frac{V_{IN(MIN)}^{2} \times\ R_{LOAD}}{ V_{OUT}^{2} \times\ 2π \times\ L_{SW}}
```
```math
=>f_{RHPZ} = \frac{5^{2} \times\ 1.52}{ 12^{2} \times\ 2π \times\ (15 \times\ 10^{-6})}
```
```math
```
```math
f_{RHPZ} = 3100 Hz
```
The closed loop crossover frequency (fcc) should be sufficiently below the RHPZ frequency to account for variability of the internal components of the IC (Datasheet). A seventh of RHPZ will be chosen to match the example given in the datasheet.
```math
f_{CC} = \frac{1}{7} \times\ f_{RHPZ}
```
```math
```
```math
f_{CC} = 443 Hz
```
Phase contribution of RHPZ:
```math
Φ_{RHPZ} = -atan(\frac{fcc}{f_{FHPZ}})
```
```math
=>Φ_{RHPZ} = -atan(\frac{100}{700})
```
```math
```
```math
Φ_{RHPZ} = -8.13°
```
Effective Output Current Gain:
```math
G_{CS(OUT)} = G_{CS} \times\ \frac{V_{IN}}{2V_{OUT}} \times\ Eff
```
```math
=>G_{CS(OUT)} = 13.6 \times\ \frac{5}{2(12)} \times\ 0.8
```
```math
```
```math
G_{CS(OUT)} = 2.27 \frac{A}{V}
```
Output Load Pole
```math
f_{VC} = \frac{2}{2π \times\ R_{LOAD} \times\ C_{OUT}}
```
```math
=>f_{VC} = \frac{2}{2π \times\ 1.67 \times\ 150 \times\ 10^{-6}}
```
```math
```
```math
f_{VC} = 1270.7 Hz
```
Gain and Phase Contributions due to the Output Filter:
```math
G_{OUT} = G_{CS(OUT)} \times\ \sqrt{\frac{R_{LOAD}^{2}}{ (\frac{f_{CC}}{f_{VC}})^{2} + 1}}
```
```math
=>G_{OUT} = 2.27 \times\ \sqrt{\frac{1.67^{2}}{ (\frac{442}{1271})^{2} + 1}}
```
```math
```
```math
G_{OUT} = 3.78
```
```math
```
```math
Φ_{VC} = -atan(\frac{f_{CC}}{f_{VC}})
```
```math
=>Φ_{VC} = -atan(\frac{442}{1271})
```
```math
```
```math
Φ_{VC} = -19.18°
```
Required Phase Boost from the Compensation Network:
A Phase margin of 50° is chosen to match the example from the datasheet.
```math
Φ_{Z} = 50 - Φ_{VC} - Φ_{RHPZ} - 180
```
```math
=>Φ_{Z} = 50 - (-19.18) - (-8.13) - 180
```
```math
```
```math
Φ_{Z} = -102.69°
```
Compensation Network Gain:
```math
G_{COMP} = (\frac{0.795}{V_{OUT}} \times\ G_{OUT} )^{-1}
```
```math
=>G_{COMP} = (\frac{0.795}{12} \times\ 3.78 )^{-1}
```
```math
G_{COMP} = 3.99 = 4
```
```math
R_{VC} = \frac{G_{COMP}}{ 120 \times\ 10^{-6}}
```
```math
=>R_{VC} = \frac{4}{ 120 \times\ 10^{-6}}
```
```math
R_{VC} = 33,333Ω = 35 kΩ
```
```math
C_{VC} = \frac{tan(Φ_{Z})}{ 2π \times\ f_{CC} \times\ R_{VC}}
```
```math
=>C_{VC} = \frac{tan(-102.69)}{ 2π \times\ 442 \times\ 35,000}
```
```math
C_{VC} = 4.57 \times\ 10^{-8} = 50 pF
```
```math
```
```math
R_{VC} = 35 kΩ
```
```math
C_{VC} = 50 pF
```
## LTC4020 Battery Charger BuckBoost Analysis
### Battery Charging Voltage Programming:
```math
V_{FLOAT} = 2.3125 \times\ (1 + \frac{R_{FB1}}{R_{FB2}})
```
The battery's required float charge voltage is in between 13.6 V and 13.8 V. A value of 13.7 V will be chosen to give room for 100 mV of error. 

R_fb2 is arbitrarily chosen to be 20 kΩ.

```math
=>13.7 = 2.3125 \times\ (1 + \frac{R_{FB1}}{20,000})
```
```math
```
```math
R_{FB1} = 98.5 kΩ
```
```math
R_{FB2} = 20 kΩ
```
The battery's cycle charge voltage range is from 14.5 V to 14.9 V. Using the above resistances, the absoption voltage is calculated as follows:
```math
V_{ABSORPTION} = 2.5 \times\ (1 + \frac{R_{FB1}}{R_{FB2}})
```
```math
=>V_{ABSORPTION} = 2.5 \times\ (1 + \frac{98,500}{20,000})
```
```math
```
```math
V_{ABSORPTION} = 14.8125
```
V_absorption is less than the maximal 14.9 V. The battery will be charged within its specifications.

### Battery Charging Current Programming:
The battery's maximum charging current is rated at 3.6 A.

```math
R_{CS} = \frac{0.05}{I_{CSMAX}}
```
```math
=>R_{CS} = \frac{0.05}{3.6}
```
```math
```
```math
R_{CS} = 0.014 Ω
```
### Output Voltage Programming:
```math
V_{OUT} = 2.75 \times\ (1 + \frac{R_{FBMAX1}}{R_{FBMAX2}})
```
The datasheet recommends the two output voltage programming resistors, R_fbmax1 and R_fbmax2, to match those of the battery charge voltage resistors, R_fb1 and R_fb2.
```math
=>V_{OUT} = 2.75 \times\ (1 + \frac{98,500}{20,000})
```
```math
```
```math
V_{OUT} = 16.29 V
```
This output voltage is unused.

### Programming Switching Frequency:
A switching frequency of 100 kHz is desired.
```math
R_{RT} = 100,000 \times] (\frac{F_{0}}{250,000})^{-1.0695}
```
```math
=>R_{RT} = 100,000 \times] (\frac{100,000}{250,000})^{-1.0695}
```
```math
```
```math
R_{RT} = 266,438 Ω ~= 270 kΩ
```
### Inductor Selection: 
### Inductor Current Sensing Selection:
### Input Supply Decoupling:
### Output Supply Decoupling:

### Overcharge and Deep Discharge Protection
MOSFET Q1 will be used to prevent deep discharge. When the Arduino reads that the battery is entering deep discharge range, the MOSFET will close and no more current will flow out of the batteries. This means that the system will not receive enough current to operate and will shut down due to lack of power. 

MOSFET Q2 will be controlled to allow excess current to flow to ground to prevent overcharge. 

Analysis of components required for Q1 AND Q2:

```math
{\rm Ic}_{(sat)}\ = \frac{Vcc - {\rm Vce}_{(sat)}}{Rc}
```
```math
{\rm Ib}_{(min)}\ = \frac{{\rm Ic}_{(sat)}}{βdc}
```
```math
Vrbjt\ = Vnano - {\rm Vbe}_{(sat)}
```
```math
Rbjt\ = \frac{Vrbjt}{{\rm Ib}_{(min)}}
```

### Battery Monitor
The batteries are connected to a bidirectional current and power monitor, U5. This will be used to keep track of the power being charged and discharged from the batteries. Having this information will allow the MCU to prevent the batteries from overcharging and deep discharging. 

Analysis of components required for U5:

Rshunt = 2 mΩ (Datasheet)

Rp1, Rp2, and Rp3 were arbitrarily chosen to be 1 kΩ as they are used for pull up resistors. 


# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Solar Panel | AM-L02P25-1 | 1 | $35.99 |  $35.99 |
| Seal Lead Acid | ML12-12F2 | 2 | $27.99 | $55.98 |
| Arduino Nano | ABX00028 | 1 | $13.70 | $13.70 |
| Buck-Boost Converter | MAX20040ATPA/VY+ | 1 | $2.48 | $2.48 |
| Digital Potentiometer | MAX5474 | 1 | $2.48 | $2.48 |
| Current Sensor | ACS712ELCTR-05B-T | 2 | $3.70 | $7.40 |
| Bidirectional Current and Power Monitor | INA226AIDGST | 1 | $3.33 | $3.33 |
| NPN Silicon medium power transistor | ZTX653 | 2 | |  | 
| Schottky Diode | | 3 | | |
| Total | ----- | ----- | ----- | $--.-- |

# References
Solar panel datasheet: https://m.media-amazon.com/images/I/C1dszUHMnaL.pdf

Digital potentiometer datasheet: https://www.analog.com/media/en/technical-documentation/data-sheets/MAX5471-MAX5475.pdf

BJT datasheet: [ZTX653_Datasheet.pdf](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/files/13336931/ZTX653_Datasheet.pdf)

Bidirectional current and power monitor datasheet: https://www.ti.com/lit/ds/symlink/ina226.pdf?ts=1699175796094&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FINA226%253Futm_source%253Dgoogle%2526utm_medium%253Dcpc%2526utm_campaign%253Dasc-null-null-GPN_EN-cpc-pf-google-eu%2526utm_content%253DINA226%2526ds_k%253DINA226%2BDatasheet%2526DCM%253Dyes%2526gclid%253DEAIaIQobChMIvurP68KsggMVYZKDBx2_egHxEAAYASAAEgIQ9PD_BwE%2526gclsrc%253Daw.ds

Arduino Nano datasheet: https://docs.arduino.cc/resources/datasheets/A000005-datasheet.pdf