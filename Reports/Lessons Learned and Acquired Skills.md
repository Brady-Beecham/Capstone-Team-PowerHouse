# Abdulrahman Alrudayan



# Khalifah Altamimi



# Brady Beecham



# Kyle Plant



# Michael Sisk

## What did not go well?  

1. At the beginning of Capstone 1, the team inherited a continuation project and struggled to understand the necessary direction of the project and whether to continue building with cameras or research for other methods of monitoring parking lots.  The first two technical reports were not as great as they could have been when looking at Capstone 1.  After the first report, the team completed more in-depth research on how inductive loops truly worked, how to utilize them in the project, how the idea would be more suitable for Tech’s campus versus cameras, and how to explain and defend the idea in the Conceptual Design. 

## What did go well? 

1. After understanding the direction of the project, the team was able to work effectively together with the common goal of building a proof of concept system that uses inductive loops to monitor parking lots and that they are a more suitable option over cameras. 

2. Once the team direction of the Loop Controller changed from understanding how someone else built their controller and trying to create similar designs to using an oscillator and sine to square wave circuit, the Loop Controller became simple in both simulation results and experimentation results.  At the end of experimentation, the Loop Controller was able to detect vehicle movement over the inductive loops due to a change in frequency from the inductive loops. 

## What “best practices” have you identified? 

1. For the Loop Controller, the team assumed we would need two PCBs as the Engineering Quad has two entrances/exits.  In the ordering parts stage of the Loop Controller, the correct number of parts needed for two PCBs was ordered and though the team later decided to use one PCB instead of two, the parts that were for the second PCB became spares.  This proved useful as some of the components on the first PCB had issues and needed to be replaced.  By having the extra components, the Loop Controller issues were resolved and testing could continue on the Loop Controller. 

2. When starting in Detail Design, having a central location to place all documentation makes the designs simpler as when you are needing help on a design, the team can easily access the documentation you have and better resolve the issue at hand without having to wait on you to send all the information via email.  This was very useful when the Loop Controller was still being completed over the Winter Break as every teammate was able to see the work done and what was still unfinished.  The team was also able to complete more in-depth research of both the Loop Controller and other subsystems that were being designed during the Winter Break. 

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
