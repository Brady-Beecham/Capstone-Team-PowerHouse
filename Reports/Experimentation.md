# System Measures of Success

These measures of success are derived from the project proposal.

| Measure of Success | Name   | Details |
|-------------------|--------|------|
| M1 | Full Time Operation | All parts of the system shall be constantly functioning. This includes having a backup power supply. |
| M2 | Wireless Communication | The sensor shall communicate with the server wirelessly.|
| M3 | Local Space Availability Retention| The sensor shall keep track of the amount of vehicles in a parking lot locally.|
| M4 | Space Availability Retention | The system shall keep a local count of vehicles that enter or exit a parking lot.|
# System Constraints
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

   For the Loop Controller, the original idea of the team was to use a Diablo DSP-21 Vehicle Detector to control the inductive loops and send a signal to the ESP32 MCU alerting of when a vehicle
enters or exits a parking lot.  However, it was decided that it would be more feasible to build a Loop Controller instead of purchasing the Diablo DSP-21 Vehicle Detector.  After numerous designs
and discussions as a team, it was decided that it would best to use a Colpitts Oscillator circuit to generate a frequency through the inductive loops as the Colpitts oscillator provides the most
stable frequency compared to circuits such as a Hartley oscillator, etc.  In order to allow the ESP32 to monitor the frequency of the inductive loops safely, a Sine to Square Wave circuit was
connected to the output of the Colpitts oscillator.  A voltage regulator was added to the Loop Controller to transform 9 V to 3.3 V so the output of the Sine to Square Wave circuit would send the square wave to the ESP32 at the safe voltage of 3.3 V to the GPIO pins.  By creating a Custom Loop Controller, the Loop Controller is designed with the needs of the project in mind and we have a more in-depth understanding of the Loop Controller in the event of troubleshooting any possible issues that may occur in the controller.

For many of the constraints of the Ground Based Sensor Subsystem, they were either revised or descoped based on the decision of designing the Loop Controller in-house instead of purchasing the Diablo DSP-21.  Each constraint for the Ground Based Sensor Subsystem and the Loop Controller Subsystem is explained in the following section.	


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

   - This constraint was achieved and further evaluation of this constraint is located in the experimentation of the ESP32 frequency vs time measurement section below.

### C10
Subsystem shall detect cars/pickup trucks (vehicles) and motorcycles that are entering a parking lot at a maximum speed of 20 mph and leaving a parking lot at a maximum speed of 20 mph.

   - This constraint was not fully achieved as motorcyles were never tested throughout the experimentation phase of the project.  However, cars/pickup trucks were detected as stated in C1.

### C11 
Vehicle detector shall cover a range of at least 50 μH to 1000 μH at a frequency at 50 kHz

   - This constraint is descoped due to the previously mentioned design changes.


### C14
All components of the subsystem, with the exception of the inductive loops and lead-in wire to the induction loops, shall be placed in an area that does not affect pedestrian traffic along the road or nearby sidewalks.

   - This constraint was achieved as the equipment was placed away from pedestrian traffic and pedestrians were able to walk on the sidewalks without being affected by the placement of the Loop Controller.  For the lead-in wire connections to the inductive loops, measurements were taken from the center of the roadway to the edge of the concrete to determine the minimum distance to avoid interfering with pedestrian traffic.  With the minimum distance determined, extra length was added to the lead-in connnections to avoid possible human errors when calculating the distance.

### C15
All turns in the inductive loop shall be a 45° turn (or 135° as noted in the schematic drawing) to avoid damaging the wire(s) that create the inductive loop that comes from using 90° turns.

   - This constraint was achieved as all turns in each inductive loop were set as close as possible to a 45° angle.

### C16 
Any wire that is used as part of the loop and is connected to the vehicle detector shall be protected using a heavy-duty cable protector that is capable of protecting the wires under the weight of a vehicle or pedestrian while protecting the wires from the weather.

   - This constraint is descoped due to the previously mentioned design changes.

### C17
Vehicle detector shall detect vehicles and motorcycles that are tailgating (when the front bumper of one vehicle is close to the back bumper and the two vehicles are in the same loop at the same time on one side of the roadway).

   - This constraint was not achieved due to time constraints and requires further evaluation of both the Loop Controller and Data Subsystem in order to meet this constraint.

### C18 
Vehicle detector shall detect vehicles and motorcycles that are going in opposite directions on the roadway, but are within the detection range of the same loop at the exact same time.

   - This constraint was not achieved due to time constraints and requires further evaluation of both the Loop Controller and Data Subsystem in order to meet this constraint.

### C19 
Inductive loops shall be placed a minimum of 4 ft. apart from the edge of one loop to the edge of the other loop to avoid cross-talk between the loops and possibly give false signals.

   - This constraint was achieved as all inductive loops were placed at a distance greater than 4 ft apart from each loop.  The distance allowed the loops to avoid cross-talk between one another and all signals received from the loops were similar to the expected results.


### Oscilloscope Testing - Purpose of the Experiment

The purpose of this experiment is test the Loop Controller and 
its function and verify it operates as it is intended.  

### Oscilloscope Testing - Experimental Procedure

For all tests, the loop(s) were placed in the road and the 
vehicle passed over the loop(s) and not to the side of the loop(s).  Throughout 
the entirety of the tests, it is expected that the frequency of the 
loops/Loop Controller will change with a noticeable difference of ± 1 
kHz and this change will be detected by the ESP32 MCU to send 
information to the server alerting of the mentioned sedan 
entering/exiting a parking lot.  To monitor the changes in frequency in both inductive loops,
the results for each test are found when using a Rigol DS1104 Oscilloscope.


### Oscilloscope Testing - Results

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

### Oscilloscope Testing - Interpretation

For the first two trials, one loop was connected to the Loop Controller (Loop A Output).  When one loop was connected, there was no set speed value (in mph) and the Loop Controller detected when a vehicle passed over the loop.  Two trials were completed to verify the Loop Controller did function as expected and was not by coincidence.  In both Test 1 and Test 2 (as seen in the graph), the frequency of the loop increased by more than 3 kHz every time.  From this data, we can interpret that the Loop Controller does function as expected and can detect a change in frequency due to a vehicle passing over the loop.

For trials 3-7, both loops were connected to the Loop Controller (Loop A Output and Loop B Output).  The speed of the vehicle was included and increased at increments of 5 mph until it reached a maximum speed of 20 mph for a total number of four tests/trials.  For speed values of 5, 10, and 15 mph, the frequency in both loops experienced a change of +1 kHz.  This change in frequency is expected as the ESP32 MCU will be able to detect the 1 kHz change in frequency and update the delta accordingly.  For the speed value of 20 mph, Loop B Output experienced a change of less than 1 kHz (change in frequency is 400 Hz). Depending on the ESP32's algorithm for detecting changes in frequency, this may not be considered a significant enough change to count as a vehicle.

Based on the test results above, the Loop Controller is able to detect vehicles passing over the loop(s) that are entering or exiting a parking lot based on the information that is received in the data tables.

### ESP32 Testing - Purpose of Experiment
The purpose of this experiment is to test that the ESP32 can read the square wave pulses from the Loop Controller PCB and determine if a vehicle is entering or exiting a parking lot (Constraint 4).

### ESP32 Testing - Experimental Procedure
The Loop Controller PCB outputs are connected to two GPIO pins on the ESP32 microcontroller. The ESP32 outputs what frequency it is reading, changes in delta, and a timestamp to the serial terminal. This output is logged and put into a CSV file so the data can be graphed. Data will be logged as vehicles drive over the loops.

### ESP32 Testing - Results
#### Frequency vs Time with Vehicle Traveling at 5 mph
<img src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/4a8d6bc3-303f-449b-9803-8fdac2ba6ef5" width="400">

#### Frequency vs Time with Vehicle Traveling at 15 mph
<img src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/ab185205-4d62-4aaf-875c-803d64e9413a" width="400">

#### Frequency vs Time with Vehicle Traveling at 20 mph
<img src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/78795e42-712c-4ba9-a755-392d9869412a" width="400">

#### Frequency vs Time with Vehicle Traveling at Random Speeds
![Freq_vs_time_random_zoomed](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/119456660/679e45d3-d89f-4d48-9c80-5d61eebf582e)
The large dip in the graph can be attributed to connection problems with the wires.


### ESP32 Testing - Interpretation
These graphs show that the ESP32 is capable of reading the square waves generated by the Loop Controller and effectively calculate the frequency of the square wave pulses. This video demonstrates the ESP32's ability to determine the direction a vehicle is traveling and update the delta accordingly. Link to video: https://youtube.com/shorts/8B8lnqCkGT8?si=NU7qAhg_zqjL0T57 

This proves constraint 4 is met. C4: "The Loop Controller shall be connected to the ESP32 Microcontroller that is used with the Data system of the project to communicate a change in frequency in both of the loops and determine whether a vehicle is entering or exiting a parking lot."

## Wall power Subsystem Experimentation

| Constraint Number | Constraint Information |
|--|---|
| C20 | Voltage equivalence: The main wall power subsystem needs to protect devices from the damage caused by voltage and guarantee the safety of the electrical system, as well as preserve the whole subsystem. | Wall power Subsystem |
| C21 | During main power failures, power flow is controlled by the switch controller. | Wall power Subsystem |
| C22 | It should be within wire capabilities. | Wall power Subsystem |
| C23 | Must be a kill switch to disconnect all the power from the source. | Wall power Subsystem |

### C20
The subsystem has fuses that protect all the connected subsystems from damage caused by voltage. There is also a fuse between the outlet power and the backup battery to ensure the electrical system is safe.
This constraint has been achieved. 
### C21 and M1
When the outlet power is disconnected, the controller switches to use the main battery after a delay of less than a second. During this delay, the output voltage is zero.

This constraint has been achieved, but M1 has not been achieved as there is a small delay where the output voltage is zero and the system is shut down.
### C22
This constraint was successful. Normal jumper wires can handle the voltage and amperage sent to each subsystem.

### C23
This constraint was successful. A physical kill switch has been connected to shut down all the power if required.

### Purpose of the Experiment
This experiment will be testing the error of the voltage regulators and the switching functionality.

### Experimental Procedure

The PCB’s input has been connected to both a wall outlet through an adapter and a backup battery. The Loop Controller PCB and the Data Subsystem has been connected to the outputs to test the power output of this subsystem’s PCB. Fuses have been used in between the outputs and the external PCBs.

### Prediction
The Loop controller should be receiving 9 VDC, 0.05 A and Data subsystem should be receiving  5.5 VDC and 0.25 A.    
### Results

| Trial No.  | Data Subsystem Voltage & Current   | Loop Controller Voltage & Current  |
|------------------|----------------|------------------|
|1	   | 5.4186 VDC &     0.219597 A  |	9.3034 VDC &    0.052276  A |
|2		| 5.4226 VDC &     0.219818 A  |	9.3035 VDC &    0.052314  A |
|3		| 5.4145 VDC &     0.219518 A  |	9.3040 VDC &    0.052397  A |

The above table shows the output of the PCB with a wall outlet through a wall adapter on the input. 


![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/ce856873-3b31-4bb9-9165-4d322b801326)

The graph above shows the power consumed by the Data Subsystem with the wall outlet input.

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/f65ca27c-9719-4408-9ca6-60bf224b01ca)


The graph above shows the power consumed by the Loop Controller PCB with the wall outlet input.


| Trial No.  | Data Subsystem Voltage & Current | Loop Controller Voltage & Current |
|------------------|---------------|------------------|
|1 	| 5.4143  VDC & 0.219523 mA      |    	9.1858 VDC  &  0.052397 mA     |
|2		| 5.4226  VDC & 0.219814 mA      |	   9.1865 VDC  &  0.052438 mA    |
|3		| 5.4187  VDC & 0.219632 mA      |	   9.1863 VDC  &  0.052419 mA     |

The above table shows the output of the PCB with the backup battery suppling the input. 


![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/2eda09d2-b2aa-49d0-962b-62b01d44f9c9)


The graph above shows the power consumed by the Data Subsystem with the battery input.


![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/143124480/15d63920-22c5-448e-b58c-bb4a1551d6ca)

The graph above shows the power consumed by the Loop Controller PCB with the battery input.



Measurements of the voltage and current are given in the video link below. For both, the power sources are input 12 VDC.


https://www.youtube.com/watch?v=EA21rRr-S3c 

### Experimental Interpretations

The output’s power tolerance with the wall outlet input can be shown below:

| No.| Subsystem    | Expected Voltage | Actual Voltage |  Expected Current | Actual Current |Power Tolerance | 
| ---  | ------------------ | -------------------|--------------|------------------|-----------------|-----------|
| a  | Sensor | 9  VDC  | 9.303 VDC  | 0.05 A  | 0.0523 A   |  8.12 %  | 
| b  | Data Subsystem | 5.5 VDC  | 5.48 VDC  | 0.25 A  | 0.2194 A  | 15.4 %  |        

The output’s power tolerance with the backup battery input can be shown below:

|No. | Subsystem        | Expected Voltage | Actual Voltage| Expected Current | Actual Current |Tolerance |
|--- |------------------|-------------------| -------------|------------------|------------------|-----------|
| a  | Sensor | 9  VDC         | 9.303 VDC      | 0.05 A  | 0.0524 A | 7.91 %  | 
| b  | Data Subsystem | 5.5 VDC   | 5.418 VDC | 0.25 A| 0.2196 A | 13.04  % |          

While not all power outputs are within the 10% tolerance, each subsystem safely receives an ample amount of power to function properly.



## Power Controller Subsystem Experimentation

| Constraint Number | Constraint Information |
|--|---|
| C24 | The subsystem shall power each subsystem's demanded voltage and current with a 10% tolerance|
| C25 | The subsystem output shall be connected to the other subsystems through three fuses|
| C26 | The subsystem shall have a DC nominal voltage of 12V |



### Purpose of the Experiment
To test the error of the voltage regulators.


### Experimental Procedure

In the experiment, the power controller will supply the required power to the Loop Controller, Data, and Charge Controller Subsystems with an input of 12 VDC. The power was measured at the output of the Power Controller PCB. Each subsystem was connected through a jumper wire and fuse.

### Prediction

The Loop Controller subsystem should be sent 9 V and 0.05 A.

The Data subsystem and Charge Controller subsystem should be sent 5.5 V and 0.25 A.

### Results

| Trial No. | Data Subsystem | Charge Controller | Loop Controller       |
|------------------|------------------|---------------|------------------|
| 1	      |5.472 VDC                |5.437 VDC      |9.495 VDC         |
|2	         |5.474 VDC                |5.4372 VDC     |9.497 VDC         |
|3	         |5.4754 VDC               |5.4369 VDC     |9.4953 VDC        |
|4	         |5.4755 VDC               |5.43691 VDC    |9.4957 VDC        |
|5	         |5.476  VDC               |5.4371 VDC      |9.4959 VDC       |

The table above displays the output voltages with no loads (subsystems) attached. The input voltage is 12 V.


| Subsystem        | Expected Voltage | Actual Avg Voltage| Expected Current |  Actual Avg Current |Expected Power |  Actual Avg Power |
|------------------|------------------|-------------------|------------------|---------------------|---------------|-------------------|
| Loop Controller   | 9  VDC           | 9.544 VDC      | 0.05 A           | 0.0318 A         | 0.45 W        |  0.303 W       |
| Data Subsystem   | 5.5 VDC          | 5.407 VDC      | 0.25 A           | 0.256 A         | 1.375 W       |  1.378 W       |
| Charge Controller| 5.5 VDC          | 5.393 VDC      | 0.25 A           | 0.255 A         | 1.375 W       |  1.382 W       | 

The table above presents the expected and actual average results for voltage, current, and power supplied to each subsystem.




| Subsystem         | Expected Power (W) | Actual Avg Power (W) | Power Tolerance (%)   |
|-------------------|---------------------|----------------------|----------------------|
| Loop Controller   | 0.45                | 0.303                | 32.67%               |
| Data Subsystem    | 1.375               | 1.378                | 0.22%                |
| Charge Controller | 1.375               | 1.382                | 0.51%                |



The table above shows the expected & actual power and the power tolerance for each subsystem provided by the power controller. 

	
https://youtu.be/cqpJeXbbNOQ?feature=shared


The video displays the voltage and current measurements for each power controller output using a 12V input.

https://youtube.com/shorts/ds0gY6Fl69w?feature=shared


The video displays the voltage and current measurements for the power controller connected to the loop controller through a fuse with a 12v input. 

#### C24



<img width="385" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/cf73c6ce-27e4-4b35-b101-52ff9b157fc8">

The graph above shows the output to the Loop Controller Subsystem. The power controller input is 12V. 

<img width="410" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/aa9dd859-6e49-461d-9158-fc3648e01b71">

The graph above shows the output to the Charge Controller Subsystem. The power controller input is 12V. 


<img width="361" alt="image" src="https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/d11a3c03-567e-402d-bccf-ef2f015ab843">

The graph above shows the output to the Data Subsystem. The power controller input is 12V. 


#### C25

This constraint was achieved by connecting the data and inductive loop subsystems through a fuse that protects against overcurrent.

#### C26

 This constraint was achieved. The power controller could take an input voltage with a minimum of 9 VDC and a maximum of 17 VDC. The power controller will deliver the needed voltages and currents for that input range for each subsystem. 


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

The experiment will be conducted by setting up the LoRaWAN gateway at my apartment which is beside Tech Village and then a person will walk with an end device into campus until the signal is lost. The location where the signal is lost will be recorded and the distance from the gateway will be measured with Google Maps. Tests will be done with adaptive data rate functionality.

### Prediction
I predict that the 354 meter range will be achieved, but the 915 meter range may not. 

Based on informal testing I conducted around January, I found that the LoRa physical layer protocol could reach approximately 500-520 meters from Brown Hall using the same ESP32 microcontrollers and RFM95W transceivers. I estimated a maximum range of about 15 km in my signoff, but I now realize I may not have the hardware nor the setup for that level of coverage. The relatively cheap components of the RFM95W transceiver make frequency error a problem. This leads to problems with higher spreading factors and lower bandwidths. A higher quality crystal oscillator that is temperature compensating (TCXO) would enable the use of the lowest bandwidths such as 7.8 kHz for maximum range.  The RFM95W, with its crystal that is not temperature compensating, can only handle bandwidths as low as 62.5 kHz.

The propagation model I used in the signoff to predict the range of the LoRaWAN network is not well suited to this LoRaWAN network. Immense range with LoRa is achieved by having your gateway antennas elevated, with high gain, high spreading factor (11 or 12), low bandwidth, and clear line of sight. LoRaWAN, more specifically the “The Things Network” standard frequency plans tend to use the lowest spreading factors and high bandwidths. This means much lower range than what the LoRa physical layer modulation technique is truly capable of.

### Number of Trials
There will be 3 trials using the adaptive data rate setting in the ESP32 code. A trial is recorded by resetting the ESP32 and successfully reconnecting to the gateway.

### Results
#### Adaptive Data Rate
| Trial | Range achieved (meters)  |
|-------|--------------------------|
| 1 | 980 |
| 2 | 1050 |
| 3 | 1000 |


### Have Constraints and Measures of Success Been Met?

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
   - The subsystem meets this constraint. All of the measured ranges were over 915 meters. I could have gone even farther, but I was already at the edge of campus by the Bryan Fine Arts building.

#### C8 
The system is constrained by the limited data rate that is inherent to the LoRaWAN protocol. Specifically, the bit rate can range between 0.3 kbps to 27 kbps depending on the spreading factor and bandwidth used.
   - This is more than sufficient for transmitting a maximum of 3 bytes at intervals such as every 5 minutes. Infrequent data transmission is common in LoRaWAN applications. The delta will be sent at a regular interval in the order of minutes instead of immediately upon a change being detected. This constraint is met.

#### C9 
The system is constrained by the maximum payload size afforded by LoRaWAN. Depending on the spreading factor, the maximum payload size can range from 51 bytes to 222 bytes.
   - The data contained in the LoRaWAN frames will never exceed 3 bytes, this constraint is met.

#### M2 
Wireless Communication: The sensor shall communicate with the server wirelessly.

 - This measure of success has been met and exceeded because the extreme range of LoRaWAN is much greater than what was initially required. Initially, we just needed something that could reach from the Capstone Lab to the parking lot outside.

#### M3 
Local Space Availability Retention: **No longer relevant:** The sensor shall track the number of vehicles in a parking lot locally.

 - This measure of success is not relevant to the current system. Each end device doesn't need to know how many spots are available in a parking lot. The sensor only needs to keep track of the delta of cars that have passed by it.

#### M4 
Space Availability Retention: The system shall keep a local count of vehicles that enter or exit a parking lot.

 - This measure of success has been met because the ESP32 can reliably update and store to nonvolatile storage the current delta of cars that have entered or exited the lot at the point the ESP32 is set up.


### Interpretation
The experimentation indicates that this subsystem is more than capable of campus-wide scale operation. 


## Solar Power Subsystem
| Constraint Number | Constraint Information | Subsystem Defined | 
|--------|------------------|----------------|
| C30 | The solar panel and the backup battery shall be connected to the charge controller. | Solar Power Subsystem |
| C31 | The solar panel should be installed at the right direction and angle that can capture the maximum amount of sunlight. | Solar Power Subsystem |
| C32 | The charge controller shall maximize the output power from the solar panel. | Solar Power Subsystem |
| C33 | The backup battery shall have enough capacity to prevent the charge controller from discharging more than 50%. | Solar Power Subsystem |
| C34 | The backup battery shall either be in the charging or discharging phase, and it cannot be in both simultaneously. | Solar Power Subsystem |

#### 30

This constraint has been achieved. The Charge Controller can switch between battery and solar inputs.

#### 31

The constraint no longer directly applies to this project as there is no housing for the solar panel to be mounted for long periods of time.

#### 32

The constraint was not accomplished due to the problems encountered in the Charge Controller Subsystem.


#### 33

The constraint was not accomplished due to the problems encountered in the Charge Controller Subsystem.

Without a way to charge the batteries, there is no way to prevent the batteries from discharging below 50%. 

#### 34

This constraint has been achieved as during the expected charging cycle the batteries are placed in series with the battery charging PCB using relays. while discharging they are placed in parallel using the same relays.


