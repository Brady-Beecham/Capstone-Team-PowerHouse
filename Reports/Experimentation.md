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

