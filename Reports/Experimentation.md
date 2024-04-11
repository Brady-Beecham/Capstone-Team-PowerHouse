# System Measures of Success

These measures of success are derived from the project proposal.

| Measure of Success | Name   | Details |
|-------------------|--------|------|
| M1 | Full Time Operation | All parts of the system shall be constantly functioning. This includes having a backup power supply. |
| M2 | Wireless Communication | The sensor shall communicate with the server wirelessly.|
| M3 | Local Space Availability Retention| The sensor shall keep track of the amount of vehicles in a parking lot locally.|
| M4 | Space Availability Retention | The system shall keep a local count of vehicles that enter or exit a parking lot.|
# System Contraints
| Constraint Number | Constraint Information | Subsystem Defined | 
|--------|------------------|----------------|
| C1  | Subsystem shall detect cars/pickup trucks (vehicles) that are entering and exiting a parking lot. | Loop Controller |
| C2  | Vehicle detector shall be compliant with the FCC frequency range for Intentional Radiators and verifying the detector is within permissible part 15 frequencies.  | Loop Controller |
| C3  | Each entrance/exit of a parking lot shall use a total of one loop controller that will control the two inductive loops at the entrance/exit. | Loop Controller |
| C4  | The Loop Controller shall be connected to the ESP32 Microcontroller that is used with the Data system of the project to communicate a change in frequency in both of the loops and determine whether a vehicle is entering or exiting a parking lot. | Loop Controller |
| C5  | Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz. | Data Subsystem |
| C6  | Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol.| Data Subsystem |
| C7  | The system shall be able to communicate effectively over a distance of 915 meters or 1 kilometer in order to scale over all of campus. This is the approximate distance from Brown Hall to the far edge of Purple Lot. This was determined to be the farthest point on campus from Brown Hall using Google Maps. This distance must be achieved even when the signal has to pass through several layers of material.| Data Subsystem |
| C8  | The system is constrained by the limited data rate that is inherent to the LoRaWAN protocol. Specifically, the bit rate can range between 0.3 kbps to 27 kbps depending on the spreading factor and bandwidth used.| Data Subsystem |
| C9  | The system is constrained by the maximum payload size afforded by LoRaWAN. Depending on the spreading factor, the maximum payload size can range from 51 bytes to 222 bytes.| Data Subsystem |
| C10 | Subsystem shall detect cars/pickup trucks (vehicles) and motorcycles that are entering a parking lot at a maximum speed of 20 mph and leaving a parking lot at a maximum speed of 20 mph. | Ground Based Sensor Subsystem|
| C11 | Vehicle detector shall cover a range of at least 50 &mu;H to 1000 &mu;H at a frequency at 50 kHz | Ground Based Sensor Subsystem |
| C12 | Vehicle detector shall be compliant with the FCC frequency range for Intentional Radiators and verifying the detector is within permissible part 15 frequencies.| Ground Based Sensor Subsystem |
| C13 | Each entrance/exit of a parking lot shall have a total of two inductive loops for determining whether a car/pickup truck is entering a parking lot or leaving a parking lot.| Ground Based Sensor Subsystem |
| C14 | All components of the subsystem, with the exception of the inductive loops and lead-in wire to the induction loops, shall be placed in an area that does not affect pedestrian traffic along the road or nearby sidewalks.| Ground Based Sensor Subsystem |
| C15 | All turns in the inductive loop shall be a 45° turn (or 135° as noted in the schematic drawing) to avoid damaging the wire(s) that create the inductive loop that comes from using 90° turns. | Ground Based Sensor Subsystem |
| C16 | Any wire that is used as part of the loop and is connected to the vehicle detector shall be protected using a heavy-duty cable protector that is capable of protecting the wires under the weight of a vehicle or pedestrian while protecting the wires from the weather. | Ground Based Sensor Subsystem|
| C17 | Vehicle detector shall detect vehicles and motorcycles that are tailgating (when the front bumper of one vehicle is close to the back bumper and the two vehicles are in the same loop at the same time on one side of the roadway).| Ground Based Sensor Subsystem |
| C18 | Vehicle detector shall detect vehicles and motorcycles that are going in opposite directions on the roadway, but are within the detection range of the same loop at the exact same time.| Ground Based Sensor Subsystem |
| C19 | Inductive loops shall be placed a minimum of 4 ft. apart from the edge of one loop to the edge of the other loop to avoid cross talk between the loops and possibly give false signals.| Ground Based Sensor Subsystem |
| C20 | Voltage equivalence: The main wall power subsystem needs to protect devices from the damage caused by voltage and guarantee the safety of the electrical system, as well as preserve the whole subsystem. | Wall power Subsystem |
| C21 | During main power failures, power flow is controlled by the switch controller. | Wall power Subsystem |
| C22 | It should be within wire capabilities. | Wall power Subsystem |
| C23 | Must be a kill switch to disconnect all the power from the source. | Wall power Subsystem |
| C24 | The subsystem shall power each subsystem's demanded voltage and current with a 10% tolerance. | Power Controller Subsystem |
| C25 | The subsystem output shall be connected to the other subsystems through three fuses.| Power Controller Subsystem |
| C26 | The subsystem shall have a DC nominal voltage of 12V. | Power Controller Subsystem |
| C27 | Controller shall maximize the output power from the solar panel. | Charge Controller Subsystem |
| C28 | Controller shall output 12 V with a 10% tolerance to the Power Controller. |Charge Controller Subsystem |
| C29 | Controller shall prevent the batteries from being damaged due to over-charging | Charge Controller Subsystem |


## Loop Controller Subsystem and Ground Based Sensor Subsystem Experimentation
The purpose of this experiment is to not only test the Power Subsystems
to verify they function as expected, but also test the Loop Controller and 
its function.  For all trials, the loop(s) were placed in the road and the 
vehicle passed over the loop(s) and not to the side of the loop(s).  For the
test vehicle, a Toyota Camry was used for all trials.  Throughout 
the entirety of the trials, it is expected that the frequency of the 
loops/Loop Controller will change with a noticeable difference of ± 1 
kHz and this change will be detected by the ESP32 MCU to send 
information to the server alerting of the mentioned sedan 
entering/exiting a parking lot.

## Loop Controller Constraints

### Constraint C1: Subsystem shall detect cars/pickup trucks (vehicles) that are entering and exiting a parking lot.

   a. This constraint was achieved as proven in the results.
   
### Constraint C2 and C12: Vehicle detector shall be compliant with the FCC frequency range for Intentional Radiators and verifying the detector is within permissible part 15 frequencies.

   a. This constraint was achieved as proven in the results.
   
### Constraint C3 and C13: Each entrance/exit of a parking lot shall use a total of one loop controller that will control the two inductive loops at the entrance/exit.

   a. This constraint was achieved as the Loop Controller that was used for Experimentation controls both inductive loops accordingly and the frequency of both inductive loops are similar to the expected results in the Loop Controller Signoff.
   
### Constraint C4: The Loop Controller shall be connected to the ESP32 Microcontroller that is used with the Data system of the project to communicate a change in frequency in both of the loops and determine whether a vehicle is entering or exiting a parking lot.

   a. This constraint was achieved and further evaluation of this constraint is located in Data Subsystem Analysis section of Experimentation.

### Constraint C10: Subsystem shall detect cars/pickup trucks (vehicles) and motorcycles that are entering a parking lot at a maximum speed of 20 mph and leaving a parking lot at a maximum speed of 20 mph.

   a. This constraint was achieved as proven in the results.

### Constraint C11: Vehicle detector shall cover a range of at least 50 μH to 1000 μH at a frequency at 50 kHz

   a. This constraint was descoped from the project as it was determined during the halfway point of the timeline of the project that this constraint would not apply to the Loop Controller.  The final design of the Loop Controller is very different from the original idea of the Loop Controller as numerous changes were made to the Loop Controller.  Due to these changes, this constraint no longer fits the Loop Controller standards.


### Constraint C14: All components of the subsystem, with the exception of the inductive loops and lead-in wire to the induction loops, shall be placed in an area that does not affect pedestrian traffic along the road or nearby sidewalks.

   a. This constraint was achieved as the equipment was placed away from pedestrian traffic and pedestrians were able to walk on the sidewalks without being affected by the placement of the Loop Controller.  For the lead-in wire connections to the inductive loops, measurements were taken from the center of the roadway to the edge of the concrete to determine the minimum distance to avoid interfering with pedestrian traffic.  With the minimum distance determined, extra length was added to the lead-in connnections to avoid possible human errors when calculating the distance.

### Constraint C15: All turns in the inductive loop shall be a 45° turn (or 135° as noted in the schematic drawing) to avoid damaging the wire(s) that create the inductive loop that comes from using 90° turns.

   a. This constraint was achieved as all turns in each inductive loop were set as close as possible to a 45° angle.

### Constraint C16: Any wire that is used as part of the loop and is connected to the vehicle detector shall be protected using a heavy-duty cable protector that is capable of protecting the wires under the weight of a vehicle or pedestrian while protecting the wires from the weather.

   a. This constraint was not achieved as it was determined by the team that it would be unnecessary to purchase cable protectors due to the loops having more durability and resistance to wear from vehicle movement than originally expected at the beginning of the project.

### Constraint C17: Vehicle detector shall detect vehicles and motorcycles that are tailgating (when the front bumper of one vehicle is close to the back bumper and the two vehicles are in the same loop at the same time on one side of the roadway).



### Constraint C18: Vehicle detector shall detect vehicles and motorcycles that are going in opposite directions on the roadway, but are within the detection range of the same loop at the exact same time.



### Constraint C19: Inductive loops shall be placed a minimum of 4 ft. apart from the edge of one loop to the edge of the other loop to avoid cross talk between the loops and possibly give false signals.

   a. This constraint was achieved as all inductive loops were placed at a distance greater than 4 ft apart from each loop.  The distance allowed the loops to avoid cross talk between one another and all signals received from the loops were similar to the expected results.

## No Loop(s) Connected to the Controller
|        | Expected Results | Actual Results |
|--------|------------------|----------------|
| Input  | 9 VDC            | 9.19 VDC       |
| Output | 3.3 VDC          | 3.3 VDC        |

## One Loop Connected to Controller with No Speed Test
|        | Set Frequency | Max. Frequency |
|--------|---------------|----------------|
| Test 1 | 62.9 kHz      | 66 kHz         |
| Test 2 | 62.9 kHz      | 67 kHz         |

## Two Loops Connected to Controller
### 5 mph
|        | Set Frequency | Max. Frequency |
|--------|---------------|----------------|
| Loop A | 62.9 kHz      | 65 kHz         |
| Loop B | 62.9 kHz      | 69 kHz         |

### 10 mph
|        | Set Frequency | Max. Frequency |
|--------|---------------|----------------|
| Loop A | 62.9 kHz      | 64.5 kHz       |
| Loop B | 62.9 kHz      | 64.5 kHz       |

### 15 mph
|        | Set Frequency | Max. Frequency |
|--------|---------------|----------------|
| Loop A | 62.9 kHz      | 64.1 kHz       |
| Loop B | 62.9 kHz      | 66.7 kHz       |

### 20 mph
|        | Set Frequency | Max. Frequency |
|--------|---------------|----------------|
| Loop A | 62.9 kHz      | 64.9 kHz       |
| Loop B | 62.9 kHz      | 63.3 kHz       |

For the first two trials, one loop was connected to the Loop Controller (Loop A Output).  When one loop was connected, there was no set speed value (in mph) and the Loop Controller detected when a vehicle passed over the loop.  Two trials were completed to verify the Loop Controller did function as expected and was not by coincidence.  In both Test 1 and Test 2 (as seen in the graph), the frequency of the loop increased by more than 3 kHz every time.  From this data, we can interpret that the Loop Controller does function as expected and can detect a change in frequency due to a vehicle passing over the loop.

For trials 3-7, both loops were connected to the Loop Controller (Loop A Output and Loop B Output).  The speed of the vehicle was included and increased at increments of 5 mph until it reached a maximum speed of 20 mph for a total number of four tests/trials.  For speed values of 5, 10, and 15 mph, the frequency in both loops experienced a change of +1 kHz.  This change in frequency is expected as the ESP32 MCU will be able to detect the 1 kHz change in frequency and send information to the server alerting of a vehicle either entering or exiting a parking lot.  For the speed value of 20 mph, Loop B Output experienced a change of less than 1 kHz (change in frequency is 400 Hz).  This small change is not expected to alert the ESP32 MCU of a vehicle passing over the loop(s).  Ultimately, the Loop Controller is able to detect vehicles passing over the loop(s) that are entering or exiting a parking lot based on the information that is received in the data tables.

## Wall power Subsystem Experimentation
## Power Controller Subsystem Experimentation


| Constraint Number | Constraint Information |
|--|---|
| C24 | The subsystem shall power each subsystem's demanded voltage and current with a 10% tolerance|
| C25 | The subsystem output shall be connected to the other subsystems through three fuses|
| C26 | The subsystem shall have a DC nominal voltage of 12V |

#### C24
The subsystem did not meet the 10% tolerance requirement because the resistor used on the PCB had different values. The resistor we ordered for this subsystem was difficult to solder, so we had to solder it through holes in the PCB with slightly different values. This caused the tolerance to be higher than what we had anticipated.

|No. | Subsystem        | Expected Voltage | Actual Voltage| Expected Current |  Actual Current | Tolerance |
|--- |------------------|------------------|---------------|------------------|-----------------|-----------|
| a  | Inductive loop   | 9  VDC           | 9.52 VDC      | 0.05 A         | 0.043 A           | 9.031%    |
| b  | Data Subsystem   | 5.5 VDC          | 5.48 VDC      | 0.25 A         | 0.212 A           | 15.51%    |
| c  | Charge Controller| 5.5 VDC          | 5.44 VDC      | 0.25 A         | 0.223 A           | 11.78%    |



#### C25

This constraint was not fully achieved due to an unfinished subsystem. However, the data and inductive loop subsystems are connected through a fuse that protects against overcurrent.

#### C26

 This constraint was achieved. The power controller was able to take an input voltage with a minimum of 9 VDC and a maximum of 17 VDC. For that range of input, the power controller will deliver the needed voltages and currents for each subsystem. 







## Charge Controller Experimentation

### Charge Controller Constraints
| Constraint Number | Constraint Information |
|--|---|
| C27 | Controller shall maximize the output power from the solar panel.|
| C28 | Controller shall output 12 V with a 10% tolerance to the Power Controller. |
| C29 | Controller shall prevent the batteries from being damaged due to over-charging |

#### Problems Encountered

#### C27

Maximization of the solar panel's power has not been achieved. 

#### C28

The output of 12 V with a 10% tolerance has not been achieved. 

This experiment is testing the output based on the input of the solar panels alone. 

To simulate the varying input from the solar panel, a power supply has been used on the input of the subsystem with voltages ranging from 0 V to 20 V. According to the solar panel's datasheet, the maximum output voltage of the panel is 18 V. After testing the panel's voltage during a sunny day, the voltage was read to be 19.5 V. This is the reason that it has been tested to 20 V instead of the original 18 V.

The output has been read using a digital multimeter set to read a DC voltage.

The results can be shown below in the *Output Voltage vs Solar Input Voltage* Graph.

*Output Voltage vs Solar Input Voltage*

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/e1713e10-1328-416a-8230-5f17e62a60c4)

The *Output Voltage vs Solar Input Voltage* Graph shows that the output voltage is not within 10% of the 12 V constraint at any input. This is due to the problems written about earlier in the Charge Controller Experimentation section.

The next experiment is testing the out based on the input of both the solar panel and also a backup battery.

To simulate the varying input from the solar panel, a power supply has been used on the input of the subsystem with voltages ranging from 0 V to 20 V. According to the solar panel's datasheet, the maximum output voltage of the panel is 18 V. After testing the panel's voltage during a sunny day, the voltage was read to be 19.5 V. This is the reason that it has been tested to 20 V instead of the original 18 V.

A single backup battery is also attached to the battery input for the system to use at its discretion. 

The output has been read using a digital multimeter set to read a DC voltage.

The results can be shown below in the *Output Voltage vs Solar and Battery Input Voltage* Graph.

*Output Voltage vs Solar and Battery Input Voltage*
![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/5a194e37-c948-4352-90aa-86ca275d404e)

The *Output Voltage vs Solar and Battery Input Voltage* Graph shows that the output voltage is within 10% of the 12 V constraint from 0 to 4 V. This is by design as the MPPC voltage regulator should have started operation at 5 V to supply the output with 12 V. Without it, C28 has not been fulfilled even with batteries attached.

#### C29

As the batteries are not able to be charged, this constraint has not been achieved. 


## Data Subsystem Experimentation

### Data Subsystem Constraints
| C5  | Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz.|
| C6  | Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol.|
| C7  | The system shall be able to communicate effectively over a distance of 915 meters or 1 kilometer in order to scale over all of campus. This is the approximate distance from Brown Hall to the far edge of Purple Lot. This was determined to be the farthest point on campus from Brown Hall using Google Maps. This distance must be achieved even when the signal has to pass through several layers of material.|
| C8  | The system is constrained by the limited data rate that is inherent to the LoRaWAN protocol. Specifically, the bit rate can range between 0.3 kbps to 27 kbps depending on the spreading factor and bandwidth used.|
| C9  | The system is constrained by the maximum payload size afforded by LoRaWAN. Depending on the spreading factor, the maximum payload size can range from 51 bytes to 222 bytes.|

### Purpose of the Experiment
The purpose of this experiment is to determine if the range of the LoRaWAN network is sufficient to scale to the entirety of the Tennessee Tech campus. The original constraint specifies a range of 915 meters is needed to reach all of campus if the gateway is located in Brown Hall. 
I argue that this constraint is unrealistic and not a typical way to scale a LoRaWAN application across a campus. One gateway should not be expected to receive all the data from end devices across the entire campus. Instead, there should be multiple spread across campus, with purposely lower range. One Semtech SX1302 LoRa baseband chip (like the one in this system’s gateway) can handle an absolute maximum of 9 end devices at one time (8+8+1 decoders). While it may seem uncommon that 9 end devices would want to send their data at the same time, many end devices would make packet loss a problem in this scenario. This would not be feasible for an application with many more than 9 end devices unless multiple gateways were used.
Therefore, I propose splitting the coverage of campus into smaller regions as pictured below. This should be more like an actual implementation.

*Image of campus split into 8 regions, Bing Maps*
![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/ead65eea-cf4e-4393-a3e1-65f46a022bb4)

I have split the campus up into 8 regions of varying size. I will use the largest region, region 3 as the benchmark for range. In summary, the purpose of this experiment is to both test if one single gateway can reach across all of campus (from Brown Hall to the edge of purple lot), and/or the largest region in a multi-gateway implementation. 


### Experimental Procedure
As mentioned before, this experiment will verify if the WM1302 + Raspberry Pi gateway and ESP32 + RFM95W end device can communicate effectively both over the maximum distance from Brown Hall, 915 meters, and the largest region of the proposed multi-gateway implementation. 
To get a number for the largest region (region 3), let’s assume the LoRa chirps will propagate outward from the center of the region in a sphere. Let’s also assume that instead of a rectangle 450 meters by 500 meters, we have a square 500 meters by 500 meters. The circle that bounds this square will be the range of the LoRaWAN network required to reach all 4 corners of the square. We are concerned with the radius of this circle. We can find the radius of the circle by: $$500 \sqrt{2} \over 2$$

We get r = 354 meters. Therefore 354 meters is what is needed for the LoRaWAN network to span region 3.
The experiment will be conducted by setting up the LoRaWAN gateway in the Capstone Lab and a person will walk with an end device toward purple lot until the signal is lost. The location where the signal is lost will be recorded and the distance from the gateway will be measured with Google or Bing maps. Tests will be done with and without adaptive data rate functionality, and with different frequency plans. I will also test the range of LoRa PHY, the physical layer only implementation. This is because I can choose higher spreading factors and lower bandwidths than with LoRaWAN.

### Prediction
I predict that the 354 meter range will be achieved, but the 915 meter range may not. Based on testing I conducted around January, I found that the LoRa physical layer protocol could reach approximately 500-520 meters from Brown Hall using the same ESP32 microcontrollers and RFM95W transceivers. I estimated a maximum range of about 15 km in my signoff, but I now realize I do not have the hardware or setup for that level of coverage. The relatively cheap components of the RFM95W transceiver make frequency error a problem. A higher quality crystal oscillator that is temperature compensating (TCXO) would be much better than the cheap crystal in the RFM95W. This leads to problems with higher spreading factors and lower bandwidths. Also, the cheap antennas from Amazon likely do not produce the advertised gain numbers.
The propagation model I used in the signoff to predict the range of the LoRaWAN network is indeed not well suited to this LoRaWAN network. Immense range with LoRa is achieved by having your gateway antennas very high up, big, with line of sight, high spreading factor (11 or 12), and low bandwidth. LoRaWAN, more specifically the “The Things Network” standard frequency plans tend to use the lowest spreading factors and high bandwidths. This means much lower range than what the LoRa physical layer modulation technique is truly capable of.

### Number of Trials
There will be 3 trials of each test. The individual tests are intended to examine how different parameters will affect the range achieved. Tests of more configurations were planned, but due to excessive join times, they were not tested. 
The tests will be: 
-	LoRaWAN gateway to end device network tests:
   1.	Adaptive data rate
   2.	Spreading Factor 8, Bandwidth 500 kHz
   3.	Spreading Factor 10, Bandwidth 125 kHz

### Results
#### Adaptive Data Rate
| Trial | Range achieved (meters)  |
|-------|--------------------------|
| 1 | 65 |
| 2 | 65 |
| 3 | 60 |

#### Spreading Factor 8, Bandwidth 500 kHz
| Trial | Range achieved (meters)  |
|-------|--------------------------|
| 1 | 65 |
| 2 | 65 |
| 3 | 65 |

#### Spreading Factor 10, Bandwidth 125 kHz
| Trial | Range achieved (meters)  |
|-------|--------------------------|
| 1 | 60 |
| 2 | 60 |
| 3 | 65 |

#### C5
Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz.
   - This constraint is satisfied by setting the region for the end device and gateway to US915 when configuring them.

#### C6 
Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol.
   - This constraint is satisfied by using a library based on the official LoRaMAC-In-C (LMIC) library by IBM, currently maintained by MCCI.
   - Link to the library used: https://github.com/manuelbl/ttn-esp32
   - LMIC library: https://github.com/mcci-catena/arduino-lmic

#### C7 
The system shall be able to communicate effectively over a distance of 915 meters or 1 kilometer in order to scale over all of campus. This is the approximate distance from Brown Hall to the far edge of Purple Lot. This was determined to be the farthest point on campus from Brown Hall using Google Maps. This distance must be achieved even when the signal has to pass through several layers of material. 

**Update:** Additionally, for a region-based, multi-gateway approach, a range of approximately 354 meters is needed. The reasoning for this has been explained in the "Purpose of the Experiment" section.
   - The subsystem fails to meet this constraint. The range of the previous LoRa physical layer protocol achieved in January (500-520 meters) was unable to be replicated. A maximum range of only 65 meters was achieved with LoRaWAN.

#### C8 
The system is constrained by the limited data rate that is inherent to the LoRaWAN protocol. Specifically, the bit rate can range between 0.3 kbps to 27 kbps depending on the spreading factor and bandwidth used.
   - This is more than sufficient for transmitting a maximum of 3 bytes at intervals such as every 5 minutes. Infrequent data transmission is common in LoRaWAN applications. The delta will be sent at a regular interval in the order of minutes instead of immediately upon a change being detected. This constraint is met.

#### C9 
The system is constrained by the maximum payload size afforded by LoRaWAN. Depending on the spreading factor, the maximum payload size can range from 51 bytes to 222 bytes.
   - The data contained in the LoRaWAN frames will never exceed 3 bytes, this constraint is met.

### Interpretation
The experimentation does not indicate that this subsystem, in its current state, is suitable for campus-wide scale. I suspect there are problems with hardware and/or software configuration. The RFM95W transceiver is intended to be a cheap LoRa transceiver for hobbyists. It is not intended to be a LoRaWAN-compliant device, although it is possible as I have proven. The informal range testing I conducted in January indicates the potential of the RFM95W transceivers for point-to-point communication but attempts to replicate those results have failed. The point-to-point setup now has similar range to the LoRaWAN range test results. I would like to test the true gain of my antennas. I suspect they are not as good as they advertise. LoRaWAN is known to have long-range capability, although this testing indicates my hardware is not up to the task. Better hardware would be the easy solution to this problem. I believe, based on how widely used LoRaWAN is in industry and record-setting ranges that have been achieved (up to 830 miles), that LoRaWAN is still a viable option for campus-scale IoT communication, despite the failure of my current hardware/software.

