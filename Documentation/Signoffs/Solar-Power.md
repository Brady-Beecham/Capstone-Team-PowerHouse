# Solar Power Subsystem
The purpose of the solar power subsystem is to generate energy using solar panels and a backup battery. The solar panels utilize a Photovoltaic system to generate the required energy to meet the load's needs. The backup battery stores the generated energy from the solar panels during daylight hours, making it available for use at night. The subsystem will supply the necessary rated energy to the other subsystems. By using a charge controller connected to both the solar panels and the backup battery, the charge controller will transmit the energy to the power controller.  
# Constraints
| No. | Constraints | Origin | 
| --- | ----------- | ------ |
| 1.  | The solar panel and the backup battery shall be connected to the charge controller.  System Requirements |
| 2.  | The solar panel should be installed at the right direction and angle that can capture the maximum amount of sunlight. | System Requirements |
| 3.  | The charge controller shall maximize the output power from the solar panel. | System Requirements |
| 4.  | The backup battery shall have enough capacity to prevent the charge controller from discharging more than 50%.| System Requirements |
| 5.  | The backup battery shall either be in the charging or discharging phase, and it cannot be in both simultaneously. | System Requirements |
| 6.  | The  Solar panel and the backup battery wiring shall have a kill switch to disconnect from the charge controller. | System Requirements |


Table 1. Constraints and origins of the constraints.


1. The solar panel and the backup battery will be connected to a charge controller to manage the solar panel output power. Also, it controls the battery charging and discharging phases.     
2. The direction of the solar panels depends on various aspects, as the sunlight differs based on the geographical location. For the case of installing solar panels in North America, the optimal direction is oriented toward facing the south [ 1 ]. Also, the positioning angle of the solar panels plays an essential role in having maximum sunlight. Moreover, it is crucial to place solar panels where they receive direct sunlight, free of obstructions such as trees, buildings, or fences.
3. The charge controller will be responsible for maximizing the output power of the solar panels. The output power of the solar panel can vary throughout the day. Therefore, the charge controller must step up or down the solar panels' output to supply the needed voltages and currents by the loads, including the charging of the backup battery.  
4. The backup battery must have enough capacity to be at most 50% of its capacity while discharging throughout the day of autonomy. The backup battery will have three days of autonomy, which is considered the worst-case.      
5. The backup battery can only perform one procedure at a time. Doing both simultaneously will impact the process of the charging and discharging phase. The charging phase can only occur if it is not discharging simultaneously. On the other hand, The discharging phase can only happen if the battery is not charging simultaneously.
6. A physical kill switch is added to the subsystem for manual control. The kill switch can be used in cases where maintenance is required or to stop either the solar panel or the battery from generating power.

| No. | Subsystem | Voltage | Current |
| --- | ----------- | ------ | ------ |
| a.  | Sensor | 9 V | 0.05 A |
| b.  | Data interpretation, Transmission, and Storage | 5.5 V | 0.25 A |
| c.  | Charge Controller | 5.5 V | 0.25 A |


Table 2.  Parameters for the voltages and currents for the subsystems.

# Buildable schematic

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/90190d97-494c-4989-bda5-5b015d1d8a00)

*Figure 1. Solar Power Block Diagram*

![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/9747e6d6-a8f2-4858-9b76-fd6fab358187)


*Figure 2. Panel Dimensions*    


 ![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/fd162e54-20aa-4a76-92f4-9bdce27a9ec5)                                                                                                                                  ![image](https://github.com/Brady-Beecham/Capstone-Team-PowerHouse/assets/131785470/bf5d8d58-b88e-4fcc-ba54-afad7f79ded0) 

 *Figure 3. Single Battery Dimensions*


# Analysis

## Solar Panel
1. The monocrystalline solar panels will be implemented in this subsystem. The common choices when selecting solar panels are between monocrystalline and polycrystalline. The monocrystalline has better efficiency with about 3 % performance ratio [ 2 ]. In this subsystem, the load and the backup battery will require a single solar panel with ratings of 25 W and 12 V. These selections are based on hand calculations by using CEDengineering.com documents that can be found in the course document of “ Design and Sizing of Solar Photovoltaic Systems” course [ 3 ].

Use Table 2 to get the voltage and current required by the three subsystems.
```math
{\rm Power}_{Consumtion} =\ 9\ V\times\ 0.05\ A+\ 5.5\ V\times\ 0.25\ A+\ 5.5\ V\times\ 0.25\ A
```

```math
{\rm Power}_{Consumtion}\ =\ 3.2\ W
```

```math
{\rm Energy}_{Daily}=\ {\rm Power}_{Consumtion}\ \times\ 24\ Hours
```

```math
{\rm Energy}_{Daily}=\ 3.2\ \times\ 24\ Hours
```
```math
{\rm Energy}_{Daily}=\ \ 76.8\ Wh
```



1. W_PV: peak wattage of the array (W_p)
2. E: daily energy requirement (Wh)
3. PSH: average daily number of Peak Sun Hours in the design month for the inclination (hours)

```math

W_{PV}=\ \ \frac{{\rm Energy}_{Daily}}{PSH\ \times\ (\ 0.65\ )}\
```


```math
W_{PV}=\ \ \frac{76.8\ Wh}{4.4\ \times\ (\ 0.65\ )}\ =\ 26.85\ W_p
```

2. PV sizing:
The solar panel sizing can be determined by doing steps of calculation. The solar panel for a stand-alone system should be designed to cover the average daily load during the critical design month[3]. The solar panel is sized to satisfy the average daily load requirements for the month or season of the year with a lower ratio of daily insolation to the daily load[ 3 ]. Therefore, according to the Weather Atlas website, the month with the least sunshine average is February, with about 4.4 hours of sunshine [ 4 ]. Using module power output and daily insolation (in peak sun hours), the energy (watt-hours or amp-hours) delivered by a photovoltaic module for an average day can be determined [ 3 ]. Then, knowing the load requirements and the output of a single module, the solar panel can be sized [ 3 ].


```math
Required\ array\ output\ per\ day\left(Wh\right)=\frac{{\rm Energy}_{Daily}}{0.85}\ ;\ \ SLD\ Battery efficiency = 0.85
```
```math
    
```
```math
Required\ array\ output\ per\ day\left(Wh\right) =\frac{76.8}{0.85} =\ 90.35\ Wh
```
```math
    
```
```math
Energy\ output\ per\ module\ per\ day\left(Wh\right) = W_{PV}\times4.4 =\ 110Wh\ ;\ \ W_{PV}=25Wh\ \, sunshine\ in\ Feb=4.4
```
The selected array output per Day is W_PV = 30Wh

```math
Energy\ output\ per\ module\ per\ day\left(Wh\right) = 30Wh\times4.4 =\ 132Wh\ ;\ \ W_{PV}=30Wh\ \, sunshine\ in\ Feb=4.4
```


```math
Module\ energy\ output\ at\ operating\ temperature\ (Wh) = 0.8\ \times\ 132\  =\ 105.6Wh  \ ;\ \ rating\ factor\ for\ critical\ applications =\ 0.8
```

```math
\ \ \frac{Required\ array\ output\ per\ day}{Module\ energy\ output\ at\ operating\ temperature}
```

```math
\ \ \Number\ of\ modules\ required\ to\ meet\ energy\ requirements\ =\ \frac{90.35\ Wh}{105.6\ Wh} =\ 0.86 \ \approx 1\ module\ \
```



Based on the hand calculations, this subsystem will require one solar module for a rated power of 30 W.


## Battery

The battery type is Sealed Lead Acid AGM. The sealed lead acid has a depth of discharge of 50%, and the battery's efficiency is 85 %. The two batteries will be connected in parallel to increase the global capacity of the battery, which is rated by amps per hour. Connected batteries are going to charge and discharge through the charge controller. The temperature factor is 1.19.
 
The batteries will be located outdoors; therefore, the discharge capacity according to the temperature should be considered. The discharge capacity for the battery being outdoors for 20 hours at a temperature of -15 C will reduce the battery capacity to 65%.

```math
Battery\ Capacity (Ah) = \ \frac{Daily\ Electrical\ Load\ \times\ Days\ of\ Autonomy\ \times\ Temperature\ Compensation\ }{Load\ Subsystem\ Efficiency\ \times\ Depth\ of\ Discharge\ \times\ Voltage}
```
```math
```
```math
Battery\ Capacity (Ah)= \ \frac{ 22.5 \times\ 3 \times\ 1.19 }{ 0.85 \times\ 0.5 \times\ 12}
```
```math
```
```math
Battery\  Capacity (Ah) =\ 15.75\ Ah
```
For a battery capacity of 15.75 Ah, increasing the battery capacity is considered a good practice when choosing battery capacity for a solar power system. Also, considering the depth of discharge and other loss power factors, the desired battery capacity will be 24 Ah, which means we will need two batteries with 12 V and 12 Ah in parallel. Since connecting a battery in parallel will increase the battery capacity, the battery capacity will increase to 24 Ah, and the battery voltage will remain the same at 12 V. 







# BOM
| Part | Part Number | Quantity | Price Per Unit | Total Price |
| ------------ | ------------- | --------- | -------- | ---------- |
| Solar Panel | AM-L02P25-1 | 1 | $35.99 |  $35.99 |
| Seal Lead Acid | ML12-12F2 | 2 | $27.99 | $55.98 |
| Total | ----- | ----- | ----- | $91.97 


Solar Panel: https://www.amazon.com/gp/product/B01IFJ73X4/ref=ewc_pr_img_1?smid=A5KU5HDAPDC75&psc=1

Seal lead acid Battery: https://www.amazon.com/ML12-12-Battery-Terminal-Mighty-Product/dp/B00K53FG5Q/ref=sr_1_4?crid=2ENRDXKVGB5V8&keywords=ml12-12%2Bbattery&qid=1698983669&s=electronics&sprefix=ML12-12%2B%2Celectronics%2C153&sr=1-4&th=1

# References
1. “Best direction for solar panels:,” Maximize Efficiency: Best Direction for Solar Panels”, https://www.sunrun.com/knowledge-center/best-direction-for-solar-panels (accessed Oct. 31, 2023).
2. H. Fitria, ”The effect of monocrystalline and polycrystalline material structure on Solar Cell Performance”,https://www.researchgate.net/publication/347745141_The_effect_of_monocrystalline_and_polycrystalline_material_structure_on_solar_cell_performance (accessed Nov. 1, 2023).
3. “Design and sizing of solar photovoltaic systems,” www.cedengineering.com, https://www.cedengineering.com/courses/design-and-sizing-of-solar-photovoltaic-systems (accessed Nov. 1, 2023).
4. Weather Atlas, “Yearly & Monthly Weather - Cookeville, TN,” Weather Atlas, https://www.weather-atlas.com/en/tennessee-usa/cookeville-climate (accessed Nov. 2, 2023). 







