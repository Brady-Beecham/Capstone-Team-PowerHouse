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
| C30 | The solar panel and the backup battery shall be connected to the charge controller. | Solar Power Subsystem |
| C31 | The solar panel should be installed at the right direction and angle that can capture the maximum amount of sunlight. | Solar Power Subsystem |
| C32 | The charge controller shall maximize the output power from the solar panel. | Solar Power Subsystem |
| C33 | The backup battery shall have enough capacity to prevent the charge controller from discharging more than 50%. | Solar Power Subsystem |
| C34 | The backup battery shall either be in the charging or discharging phase, and it cannot be in both simultaneously. | Solar Power Subsystem |


## Loop Controller Subsystem and Ground Based Sensor Subsystem Experimentation

### Design Changes
   Update later and add section explaining changes

### Loop Controller Constraints

### C1
Subsystem shall detect cars/pickup trucks (vehicles) that are entering and exiting a parking lot.

   - This constraint was achieved as proven in the results.
   
### C2 and C12
Vehicle detector shall be compliant with the FCC frequency range for Intentional Radiators and verifying the detector is within permissible part 15 frequencies.

   - This constraint was achieved as proven in the results.
   
### C3 and C13
Each entrance/exit of a parking lot shall use a total of one loop controller that will control the two inductive loops at the entrance/exit.

   - This constraint was achieved as the Loop Controller that was used for Experimentation controls both inductive loops accordingly and the frequency of both inductive loops are similar to the expected results in the Loop Controller Signoff.
   
### C4
The Loop Controller shall be connected to the ESP32 Microcontroller that is used with the Data system of the project to communicate a change in frequency in both of the loops and determine whether a vehicle is entering or exiting a parking lot.

   - This constraint was achieved and further evaluation of this constraint is located in Data Subsystem Analysis section of Experimentation.

### C10
Subsystem shall detect cars/pickup trucks (vehicles) and motorcycles that are entering a parking lot at a maximum speed of 20 mph and leaving a parking lot at a maximum speed of 20 mph.

   - This constraint was not fully achieved as motorcyles were never tested throughout the experimentation phase of the project.  However, cars/pickup trucks were detected as stated in C1.

### C11 
Vehicle detector shall cover a range of at least 50 μH to 1000 μH at a frequency at 50 kHz

   - This constraint was descoped as it was determined during the halfway point of the project that it would not apply to the Loop Controller.  The original constraint was designed around an off the shelf Loop Controller, but as it was decided to design our own, this constraint was descoped.


### C14
All components of the subsystem, with the exception of the inductive loops and lead-in wire to the induction loops, shall be placed in an area that does not affect pedestrian traffic along the road or nearby sidewalks.

   - This constraint was achieved as the equipment was placed away from pedestrian traffic and pedestrians were able to walk on the sidewalks without being affected by the placement of the Loop Controller.  For the lead-in wire connections to the inductive loops, measurements were taken from the center of the roadway to the edge of the concrete to determine the minimum distance to avoid interfering with pedestrian traffic.  With the minimum distance determined, extra length was added to the lead-in connnections to avoid possible human errors when calculating the distance.

### C15
All turns in the inductive loop shall be a 45° turn (or 135° as noted in the schematic drawing) to avoid damaging the wire(s) that create the inductive loop that comes from using 90° turns.

   - This constraint was achieved as all turns in each inductive loop were set as close as possible to a 45° angle.

### C16 
Any wire that is used as part of the loop and is connected to the vehicle detector shall be protected using a heavy-duty cable protector that is capable of protecting the wires under the weight of a vehicle or pedestrian while protecting the wires from the weather.

   - This constraint was descoped as it was determined by the team that it would be unnecessary to purchase cable protectors due to the loops having more durability and resistance to wear from vehicle movement than originally expected at the beginning of the project.

### C17
Vehicle detector shall detect vehicles and motorcycles that are tailgating (when the front bumper of one vehicle is close to the back bumper and the two vehicles are in the same loop at the same time on one side of the roadway).

   - This constraint was not achieved due to time constraints and requires further evaluation of both the Loop Controller and Data Subsystem in order to meet this constraint.

### C18 
Vehicle detector shall detect vehicles and motorcycles that are going in opposite directions on the roadway, but are within the detection range of the same loop at the exact same time.

   - This constraint was not achieved due to time constraints and requires further evaluation of both the Loop Controller and Data Subsystem in order to meet this constraint.

### C19 
Inductive loops shall be placed a minimum of 4 ft. apart from the edge of one loop to the edge of the other loop to avoid cross-talk between the loops and possibly give false signals.

   - This constraint was achieved as all inductive loops were placed at a distance greater than 4 ft apart from each loop.  The distance allowed the loops to avoid cross-talk between one another and all signals received from the loops were similar to the expected results.


### Purpose of the Experiment

The purpose of this experiment is test the Loop Controller and 
its function and verify it operates as it is intended.  

### Experimental Procedure

For all tests, the loop(s) were placed in the road and the 
vehicle passed over the loop(s) and not to the side of the loop(s).  Throughout 
the entirety of the tests, it is expected that the frequency of the 
loops/Loop Controller will change with a noticeable difference of ± 1 
kHz and this change will be detected by the ESP32 MCU to send 
information to the server alerting of the mentioned sedan 
entering/exiting a parking lot.  To monitor the changes in frequency in both inductive loops,
the results for each test are found when using a Rigol DS1104 Oscilloscope.


### Results

#### No Loop(s) Connected to the Controller
|        | Expected Results | Actual Results |
|--------|------------------|----------------|
| Input  | 9 VDC            | 9.19 VDC       |
| Output | 3.3 VDC          | 3.3 VDC        |

#### One Loop Connected to Controller with No Speed Test
|        | Set Frequency | Max. Frequency |
|--------|---------------|----------------|
| Test 1 | 62.9 kHz      | 66 kHz         |
| Test 2 | 62.9 kHz      | 67 kHz         |

#### Two Loops Connected to Controller
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

### Interpretation

For the first two trials, one loop was connected to the Loop Controller (Loop A Output).  When one loop was connected, there was no set speed value (in mph) and the Loop Controller detected when a vehicle passed over the loop.  Two trials were completed to verify the Loop Controller did function as expected and was not by coincidence.  In both Test 1 and Test 2 (as seen in the graph), the frequency of the loop increased by more than 3 kHz every time.  From this data, we can interpret that the Loop Controller does function as expected and can detect a change in frequency due to a vehicle passing over the loop.

For trials 3-7, both loops were connected to the Loop Controller (Loop A Output and Loop B Output).  The speed of the vehicle was included and increased at increments of 5 mph until it reached a maximum speed of 20 mph for a total number of four tests/trials.  For speed values of 5, 10, and 15 mph, the frequency in both loops experienced a change of +1 kHz.  This change in frequency is expected as the ESP32 MCU will be able to detect the 1 kHz change in frequency and update the delta accordingly.  For the speed value of 20 mph, Loop B Output experienced a change of less than 1 kHz (change in frequency is 400 Hz). Depending on the ESP32's algorithm for detecting changes in frequency, this may not be considered a significant enough change to count as a vehicle.

Based on the test results above, the Loop Controller is able to detect vehicles passing over the loop(s) that are entering or exiting a parking lot based on the information that is received in the data tables.

## Wall power Subsystem Experimentation

| Constraint Number | Constraint Information |
|--|---|
| C20 | Voltage equivalence: The main wall power subsystem needs to protect devices from the damage caused by voltage and guarantee the safety of the electrical system, as well as preserve the whole subsystem. |  Wall power Subsystem |
| C21 | During main power failures, power flow is controlled by the switch controller. | Wall power Subsystem |
| C22 | It should be within wire capabilities. | Wall power Subsystem |
| C23 | Must be a kill switch to disconnect all the power from the source. | Wall power Subsystem |

 ### C20
This constraint was successful, as confirmed by the results. The power subsystem has fusees that protect all the subsystems from damage caused by voltage, and there is a fuse between the outlet power and the backup battery to ensure the electrical system is safe.
### C21
This constraint was successful, as confirmed by the results. If the outlet power fails, the controller immediately transforms to the backup power battery, which is a relay switch, to feed all the subsystems.

### C22
This constraint was successful, as confirmed by the results. The wires can withstand voltage drops and overheating.

### C23
This constraint was successful, as confirmed by the results. For emergencies, I used a physical kill switch to shut down all the power if something happened.

### Purpose of the Experiment
The purpose of this experiment is to test the main wall power subsystem, which has an adapter power supply that converts AC to DC. However, we have another subsystem, a backup battery. If the main wall power shuts down, a relay switch will activate the backup power battery to feed the two subsystems. The goal of this test is to determine the value of the results derived from both inputs for wall power and backup battery.

### Experimental Procedure
In this experiment, I connected the adapter power supply and the backup battery to the PCB with wires to get the voltage and current from both powers. When we connect, it feeds the two subsystems. As soon as the input voltage is connected, we can measure the voltage reading that we expected to come out. Wires with fuses between them are used as the output for two subsystems.

### Number of Trials

| Trial No.  | Charge Controller | Loop Controller |
|------------------|----------------|------------------|
| 1	 | 5.4186     |	9.3034 |
|2		| 5.4226      |	9.3035 |
|3		| 5.4217      |	9.3040 |

This table shows the number of tests for each subsystem. However, the input 12 VDC. , and the power source is the wall power.



| Trial No.  | Charge Controller | Loop Controller |
|------------------|---------------|------------------|
| 1	| 5.4243      |	9.1858 |
|2		| 5.4275      |	9.1865 |
|3		| 5.4268      |	9.1863 |

This table shows the number of tests for each subsystem. However, the input is 12 VDC, and the power source is the backup battery.

### Results
Wall power

| No.| Subsystem    | Expected Voltage | Actual Voltage |  Expected Current | Actual Current |Tolerance | 
| ---  | ------------------ | -------------------|--------------|------------------|-----------------|-----------|
| a  | Sensor | 9  VDC  | 9.303 VDC  | 0.05 A  | 0.0523 A   |  8.12 %  | 
| b  | Date interpretation, Transmission and storge | 5.5 VDC  | 5.48 VDC  | 0.25 A  | 0.2123 A  | 15.4 %  |        

Backup battery 

|No. | Subsystem        | Expected Voltage | Actual Voltage| Expected Current | Actual Current |Tolerance |
|--- |------------------|-------------------| -------------|------------------|------------------|-----------|
| a  | Sensor | 9  VDC         | 9.303 VDC      | 0.05 A  | 0.0522 A | 7.91 %  | 
| b  | Date interpretation, Transmission and storge | 5.5 VDC   | 5.418 VDC | 0.25 A| 0.2207 A | 13.04  % |          




## Power Controller Subsystem Experimentation


| Constraint Number | Constraint Information |
|--|---|
| C24 | The subsystem shall power each subsystem's demanded voltage and current with a 10% tolerance|
| C25 | The subsystem output shall be connected to the other subsystems through three fuses|
| C26 | The subsystem shall have a DC nominal voltage of 12V |



### Purpose of the Experiment
To test the error of the voltage regulators.


### Experimental Procedure

In the experiment, we connected an input voltage source with a range between 9 VDC and 15 VDC to test its ability to supply the required voltages and current. Once we connected the input voltage, we measured the voltage to ensure that we were receiving the expected voltage reading. subsystem and the second output to the loop inductive subsystem using a wire with fuses between them.

### Prediction



### Number of Trials

| Trial No. | Data Subsystem | Charge Controller | Loop Controller |
|------------------|------------------|---------------|------------------|
| 1	      |5.472                    |5.437	         |9.495|
|2	         |5.474	                 |5.4372	      |9.497|
|3	         |5.4754	                 |5.4369	      |9.4953|
|4	         |5.4755	                 |5.43691	      |9.4957|
|5	         |5.476	                 |5.4371	      |9.4959|

The table displays the number of tests conducted on each output of the power controller, with an input of 12VDC, while no outputs are connected to the loads.


<img width="385" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/cf73c6ce-27e4-4b35-b101-52ff9b157fc8">

The power controller input is 12V and the Result displays the voltage and current output of the Loop Controller Subsystem across five trials. 

<img width="410" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/aa9dd859-6e49-461d-9158-fc3648e01b71">

The Result shows the output of the power controller connected to the Charge Controller Subsystem while measuring both the voltage and current for five trials. The power controller input is 12V. 


<img width="361" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/d11a3c03-567e-402d-bccf-ef2f015ab843">

The Result shows the output of the power controller connected to the Data Subsystem while measuring both the voltage and current for five trials. The power controller input is 12V. 


### Results

| Subsystem        | Expected Voltage | Actual Voltage| Expected Current |  Actual Current |Expected Power |  Actual Power | Tolerance |
|------------------|------------------|---------------|------------------|-----------------|---------------|---------------|-----------|
| Inductive loop   | 9  VDC           | 9.52 VDC      | 0.05 A           | 0.043 A         | 0.45 W        |  0.41 W       | 8.89%     |
| Data Subsystem   | 5.5 VDC          | 5.48 VDC      | 0.25 A           | 0.212 A         | 1.375 W       |  1.16 W       | 15.63%    |
| Charge Controller| 5.5 VDC          | 5.44 VDC      | 0.25 A           | 0.223 A         | 1.375 W       |  1.21 W       | 12.00%    |



https://youtu.be/cqpJeXbbNOQ?feature=shared
The video displays the voltage and current measurements for each power controller output using a 12V input.

https://youtube.com/shorts/ds0gY6Fl69w?feature=shared
The video displays the voltage and current measurements for the power controller connected to the loop controller through a fuse with a 12v input. 

#### C24



<img width="385" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/cf73c6ce-27e4-4b35-b101-52ff9b157fc8">

The Result shows the output of the power controller connected to the Loop Controller Subsystem while measuring both the voltage and current for five trials. The power controller input is 12V. 

<img width="410" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/aa9dd859-6e49-461d-9158-fc3648e01b71">

The Result shows the output of the power controller connected to the Charge Controller Subsystem while measuring both the voltage and current for five trials. The power controller input is 12V. 


<img width="361" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/d11a3c03-567e-402d-bccf-ef2f015ab843">

The Result shows the output of the power controller connected to the Data Subsystem while measuring both the voltage and current for five trials. The power controller input is 12V. 


#### C25

This constraint was not fully achieved due to an unfinished subsystem. However, the data and inductive loop subsystems are connected through a fuse that protects against overcurrent.

#### C26

 This constraint was achieved. The power controller was able to take an input voltage with a minimum of 9 VDC and a maximum of 17 VDC. For that range of input, the power controller will deliver the needed voltages and currents for each subsystem. 


### Interpretation

The subsystem did not meet the 10% tolerance requirement because the resistor used on the PCB had different values. The resistor we ordered for this subsystem was difficult to solder, so we had to solder it through holes in the PCB with slightly different values. This caused the tolerance to be higher than what we had anticipated.


## Charge Controller Experimentation

### Charge Controller Constraints
| Constraint Number | Constraint Information |
|--|---|
| C27 | Controller shall maximize the output power from the solar panel.|
| C28 | Controller shall output 12 V with a 10% tolerance to the Power Controller. |
| C29 | Controller shall prevent the batteries from being damaged due to over-charging |

### Problems Encountered

1) Main PCB problems
   
This PCB has encountered problems while soldering the QFN components, mainly the boost switching regulator used to assist the Arudino in controlling the MPPC voltage regulator's output.

   This switching regulator has a fairly simple circuit as shown in the figure below. The circuitry is simple and the chip is very small with QFN packaging. Also, due to the heat sink on the bottom, it requires the use of a heat oven to be properly soldered. The combination of size, heatsink, and novice soldering skills caused this chip to be short-circuited on the first round of soldering. This short circuit led to the MPPC Voltage regulator along with the boost regulator to be desoldered with a heat gun and placed back into the heat oven. In total, the MPPC went through the heat oven four times and the boost regulator went in three times. (The second time for both was prior to the discovery of the short circuit and was intended to ensure the solder properly flowed. The third time in the oven for the MPPC was to resolder it to the board without the voltage regulator. The fourth time for the MPPC and the third for the boost regulator was to apply the boost regulator.)  

![BoostPWMCircuit](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/b4cdc252-34ae-443d-bc0f-fa34f01c6c57)

   I hypothesize that the minutes spent under the heat gun and multiple trips through the heat oven damaged both the MPPC Voltage regulator and the boost voltage regulator. The main reason for this hypothesis is that the MPPC voltage regulator was working as expected prior to the last (fourth) trip in the heat oven when the boost regulator was added. 
   
   To test this hypothesis, the boost voltage regulator was removed with a heat gun once again and the MPPC was tested once more (the MPPC is much more important to the subsystem since it maximizes the input solar power.) The result was that the MPPC did not produce the same results prior to the last round in the heat oven. 

   While this test is not conclusive, due to time constraints progress on the main PCB had to take precedence over continued testing. An LM317T Voltage regulator was used to bypass the MPPC regulator and supply the output with 9.25 V as 9 V is required by the Power Controller with 0.25 V of room for error. As the LM317T is only a buck converter and not a buck-boost, the output will not reach an acceptable voltage between solar input voltages of 5 V (when the relay is designed to switch to the MPPC regulator output) to somewhere around 9.25 V. The solar input cannot be directly connected to the output due to voltage limitations on the power controller.

   Without the boost regulator, the Arduino can't control the output of either the MPPC or LM317T. Without the Arduino to regulate the voltage the battery PCBs are not able to be sent power without harming the system during times of low light levels.

2) Battery Charging PCB Problems

The battery charging PCB was not devoted as much attention as the main PCB as it cannot be used without the main PCB being fully operational.

The voltage regulator on this PCB, LTC4020, never showed signs of life during testing. The circuit schematic was triple checked across the datasheet, the capacitors and diodes were checked for correct orientation, and no shorts were found. 

The LTC4020 has QFN packaging, so its possible the leads aren't properly soldered. It could be reflowed in the heat oven or taken completely off with a heat gun, but, due to time constraints with resoldering the circuit and the previous heat related problems in the previous PCB, this was not done. 
   

### C27

Maximization of the solar panel's power has not been achieved. 

Without the MPPC voltage regulator, the subsystem has no way of maximizing the input solar power.

### C28

The output of 12 V with a 10% tolerance has not been achieved. 

#### The Purpose of the Experiment
This experiment is testing the output based on the input of the solar panels alone.  Although the constraint requires 12 V with a 10% tolerance, with the LM317T, I expect to see 9.25 V on the output after reaching 9.25 V on the input.

#### Experimental Procedure
To simulate the varying input from the solar panel, a power supply has been used on the input of the subsystem with voltages ranging from 0 V to 20 V at 1 V increments. The maximum voltage tested is 20 V instead of the solar panel's maximal output according to the datasheet, 18 V, is due to the actual reading of the solar panel during a sunny day being 19.5 V.

The output has been read using a digital multimeter set to read a DC voltage.

#### Results
The results can be shown below in the *Output Voltage vs Solar Input Voltage* Graph.

*Output Voltage vs Solar Input Voltage*

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/e1713e10-1328-416a-8230-5f17e62a60c4)

#### Interpretation
The *Output Voltage vs Solar Input Voltage* Graph shows that the output voltage is not within 10% of the 12 V constraint at any input. This is expected due to the LM317T addition.

#### The Purpose of the Experiment
The next experiment is testing the output based on the input of both the solar panel and also a backup battery. With the battery attached, the output voltage should be the same as the battery voltage until 5 V is reached, which the relay will be triggered to switch to the solar panel input.

#### Experimental Procedure
To simulate the varying input from the solar panel, a power supply has been used on the input of the subsystem with voltages ranging from 0 V to 20 V at 1 V increments. The maximum voltage tested is 20 V instead of the solar panel's maximal output according to the datasheet, 18 V, is due to the actual reading of the solar panel during a sunny day being 19.5 V.

A single backup battery is also attached to the battery input for the system to use at its discretion. Its voltage reading prior to testing is 12.95 V.

The output has been read using a digital multimeter set to read a DC voltage.

#### Results
The results can be shown below in the *Output Voltage vs Solar and Battery Input Voltage* Graph.

*Output Voltage vs Solar and Battery Input Voltage*
![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/45153206/5a194e37-c948-4352-90aa-86ca275d404e)

#### Interpretation
The *Output Voltage vs Solar and Battery Input Voltage* Graph shows that the output voltage is within 10% of the 12 V constraint from 0 to 4 V due to the battery voltage being supplied. This is by design as the MPPC voltage regulator should start operation at 5 V to supply the output with 12 V. But without proper operation of the MPPC voltage regulator, C28 has not been fulfilled even with batteries attached.

### C29

As the batteries are not able to be charged due to the problems encountered, this constraint has not been achieved. 

## Data Subsystem Experimentation

### Data Subsystem Constraints
| Constraint Number | Constraint Information |
|--|---|
| C5  | Data shall be transmitted on the unlicensed 915 MHz ISM band bounded by 902 MHz and 928 MHz.|
| C6  | Data shall be transmitted according to the standards set by The LoRa Alliance that define the LoRa protocol.|
| C7  | The system shall be able to communicate effectively over a distance of 915 meters or 1 kilometer in order to scale over all of campus. This is the approximate distance from Brown Hall to the far edge of Purple Lot. This was determined to be the farthest point on campus from Brown Hall using Google Maps. This distance must be achieved even when the signal has to pass through several layers of material.|
| C8  | The system is constrained by the limited data rate that is inherent to the LoRaWAN protocol. Specifically, the bit rate can range between 0.3 kbps to 27 kbps depending on the spreading factor and bandwidth used.|
| C9  | The system is constrained by the maximum payload size afforded by LoRaWAN. Depending on the spreading factor, the maximum payload size can range from 51 bytes to 222 bytes.|

### Relevant Measures of Success
| Measure of Success | Name   | Details |
|-------------------|--------|------|
| M2 | Wireless Communication | The sensor shall communicate with the server wirelessly.|
| M3 | Local Space Availability Retention| **No longer relevant:** The sensor shall keep track of the amount of vehicles in a parking lot locally.|
| M4 | Space Availability Retention | The system shall keep a local count of vehicles that enter or exit a parking lot.|

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

The experiment will be conducted by setting up the LoRaWAN gateway in the Capstone Lab and then a person will walk with an end device toward purple lot until the signal is lost. The location where the signal is lost will be recorded and the distance from the gateway will be measured with Google Maps. Tests will be done with and without adaptive data rate functionality, and with different frequency plans. I will also test the range of LoRa PHY, the physical layer only implementation. This is because I can choose higher spreading factors and lower bandwidths than with LoRaWAN.

### Prediction
I predict that the 354 meter range will be achieved, but the 915 meter range may not. 

Based on informal testing I conducted around January, I found that the LoRa physical layer protocol could reach approximately 500-520 meters from Brown Hall using the same ESP32 microcontrollers and RFM95W transceivers. I estimated a maximum range of about 15 km in my signoff, but I now realize I do not have the hardware nor the setup for that level of coverage. The relatively cheap components of the RFM95W transceiver make frequency error a problem. This leads to problems with higher spreading factors and lower bandwidths. A higher quality crystal oscillator that is temperature compensating (TCXO) would enable the use of the lowest bandwidths such as 7.8 kHz for maximum range.  The RFM95W, with its crystal that is not temperature compensating, can only handle bandwidths as low as 62.5 kHz. Also, the antennas from Amazon likely do not produce the advertised gain numbers.

The propagation model I used in the signoff to predict the range of the LoRaWAN network is not well suited to this LoRaWAN network. Immense range with LoRa is achieved by having your gateway antennas elevated, with high gain, high spreading factor (11 or 12), low bandwidth, and clear line of sight. LoRaWAN, more specifically the “The Things Network” standard frequency plans tend to use the lowest spreading factors and high bandwidths. This means much lower range than what the LoRa physical layer modulation technique is truly capable of.

### Number of Trials
There will be 3 trials of each test. The individual tests are intended to examine how different parameters affect the range achieved. Tests of more configurations were planned, but due to excessive join times, they were not tested. 
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


### Have Constraints and Measures of Success been Met?

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

#### M2 
Wireless Communication: The sensor shall communicate with the server wirelessly.

 - This measure of success has been met because, despite the low range of the LoRaWAN network, data is still transmitted effectively to the cloud server.

#### M3 
Local Space Availability Retention: **No longer relevant:** The sensor shall track the number of vehicles in a parking lot locally.

 - This measure of success is not relevant to the current system. Each end device doesn't need to know how many spots are available in a parking lot. The sensor only needs to keep track of the delta of cars that have passed by it.

#### M4 
Space Availability Retention: The system shall keep a local count of vehicles that enter or exit a parking lot.

 - This measure of success has been met because the ESP32 can reliably update and store to nonvolatile storage the current delta of cars that have entered or exited the lot at the point the ESP32 is set up.


### Interpretation
The experimentation does not indicate that this subsystem, in its current state, is suitable for campus-wide scale. 

I suspect there are problems with hardware and/or software configuration. The RFM95W transceiver is intended to be a cheap LoRa transceiver for hobbyists. It is not intended to be a LoRaWAN-compliant device. The informal range testing conducted in January indicates the potential of the RFM95W transceivers for point-to-point communication but attempts to replicate those results have failed. The point-to-point setup now has similar range to the LoRaWAN range test results. LoRaWAN is known to have long-range capability, although this testing indicates my hardware is not up to the task. Better hardware would be the easy solution to this problem. 

Despite the failure of my current hardware/software, LoRaWAN is still a viable option for campus-scale IoT communication based on the wide use of LoRaWAN in industry and the incredible ranges that have been achieved with the technology.


## Solar Power Subsystem
| Constraint Number | Constraint Information | Subsystem Defined | 
|--------|------------------|----------------|
| C30 | The solar panel and the backup battery shall be connected to the charge controller. | Solar Power Subsystem |
| C31 | The solar panel should be installed at the right direction and angle that can capture the maximum amount of sunlight. | Solar Power Subsystem |
| C32 | The charge controller shall maximize the output power from the solar panel. | Solar Power Subsystem |
| C33 | The backup battery shall have enough capacity to prevent the charge controller from discharging more than 50%. | Solar Power Subsystem |
| C34 | The backup battery shall either be in the charging or discharging phase, and it cannot be in both simultaneously. | Solar Power Subsystem |

#### 30

This constraint was not fully achieved. The solar panel was connected to the charge controller and delivered the needed voltages and current. However, the battery was not connected to the charge controller due to the incompletion of the charge controller subsystem.      


#### 31

The constraint was accomplished. However, there was not much change in the output voltage from the solar panel if the solar was facing the sunlight. 

#### 32

The constraint was not accomplished. The reason is a change in the path for the charge controller subsystem. The new path for the charge controller subsystem was to drop the voltage coming from the solar panel and the voltage of the solar panel. Therefore, the charge controller subsystem steps down the voltage from the solar panel to the voltage needed for the power controller subsystem. 


#### 33

The constraint was not accomplished. The battery will not be able to charge from the solar panel through the charge controller because the battery charge controller for the charge controller subsystem was not fully accomplished. Therefore, the battery must be charged by a specific adapter, allowing it to charge at full capacity. 

#### 34

Constraint was not accomplished. The battery charge controller for the charge controller subsystem was not fully completed. Hence, if we connect the battery directly to the power controller subsystem, it will discharge. However, if the battery has sufficient capacity, it can deliver the required voltages and current. Therefore, before connecting the battery to the power controller, we should measure its voltage to get a good estimate of its capacity.

