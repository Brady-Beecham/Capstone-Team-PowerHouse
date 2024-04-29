# Abdulrahman Alrudayan
## What went well? 
At the beginning of the Capstone one, we chose to have weekly meetings with our supervisor as a team. Every two weeks, we meet with our sponsors. However, at each meeting, we have a target to do something. Also, at every meeting, we made decisions about new details for each one. Also, if we face some problems, we can fix them early together as a group. We kept up these weekly meetings throughout capstone two, which kept us very successful. Even during Christmas break, we met once every week in teams. We worked on our problem and what’s the new update. That is shown as necessary to help us reach our goals.

Furthermore, the wall power subsystem was carefully designed, soldered, and selected components in specific sizes and chips, such as adapter power supply, chips “buck converters,” inductors, capacitors, resistors, relay switches, and backup batteries. The main thing for my subsystem is to step down the voltage and current to feed each of the two subsystems. Both components were carefully calculated to provide reliable results.

## What did not go well? 
everything go well. In capstone one, I struggled to understand how to select some components such as, chips  and switches 


## What “best practices” have you identified? 
I really understood how to select the components and design PCBs with soldered components, especially chips. For the chips “buck converter,” do not use the Weller soldering station. You can use surface mount ICs, which are excellent.

## What unanticipated problems occurred? 
All I selected was a small size for resistors and Capacitors for solder. 

## What would you do differently if you were able to do it over again? 
## What new knowledge or skills did you acquire throughout Capstone? 

# Khalifah Altamimi
## What went well? 
Our group's decision to hold weekly meetings proved instrumental in accomplishing our goals and resolving design phase challenges.The significant impact of these sessions was great.Each meeting was goal-oriented, ensuring efficient use of time and focused discussions.

Through consistent communication, we addressed issues promptly, brainstormed solutions, and maintained a sense of unity. This commitment to regular meetings exemplified the power of structured communication in driving success in group endeavors.

The Power Controller subsystem was meticulously designed and soldered to efficiently step down voltage and supply the necessary currents to all project subsystems. Moreover, it incorporated safety measures by utilizing fuses to ensure a secure power path.

Meanwhile, the Solar Power subsystem was meticulously designed and implemented. The solar panel successfully provided the required voltage to the charge controller, while the backup battery ensured uninterrupted power supply. Both components were meticulously calculated to meet the system's voltage and current requirements, ensuring reliable operation.

## What did not go well? 
A problem occurred with the Power Controller subsystem when one of its outputs had a tolerance higher than 10%. 

## What “best practices” have you identified? 

I have learned that designing a PCB requires careful attention because even a small issue could cause a short circuit. Another important practice is to print the PCB and check the component sizes and layout for accuracy.

## What unanticipated problems occurred? 

The only unanticipated problem I faced was selecting a very small SMD size for all resistors on my PCB. 

## What would you do differently if you were able to do it over again? 

I would print the PCB design on paper, and then I would be able to see the actual size of all the components on my PCB. If an issue were found, I could change the size or redesign the PCB to get the best outcome. 

## What new knowledge or skills did you acquire throughout Capstone? 

I learned many new things, such as designing PV systems, voltage regulators, and PCBs. These new skills helped me determine what I prefer to do in the future. Moreover, each skill and knowledge I acquired was the key to accomplishing my assigned subsystem. 

# Brady Beecham
## What went well? 

We chose to have weekly meetings for just the team, weekly meetings with our supervisor, and biweekly meetings with our sponsers. Continuing to have these weekly meetings even into capstone two played a huge part into our success.

Another thing that helped our team succeed is our willingness to work over christmas break. We met once a week over break and it saved us weeks as we were able to problem solve in a much more relaxed environment (i.e. not having four other classes to worry about.)


## What did not go well? 

For our team, everything went very smooth due to how often we met during the project. Any problem that came up for an individual was able to be solved as a team. 

For my design specifically, populating and testing my pcbs did not go well. While the design should work if soldered properly, the chips chosen (QFN chips) were not novice friendly and crippled my subsystem.

## What “best practices” have you identified? 

### Communication is key
Meet once a week with just the team and another time with your supervisor (especially capstone one!!!) The team meeting can just be updates and keeping track of any problems that come up. It is surprisingly helpful explaining your problems to others who understand (helpful with problem solving and also mentally. It's a long project, lean on your teammates and let your teammates lean on you.) The supervisor meeting should be a simple check in and to get validation that what you are designing aligns with the problem / what is being asked. 

### Design PCBs with the soldering in mind
If possible, always use IC chips that have leads. Do not use no leads ICs. Surface mount ICs are pretty simple to solder with the right equipment. ( Use Conard's equipment! It's great!)

### Know about the electrical engineer on campus. He's great
Talk to Conard (the electrical engineer on campus) for any PCB questions or advice in general. He is here to help.

### Comminucation is key

This is so important I'm putting two sections about it!!!

Talk about the problems you are facing with your teammates, even if you feel stupid for not knowing how to solve it at that moment. It will save you time and help your teammates gain confidence about sharing problems they are facing as well. It is much better knowing about problems everybody is facing BEFORE meeting with your supervisor. 


## What unanticipated problems occurred? 

Some problems came up after not talking to our supervisor properly. We had to scrap some subsystems and come up with new subsytem ideas near the end of capstone one. This was as frustrating as you imagine. With better communication with our supervisor earlier in capstone one, this problem would not have occured. 

Another problem arose due to not being adament about _everybody_ having to share how their design was going during capstone one. Some simple problems/misunderstandings came up that could have been easily fixed if designer was more open about the problems they were facing. 

## What would you do differently if you were able to do it over again? 

I would replace all QFN ICs with ICs that have leads.

I would also split up my main pcb into at least two pcbs so that once a single circuit is proven, that pcb can be set aside. (I had a circuit that broke after being proven due to having to put the whole pcb back into the heat oven for a different circuit.) Note that this would have caused a more complex wiring once the pcbs were complete, but I think it's worth it.

Each PCB should have only one function. (Very similar to how each function in code should only have one job.) 


## What new knowledge or skills did you acquire throughout Capstone? 

I learned about PCB design and also really understood circuit design for the first time.

While I did well in all of the circuits and electronics classes, I never really _got it_ with circuit design. Since I'm a computer engineer and not a electrical engineer it was easy to tell myself that not having a great feel for circuit design is acceptable. It is not. Getting a good feel for circuit design is the most valuable hard skill / lesson I got from capstone.

Communicating engineering problems is the best soft skill that I learned. Having so many meetings made this skill nearly impossible not to learn.

# Kyle Plant
## What went well? 
1. The utilization of the Pulse Counter hardware module of the ESP32 microcontroller. The PCNT module of the ESP32 allows for the measurement of frequencies up to 40 MHz supposedly (I have not tested that myself), so we had plenty of resolution for measuring the frequencies of the loop controller, which range from 50-75 kHz. The sampling window just needs to be adjusted to match the frequency you are trying to measure. If you have too long of a sample period and a high-frequency signal, the PCNT module can overflow and get set back to 0 in that amount of time. Each PCNT unit uses a 16-bit signed counter register and 2 channels that can either increment or decrement the count on the register. So, that means a maximum of 32767 and a minimum of -32768.
2. LoRaWAN with The Things Stack, eventually. Once I found a good library that works how I need it to, allowing me to split up the LoRaWAN functionality into tasks under FreeRTOS, getting set up with The Things Stack was easy. I used this library https://github.com/manuelbl/ttn-esp32 with the ESP-IDF. With this library, I was able to use Over-the-air authentication (OTAA) to connect to the gateway and send and receive messages with range in excess of 1 km. Setting up the gateway was also easy. I just had to download the sx1302 hardware abstraction layer and make some changes in the global config file for it to register with my TTS application. Also, the WM1302 has u.FL connectors RFIO and ANT. The RFIO connection is on the mini PCIE PCB and the ANT is on the PiHat. The one labeled ANT IS NOT WHERE YOU PLUG IN THE ANTENNA! You plug the antenna for your gateway into the RFIO connection and ANT is for something like a GPS module. Connecting my antenna correctly increased my range from 60m  to over 1 km.
3. The static threshold over rolling average algorithm I used for vehicle detection and directional logic in the ESP32 code. The algorithm used for directional logic as I call it is very simple but effective. Over 160 tests we got 96% accuracy. It works by comparing new frequency samples to the rolling average frequency per loop. The rolling average is calculated by taking the average of an array containing the most recent measured frequencies. The array size can be changed to make it more or less reactive to change. We compare the new frequencies to that average and see if they exceed the average by the specified threshold value. If the new frequency exceeds the threshold we push a loop event to a queue containing the loop ID, frequency, and timestamp. We read from that queue using a different task. That task is the directional logic proper. It looks for consecutive events with different loop IDs and also checks if the delta change is in "timeout" or if the event is deemed unrelated or "stale." Timeout is an easy way of debouncing. It is simply a time after the delta is changed that has to pass before the delta can be changed again. Staleness determines if the two events are close enough in time to be related to each other. Based on the conclusions, the delta will be updated based on the order of loop IDs in the queue.
4. ESP-IDF. The ESP-IDF gives much better control of the ESP32 hardware. It is built with FreeRTOS in mind and I highly recommend the ESP-IDF be used over Arduino for more complex applications.

## What did not go well?  
1. LoRaWAN with ChirpStack. Setting up the Raspberry Pi to work with ChirpStack as its individual components and also running the Gateway OS was much more complicated than The Things Stack. I highly recommend TTS over ChirpStack if you want something straightforward.
2. Finding good LoRaWAN libraries for Arduino/ESP-IDF that work well with FreeRTOS. I recommend the ESP-IDF if you need more control over your LoRaWAN code.
3. Speed estimation. This was tried out in the ESP32 code. We wanted to be able to determine the speed a vehicle travels over the loops, but I could not find a good way to implement it due to the fixed sample period of the Pulse Counter task. That resulted in wildly inaccurate speeds.
4. ESP32 with RFM95W LoRa radio transceiver still takes absolutely forever to join TTS network sometimes.



## What “best practices” have you identified? 
1.	"Being a good neighbor" with The Things Stack. To be a good neighbor with your LoRaWAN network under The Things Stack/The Things Network, you should transmit infrequently and not have excessive range. Transmitting all the time and having enormous range makes you a "noisy neighbor" because they will pick up all your transmissions, possibly causing them to miss some of their own messages.
2.	Feeding the watchdog with ESP32 and FreeRTOS in ESP-IDF. You should subscribe tasks to the task watchdog and reset it at regular intervals while avoiding any form of blocking code or else you will trigger the watchdog. You do not want your device to enter a state where it will have to reset because the watchdog was not fed.


## What unanticipated problems occurred? 
1. LoRaWAN range was much lower than expected initially, but this was later solved by connecting the antenna to the correct connector on the WM1302. ANT is not where you put the antenna, RFIO is...


## What would you do differently if you were able to do it over again? 
1. Not spend so much time trying to get LoRa physical layer or LoRaWAN with ChirpStack to work and instead just start with LoRaWAN with The Things Stack.
2. Develop a more sophisticated algorithm that can classify the vehicles it detects. For example, if it is a car or a truck.
3. Test motorcycles because everyone always asks about them.


## What new knowledge or skills did you acquire throughout Capstone? 
1. LoRa and LoRaWAN as a whole.
2. The Things Stack.
3. ChirpStack.
4. ESP32 hardware.
5. ESP-IDF.
6. FreeRTOS.
7. Better teamwork skills.


# Michael Sisk

## What did not go well?  

1. At the beginning of Capstone 1, the team inherited a continuation project and struggled to understand the necessary direction of the project and whether to continue building with cameras or research for other methods of monitoring parking lots.  The first two technical reports were not as great as they could have been when looking at Capstone 1.  After the first report, the team completed more in-depth research on how inductive loops truly worked, how to utilize them in the project, how the idea would be more suitable for Tech’s campus versus cameras, and how to explain and defend the idea in the Conceptual Design. 

## What did go well? 

1. After understanding the direction of the project, the team was able to work effectively together with the common goal of building a proof of concept system that uses inductive loops to monitor parking lots and that they are a more suitable option over cameras. 

2. Once the team direction of the Loop Controller changed from understanding how someone else built their controller and trying to create similar designs to using an oscillator and sine to square wave circuit, the Loop Controller became simple in both simulation results and experimentation results.  At the end of experimentation, the Loop Controller was able to detect vehicle movement over the inductive loops due to a change in frequency from the inductive loops. 

## What “best practices” have you identified? 

1. For the Loop Controller, the team assumed we would need two PCBs as the Engineering Quad has two entrances/exits.  In the ordering parts stage of the Loop Controller, the correct number of parts needed for two PCBs was ordered and though the team later decided to use one PCB instead of two, the parts that were for the second PCB became spares.  This proved useful as some of the components on the first PCB had issues and needed to be replaced.  By having the extra components, the Loop Controller issues were resolved and testing could continue on the Loop Controller. 

2. When starting in Detail Design, having a central location to place all documentation makes the designs simpler as when you need help on a design, the team can easily access the documentation you have and better resolve the issue at hand without having to wait on you to send all the information via email.  This was very useful when the Loop Controller was still being completed over the Winter Break as every teammate was able to see the work done and what was still unfinished.  The team was also able to complete more in-depth research of both the Loop Controller and other subsystems that were being designed during the Winter Break. 

## What unanticipated problems occurred? 

1. For the Loop Controller, the Linear Voltage Regulator pinout was incorrect. The datasheet for the component was reversed and this caused major issues as it would send 8.5 VDC to the Comparator (maximum voltage for the comparator is 7.5 V).  For the Comparator, it did not have an indented notch as most IC chips normally have to specify the top side of the component.  Due to this, the first Comparator was placed on the PCB incorrectly and with the issue of higher than maximum voltage being sent to the incorrect pin of the Comparator, the Comparator was replaced with a new component.  Since the team unanimously agreed to order extra of every component for all designs, both the Linear Voltage Regulator and the Comparator were replaced in the same day and there was no downtime due to the incorrect datasheets and the missing indented notch for the Comparator. 

## What would you do differently if you were able to do it over again? 

1. For the Loop Controller, the original plan was to find a DIY Loop Controller someone had previously built and understand how it works through the design.  This proved to be not useful as it was impossible to simulate the design and produce the same results.  For all circuits that are DIY, find the basic level circuits necessary to complete the objective and combine the circuits together one at a time and constantly test to verify the circuits work together accordingly.  This process will save lots of time and avoid numerous headaches that would come with trying to understand someone else’s work. 

## What words of wisdom would you pass on to future students? 

1. Continue having meetings through Capstone 2 

    a. Thanks to having a team meeting once every week (sometimes twice depending on deadlines), meeting with NAVSEA every other week, and constant communication through Discord, everyone was able to stay informed of what was happening for all subsystems.  For issues that occurred, the team was able to stay well informed of the issue and how to resolve issues before it was too late to do anything about it. 

2. Utilize every team member’s strengths to help the team 

    a. By learning what every team member’s strengths for subsystem development, technical writing, etc., each team member was able to contribute significantly to the project.  By utilizing each team member’s strengths, everyone in the project will be able to utilize the knowledge they have obtained over their undergraduate studies and apply it to the project. 

3. The original ideas of how the project will be at the end of Capstone will more than likely change throughout the project. 

    a. At the beginning of Capstone, the original idea was to measure inductance and voltage change of the inductive loops.  This was not the case as it was simpler to monitor change in frequency and to also use a custom-built controller that was designed in house and not use a prefabricated controller to monitor the inductive loops.  The original idea of the inductive loops and the loop controller changed over the course of the project and was simpler to use the final product than to use the ideas generated at the beginning of Capstone. 

## What new knowledge or skills did you acquire throughout Capstone? 

1. During the course of this project, I learned how to draw schematics and create PCB layouts using KiCAD software.  Through numerous drawings for both the Loop Controller and Ground Based Sensors, I was able to create schematics and PCB layouts that were simple to follow and understand as to how each component was connected to other components. 

2. For technical documentation, I obtained a better understanding of IEEE format using LaTeX in Overleaf and how to write effective technical documentation for projects. 

3. Besides the technical knowledge acquired in Capstone, I learned more on how to work with a team and how to communicate effectively so everyone on the team has the same understanding of the discussion. 
