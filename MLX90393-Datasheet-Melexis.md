# **MLX90393**

Triaxis® Magnetic Node

Datasheet

## **1. Features and Benefits**


  - Absolute Position Sensor IC featuring

Triaxis® Hall Technology


  - Simple & Robust Magnetic Design


  - Miniature size for tiny assemblies


  - Selectable SPI and I [2] C bus protocols


  - Wide dynamic range (5-50mT) with on-the
fly programmable gain


  - 2.2V-3.6V supply for battery powered

applications, down to 1.8V IO voltage


  - On board filter settings


  - On the fly programmable operating modes

and sleep times for micro-power use


  - External and internal acquisition triggering


modes


  - External interrupt pin when the field

changes


  - On board temperature sensor

## **2. Application Examples**


  - Non-contacting HMI applications with

push-pull functionality


    - Rotary knobs & dials


    - (Long stroke) Linear motion in one or

two axes for levers & sliding switches


    - Joystick (gimbal or ball & socket)


  - Home Security 3D closure detection


  - Accurate liquid level sensing


  - Factory automation position sensing


  - Magnetic fingerprint detection


REVISION 011 – SEP 24, 2024


3901090393


## **3. Description**

The MLX90393 brings the highest flexibility in the
Triaxis portfolio's smallest packaged assembly.
Additionally, the MLX90393 is designed for
micropower applications, with programmable duty
cycles in the range of 0.1% to 100% allowing for
configurable power consumption based on system
requirements.


The MLX90393 magnetic field sensor can be
reprogrammed to different modes and with
different settings at run-time to fine-tune the
performance and power consumed. The sensor
offers a 16-bit output proportional to the magnetic
flux density sensed along the X, Y, and Z axes using
the Melexis proprietary Triaxis technology and
offers a 16-bit temperature output signal. These
digital values are available via I [2] C and SPI, where
the MLX90393 is a slave on the bus. Multiple
sensors can be connected to the same bus, by A 0
and A 1 hardwired connection (4x) but also through
ordering codes with different SW address (4x).


By selecting which axes are to be measured, the
raw data can be used as input for further postprocessing, such as for joystick applications, rotary
knobs, and more complex 3D position sensing
applications. Unparalleled performance is achieved
with this sensor, which is primarily targeting
industrial and consumer applications.



A0 A1







V DD V DD_IO



SDA/ MOSI


SCL/ SCLK


MISO


MS/ CS


Interrupt


Trigger


V SS








|State Machine<br>Bias<br>RAM EEPROM<br>Triaxis® V V VX Y Z G ADC SC Po In / t I2ro Cl MUX<br>VT Interface<br>Temp Compensation<br>Temp Sensor<br>Oscillator L Oow sc iP llo aw toe rr Wake-Up|Col2|achine|Col4|
|---|---|---|---|
|VX<br>VY<br>VZ<br>ADC<br>G<br>MUX<br>Temp Sensor<br>Bias<br>EEPROM<br>State Machine<br>RAM<br>Control<br>SPI/ I2C<br>Interface<br>Low Power<br>Oscillator<br>Wake-Up<br>Oscillator<br>VT<br>Temp Compensation<br>**Triaxis®**|EEPROM<br><br>RAM<br>Control<br>SPI/ I2C<br>|EEPROM<br><br>RAM<br>Control<br>SPI/ I2C<br>||



_Figure 1: General Block Diagram_


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **Contents**


1. Features and Benefits ............................................................................................................................ 1


2. Application Examples ............................................................................................................................. 1


3. Description ............................................................................................................................................ 1


4. Ordering Information ............................................................................................................................ 4


5. Functional Diagram ............................................................................................................................... 5


5.1. QFN-16 Block Diagram........................................................................................................................ 5


5.2. UTDFN-8 Block Diagram ..................................................................................................................... 5


6. Glossary of Terms .................................................................................................................................. 6


7. QFN-16 Pinout ....................................................................................................................................... 7


8. UTDFN-8 Pinout ..................................................................................................................................... 8


9. Absolute Maximum Ratings ................................................................................................................... 9


10. General Electrical Specifications ........................................................................................................ 10


11. Thermal Specification ........................................................................................................................ 11


12. Timing Specification........................................................................................................................... 12


13. Magnetic Specification ...................................................................................................................... 14


13.1. Noise vs Conversion Time .............................................................................................................. 16


14. Mode Selection ................................................................................................................................. 17


14.1. Burst mode ...................................................................................................................................... 18


14.2. Single Measurement mode ............................................................................................................ 18


14.3. Wake-Up on Change mode ............................................................................................................ 19


15. Digital Specification ........................................................................................................................... 19


15.1. Command List ................................................................................................................................. 20


15.2. Status Byte ...................................................................................................................................... 21


15.3. SPI Communication ......................................................................................................................... 21


15.3.1. Command implementation ...................................................................................................... 22


15.3.2. SPI Timing Specification............................................................................................................ 24


15.4. I [2] C Communication ......................................................................................................................... 24


15.4.1. Command Implementation ...................................................................................................... 25


15.4.2. I [2] C Timing Specification ............................................................................................................ 27


16. Memory Map ..................................................................................................................................... 28


16.1. General Description ........................................................................................................................ 28


16.2. Parameter Description ................................................................................................................... 30



REVISION 011 – SEP 24, 2024

3901090393



Page 2 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


16.2.1. ANA_RESERVED_LOW .............................................................................................................. 31


16.2.2. BIST ............................................................................................................................................ 31


16.2.3. Z_Series ..................................................................................................................................... 31


16.2.4. GAIN_SEL[2:0] ........................................................................................................................... 32


16.2.5. HALLCONF[3:0] ......................................................................................................................... 33


16.2.6. TRIG_INT_SEL ............................................................................................................................ 33


16.2.7. COMM_MODE[1:0] .................................................................................................................. 33


16.2.8. WOC_DIFF ................................................................................................................................. 33


16.2.9. EXT_TRIG ................................................................................................................................... 34


16.2.10. TCMP_EN ................................................................................................................................ 34


16.2.11. BURST_SEL[3:0] ...................................................................................................................... 34


16.2.12. OSR2[1:0] ................................................................................................................................ 34


16.2.13. RES_XYZ[5:0] ........................................................................................................................... 34


16.2.14. DIG_FILT[1:0] .......................................................................................................................... 34


16.2.15. OSR[1:0] .................................................................................................................................. 34


16.2.16. SENS_TC_HT[7:0] .................................................................................................................... 34


16.2.17. SENS_TC_LT[7:0] .................................................................................................................... 34


16.2.18. OFFSET_i[15:0]........................................................................................................................ 35


16.2.19. WOi_THRESHOLD[15:0] ......................................................................................................... 35


17. Recommended Application Diagram ................................................................................................. 36


1.1 I [2] C ........................................................................................................................................................ 36


1.2 SPI ....................................................................................................................................................... 36


18. Packaging Specification ..................................................................................................................... 37


18.1. QFN-16 ............................................................................................................................................ 37


18.1.1. Package dimensions and sensitive spot location .................................................................... 37


18.1.2. QFN-16 - Pinout and Marking .................................................................................................. 38


18.2. UDTFN-8 package ........................................................................................................................... 39


18.2.1. Package dimensions and sensitive spot location .................................................................... 39


18.2.2. UTDFN-8 - Pinout and Marking ................................................................................................ 40


19. Standard Information ........................................................................................................................ 41


20. ESD Precautions ................................................................................................................................. 41


21. Revision History ................................................................................................................................. 42


22. Contact .............................................................................................................................................. 44


23. Disclaimer .......................................................................................................................................... 45



REVISION 011 – SEP 24, 2024

3901090393



Page 3 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **4. Ordering Information**





MLX90393 S (-20°C to 85°C) LW ABA-012 RE I [2] C address = 00100xx
MLX90393 S (-20°C to 85°C) LW ABA-013 RE I [2] C address = 00101xx
MLX90393 S (-20°C to 85°C) LW ABA-014 RE I [2] C address = 00110xx
MLX90393 E (-40°C to 85°C) LW ABA-011 RE I [2] C address = 00011xx
MLX90393 E (-40°C to 85°C) LW ABA-012 RE I [2] C address = 00100xx
MLX90393 E (-40°C to 85°C) LW ABA-013 RE I [2] C address = 00101xx
MLX90393 E (-40°C to 85°C) LW ABA-014 RE I [2] C address = 00110xx
MLX90393 S (-20°C to 85°C) LW ABA-111 RE I [2] C address = 00011xx
MLX90393 S (-20°C to 85°C) LQ ABA-011 RE I [2] C address = 0010000
MLX90393 S (-20°C to 85°C) LQ ABA-014 RE I [2] C address = 0011000


_Table 1: Product Ordering Codes_

## **Legend:**








|Temperature Code:<br>S: from -20°C to 85°C<br>E: from -40°C to 85°C<br>Package Code: “LW” for QFN-16 3x3x1mm package with wettable flanks<br>“LQ” for UTDFN-8 2.5x2mm package<br>Option Code: ABA-xx1, ABA-xx2, ABA-xx3, ABA-xx4: Different I2C addresses – 5 most<br>significant bits. The 2 least significant bits of the address are defined by the<br>external address pins A and A .<br>0 1<br>ABA-0xx: Standard IMC, magnetic saturation onset at 50mT<br>ABA-1xx: Thin IMC, magnetic saturation onset at 25mT<br>Packing Form: “RE for Reel”<br>Ordering Example: “MLX90393-ELW-ABA-011-RE”<br>MLX90393 Micropower magnetometer with I2C address 00011xx where the last<br>two bits are defined by external address pins A and A . In QFN package,<br>0 1<br>temperature range -40°C to 85°C.|Col2|Col3|Col4|
|---|---|---|---|
|Temperature Code:<br>S: from -20°C to 85°C<br>E: from -40°C to 85°C <br>Package Code:<br>“LW” for QFN-16 3x3x1mm package with wettable flanks<br>“LQ” for UTDFN-8 2.5x2mm package<br>Option Code:<br> <br>ABA-xx**1**, ABA-xx**2**, ABA-xx**3**, ABA-xx**4**: Different I2C addresses – 5 most<br>significant bits. The 2 least significant bits of the address are defined by the<br>external address pins A0 and A1. <br> <br>ABA-**0**xx: Standard IMC, magnetic saturation onset at 50mT<br>ABA-**1**xx: Thin IMC, magnetic saturation onset at 25mT<br>Packing Form:<br>“RE for Reel”<br>Ordering Example:<br>“MLX90393-ELW-ABA-011-RE”<br>MLX90393 Micropower magnetometer with I2C address 00011xx where the last<br>two bits are defined by external address pins A0 and A1. In QFN package,<br>temperature range -40°C to 85°C.|Ordering Example:|“MLX90393-ELW-ABA-011-RE”<br>MLX90393 Micropower magnetometer with I2C address 00011xx where the last<br>two bits are defined by external address pins A0 and A1. In QFN package,<br>temperature range -40°C to 85°C.|“MLX90393-ELW-ABA-011-RE”<br>MLX90393 Micropower magnetometer with I2C address 00011xx where the last<br>two bits are defined by external address pins A0 and A1. In QFN package,<br>temperature range -40°C to 85°C.|
|_Table 2: Product Ordering Code Example_|_Table 2: Product Ordering Code Example_|_Table 2: Product Ordering Code Example_|_Table 2: Product Ordering Code Example_|



REVISION 011 – SEP 24, 2024

3901090393



Page 4 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **5. Functional Diagram**

### 5.1. QFN-16 Block Diagram

### 5.2. UTDFN-8 Block Diagram


REVISION 011 – SEP 24, 2024

3901090393



Page 5 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **6. Glossary of Terms**


Gauss (G), Tesla (T) Units for the magnetic flux density  1 mT = 10 G


NC Not Connected


PWM Pulse Width Modulation


%DC Duty Cycle of the output signal i.e. TON /(TON + TOFF)


ADC Analog-to-Digital Converter


DAC Digital-to-Analog Converter


LSb Least Significant Bit


MSb Most Significant Bit


DNL Differential Non-Linearity


INL Integral Non-Linearity


EMC Electro-Magnetic Compatibility


REVISION 011 – SEP 24, 2024

3901090393



Page 6 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **7. QFN-16 Pinout**



















2 MS/CS I/O in MLX Test VDD_IO To
VDD_IO



Required Required



3 SCL/SCLK I/O in MLX Test VDD_IO Required Required Required


4 N/C -- -- -- -- -- -

8 VDD_IO Supply N/A Required Required Required


9 N/C -- -- -- -- -- -

10 N/C -- -- -- -- -- -


12 A0 I [2] C Address

LSB



MLX Test VDD To

VDD/GND



To GND To GND



13 VSS Ground N/A Required Required Required


14 N/C -- -- -- -- -- -

15 VDD Supply N/A Required Required Required

|Col1|16|N/C|--|--|--|--|--|--|Col10|
|---|---|---|---|---|---|---|---|---|---|
|_Table 3: Pinout Description_|_Table 3: Pinout Description_|_Table 3: Pinout Description_|_Table 3: Pinout Description_|_Table 3: Pinout Description_|_Table 3: Pinout Description_|_Table 3: Pinout Description_|_Table 3: Pinout Description_|_Table 3: Pinout Description_|_Table 3: Pinout Description_|



It is recommended to connect the N/C pins (Not Connected) to Ground.


The exposed pad of the QFN package can be left floating or shorted to ground.


REVISION 011 – SEP 24, 2024

3901090393



Page 7 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **8. UTDFN-8 Pinout**

















2 SDA/MOSI I/O bi MLX Test VDD_IO Required Required Short


4 VDD_IO Supply N/A Required Required Required
5 VSS Ground N/A Required Required Required
6 VDD Supply N/A Required Required Required

|Col1|8|INT|I/O out|N/A|VDD_IO|Optional|Optional|Optional|Col10|
|---|---|---|---|---|---|---|---|---|---|
|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|<br>_Table 4: UTDFN-8 Pinout Description_|



The exposed pad of the UTDFN-8 package can be left floating or shorted to ground.


REVISION 011 – SEP 24, 2024

3901090393



Page 8 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **9. Absolute Maximum Ratings**


V DD_IO_MAX Digital IO Supply Limits -0.3 min(4, V DD +0.3) V


ESD HBM According to AEC-Q100-002 2.5 kV


_Table 5: Absolute Maximum Ratings_


Exceeding the absolute maximum ratings may cause permanent damage. Exposure to absolute maximum-rated
conditions for extended periods may affect device reliability.



REVISION 011 – SEP 24, 2024

3901090393



Page 9 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **10. General Electrical Specifications**


V DD_IO Digital IO Supply 1.65 1.8 V DD V







V POR_HL Power-on Reset threshold


(falling edge)



1 1.31 V



I DD,CONVXY Conversion Current XY-axis 2.29 3 mA


I DD,CONVZ Conversion Current Z-axis 2.96 4 mA


I DD,CONVT Conversion Current Temperature 1.60 2 mA


I DD, CONV_END Current during T CONV_END 1.5 1.75 mA


I DD_IDLEtoSTBY Current during T STBY 1.2 1.75 mA


I DD,STBY Standby Current [(1)] 43 60 µA


I DD,IDLE Idle Current [(2)] 1 2.4 5 µA



_Table 6: General Electrical Specifications_





_1_ _Standby current corresponds to the current consumed in the digital where only the low power oscillator is running._

_This standby current is present in burst mode, or whenever the IC is counting down to start a new conversion._


_2_ _Idle current corresponds to the current drawn by the IC in idle mode where all operating functions are disabled except_

_communications._



REVISION 011 – SEP 24, 2024

3901090393



Page 10 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **11. Thermal Specification**


The MLX90393 has an on-board temperature sensor which measures the temperature of the MLX90393
sensor. The temperature can be read out via the communication protocol in a digital format


T 25 Temperature sensor output at 25°C 46244 LSB 16u


T OPERATING Operating temperature range [S code] -20 25 85 °C


Operating temperature range [E code] -40 25 85 °C


_Table 7: Thermal Specifications_


_3_ _The linearity is defined as the best fit curve through the digital temperature outputs over the entire temperature_

_range. It includes ADC non-linearity effects_



REVISION 011 – SEP 24, 2024

3901090393



Page 11 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **12. Timing Specification**


The specifications are applicable at 25 DegC unless specified otherwise and for the complete supply range.





T ACTIVE Time from STBY to ACTIVE 288 360 432 µs






|Single Magnetic axis conversion time(4) 259 66627<br>T<br>CONVM typical programming range<br>67 + 64 ∙2ைௌோ ∙(2 + 2஽ூீ_ிூ௅்)|Col2|µs|
|---|---|---|
|TCONVT|Temperature conversion time<br>typical programming range<br>259<br> <br>1603<br> µs<br>67 + 192 ∙2ைௌோଶ|Temperature conversion time<br>typical programming range<br>259<br> <br>1603<br> µs<br>67 + 192 ∙2ைௌோଶ|





Total conversion time in Single
T CONV_SMM Measurement Mode



T STBY + T ACTIVE + m*T CONVM + T CONVT+

ms
T CONV_END







Total conversion time in BURST with burst
T CONV_BURST_DLY data rate > 0 T ACTIVE + m*T CONVM + T CONVT+ T CONV_END ms



Total conversion time in WOC with burst
T CONV_WOC_DLY data rate > 0



T STBY + T ACTIVE + m*T CONVM + T CONVT+

ms
T CONV_END



T OSC_TRIM Trimming accuracy -5 +5 %


T OSC_THD Thermal drift (full temperature range) -5 +5 %











T LPOSC_THD Thermal drift (full temperature range) -5 +5 %


_4_ _This conversion time is defined as the time to acquire a single axis of the magnetic flux density. When measuring_

_multiple axes they are obtained through time multiplexing. The conversion time is programmable through parameters_

_OSR and DIG_FILT for magnetic values and OSR2 for the temperature value. The conversion sequence is TXYZ, opposite_

_of the ZYXT argument of the command set._


_5_ _The time T_ _INTERVAL_ _is defined as the time between the end of one set of measurements (any combination of TXYZ) and_

_the start of the following same set of measurements in BURST and WOC mode. As a result of this, the maximum output_

_data rate is not only a function of T_ _INTERVAL_ _but equals 1/(T_ _CONV_BURSTWOC_ _+ T_ _INTERVAL_ _)._



REVISION 011 – SEP 24, 2024

3901090393



Page 12 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


**Parameter** **Remark** **Min** **Nom** **Max** **Unit**


Time between INT rising and full
T INT_RDY accessibility [(6)] 132 µs


Startup


T POR Power-on-reset completion time 0.6 1.5 ms


External Trigger


T TRIG Trigger pulse width (active high) 0.01 250 µs


_Table 8: Timing Specifications_


_6_ _Reading the measurements (once) sooner than this specified time after the rising INT will work, however the status_

_byte can still show an active measurement mode (single measurement). Other commands are not allowed during this_

_time._



REVISION 011 – SEP 24, 2024

3901090393



Page 13 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **13. Magnetic Specification**


The specifications are applicable at 25 DegC unless otherwise specified and for the complete supply voltage

range.


N OUT Output span (taken from 19 by RES XYZ ) 16 bits







B SAT Magnetic saturation onset


Option codes -011, -012, -013, -014



50 mT





OFFS Deviation from expected 0mT output 0 LSB


OFFS THD Offset thermal drift, Delta from 25°C [ (7)] < ±1000 LSB



SENS XX,



, Programming range of magnetic resolution

SENS YY (µT/LSB) or sensitivity (LSB/mT) [ (8)]

[modifying GAIN_SEL and RES XYZ ], cfr. Table
17: Sensitivity table for given gain and

SENS ZZ resolution selection for HALLCONF=0xC



SENS ZZ



SENS XY,


SENS YX



Cross-axis sensitivity (X/Y-axis sensitivity to
Y/X magnetic fields)



3.220 0.161 µT/LSB


311 6211 LSB/mT


5.872 0.294 µT/LSB


170 3406 LSB/mT


< ±1 %







_7_ _The offset thermal drift is defined as the deviation at 0Gauss from the output with respect to the output at 25°C when_

_sweeping the temperature. The highest gradient (µT/°C) typically occurs at 85°C. The spec value is based on_

_characterization on limited sample size at GAIN_SEL=0x7 and RES_XYZ=0x00._


_8_ _The total axis sensitivity is programmable to support different applications, but has no Automatic Gain control on-chip_

_as do the other angular position sensors from Melexis. The highest gain corresponds to at least the minimum +/-4.8mT_

_magnetic measurement range and the magnetic resolution defined by SENS_ _ii_ _._



REVISION 011 – SEP 24, 2024

3901090393



Page 14 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


**Parameter** **Remark** **Min** **Nom** **Max** **Unit**



< ±1 %



SENS ZX,


SENS ZY



Cross-axis sensitivity (Z-axis sensitivity to X
and Y magnetic fields)







_Table 9: Magnetic Specifications_


_9_ _The sensitivity thermal drift is expressed as a band around the sensitivity at 25°C. It is applicable on wafer level_

_trimming, but can be influenced by packaging (overmolding)._



REVISION 011 – SEP 24, 2024

3901090393



Page 15 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 13.1. Noise vs Conversion Time



The MLX90393 provides configurable filters to adjust the tradeoff between current consumption, noise, and
conversion time. See section 15.1.5 for details on selecting the conversion time by adjusting OSR and DIG_FILT.











_Figure 2: XY axis RMS noise versus conversion time, expressed in mGauss for GAIN_SEL = 0x7 - Based on -0xx version_















_Figure 3: Z axis RMS noise versus conversion time, expressed in mGauss for GAIN_SEL = 0x7 - Based on -0xx version_



REVISION 011 – SEP 24, 2024

3901090393



Page 16 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **14. Mode Selection**


The MLX90393 can operate in three modes. They are: Burst mode, Single Measurement mode, and Wake-OnChange mode.


  - Burst mode


The ASIC will have a programmable data rate at which it will operate. This data rate implies autowakeup and sequencing of the ASIC, flagging that data is ready on a dedicated pin (INT/DRDY). The
maximum data rate corresponds to continuous burst mode, and is a function of the chosen
measurement axes. For non-continuous burst modes, the time during which the ASIC has a counter
running but is not doing an actual conversion is called the Standby mode (STBY).


  - Single Measure mode


The master will ask for data via the corresponding protocol (I [2] C or SPI), waking up the ASIC to make a
single conversion, immediately followed by an automatic return to sleep mode (IDLE) until the next
polling of the master. This polling can also be done by strobing the TRG pin instead, which has the
same effect as sending a protocol command for a single measurement.


  - Wake-Up on Change


This mode is similar to the burst mode in the sense that the device will be auto-sequencing, with the
difference that the measured component(s) is/are compared with a reference and in case the
difference is bigger than a user-defined threshold, the DRDY signal is set on the designated pin. The
user can select which axes and/or temperature fall under this cyclic check, and which thresholds are

allowed.


The user can change the operating mode at all time through a specific command on the bus. The device waits
in IDLE mode after power-up, but with a proper user command any mode can be set after power-up. Changing
to Burst or WOC mode, coming from Single Measure mode, is always accompanied by a measurement first.
The top-level state diagram indicating the different modes and some relevant timing is shown below in Figure
4. In the Measure state, the MDATA flag will define which components will be measured (ZYXT). The order of
conversion is defined as TXYZ and cannot be modified by the user, only the combination of axes is a degree of

freedom.


Arrows indicated in grey are the direct result of an Exit command. The main difference between STANDBY and
WOC_IDLE is that in STANDBY mode, all analog circuitry is ready to make a conversion, but this is accompanied
by a larger current consumption than IDLE mode. For burst mode this extra current consumption is justified
because the emphasis is more on accurate timing intervals, avoiding the delay of T STBY before conversion and
supporting an efficient continuous burst mode without standby overhead.


It is the user’s responsibility to read back the measured data as the MLX90393 is a slave device on the bus.
Even in burst mode and WOC mode when the MLX90393 is auto-sequencing, the master will be responsible
for collecting the acquired sensor data.



REVISION 011 – SEP 24, 2024

3901090393



Page 17 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 14.1. Burst mode



_Figure 4: Top-level state diagram with indication of timings_



When the sensor is operating in burst mode, it will make conversions at specific time intervals. The
programmability of the user is the following:


  - Burst speed (T INTERVAL ) through parameter BURST_DATA_RATE


  - Conversion time (T CONV ) through parameters OSR, OSR2 and DIG_FILT


  - Axes/Temperature (MDATA) through parameter BURST_SEL or via the command argument (ZYXT)


Whenever the MLX90393 has made the selected conversions (based on MDATA), the DRDY signal will be set
(active H) on the INT and/or INT/TRG pin to indicate that the data is ready for readback. It will remain high
until the master has sent the command to read out at least one of the converted quantities (ZYXT). Should the
master have failed to read out any of them by the time the sensor has made a new conversion, the INT/DRDY
pin will be strobed low for 10µs, and the next rising edge will indicate a new set of data is ready.

### 14.2. Single Measurement mode


Whenever the sensor is set to this mode (or after startup) the MLX90393 goes to the IDLE state where it awaits
a command from the master to perform a certain acquisition. The duration of the acquisition will be the
concatenation of the T STBY, T ACTIVE, m*T CONVM (with m # of axes) and T CONVT . The conversion time will effectively



REVISION 011 – SEP 24, 2024

3901090393



Page 18 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


be programmable by the user (see burst mode), but is equally a function of the required axes/temperature to

be measured.


Upon reception of such a polling command from the master, the sensor will make the necessary acquisitions,
and set the DRDY signal high to flag that the measurement has been performed and the master can read out
the data on the bus at his convenience. The INT/DRDY will be cleared either when:


  - The master has issued a command to read out at least one of the measured components


  - The master issues an Exit (EX) command to cancel the measurement


  - The chip is reset, after POR (Power-on reset) or Reset command (RT)

### 14.3. Wake-Up on Change mode


The Wake-Up on Change (WOC) functionality can be set by the master with as main purpose to only receive
an interrupt when a certain threshold is crossed. The WOC mode will always compare a new burst value with

a reference value to assess if the difference between both exceeds a user-defined threshold. The reference

value is defined as one of the following:


  - The first measurement of WOC mode is stored as reference value once. This measurement at “t=0” is

then the basis for comparison or,


  - The reference for acquisition(t) is always acquisition(t-1), in such a way that the INT signal will only
be set if the derivative of any component exceeds a threshold.


The in-application programmability is the same as for burst mode, but now the thresholds for setting the
interrupt are also programmable by the user, as well as the reference, if the latter is data(t=0) or data(t-1).

## **15. Digital Specification**


The supported protocols are I [2] C and SPI. The MS/CS pin is used to define the protocol to be used:


  - /CS = 0 for SPI, addressing the MLX90393 slave in SPI mode (3- and 4-wire), but releasing this line in
between commands (no permanent addressing allowed)


  - /CS = 1 for I [2] C, addressing the MLX90393 slave when the correct address is transmitted over the bus
(permanently kept high)



REVISION 011 – SEP 24, 2024

3901090393



Page 19 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


To ensure the activity on the SPI bus cannot be accidentally interpreted as I [2] C protocol, programming bits are
available in the memory of the MLX90393 to force the communication mode. It concerns the
COMM_MODE[1:0] bits with the following effect:


1 0 SPI mode only


1 1 I [2] C mode only


_Table 10: Communication mode definition_

### 15.1. Command List


The MLX90393 only listens to a specific set of commands. Apart from the Reset command, all commands
generate a status byte that can be read out. The table below indicates the 10 different commands that are
(conditionally) accepted by the MLX90393. The MLX90393 will always acknowledge a command in I [2] C, even if
the command is not a valid command. Interpreting the associated status byte is the method for verification of
command acceptance.





Start Burst Mode SB 1 0001 zyxt N/A N/A N/A


Start Wake-up on Change Mode SW 2 0010 zyxt N/A N/A N/A


Start Single Measurement Mode SM 3 0011 zyxt N/A N/A N/A


Read Measurement RM 4 0100 zyxt N/A N/A N/A


Read Register RR 5 0101 0abc {A5…A0,0,0} N/A N/A


Write Register WR 6 0110 0abc D15…D8 D7…D0 {A5…A0,0,0}


Exit Mode EX 8 1000 0000 N/A N/A N/A


Memory Recall HR D 1101 0000 N/A N/A N/A


Memory Store HS E 1110 0000 N/A N/A N/A


Reset RT F 1111 0000 N/A N/A N/A


_Table 11: Command List_


The argument for the volatile memory access commands (RR/WR) «abc» should be set to 0x0, in order to get
normal read-out and write of the memory.



REVISION 011 – SEP 24, 2024

3901090393



Page 20 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


The argument in all mode-starting commands (SB/SW/SM) is a nibble specifying the conversions to be
performed by the sensor in the following order «zyxt». For example, if only Y axis and temperature are to be
measured in Single Measurement mode the correct command to be transmitted is 0x35. The sequence of
measurement execution on-chip is inverted to «TXYZ», so T will be measured before X, followed by Y and
finally Z. By issuing an all-zero «zyxt» nibble, the BURST_SEL value from RAM will be used instead of the empty
argument of the command.

### 15.2. Status Byte


The status byte is the first byte transmitted by the MLX90393 in response to a command issued by the master.
It is composed of a fixed combination of informative bits:


_Table 12: Status Byte Definition_


  - MODE bits


These bits define in which mode the MLX90393 is currently set. Whenever a mode transition
command is rejected, the first status byte after this command will have the expected mode bit
cleared, which serves as an indication that the command has been rejected, next to the ERROR bit.
The SM_MODE flag can be the result of an SM command or from raising the TRG pin when TRG mode
is enabled in the volatile memory of the MLX90393.


  - ERROR bit


This bit is set in case a command has been rejected or in case an uncorrectable error is detected in
the memory, a so called ECC_ERROR. A single error in the memory can be corrected (see SED bit),
two errors can be detected and will generate the ECC_ERROR. In such a case all commands but the
RT (Reset) command are not allowed. For example, a RR/WR command is not allowed during burst
mode, resulting in the ERROR bit being set yet the command is not actively rejected. The error bit is
equally set when the master is reading back data while the DRDY flag is low.


  - SED bit


The single error detection bit simply flags that a bit error in the non-volatile memory has been
corrected. It is purely informative and has no impact on the operation of the MLX90393.


  - RS bit


Whenever the RT command is issued, the status message indicates that the RT is going to be
performed by setting this bit. Then the bit is cleared again during the reset.


  - D[1:0] bits


These bits only have a meaning after the RR and RM commands, when data is expected as a response
from the MLX90393. The number of response bytes correspond to 2*D[1:0] + 2, so the expected byte
counts are either 2, 4, 6 or 8. For commands where no response is expected, the content of D[1:0]
should be ignored.

### 15.3. SPI Communication


The MLX90393 can handle SPI communication at a bitrate of 10Mhz. The SPI communication is implemented
in a half-duplex way, showing high similarities with I [2] C communication, but addressing through the \CS (Chip
Select) pin instead of through bus arbitration. The half-duplex nature is at the basis of the supported 3-wire



REVISION 011 – SEP 24, 2024

3901090393



Page 21 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


SPI operation. SPI mode 3 is implemented: CPHA=1 (data changed on leading edge and captured on trailing
edge, and CPOL=1 (high level is inactive state). The Chip Select line is active-low.


The communication is also bundled in bytes, equally MSB first and MSByte first. A command can of course
consist of more than 1 byte (refer to Table 10: Communication mode definition) as can the response be from
the MLX90393 in the form of multiple bytes after the status byte (not shown in Figure 5: SPI communication
example)


/CS



SCL


MOSI


MISO








|Col1|Col2|Col3|Col4|Col5|
|---|---|---|---|---|
||||||
|||COMMAND[7:0]<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>STATUS_BYTE[7:0]<br>X (4-wire SPI) or Z (3-wire SPI)<br>Z (3 & 4-wire SPI)<br>|COMMAND[7:0]<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>STATUS_BYTE[7:0]<br>X (4-wire SPI) or Z (3-wire SPI)<br>Z (3 & 4-wire SPI)<br>|COMMAND[7:0]<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>STATUS_BYTE[7:0]<br>X (4-wire SPI) or Z (3-wire SPI)<br>Z (3 & 4-wire SPI)<br>|
||||||
||||||
||||||



ADD NADD


_Figure 5: SPI communication example_

### 15.3.1. Command implementation


For the examples give, the below convention is used.



xxx


xxx



MOSI data (1 byte)


MISO data (1 byte)


_Figure 6: SPI convention_



15.3.1.1. SB, SWOC, SM, EX, HR, HS


All the commands follow the structure below. The reply from the MLX90393 is only the status byte. The
example below is for a start of a burst mode with X and Y being measured.


_Figure 7: SB command, XY_


After the HS command, wait at least 15ms before sending the next command to allow the IC to update the
NVRAM correctly.



REVISION 011 – SEP 24, 2024

3901090393



Page 22 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


15.3.1.2. RT


This command will (warm-)reset the IC. The status byte of the command following will indicate the reset event.
It is recommended to perform an ‘EX’ command and to wait 1ms, before issuing a ‘RT’ command. After the RT
command, it is recommended to wait 1.5ms for the start-up sequence to complete.











_Figure 8: RT command_


15.3.1.3. RM


This command differs depending on the value for zyxt. The data is returned in the order Status-TXYZ, where
the components which are set to zero are skipped.























_Figure 9: RM command, XYZT_













_Figure 10: RM command, YT_



15.3.1.4. RR


Important in this command is that the register address to be read needs to be shifter left by two bits. To read
register 0x12 for example, the MOSI byte becomes 0x48.





_Figure 11: RR command_





15.3.1.5. WR


Important in this command is that the register address to be read needs to be shifter left by two bits. To read
register 0x12 for example, the MOSI byte becomes 0x48.











_Figure 12: WR command_



REVISION 011 – SEP 24, 2024

3901090393



Page 23 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 15.3.2. SPI Timing Specification


All timings are referred to the levels found in Table 6: General Electrical Specifications.


_Table 13: General SPI Timing Specification_









_Figure 13: SPI Timing Diagram_

### 15.4. I [2] C Communication


The I [2] C protocol is implemented such that the command is written to a specific register in the RAM, and the

status and measurement data are read back from this RAM. The commands themselves are the same as for

SPI (section 15.3) except for the read measurement commands and the memory read/write commands. For
memory read/write commands, written can be done directly to the required register. Note that memory
read/write commands are required to be word-wise, so always in multiples of 2 bytes. Read measurement is
the same as a memory read, except starting from the status register. MSbits are sent first.


The 7-bit I [2] C-address is determined by the connection to the A0 and A1 pins. The 5 MSBs are programmed by
Melexis in the MLX90393. Please contact Melexis in case other addressing is required.



REVISION 011 – SEP 24, 2024

3901090393



Page 24 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet



0 if A1 shorted to ground
0 0 0 1 1

1 if A1 shorted to supply



0 if A0 shorted to ground

1 if A0 shorted to supply



0 for I [2] C write


1 for I [2] C read



MLX90393xLW-ABA-012-RE 0x04 0x10, 0x11, 0x12, 0x13


MLX90393xLW-ABA-013-RE 0x05 0x14, 0x15, 0x16, 0x17


MLX90393xLW-ABA-014-RE 0x06 0x18, 0x19, 0x1A, 0x1B


MLX90393xLQ-ABA-011-RE 0x04 0x10


_Table 14: I_ _[2]_ _C address ordering codes_

### 15.4.1. Command Implementation


For the examples given, the below convention is used.















I2C Start


I2C Repeated Start


I2C Stop


Acknowledge from IC (1 bit)


(Not) Acknowledge from Master (1 bit)


I2C Addressing (1 byte)


Data from Master to IC (1 byte)







xxx Data from IC to Master (1 byte)


_Figure 14: I_ _[2]_ _C Convention_


15.4.1.1. SB, SWOC, SM, EX, HR, HS


All the commands follow the structure below. The reply from the MLX90393 is only the status byte. The
example below is for a start of a burst mode with X and Y being measured.


S I2C addr [W] A 0x16 A SR I2C addr [R] A Status NACK P


_Figure 15: SB command, XY_


After the HS command, wait at least 15ms before sending the next command to allow the IC to update the
NVRAM correctly.



REVISION 011 – SEP 24, 2024

3901090393



Page 25 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


15.4.1.2. RT


This command will (warm-)reset the IC. The status byte of the command following will indicate the reset event.
It is recommended to perform an ‘EX’ command and to wait 1ms, before issuing a ‘RT’ command. After the RT
command, it is recommended to wait 1.5ms for the start-up sequence to complete.


S I2C addr [W] A 0x80 A SR I2C addr [R] A Status NACK P


_Figure 16: RT command_


15.4.1.3. RM


This command differs depending on the value for zyxt. The data is returned in the order Status-TXYZ, where
the components which are set to zero are skipped.


S I2C addr [W] A 0x4F A SR I2C addr [R] A Status A T [15:8] A T [7:0] A



X [15:8] A X [7:0] A Y [15:8] A Y [7:0] A Z [15:8] A Z [7:0]


_Figure 17: RM command-XYZT_



NACK P



S I2C addr [W] A 0x45 A SR I2C addr [R] A Status A T [15:8] A T [7:0] A



15.4.1.4. RR





_Figure 18: RM command-YT_



Important in this command is that the register address to be read needs to be shifted left by two bits. To read
register 0x12 for example, the SDA byte becomes 0x48.


S I2C addr [W] A 0x50 A Register << 2 A SR I2C addr [R] A Status A Data [15:8] A Data [7:0] NACK P


_Figure 19: RR command_


15.4.1.5. WR


Important in this command is that the register address to be read needs to be shifted left by two bits. To read
register 0x12 for example, the SDA byte becomes 0x48.


S I2C addr [W] A 0x60 A Data [15:8] A Data [7:0] A Register << 2 A SR I2C addr [R] A Status NACK P


_Figure 20: WR command_



REVISION 011 – SEP 24, 2024

3901090393



Page 26 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 15.4.2. I [2] C Timing Specification


All timings are referred to the levels found in Table 6: General Electrical Specifications.


_Table 15: General I_ _[2]_ _C Timing Specification_

















_Figure 21: I_ _[2]_ _C Timing Diagram_


_10_ _Where C_ _b_ _is the total bus capacitance (in pF)_


REVISION 011 – SEP 24, 2024

3901090393



Page 27 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **16. Memory Map**

### 16.1. General Description


The MLX90393 has 1kbit of non-volatile memory, and the same amount of volatile memory. Each memory
consists out of 64 addresses containing 16 bit words. The non-volatile memory has automatic 2-bit error
detection and 1-bit error correction capabilities per address. The handling of such corrections & detections is
explained in Section 15.2.


The memory is split in 2 areas:


  - Customer area [address 0x00 to 0x1F]


  - Melexis area [address 0x20 to 0x3F]


The RR and WR commands impact the volatile memory only, there no direct access possible to the non-volatile
memory. The customer area of the volatile memory is bidirectionally accessible to the customer; the Melexis
area is write-protected. Only modifications in the blue area are allowed with the WR command. The
adjustments in the customer area can be stored in the permanent non-volatile memory with the STORE
command HS, which copies the entire volatile memory including the Melexis area to the non-volatile one.
With the HR command the non-volatile memory content can be recalled to the volatile memory, which can
restore any modifications due to prior WR commands. The HR step is performed automatically at start-up of
the ASIC, either through cold reset or warm reset with the RT command.


The above is graphically shown in Figure 22.



VOLATILE


MEMORY



NON-VOLATILE


MEMORY



CUSTOMER AREA CUSTOMER AREA


STORE (HS)


RECALL (HR)

MELEXIS AREA MELEXIS AREA


RR WR


_Figure 22: The memories of the MLX90393, their areas and the impacting commands._


The customer area houses 3 types of data:


  - Analog configuration bits


  - Digital configuration bits


  - Informative (free) bits


REVISION 011 – SEP 24, 2024

3901090393



Page 28 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet


The latter can be filled with customer content freely, and covers the address span from (and including) 0x0A
to 0x1F, a total of 352 bits. The memory mapping of volatile and non-volatile memory on address level is
identical. The volatile memory map is given in Figure 23.


The table below gives an overview of the customer area in the MLX90393’s NVRAM.


In the register map, the 16-bit words are split into 2 bytes for the sake of readability. The general format is
shown below in the yellow table.


|Register Bit 7 Bit 6 Bit 5 Bit 4 Bit 3 Bit 2 Bit 1 Bit 0|Col2|Col3|Col4|Col5|Col6|Col7|Col8|Col9|
|---|---|---|---|---|---|---|---|---|
|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|
|0x..<br>Bit 7<br>Bit 6<br>Bit 5<br>Bit 4<br>Bit 3<br>Bit 2<br>Bit 1<br>Bit 0 (LSB)<br>Bit 15(MSB)<br>Bit 14<br>Bit 13<br>Bit 12<br>Bit 11<br>Bit 10<br>Bit 9<br>Bit 8|Bit 15(MSB)|Bit 14|Bit 13|Bit 12|Bit 11|Bit 10|Bit 9|Bit 8|

















|0x09h 0x0Ah …|WOT_THRESHOLD WOT_THRESHOLD FREE|Col3|
|---|---|---|
|0x1Fh|||
|_Figure 23: Customer area memory map._|_Figure 23: Customer area memory map._|_Figure 23: Customer area memory map._|


The non-volatile memory can only be written (HS store command) if pin VDD is supplied with 3.3V minimum,
otherwise the write sequence cannot be performed in a reliable way. Additionally, this HS command was
designed to be used as one-time calibration, but not as multi write-cycle memory within the application. In
case memory is written within the application, the number of write cycles should be kept to a minimum. There
is no limit to the write cycles in the volatile memory (WR write command).



REVISION 011 – SEP 24, 2024

3901090393



Page 29 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 16.2. Parameter Description


The meaning of each customer accessible parameter is explained in this section. The customer area of both
the volatile and the non-volatile memory can be written through standard SPI and I [2] C communication, within
the application. No external high-voltages are needed to perform such operations, nor access to dedicated
pins that need to be grounded in the application. Note that the default settings are “illegal” in the filter
settings.


BIST Enabled the on-chip coil, applying a Z-field [Built-In Self Test] 0x0


Z_SERIES Enable all plates for Z-measurement 0x0


GAIN_SEL[2:0] Analog chain gain setting, factor 5 between min and max code 0x7


HALLCONF[3:0] Hall plate spinning rate adjustment 0xC


TRIG_INT_SEL Puts TRIG_INT pin in TRIG mode when cleared, INT mode otherwise 0x0


COMM_MODE[1:0] Allow only SPI [10b], only I [2] C [11b] or both [0Xb] according to CS pin 0x0


WOC_DIFF Sets the Wake-up On Change based on Δ{sample(t),sample(t-1)} 0x0


EXT_TRIG Allows external trigger inputs when set, if TRIG_INT_SEL = 0 0x0


TCMP_EN Enables on-chip sensitivity drift compensation 0x0


BURST_SEL[3:0] Defines the MDATA in burst mode if SB command argument = 0 0x0


BURST_DATARATE[6:0] Defines T INTERVAL as BURST_DATA_RATE * 20ms 0x00


OSR2[1:0] Temperature sensor ADC oversampling ratio 0x0


RES_XYZ[5:0] Selects the desired 16-bit output value from the 19-bit ADC 0x00


DIG_FILT[1:0] Digital filter applicable to ADC 0x0


OSR[1:0] Magnetic sensor ADC oversampling ratio 0x0


SENS_TC_HT[7:0] Sensitivity drift compensation factor for T < T REF Trimmed


SENS_TC_LT[7:0] Sensitivity drift compensation factor for T > T REF Trimmed


OFFSET_i[15:0] Constant offset correction, independent for i = X, Y, Z 0x0000


|Col1|WOi_THRESHOLD[15:0]|Wake-up On Change threshold, independent for i = X, Y, Z and T|0x0000|Col5|
|---|---|---|---|---|
|_Table 16: NVRAM parameter description_|_Table 16: NVRAM parameter description_|_Table 16: NVRAM parameter description_|_Table 16: NVRAM parameter description_|_Table 16: NVRAM parameter description_|



REVISION 011 – SEP 24, 2024

3901090393



Page 30 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 16.2.1. ANA_RESERVED_LOW


Reserved bits for analog trimming at Melexis factory. Do not modify.

### 16.2.2. BIST


Enables (1) or disables (0) the built in self-test coil. In normal operation set to 0. A measurement with this coil
enabled shows a change in magnetic field sensed on the Z-axis.

### 16.2.3. Z_Series


Enables series connection of hall plates for Z axis measurement. In normal operation set to 0.



REVISION 011 – SEP 24, 2024

3901090393



Page 31 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 16.2.4. GAIN_SEL[2:0]


Sets the analog gain to the desired value. The sensitivity is dependent on the axis (the X- and Y-axis have higher
sensitivity, compared with the Z-axis, expressed in LSB/µT) as well as the setting of the RES_XYZ[5:0]
parameter. The relationship is given in the below table.


Table for HALLCONF [(11)] = 0xC, sensitivity in µT/LSB, TC off, T=25°C:

|RES = 0 RES = 1 RES = 2 RES = 3<br>GAIN_SEL<br>SENS SENS SENS SENS SENS SENS SENS SENS<br>XY Z XY Z XY Z XY Z<br>0 0.751 1.210 1.502 2.420 3.004 4.840 6.009 9.680<br>1 0.601 0.968 1.202 1.936 2.403 3.872 4.840 7.744<br>2 0.451 0.726 0.901 1.452 1.803 2.904 3.605 5.808<br>3 0.376 0.605 0.751 1.210 1.502 2.420 3.004 4.840<br>4 0.300 0.484 0.601 0.968 1.202 1.936 2.403 3.872<br>5 0.250 0.403 0.501 0.807 1.001 1.613 2.003 3.227<br>6 0.200 0.323 0.401 0.645 0.801 1.291 1.602 2.581<br>7 0.150 0.242 0.300 0.484 0.601 0.968 1.202 1.936|Col2|Col3|Col4|Col5|Col6|Col7|Col8|Col9|Col10|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
|**GAIN_SEL**<br>**RES = 0**<br>**RES = 1**<br>**RES = 2**<br>**RES = 3**<br>SENSXY <br>SENSZ <br>SENSXY <br>SENSZ <br>SENSXY <br>SENSZ <br>SENSXY <br>SENSZ <br>0 <br>0.751<br>1.210<br>1.502<br>2.420<br>3.004<br>4.840<br>6.009<br>9.680<br>1 <br>0.601<br>0.968<br>1.202<br>1.936<br>2.403<br>3.872<br>4.840<br>7.744<br>2 <br>0.451<br>0.726<br>0.901<br>1.452<br>1.803<br>2.904<br>3.605<br>5.808<br>3 <br>0.376<br>0.605<br>0.751<br>1.210<br>1.502<br>2.420<br>3.004<br>4.840<br>4 <br>0.300<br>0.484<br>0.601<br>0.968<br>1.202<br>1.936<br>2.403<br>3.872<br>5 <br>0.250<br>0.403<br>0.501<br>0.807<br>1.001<br>1.613<br>2.003<br>3.227<br>6 <br>0.200<br>0.323<br>0.401<br>0.645<br>0.801<br>1.291<br>1.602<br>2.581<br>7 <br>0.150<br>0.242<br>0.300<br>0.484<br>0.601<br>0.968<br>1.202<br>1.936|7|0.150|0.242|0.300|0.484|0.601|0.968|1.202|1.936|1.936|
|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|



Table for HALLCONF [(11)] = 0xC, sensitivity in µT/LSB, TC off, T=35°C:

|RES = 0 RES = 1 RES = 2 RES = 3<br>GAIN_SEL<br>SENS SENS SENS SENS SENS SENS SENS SENS<br>XY Z XY Z XY Z XY Z<br>0 0.787 1.267 1.573 2.534 3.146 5.068 6.292 10.137<br>1 0.629 1.014 1.258 2.027 2.517 4.055 5.034 8.109<br>2 0.472 0.760 0.944 1.521 1.888 3.041 3.775 6.082<br>3 0.393 0.634 0.787 1.267 1.573 2.534 3.146 5.068<br>4 0.315 0.507 0.629 1.014 1.258 2.027 2.517 4.055<br>5 0.262 0.422 0.524 0.845 1.049 1.689 2.097 3.379<br>6 0.210 0.338 0.419 0.676 0.839 1.352 1.678 2.703<br>7 0.157 0.253 0.315 0.507 0.629 1.014 1.258 2.027|Col2|Col3|Col4|Col5|Col6|Col7|Col8|Col9|Col10|Col11|
|---|---|---|---|---|---|---|---|---|---|---|
|**GAIN_SEL**<br>**RES = 0**<br>**RES = 1**<br>**RES = 2**<br>**RES = 3**<br>SENSXY <br>SENSZ <br>SENSXY <br>SENSZ <br>SENSXY <br>SENSZ <br>SENSXY <br>SENSZ <br>0 <br>0.787 <br>1.267 <br>1.573 <br>2.534 <br>3.146 <br>5.068 <br>6.292 <br>10.137 <br>1 <br>0.629 <br>1.014 <br>1.258 <br>2.027 <br>2.517 <br>4.055 <br>5.034 <br>8.109 <br>2 <br>0.472 <br>0.760 <br>0.944 <br>1.521 <br>1.888 <br>3.041 <br>3.775 <br>6.082 <br>3 <br>0.393 <br>0.634 <br>0.787 <br>1.267 <br>1.573 <br>2.534 <br>3.146 <br>5.068 <br>4 <br>0.315 <br>0.507 <br>0.629 <br>1.014 <br>1.258 <br>2.027 <br>2.517 <br>4.055 <br>5 <br>0.262 <br>0.422 <br>0.524 <br>0.845 <br>1.049 <br>1.689 <br>2.097 <br>3.379 <br>6 <br>0.210 <br>0.338 <br>0.419 <br>0.676 <br>0.839 <br>1.352 <br>1.678 <br>2.703 <br>7 <br>0.157 <br>0.253 <br>0.315 <br>0.507 <br>0.629 <br>1.014 <br>1.258 <br>2.027|7|0.157|0.253|0.315|0.507|0.629|1.014|1.258|2.027|2.027|
|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|_Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC_|



_11_ _For HALLCONF = 0x0, the sensitivity scales with a factor 98/75. For example (0.150µT/LSB with HALLCONF 0xC_

_becomes 0.196µT/LSB with HALLCONF 0x0)_



REVISION 011 – SEP 24, 2024

3901090393



Page 32 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 16.2.5. HALLCONF[3:0]


Modifies the hall plate spinning (2-phase vs 4-phase) which has an effect on the minimum sampling rate
achievable. Some configurations of OSR and DIG_FILT are not permitted. The cells shown in red are not
permitted with HALL_CONF=0xC (default) but are allowed when HALL_CONF=0x0.








|Typical T (TXYZ) OSR<br>CONV<br>for OSR =0x0 [ms] 0 1 2 3<br>2<br>0 1.27 1.84 3.00 5.30<br>1 1.46 2.23 3.76 6.84<br>2 1.84 3.00 5.30 9.91<br>DIG_FILT<br>3 2.61 4.53 8.37 16.05<br>4 4.15 7.60 14.52 28.34<br>5 7.22 13.75 26.80 52.92<br>6 13.36 26.04 51.38 102.07<br>7 25.65 50.61 100.53 200.37|Col2|Col3|Col4|Col5|Col6|Col7|
|---|---|---|---|---|---|---|
|**Typical** TCONV(TXYZ)<br>for OSR2=0x0 [ms] <br>OSR <br>0 <br>1 <br>2 <br>3 <br>DIG_FILT <br>0 <br>1.27<br>1.84<br>3.00<br>5.30<br>1 <br>1.46 <br>2.23<br>3.76<br>6.84<br>2 <br>1.84<br>3.00<br>5.30<br>9.91<br>3 <br>2.61<br>4.53<br>8.37<br>16.05<br>4 <br>4.15<br>7.60<br>14.52<br>28.34<br>5 <br>7.22<br>13.75<br>26.80<br>52.92<br>6 <br>13.36<br>26.04<br>51.38<br>102.07<br>7 <br>25.65<br>50.61<br>100.53<br>200.37|7|25.65|50.61|100.53|200.37|200.37|
|_Table 19: TCONV as a function of OSR & DIG_FILT_|_Table 19: TCONV as a function of OSR & DIG_FILT_|_Table 19: TCONV as a function of OSR & DIG_FILT_|_Table 19: TCONV as a function of OSR & DIG_FILT_|_Table 19: TCONV as a function of OSR & DIG_FILT_|_Table 19: TCONV as a function of OSR & DIG_FILT_|_Table 19: TCONV as a function of OSR & DIG_FILT_|







|Maximum ODR OSR<br>for OSR =0x0 [Hz] 0 1 2 3<br>2<br>0 716.9 493.0 303.4 171.5<br>1 622.7 408.0 241.5 133.0<br>2 493.0 303.4 171.5 91.8<br>DIG_FILT<br>3 348.0 200.6 108.6 56.6<br>4 219.2 119.6 62.6 32.1<br>5 125.9 66.1 33.9 17.2<br>6 68.0 34.9 17.7 8.9<br>7 35.4 18.0 9.0 4.5|Col2|Col3|Col4|Col5|Col6|Col7|
|---|---|---|---|---|---|---|
|**Maximum** ODR<br>for OSR2=0x0 [Hz]<br>OSR <br>0 <br>1 <br>2 <br>3 <br>DIG_FILT<br>0 <br>716.9<br>493.0<br>303.4<br>171.5<br>1 <br>622.7<br>408.0<br>241.5<br>133.0<br>2 <br>493.0<br>303.4<br>171.5<br>91.8<br>3 <br>348.0<br>200.6<br>108.6<br>56.6<br>4 <br>219.2<br>119.6<br>62.6<br>32.1<br>5 <br>125.9<br>66.1<br>33.9<br>17.2<br>6 <br>68.0<br>34.9<br>17.7<br>8.9<br>7 <br>35.4<br>18.0<br>9.0<br>4.5|7|35.4|18.0|9.0|4.5|4.5|
|_Table 20: Maximum Output Data Rate (ODR) as a function of OSR & DIG_FILT_|_Table 20: Maximum Output Data Rate (ODR) as a function of OSR & DIG_FILT_|_Table 20: Maximum Output Data Rate (ODR) as a function of OSR & DIG_FILT_|_Table 20: Maximum Output Data Rate (ODR) as a function of OSR & DIG_FILT_|_Table 20: Maximum Output Data Rate (ODR) as a function of OSR & DIG_FILT_|_Table 20: Maximum Output Data Rate (ODR) as a function of OSR & DIG_FILT_|_Table 20: Maximum Output Data Rate (ODR) as a function of OSR & DIG_FILT_|

### 16.2.6. TRIG_INT_SEL

When set to 0 the TRIG_INT pin is in trigger mode. When set to 1 the TRIG_INT pin acts as an interrupt pin.

### 16.2.7. COMM_MODE[1:0]


When set to 0x2 only SPI communication is allowed. When set to 0x3 only I [2] C communication is allowed. When
set to 0x0 or 0x1 both communication modes can be used but the selection is made by the CS pin.

### 16.2.8. WOC_DIFF


When wake-on-change mode is enabled this parameter defines the mode to use. When enabled, a comparison
on the current measurement is made with the previous measurement. When disabled, the first initial
measurement is used as a reference.



REVISION 011 – SEP 24, 2024

3901090393



Page 33 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 16.2.9. EXT_TRIG


Allows for external trigger events when set to 1 and TRIG_INT_SEL = 0. When enabled an acquisition will start
with the external trigger pin detects a high value. Acquisitions will continue to be triggered until the EXT_TRIG
pin is brought low.

### 16.2.10. TCMP_EN


Enables (1) or disables (0) the on-chip sensitivity drift compensation. Enabling the temperature compensation
will influence the way the magnetic values are encoded and transmitted to the system microcontroller as

shown in the table below.










|TCMP_EN = 0x0 TCMP_EN = 0x1<br>ABA<br>RANGE TYPE RANGE TYPE<br>2’s complement unsigned<br>0 ±215 ±215<br>0µT = 0LSB 0µT = 215LSB<br>2’s complement unsigned<br>1 ±215 ±215<br>0µT = 0LSB 0µT = 215LSB RES i<br>unsigned<br>2 ±22000<br>0µT = 215LSB<br>N/A<br>unsigned<br>3 ±11000<br>0µT = 214LSB|Col2|
|---|---|
|_Table 21: Output Range and Type as a function of TCMP_EN and RES_XYZ={RESX,RESY,RESZ} _|_Table 21: Output Range and Type as a function of TCMP_EN and RES_XYZ={RESX,RESY,RESZ} _|


### 16.2.11. BURST_SEL[3:0]

Defines the axes that will be converted in burst mode if the SB command argument is 0.

### 16.2.12. OSR2[1:0]


Selects the temperature sensor ADC oversampling ratio

### 16.2.13. RES_XYZ[5:0]


See 16.2.4 for the relationship between the gain and resolution. Additionally, section 16.2.10 for the
relationship between RES_XYZ and the output data format.

### 16.2.14. DIG_FILT[1:0]


See 16.2.5 for the selection of DIG_FILT and the impact on conversion time.

### 16.2.15. OSR[1:0]


Oversampling ratio for the magnetic measurements. See 16.2.5 for the selection of OSR

### 16.2.16. SENS_TC_HT[7:0]


Sensitivity drift compensation factor for T > T REF

### 16.2.17. SENS_TC_LT[7:0]


Sensitivity drift compensation factor for T < T REF



REVISION 011 – SEP 24, 2024

3901090393



Page 34 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 16.2.18. OFFSET_i[15:0]


Constant offset correction, independent of temperature, and programmable for each individual axis where
i=X, Y, or Z.

### 16.2.19. WOi_THRESHOLD[15:0]


Wake-on-change threshold. Independently programmable for each magnetic axis (i=X, Y, Z) and temperature
(i=T)



REVISION 011 – SEP 24, 2024

3901090393



Page 35 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **17. Recommended Application Diagram**

### 1.1 I [2] C


**A1** **A0    I2C Address**

------------------------------------
Vss  Vss   00011 **00** _R/W_

Vss  Vdd   00011 **01** _R/W_

Vdd  Vss   00011 **10** _R/W_

Vdd  Vdd   00011 **11** _R/W_



VDDIO





R1=R2=10K

C1=C2=0.1uF


|R1<br>SDA/MOSI|Col2|Col3|C2|Col5|
|---|---|---|---|---|
|~~**SCL**/SCLK~~<br>R2|~~**SCL**/SCLK~~<br>R2|~~**SCL**/SCLK~~<br>R2|||









|MLX90393|Col2|I2C<br>MCU<br>Trigger<br>Interrupt/DRDY|
|---|---|---|
|MLX90393|~~INT~~<br>|~~INT~~<br>|
|MLX90393|||


_Figure 24: I_ _[2]_ _C recommended schematic_


### 1.2 SPI

|MLX90393|Col2|SPI<br>MCU<br>Trigger<br>Interrupt/DRDY|
|---|---|---|
|MLX90393|~~INT~~<br>|~~INT~~<br>|
|MLX90393|||



REVISION 011 – SEP 24, 2024

3901090393





VDDIO





C1=C2=0.1uF


|VDDIO|Col2|Col3|
|---|---|---|
|C2<br>~~MISO~~|C2<br>~~MISO~~|C2<br>~~MISO~~|
|~~SDA/~~~~**MOSI**~~<br>|||
|~~SCL/~~~~**SCLK**~~|~~SCL/~~~~**SCLK**~~||
|~~**MS/CS**~~|~~**MS/CS**~~||









_Figure 25: 3/4wire SPI recommended schematic_





Page 36 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **18. Packaging Specification**

### 18.1. QFN-16


The MLX90393 shall be delivered in a QFN-16 package as shown below in Figure 26.

### 18.1.1. Package dimensions and sensitive spot location


_Figure 26: QFN-16 - Package Outline Drawing_

The sensing elements – Hall plates with the patented IMC technology – are located in the center of the die, which on its turn
is located in the center of the package.



REVISION 011 – SEP 24, 2024

3901090393



Page 37 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 18.1.2. QFN-16 - Pinout and Marking



































_Figure 27: QFN-16 Pinout and Marking – Top view_



REVISION 011 – SEP 24, 2024

3901090393



Page 38 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 18.2. UDTFN-8 package


The MLX90393 shall be delivered in a UTDFN-8 package as shown below in Figure 28:

### 18.2.1. Package dimensions and sensitive spot location



_Figure 28: UTDFN-8 - Package Outline Drawing_



REVISION 011 – SEP 24, 2024

3901090393



Page 39 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

### 18.2.2. UTDFN-8 - Pinout and Marking


_Figure 29: UTDFN-8 – Pinout and Marking (-011 version)_


_Figure 30: UTDFN-8 – Pinout and Marking (-014 version)_


REVISION 011 – SEP 24, 2024

3901090393



Page 40 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **19. Standard Information**


Our products are classified and qualified regarding soldering technology, solderability and moisture sensitivity level
according to standards in place in Semiconductor industry.


For further details about test method references and for compliance verification of selected soldering method for
product integration, Melexis recommends reviewing on our web site the General Guidelines soldering recommendation.
For all soldering technologies deviating from the one mentioned in above document (regarding peak temperature,
temperature gradient, temperature profile, etc.), additional classification and qualification tests have to be agreed upon

with Melexis.


For package technology embedding trim and form post-delivery capability, Melexis recommends to consult the dedicated
trim & form recommendation application note: lead trimming and forming recommendations


Melexis is contributing to global environmental conservation by promoting **lead free** solutions. For more information on
qualifications of **RoHS** compliant products (RoHS = European directive on the Restriction Of the use of certain Hazardous
Substances) please visit the quality page on our website: http://www.melexis.com/en/quality-environment

## **20. ESD Precautions**


Electronic semiconductor products are sensitive to Electro Static Discharge (ESD).
Always observe Electro Static Discharge control procedures whenever handling semiconductor products.



REVISION 011 – SEP 24, 2024

3901090393



Page 41 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **21. Revision History**


16-Feb-2015 002  - Changed Ordering Code to indicate QFN wettable flanks

               - Update Document number

               - Added description of yellow cells in Table 1 and Table 2.





28-May-2019 004 - UTDFN-8 Package / Pinout/ Marking

              - Updated sensitivity tables

              - Additional Communication commands details

              - Functional flowchart updated

              - Timings and current consumption updated





14-Jan-2021 007 - RR + WR in I2C: typo (one bit->two bits)

              - Sensitivity chapter: footer, and footnote corrected; uT to µT.

Added note that sensitivity increase is in LSB/µT.

              - RM commands: wrong explanation

              - RES_XYZ[5:0] and DIG_FILT[1:0]: corrected cross references

              - OSR[1:0]: link to HALLCONF added

              - I2C timing diagram

              - I2C address of UTDFN (was 0001100, now 0010000), in both

option codes and table (I2C chapter)

              - BIST: some more explanation







18-Jan-2023


REVISION 011 – SEP 24, 2024

3901090393



009 - Added version SLQ ABA-014

     - UTDFN package marking update

     - Correct temperature range in SLW ABA-111



Page 42 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet









24-Sep-2024 011 - Added timing specification on INT pin


REVISION 011 – SEP 24, 2024

3901090393



Page 43 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **22. Contact**


For the latest version of this document visit www.melexis.com/MLX90393

For additional information, www.melexis.com/contact


REVISION 011 – SEP 24, 2024

3901090393



Page 44 of 45


**MLX90393**


Triaxis® Magnetic Node

Datasheet

## **23. Disclaimer**


_The content of this document is believed to be correct and accurate. However, the content of this document is furnished "as is" for_
_informational use only and no representation, nor warranty is provided by Melexis about its accuracy, nor about the results of its_
_implementation. Melexis assumes no responsibility or liability for any errors or inaccuracies that may appear in this document. Customer will_
_follow the practices contained in this document under its sole responsibility. This documentation is in fact provided without warranty, term,_
_or condition of any kind, either implied or expressed, including but not limited to warranties of merchantability, satisfactory quality, non-_
_infringement, and fitness for purpose. Melexis, its employees and agents and its affiliates' and their employees and agents will not be_
_responsible for any loss, however arising, from the use of, or reliance on this document. Notwithstanding the foregoing, contractual_
_obligations expressly undertaken in writing by Melexis prevail over this disclaimer._

_This document is subject to change without notice, and should not be construed as a commitment by Melexis. Therefore, before placing_
_orders or prior to designing the product into a system, users or any third party should obtain the latest version of the relevant information._
_Users or any third party must determine the suitability of the product described in this document for its application, including the level of_
_reliability required and determine whether it is fit for a particular purpose._

_This document as well as the product here described may be subject to export control regulations. Be aware that export might require a prior_
_authorization from competent authorities. The product is not designed, authorized or warranted to be suitable in applications requiring_
_extended temperature range and/or unusual environmental requirements. High reliability applications, such as medical life-support or life-_
_sustaining equipment or avionics application are specifically excluded by Melexis. The product may not be used for the following applications_
_subject to export control regulations: the development, production, processing, operation, maintenance, storage, recognition or proliferation_
_of:_


_1. chemical, biological or nuclear weapons, or for the development, production, maintenance or storage of missiles for such_

_weapons;_

_2. civil firearms, including spare parts or ammunition for such arms;_

_3. defense related products, or other material for military use or for law enforcement;_

_4. any applications that, alone or in combination with other goods, substances or organisms could cause serious harm to_

_persons or goods and that can be used as a means of violence in an armed conflict or any similar violent situation._

_No license nor any other right or interest is granted to any of Melexis' or third party's intellectual property rights._

_If this document is marked “restricted” or with similar words, or if in any case the content of this document is to be reasonably_

_understood as being confidential, the recipient of this document shall not communicate, nor disclose to any third party, any part of_

_the document without Melexis’ express written consent. The recipient shall take all necessary measures to apply and preserve the_

_confidential character of the document. In particular, the recipient shall (i) hold document in confidence with at least the same degree_

_of care by which it maintains the confidentiality of its own proprietary and confidential information, but no less than reasonable care;_

_(ii) restrict the disclosure of the document solely to its employees for the purpose for which this document was received, on a strictly_

_need to know basis and providing that such persons to whom the document is disclosed are bound by confidentiality terms_

_substantially similar to those in this disclaimer; (iii) use the document only in connection with the purpose for which this document_

_was received, and reproduce document only to the extent necessary for such purposes; (iv) not use the document for commercial_

_purposes or to the detriment of Melexis or its customers. The confidentiality obligations set forth in this disclaimer will have indefinite_

_duration and in any case they will be effective for no less than 10 years from the receipt of this document._

_This disclaimer will be governed by and construed in accordance with Belgian law and any disputes relating to this disclaimer will be_

_subject to the exclusive jurisdiction of the courts of Brussels, Belgium._

_The invalidity or ineffectiveness of any of the provisions of this disclaimer does not affect the validity or effectiveness of the other_

_provisions._

_The previous versions of this document are repealed._

_Melexis © - No part of this document may be reproduced without the prior written consent of Melexis. (2024)_

_IATF 16949 and ISO 14001 Certified_



REVISION 011 – SEP 24, 2024

3901090393



Page 45 of 45


