## System Contraints
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
| C13 | Vehicle detector shall be compliant with the FCC frequency range for Intentional Radiators and verifying the detector is within permissible part 15 frequencies.| Ground Based Sensor Subsystem |
| C14 | Each entrance/exit of a parking lot shall have a total of two inductive loops for determining whether a car/pickup truck is entering a parking lot or leaving a parking lot.| Ground Based Sensor Subsystem |
| C15 | All components of the subsystem, with the exception of the inductive loops and lead-in wire to the induction loops, shall be placed in an area that does not affect pedestrian traffic along the road or nearby sidewalks.| Ground Based Sensor Subsystem |
| C16 | All turns in the inductive loop shall be a 45° turn (or 135° as noted in the schematic drawing) to avoid damaging the wire(s) that create the inductive loop that comes from using 90° turns. | Ground Based Sensor Subsystem |
| C17 | Any wire that is used as part of the loop and is connected to the vehicle detector shall be protected using a heavy-duty cable protector that is capable of protecting the wires under the weight of a vehicle or pedestrian while protecting the wires from the weather. | Ground Based Sensor Subsystem|
| C18 | Vehicle detector shall detect vehicles and motorcycles that are tailgating (when the front bumper of one vehicle is close to the back bumper and the two vehicles are in the same loop at the same time on one side of the roadway).| Ground Based Sensor Subsystem |
| C19 | Vehicle detector shall detect vehicles and motorcycles that are going in opposite directions on the roadway, but are within the detection range of the same loop at the exact same time.| Ground Based Sensor Subsystem |
| C20 | Inductive loops shall be placed a minimum of 4 ft. apart from the edge of one loop to the edge of the other loop to avoid cross talk between the loops and possibly give false signals.| Ground Based Sensor Subsystem |
| C21 | Voltage equivalence: The main wall power subsystem needs to protect devices from the damage caused by voltage and guarantee the safety of the electrical system, as well as preserve the whole subsystem. | Wall power Subsystem |
| C22 | During main power failures, power flow is controlled by the switch controller. | Wall power Subsystem |
| C23 | It should be within wire capabilities. | Wall power Subsystem |
| C24 | Must be a kill switch to disconnect all the power from the source. | Wall power Subsystem |
| C25 | The subsystem shall power each subsystem's demanded voltage and current with a 10% tolerance. | Power Controller Subsystem |
| C26 | The subsystem output shall be connected to the other subsystems through three fuses.| Power Controller Subsystem |
| C27 | The subsystem shall have a DC nominal voltage of 12V. | Power Controller Subsystem |
| C28 | Controller shall maximize the output power from the solar panel. | Charge Controller Subsystem |
| C29 | Controller shall output 12 V with a 10% tolerance to the Power Controller. |Charge Controller Subsystem |
| C30 | Controller shall prevent the batteries from being damaged due to over-charging | Charge Controller Subsystem |


# Loop Controller
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

## Constraints of the Loop Controller
1. Subsystem shall detect cars/pickup trucks (vehicles) that are entering and exiting a parking lot.

   a. This constraint was achieved as proven in the results.
   
2. Vehicle detector shall be compliant with the FCC frequency range for Intentional Radiators and verifying the detector is within permissible part 15 frequencies.

   a. This constraint was achieved as proven in the results.
   
3. Each entrance/exit of a parking lot shall use a total of one loop controller that will control the two inductive loops at the entrance/exit.

   a. This constraint was achieved as the Loop Controller that was used for Experimentation controls both inductive loops accordingly and the frequency of both inductive loops are similar to the expected results in the Loop Controller Signoff.
   
4. The Loop Controller shall be connected to the ESP32 Microcontroller that is used with the Data system of the project to communicate a change in frequency in both of the loops and determine whether a vehicle is entering or exiting a parking lot.

   a. This constraint was achieved and further evaluation of this constraint is located in Data Subsystem Analysis section of Experimentation.

