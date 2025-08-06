MLX90393
Triaxis® Magnetic Node
Datasheet

1. Features and Benefits

3. Description

The MLX90393  brings the highest flexibility in the
Triaxis  portfolio's  smallest  packaged  assembly.
Additionally,  the  MLX90393
for
micropower applications, with programmable duty
cycles  in  the  range  of  0.1%  to  100%  allowing  for
configurable power consumption based on system
requirements.

is  designed

The  MLX90393  magnetic  field  sensor  can  be
reprogrammed  to  different  modes  and  with
different  settings  at  run-time  to  fine-tune  the
performance  and  power  consumed.  The  sensor
offers a 16-bit output proportional to the magnetic
flux density sensed along the X, Y, and Z axes using
the  Melexis  proprietary  Triaxis  technology  and
offers  a  16-bit  temperature  output  signal.  These
digital  values  are  available  via  I2C  and  SPI,  where
the  MLX90393  is  a  slave  on  the  bus.  Multiple
sensors can  be  connected  to the  same  bus,  by  A0
and A1 hardwired connection (4x) but also through
ordering codes with different SW address (4x).

By  selecting  which  axes  are  to  be  measured,  the
raw  data  can  be  used  as  input  for  further  post-
processing, such as for joystick applications, rotary
knobs,  and  more  complex  3D  position  sensing
applications. Unparalleled performance is achieved
with  this  sensor,  which
is  primarily  targeting
industrial and consumer applications.

VDD

VDD_IO

A0 A1

Bias

Triaxis®

VX
VY
VZ

Temp Sensor

X
U
M

VT

G

ADC

Oscillator

Low Power
Oscillator

Wake-Up

State Machine

RAM

EEPROM

Control
SPI/ I2C
Interface

Temp Compensation

SDA/ MOSI

SCL/ SCLK

M ISO

M S/ CS

Interrupt

Trigger

VSS

Figure 1: General Block Diagram

  Absolute Position Sensor IC featuring

Triaxis® Hall Technology

  Simple & Robust Magnetic Design

  Miniature size for tiny assemblies

  Selectable SPI and I2C bus protocols

  Wide dynamic range (5-50mT) with on-the-

fly programmable gain

  2.2V-3.6V supply for battery powered
applications, down to 1.8V IO voltage

  On board filter settings

  On the fly programmable operating modes
and sleep times for micro-power use

  External and internal acquisition triggering

modes

  External interrupt pin when the field

changes

  On board temperature sensor

2. Application Examples

  Non-contacting HMI applications with

push-pull functionality

  Rotary knobs & dials





(Long stroke) Linear motion in one or
two axes for levers & sliding switches

Joystick (gimbal or ball & socket)

  Home Security 3D closure detection

  Accurate liquid level sensing

  Factory automation position sensing

  Magnetic fingerprint detection

REVISION 011 – SEP 24, 2024

3901090393

MLX90393
Triaxis® Magnetic Node

Datasheet

Contents

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

15.4. I2C Communication ......................................................................................................................... 24

15.4.1. Command Implementation ...................................................................................................... 25

15.4.2. I2C Timing Specification ............................................................................................................ 27

16. Memory Map ..................................................................................................................................... 28

16.1. General Description ........................................................................................................................ 28

16.2. Parameter Description ................................................................................................................... 30

REVISION 011 – SEP 24, 2024
3901090393

Page 2 of 45

MLX90393
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

1.1 I2C ........................................................................................................................................................ 36

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

MLX90393
Triaxis® Magnetic Node

Datasheet

4. Ordering Information

Product

Temperature

Package  Option Code  Packing

Definition

MLX90393
MLX90393
MLX90393
MLX90393
MLX90393
MLX90393
MLX90393
MLX90393
MLX90393
MLX90393
MLX90393

S (-20°C to 85°C)
S (-20°C to 85°C)
S (-20°C to 85°C)
S (-20°C to 85°C)
E (-40°C to 85°C)
E (-40°C to 85°C)
E (-40°C to 85°C)
E (-40°C to 85°C)
S (-20°C to 85°C)
S (-20°C to 85°C)
S (-20°C to 85°C)

LW
LW
LW
LW
LW
LW
LW
LW
LW
LQ
LQ

ABA-011
ABA-012
ABA-013
ABA-014
ABA-011
ABA-012
ABA-013
ABA-014
ABA-111
ABA-011
ABA-014

Form

RE
RE
RE
RE
RE
RE
RE
RE
RE
RE
RE

I2C address = 00011xx
I2C address = 00100xx
I2C address = 00101xx
I2C address = 00110xx
I2C address = 00011xx
I2C address = 00100xx
I2C address = 00101xx
I2C address = 00110xx
I2C address = 00011xx
I2C address = 0010000
I2C address = 0011000

Table 1: Product Ordering Codes

Legend:

Temperature Code:

S: from -20°C to 85°C

E: from -40°C to 85°C

Package Code:

“LW” for QFN-16 3x3x1mm package with wettable flanks

“LQ” for UTDFN-8 2.5x2mm package

Option Code:

ABA-xx1, ABA-xx2, ABA-xx3, ABA-xx4: Different I2C addresses – 5 most
significant bits. The 2 least significant bits of the address are defined by the
external address pins A0 and A1.

ABA-0xx: Standard IMC, magnetic saturation onset at 50mT

ABA-1xx: Thin IMC, magnetic saturation onset at 25mT

Packing Form:

“RE for Reel”

Ordering Example:

“MLX90393-ELW-ABA-011-RE”
MLX90393 Micropower magnetometer with I2C address 00011xx where the last
two bits are defined by external address pins A0 and A1. In QFN package,
temperature range -40°C to 85°C.

Table 2: Product Ordering Code Example

REVISION 011 – SEP 24, 2024
3901090393

Page 4 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

5. Functional Diagram
5.1. QFN-16 Block Diagram

5.2. UTDFN-8 Block Diagram

REVISION 011 – SEP 24, 2024
3901090393

Page 5 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

6. Glossary of Terms

Term

TC

Definition

Temperature Coefficient (in ppm/°C)

Gauss (G), Tesla (T)

Units for the magnetic flux density  1 mT = 10 G

NC

PWM

%DC

ADC

DAC

LSb

MSb

DNL

INL

EMC

Not Connected

Pulse Width Modulation

Duty Cycle of the output signal i.e. TON /(TON + TOFF)

Analog-to-Digital Converter

Digital-to-Analog Converter

Least Significant Bit

Most Significant Bit

Differential Non-Linearity

Integral Non-Linearity

Electro-Magnetic Compatibility

REVISION 011 – SEP 24, 2024
3901090393

Page 6 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

7. QFN-16 Pinout

Name

Pin
#

Type

Supply
System

Wiring Recommendation

Primary

Secondary  Reference

I2C

To

4-wire
SPI

3-wire
SPI

1

INT

I/O out

N/A

VDD_IO

Optional  Optional  Optional

2  MS/CS

I/O in

MLX Test

VDD_IO

To
VDD_IO

Required  Required

SCL/SCLK

I/O in

MLX Test

VDD_IO

Required

Required  Required

N/C

--

--

--

--

--

--

SDA/MOSI

I/O bi

MLX Test

VDD_IO

Required

Required

6  MISO

I/O out

MLX Test

VDD_IO

Floating

Required

Short
together

3

4

5

7

8

9

INT/TRIG

I/O bi

VDD_IO

Supply

N/C

10  N/C

11

A1

12

A0

--

--

I2C Address
LSB

I2C Address
LSB

N/A

N/A

--

--

VDD_IO

Optional  Optional  Optional

Required

Required  Required

--

--

--

--

--

--

--

--

MLX Test

VDD

MLX Test

VDD

To
VDD/GND

To
VDD/GND

To GND

To GND

To GND

To GND

Required

Required  Required

--

--

--

Required

Required  Required

--

--

--

13

VSS

Ground

14  N/C

--

15

VDD

Supply

16  N/C

--

N/A

--

N/A

--

--

--

Table 3: Pinout Description

It is recommended to connect the N/C pins (Not Connected) to Ground.

The exposed pad of the QFN package can be left floating or shorted to ground.

REVISION 011 – SEP 24, 2024
3901090393

Page 7 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

8. UTDFN-8 Pinout

Name

Pin
#

Type

Supply
System

Wiring Recommendation

Primary

Secondary  Reference

I2C

SCL/SCLK
SDA/MOSI

1
2
3  MISO

I/O in
I/O bi
I/O out

VDD_IO
VSS
VDD

4
5
6
7  MS/CS

Supply
Ground
Supply
I/O in

MLX Test
MLX Test
MLX Test

N/A
N/A
N/A
MLX Test

To

VDD_IO
VDD_IO
VDD_IO

VDD_IO

8

INT

I/O out

N/A

VDD_IO

4-wire
SPI

3-wire
SPI

Required  Required  Required
Required  Required
Required
Floating

Short
together

Required  Required  Required
Required  Required  Required
Required  Required  Required
Required  Required
To
VDD_IO
Optional  Optional  Optional

The exposed pad of the UTDFN-8 package can be left floating or shorted to ground.

Table 4: UTDFN-8 Pinout Description

REVISION 011 – SEP 24, 2024
3901090393

Page 8 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

9. Absolute Maximum Ratings

Parameter

Symbol

Min.

Typ.  Max.

Unit

VDD_MAX

Analog Supply Voltage Limits

VDD_IO_MAX

Digital IO Supply Limits

TSTORAGE

Storage (idle) temperature range

ESDHBM

ESDCDM

According to AEC-Q100-002

According to AEC-Q100-011-B (QFN)

-0.3

-0.3

-50

4

min(4, VDD+0.3)

125

2.5

750

V

V

°C

kV

V

Table 5: Absolute Maximum Ratings

Exceeding  the  absolute  maximum  ratings  may  cause  permanent  damage.    Exposure  to  absolute  maximum-rated
conditions for extended periods may affect device reliability.

REVISION 011 – SEP 24, 2024
3901090393

Page 9 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

10. General Electrical Specifications

Parameter  Remark

VDD

Analog Supply Voltage

VDD_IO

Digital IO Supply

Min

2.2

1.65

Nom

Max

Unit

3

1.8

3.6

VDD

VPOR_LH

Power-on Reset threshold

1.42

1.55

(rising edge)

VPOR_HL

Power-on Reset threshold

1

1.31

(falling edge)

IDD,CONVXY

Conversion Current XY-axis

IDD,CONVZ

Conversion Current Z-axis

IDD,CONVT

Conversion Current Temperature

IDD, CONV_END

IDD_ACTIVE

Current during TCONV_END

Current during TACTIVE

IDD_IDLEtoSTBY

Current during TSTBY

IDD,STBY

Standby Current(1)

IDD,IDLE

Idle Current(2)

1

IDD,NOM

Nominal Current (TXYZ, Datarate = 10Hz,
OSR=OSR2=0, DIG_FILT=4)

3

4

2

1.75

1.75

1.75

60

5

2.29

2.96

1.60

1.5

1.2

1.2

43

2.4

100

Table 6: General Electrical Specifications

V

V

V

V

mA

mA

mA

mA

mA

mA

µA

µA

µA

1 Standby current corresponds to the current consumed in the digital where only the low power oscillator is running.
This standby current is present in burst mode, or whenever the IC is counting down to start a new conversion.
2 Idle current corresponds to the current drawn by the IC in idle mode where all operating functions are disabled except
communications.

REVISION 011 – SEP 24, 2024
3901090393

Page 10 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

11. Thermal Specification

The  MLX90393  has  an  on-board  temperature  sensor  which  measures  the  temperature  of  the  MLX90393
sensor. The temperature can be read out via the communication protocol in a digital format

Parameter

Symbol

Min.

Typ.  Max.  Unit

TRES

T25

TLIN

Temperature sensor resolution

Temperature sensor output at 25°C

Temperature Linearity (3)

TOPERATING

Operating temperature range [S code]

Operating temperature range [E code]

45.2

46244

+/-3

25

25

LSB/°C

LSB16u

°C

°C

°C

85

85

-20

-40

Table 7: Thermal Specifications

3 The linearity is defined as the best fit curve through the digital temperature outputs over the entire temperature
range. It includes ADC non-linearity effects

REVISION 011 – SEP 24, 2024
3901090393

Page 11 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

12. Timing Specification

The specifications are applicable at 25 DegC unless specified otherwise and for the complete supply range.

Parameter  Remark

Min

Nom

Max

Unit

TSTBY

TACTIVE

TCONVM

TCONVT

Main Oscillator & Derived Timings

Time from IDLE to STBY

Time from STBY to ACTIVE

176

288

220

360

264

432

Single Magnetic axis conversion time(4)
typical programming range

Temperature conversion time
typical programming range

TCONV_END

Time to end analog active mode

259

66627
67 + 64 ∙ 2(cid:3016)(cid:3020)(cid:3019) ∙ (2 + 2(cid:3005)(cid:3010)(cid:3008)_(cid:3007)(cid:3010)(cid:3013)(cid:3021))
1603

259

67 + 192 ∙ 2(cid:3016)(cid:3020)(cid:3019)(cid:2870)
100

80

120

TCONV_SMM

Total conversion time in Single
Measurement Mode

TSTBY + TACTIVE + m*TCONVM + TCONVT+
TCONV_END

TCONV_BURST_NDL
Y

Total conversion time in BURST with burst
data rate =0

m*TCONVM + TCONVT+ TCONV_END

TCONV_BURST_DLY

Total conversion time in BURST with burst
data rate > 0

TACTIVE + m*TCONVM + TCONVT+ TCONV_END

ms

TCONV_WOC_NDLY

Total conversion time in WOC with burst
data rate = 0

m*TCONVM + TCONVT+ TCONV_END

TCONV_WOC_DLY

Total conversion time in WOC with burst
data rate > 0

TSTBY + TACTIVE + m*TCONVM + TCONVT+
TCONV_END

TOSC_TRIM

Trimming accuracy

TOSC_THD

Thermal drift (full temperature range)

-5

-5

Low-power Oscillator & Derived Timings

TINTERVAL

Time in between 2 conversions (Burst
mode or Wake-Up on Change)(5)

TLPOSC_TRIM

Trimming accuracy

TLPOSC_THD

Thermal drift (full temperature range)

0

BURST_DATA_RATE * 20

-4

-5

+4

+5

+5

+5

1260

µs

µs

µs

 µs

µs

ms

ms

ms

ms

%

%

ms

%

%

4 This conversion time is defined as the time to acquire a single axis of the magnetic flux density. When measuring
multiple axes they are obtained through time multiplexing. The conversion time is programmable through parameters
OSR and DIG_FILT for magnetic values and OSR2 for the temperature value. The conversion sequence is TXYZ, opposite
of the ZYXT argument of the command set.
5 The time TINTERVAL is defined as the time between the end of one set of measurements (any combination of TXYZ) and
the start of the following same set of measurements in BURST and WOC mode. As a result of this, the maximum output
data rate is not only a function of TINTERVAL but equals 1/(TCONV_BURSTWOC + TINTERVAL).

REVISION 011 – SEP 24, 2024
3901090393

Page 12 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

Parameter  Remark

TINT_RDY

Time between INT rising and full
accessibility(6)

Nom

Max

Min

132

Startup

TPOR

Power-on-reset completion time

0.6

1.5

TTRIG

Trigger pulse width (active high)

0.01

250

External Trigger

Unit

µs

ms

µs

Table 8: Timing Specifications

6 Reading the measurements (once) sooner than this specified time after the rising INT will work, however the status
byte can still show an active measurement mode (single measurement). Other commands are not allowed during this
time.

REVISION 011 – SEP 24, 2024
3901090393

Page 13 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

13. Magnetic Specification

The specifications are applicable at 25 DegC unless otherwise specified and for the complete supply voltage
range.

Parameter  Remark

NADC

ADC span

NOUT

Output span (taken from 19 by RESXYZ)

BRANGE

Output range (function of RESXYZ)

BSAT

Magnetic saturation onset

Option codes -011, -012, -013, -014

BSAT

Magnetic saturation onset

Option code -111

OFFS

Deviation from expected 0mT output

OFFSTHD

Offset thermal drift, Delta from 25°C (7)

Min

Nom

Max

Unit

17.4

16

RANGE from Table 17:
Sensitivity table for given gain
and resolution selection for
HALLCONF=0xC / SENSii

bits

bits

mT

mT

mT

LSB

LSB

50

25

3.220

311

5.872

170

0

< ±1000

SENSXX,
SENSYY

SENSZZ

SENSXY,
SENSYX

SENSXZ,
SENSYZ

Programming range of magnetic resolution
(µT/LSB) or sensitivity (LSB/mT) (8)
[modifying GAIN_SEL and RESXYZ], cfr. Table
17: Sensitivity table for given gain and
resolution selection for HALLCONF=0xC

Cross-axis sensitivity (X/Y-axis sensitivity to
Y/X magnetic fields)

Cross-axis sensitivity (X/Y-axis sensitivity to Z
magnetic field)

< ±1

< ±1

0.161

µT/LSB

6211

LSB/mT

0.294

µT/LSB

3406

LSB/mT

%

%

7 The offset thermal drift is defined as the deviation at 0Gauss from the output with respect to the output at 25°C when
sweeping the temperature. The highest gradient (µT/°C) typically occurs at 85°C. The spec value is based on
characterization on limited sample size at GAIN_SEL=0x7 and RES_XYZ=0x00.
8 The total axis sensitivity is programmable to support different applications, but has no Automatic Gain control on-chip
as do the other angular position sensors from Melexis. The highest gain corresponds to at least the minimum +/-4.8mT
magnetic measurement range and the magnetic resolution defined by SENSii.

REVISION 011 – SEP 24, 2024
3901090393

Page 14 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

Parameter  Remark

Min

Nom

Max

Unit

SENSZX,
SENSZY

Cross-axis sensitivity (Z-axis sensitivity to X
and Y magnetic fields)

< ±1

SENSTHD

Sensitivity thermal drift

-3

+3

%

%

Delta from 25°C(9)

Table 9: Magnetic Specifications

9 The sensitivity thermal drift is expressed as a band around the sensitivity at 25°C. It is applicable on wafer level
trimming, but can be influenced by packaging (overmolding).

REVISION 011 – SEP 24, 2024
3901090393

Page 15 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

13.1. Noise vs Conversion Time

The MLX90393 provides configurable filters to adjust the tradeoff between current consumption, noise, and
conversion time. See section 15.1.5 for details on selecting the conversion time by adjusting OSR and DIG_FILT.

XY-axis Noise over Conversion Time (bundled per OSR setting)

60

50

40

30

20

10

]
s
s
u
a
G
m

[
v
e
d
t
S
e
s
i
o
N

0

1

OSR = 0

OSR = 1

OSR = 2

OSR = 3

10

Conversion Time [ms]

100

Figure 2: XY axis RMS noise versus conversion time, expressed in mGauss for GAIN_SEL = 0x7 - Based on -0xx version

Z-axis Noise over Conversion Time (bundled per OSR setting)

]
s
s
u
a
G
m

[
v
e
d
t
S
e
s
i
o
N

90

80

70

60

50

40

30

20

10

0

1

OSR = 0

OSR = 1

OSR = 2

OSR = 3

10

Conversion Time [ms]

100

Figure 3: Z axis RMS noise versus conversion time, expressed in mGauss for GAIN_SEL = 0x7 - Based on -0xx version

REVISION 011 – SEP 24, 2024
3901090393

Page 16 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

14. Mode Selection

The MLX90393 can operate in three modes. They are: Burst mode, Single Measurement mode, and Wake-On-
Change mode.

  Burst mode

The ASIC will have a programmable data rate at which it will operate. This data rate implies auto-
wakeup and sequencing of the ASIC, flagging that data is ready on a dedicated pin (INT/DRDY). The
maximum data rate corresponds to continuous burst mode, and is a function of the chosen
measurement axes. For non-continuous burst modes, the time during which the ASIC has a counter
running but is not doing an actual conversion is called the Standby mode (STBY).

  Single Measure mode

The master will ask for data via the corresponding protocol (I2C or SPI), waking up the ASIC to make a
single conversion, immediately followed by an automatic return to sleep mode (IDLE) until the next
polling of the master. This polling can also be done by strobing the TRG pin instead, which has the
same effect as sending a protocol command for a single measurement.

  Wake-Up on Change

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
because the emphasis is more on accurate timing intervals, avoiding the delay of TSTBY before conversion and
supporting an efficient continuous burst mode without standby overhead.

It is the user’s responsibility to read back the measured data as the MLX90393 is a slave device on the bus.
Even in burst mode and WOC mode when the MLX90393 is auto-sequencing, the master will be responsible
for collecting the acquired sensor data.

REVISION 011 – SEP 24, 2024
3901090393

Page 17 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

14.1. Burst mode

Figure 4: Top-level state diagram with indication of timings

When  the  sensor  is  operating  in  burst  mode,  it  will  make  conversions  at  specific  time  intervals.  The
programmability of the user is the following:

  Burst speed (TINTERVAL) through parameter BURST_DATA_RATE

  Conversion time (TCONV) through parameters OSR, OSR2 and DIG_FILT

  Axes/Temperature (MDATA) through parameter BURST_SEL or via the command argument (ZYXT)

Whenever the MLX90393 has made the selected conversions (based on MDATA), the DRDY signal will be set
(active H) on the INT and/or INT/TRG pin to indicate that the data is ready for readback. It will remain high
until the master has sent the command to read out at least one of the converted quantities (ZYXT). Should the
master have failed to read out any of them by the time the sensor has made a new conversion, the INT/DRDY
pin will be strobed low for 10µs, and the next rising edge will indicate a new set of data is ready.

14.2. Single Measurement mode

Whenever the sensor is set to this mode (or after startup) the MLX90393 goes to the IDLE state where it awaits
a  command  from  the  master  to  perform  a  certain  acquisition.  The  duration  of  the  acquisition  will  be  the
concatenation of the TSTBY, TACTIVE, m*TCONVM (with m # of axes) and TCONVT. The conversion time will effectively

REVISION 011 – SEP 24, 2024
3901090393

Page 18 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

be programmable by the user (see burst mode), but is equally a function of the required axes/temperature to
be measured.

Upon reception of such a polling command from the master, the sensor will make the necessary acquisitions,
and set the DRDY signal high to flag that the measurement has been performed and the master can read out
the data on the bus at his convenience. The INT/DRDY will be cleared either when:

  The master has issued a command to read out at least one of the measured components

  The master issues an Exit (EX) command to cancel the measurement

  The chip is reset, after POR (Power-on reset) or Reset command (RT)

14.3. Wake-Up on Change mode

The Wake-Up on Change (WOC) functionality can be set by the master with as main purpose to only receive
an interrupt when a certain threshold is crossed. The WOC mode will always compare a new burst value with
a reference value to assess if the difference between both exceeds a user-defined threshold. The reference
value is defined as one of the following:

  The first measurement of WOC mode is stored as reference value once. This measurement at “t=0” is

then the basis for comparison or,

  The reference for acquisition(t) is always acquisition(t-1), in such a way that the INT signal will only

be set if the derivative of any component exceeds a threshold.

The  in-application  programmability  is  the  same  as  for  burst  mode,  but  now  the  thresholds  for  setting  the
interrupt are also programmable by the user, as well as the reference, if the latter is data(t=0) or data(t-1).

15. Digital Specification

The supported protocols are I2C and SPI. The MS/CS pin is used to define the protocol to be used:





/CS = 0 for SPI, addressing the MLX90393 slave in SPI mode (3- and 4-wire), but releasing this line in
between commands (no permanent addressing allowed)

/CS = 1 for I2C, addressing the MLX90393 slave when the correct address is transmitted over the bus
(permanently kept high)

REVISION 011 – SEP 24, 2024
3901090393

Page 19 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

To ensure the activity on the SPI bus cannot be accidentally interpreted as I2C protocol, programming bits are
available
It  concerns  the
COMM_MODE[1:0] bits with the following effect:

in  the  memory  of  the  MLX90393  to  force  the  communication  mode.

COMM_MODE[1]  COMM_MODE[0]

Description

0

1

1

X

0

1

The mode in which the first valid command is transmitted to the
MLX90393 defines the operating mode (SPI or I2C) for all its future
commands, until a reset (hard or soft) is done.

SPI mode only

I2C mode only

15.1. Command List

Table 10: Communication mode definition

The  MLX90393  only  listens  to  a  specific  set  of  commands.  Apart  from  the  Reset  command,  all  commands
generate a status byte that can be read out. The table below indicates the 10 different commands that are
(conditionally) accepted by the MLX90393. The MLX90393 will always acknowledge a command in I2C, even if
the command is not a valid command. Interpreting the associated status byte is the method for verification of
command acceptance.

Command Name

Symbol

#

CMD1 byte  CMD2 byte  CMD3 byte  CMD4 byte

Command Set

Start Burst Mode

SB

Start Wake-up on Change Mode

SW

Start Single Measurement Mode

SM

Read Measurement

Read Register

Write Register

Exit Mode

Memory Recall

Memory Store

Reset

RM

RR

WR

EX

HR

HS

RT

1

2

3

4

5

6

8

D

E

F

0001 zyxt

0010 zyxt

0011 zyxt

0100 zyxt

N/A

N/A

N/A

N/A

0101 0abc

{A5…A0,0,0}

N/A

N/A

N/A

N/A

N/A

N/A

N/A

N/A

N/A

N/A

0110 0abc

D15…D8

D7…D0

{A5…A0,0,0}

1000 0000

1101 0000

1110 0000

1111 0000

N/A

N/A

N/A

N/A

N/A

N/A

N/A

N/A

N/A

N/A

N/A

N/A

Table 11: Command List

The argument for the volatile memory access commands (RR/WR) «abc» should be set to 0x0, in order to get
normal read-out and write of the memory.

REVISION 011 – SEP 24, 2024
3901090393

Page 20 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

The  argument  in  all  mode-starting  commands  (SB/SW/SM)  is  a  nibble  specifying  the  conversions  to  be
performed by the sensor in the following order «zyxt». For example, if only Y axis and temperature are to be
measured  in  Single  Measurement  mode  the  correct  command  to  be  transmitted  is  0x35.  The  sequence  of
measurement  execution  on-chip  is  inverted  to  «TXYZ»,  so  T  will  be  measured  before  X,  followed  by  Y  and
finally Z. By issuing an all-zero «zyxt» nibble, the BURST_SEL value from RAM will be used instead of the empty
argument of the command.

15.2. Status Byte

The status byte is the first byte transmitted by the MLX90393 in response to a command issued by the master.
It is composed of a fixed combination of informative bits:

bit 7

bit 6

bit 5

bit 4

bit 3

bit 2

bit 1

bit 0

BURST_MODE

WOC_MODE

SM_MODE

ERROR

SED

RS

D1

D0

  MODE bits

Table 12: Status Byte Definition

These bits define in which mode the MLX90393 is currently set. Whenever a mode transition
command is rejected, the first status byte after this command will have the expected mode bit
cleared, which serves as an indication that the command has been rejected, next to the ERROR bit.
The SM_MODE flag can be the result of an SM command or from raising the TRG pin when TRG mode
is enabled in the volatile memory of the MLX90393.

  ERROR bit

This bit is set in case a command has been rejected or in case an uncorrectable error is detected in
the memory, a so called ECC_ERROR. A single error in the memory can be corrected (see SED bit),
two errors can be detected and will generate the ECC_ERROR. In such a case all commands but the
RT (Reset) command are not allowed. For example, a RR/WR command is not allowed during burst
mode, resulting in the ERROR bit being set yet the command is not actively rejected. The error bit is
equally set when the master is reading back data while the DRDY flag is low.

  SED bit

The single error detection bit simply flags that a bit error in the non-volatile memory has been
corrected. It is purely informative and has no impact on the operation of the MLX90393.

  RS bit

Whenever the RT command is issued, the status message indicates that the RT is going to be
performed by setting this bit. Then the bit is cleared again during the reset.

  D[1:0] bits

These bits only have a meaning after the RR and RM commands, when data is expected as a response
from the MLX90393. The number of response bytes correspond to 2*D[1:0] + 2, so the expected byte
counts are either 2, 4, 6 or 8. For commands where no response is expected, the content of D[1:0]
should be ignored.

15.3. SPI Communication

The MLX90393 can handle SPI communication at a bitrate of 10Mhz. The SPI communication is implemented
in a half-duplex way, showing high similarities with I2C communication, but addressing through the \CS (Chip
Select) pin instead of through bus arbitration. The half-duplex nature is at the basis of the supported 3-wire

REVISION 011 – SEP 24, 2024
3901090393

Page 21 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

SPI operation. SPI mode 3 is implemented: CPHA=1 (data changed on leading edge and captured on trailing
edge, and CPOL=1 (high level is inactive state). The Chip Select line is active-low.

The communication  is also  bundled  in  bytes, equally MSB first  and MSByte  first. A command can of  course
consist of more than 1 byte (refer to Table 10: Communication mode definition) as can the response be from
the MLX90393 in the form of multiple bytes after the status byte (not shown in Figure 5: SPI communication
example)

/CS

SCL

MOSI

MISO

ADD

1

2

3

4

5

6

7

8

1

2

3

4

5

6

7

8

COMMAND[7:0]

X (4-wire SPI) or Z  (3-wire SPI)

Z (3 & 4-wire SPI)

STATUS_BYTE[7:0]

Figure 5: SPI communication example

NADD

15.3.1. Command implementation

For the examples give, the below convention is used.

xxx

xxx

MOSI data (1 byte)

MISO data (1 byte)

Figure 6: SPI convention

15.3.1.1. SB, SWOC, SM, EX, HR, HS

All  the  commands  follow  the  structure  below.  The  reply  from  the  MLX90393  is  only  the  status  byte.  The
example below is for a start of a burst mode with X and Y being measured.

0x16

xx

0x00

Status

Figure 7: SB command, XY

After the HS command, wait at least 15ms before sending the next command to allow the IC to update the
NVRAM correctly.

REVISION 011 – SEP 24, 2024
3901090393

Page 22 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

15.3.1.2. RT

This command will (warm-)reset the IC. The status byte of the command following will indicate the reset event.
It is recommended to perform an ‘EX’ command and to wait 1ms, before issuing a ‘RT’ command. After the RT
command, it is recommended to wait 1.5ms for the start-up sequence to complete.

0xF0

xx

0x00

Status

Figure 8: RT command

15.3.1.3. RM

This command differs depending on the value for zyxt. The data is returned in the order Status-TXYZ, where
the components which are set to zero are skipped.

0x4F

xx

0x00

Status

0x00

T [15:8]

0x00

T [7:0]

0x00

X [15:8]

0x00

X [7:0]

0x00

Y [15:8]

0x00

Y [7:0]

0x00

Z [15:8]

0x00

Z [7:0]

Figure 9: RM command, XYZT

0x45

xx

0x00

Status

0x00

T [15:8]

0x00

T [7:0]

0x00

Y [15:8]

0x00

Y [7:0]

15.3.1.4. RR

Figure 10: RM command, YT

Important in this command is that the register address to be read needs to be shifter left by two bits. To read
register 0x12 for example, the MOSI byte becomes 0x48.

0x50

xx

Register << 2

xx

0x00

Status

0x00

0x00

Data [15:8]

Data [7:0]

Figure 11: RR command

15.3.1.5. WR

Important in this command is that the register address to be read needs to be shifter left by two bits. To read
register 0x12 for example, the MOSI byte becomes 0x48.

0x60

xx

Data [15:8]

Data [7:0]

Register << 2

xx

xx

xx

0x00

Status

Figure 12: WR command

REVISION 011 – SEP 24, 2024
3901090393

Page 23 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

15.3.2. SPI Timing Specification

All timings are referred to the levels found in Table 6: General Electrical Specifications.

Electrical Parameter

SPI Clock Cycle
SPI Clock Cycle
CS Setup Time
CS Hold Time
SDI Input Setup Time
SDI Input Hold Time
SDO Valid Output Time
SDO Output Hold Time
SDO Output Disable Time

Symbol

tc (SPC)
tc (SPC)
tsu (CS)
th (CS)
tsu (SI)
th (SI)
tv (SO)
th (SO)
tdis (SO)

Min.

Max.

100

5
10
5
15

5

10

50

50

Unit

ns
MHz
ns
ns
ns
ns
ns
ns
ns

Table 13: General SPI Timing Specification

CS

SPC

SDI

SDO

tsu (CS)

tc (SPC)

th (CS)

tsu (SI)

th (SI)

MSB IN

MSB OUT

tv (SO)

th (SO)

LSB IN

tdis (SO)

LSB OUT

15.4. I2C Communication

Figure 13: SPI Timing Diagram

The I2C protocol is implemented such that the command is written to a specific register in the RAM, and the
status and measurement data are read back from this RAM. The commands themselves are the same as for
SPI (section 15.3) except for the read measurement commands and the memory read/write commands. For
memory  read/write  commands,  written  can  be  done  directly  to  the  required  register.  Note  that  memory
read/write commands are required to be word-wise, so always in multiples of 2 bytes. Read measurement is
the same as a memory read, except starting from the status register. MSbits are sent first.

The 7-bit I2C-address is determined by the connection to the A0 and A1 pins. The 5 MSBs are programmed by
Melexis in the MLX90393. Please contact Melexis in case other addressing is required.

REVISION 011 – SEP 24, 2024
3901090393

Page 24 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

7

0

6

0

5

0

4

1

3

1

7-bit I2C address

2
0 if A1 shorted to ground
1 if A1 shorted to supply

1
0 if A0 shorted to ground
1 if A0 shorted to supply

R/W bit
0
0 for I2C write
1 for I2C read

Ordering Code

EE_I2C_ADDR[4:0]

7-bit I2C addresses possible

MLX90393xLW-ABA-011-RE

MLX90393xLW-ABA-012-RE

MLX90393xLW-ABA-013-RE

MLX90393xLW-ABA-014-RE

MLX90393xLQ-ABA-011-RE

0x03

0x04

0x05

0x06

0x04

0x0C, 0x0D, 0x0E, 0x0F

0x10, 0x11, 0x12, 0x13

0x14, 0x15, 0x16, 0x17

0x18, 0x19, 0x1A, 0x1B

0x10

Table 14: I2C address ordering codes

15.4.1. Command Implementation

For the examples given, the below convention is used.

S

SR

P

A

I2C Start

I2C Repeated Start

I2C Stop

Acknowledge from IC (1 bit)

NACK

(Not) Acknowledge from Master (1 bit)

I2C Addressing (1 byte)

Data from Master to IC (1 byte)

Data from IC to Master (1 byte)

Figure 14: I2C Convention

A

xxx

xxx

xxx

15.4.1.1. SB, SWOC, SM, EX, HR, HS

All  the  commands  follow  the  structure  below.  The  reply  from  the  MLX90393  is  only  the  status  byte.  The
example below is for a start of a burst mode with X and Y being measured.

S

I2C addr [W]

A

0x16

A

SR

I2C addr [R]

A

Status

NACK

P

After the HS command, wait at least 15ms before sending the next command to allow the IC to update the
NVRAM correctly.

Figure 15: SB command, XY

REVISION 011 – SEP 24, 2024
3901090393

Page 25 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

15.4.1.2. RT

This command will (warm-)reset the IC. The status byte of the command following will indicate the reset event.
It is recommended to perform an ‘EX’ command and to wait 1ms, before issuing a ‘RT’ command. After the RT
command, it is recommended to wait 1.5ms for the start-up sequence to complete.

S

I2C addr [W]

A

0x80

A

SR

I2C addr [R]

A

Status

NACK

P

Figure 16: RT command

15.4.1.3. RM

This command differs depending on the value for zyxt. The data is returned in the order Status-TXYZ, where
the components which are set to zero are skipped.

S

I2C addr [W]

X [15:8]

S

I2C addr [W]

Y [15:8]

A

A

A

A

15.4.1.4. RR

0x4F

X [7:0]

A

A

SR

I2C addr [R]

A

Status

A

T [15:8]

A

T [7:0]

Y [15:8]

A

Y [7:0]

A

Z [15:8]

A

Z [7:0]

NACK

Figure 17: RM command-XYZT

0x45

A

SR

I2C addr [R]

A

Status

A

T [15:8]

A

T [7:0]

Y [7:0]

NACK

P

A

P

A

Figure 18: RM command-YT

Important in this command is that the register address to be read needs to be shifted left by two bits. To read
register 0x12 for example, the SDA byte becomes 0x48.

S

I2C addr [W]

A

0x50

A

Register << 2

A

SR

I2C addr [R]

A

Status

A

Data [15:8]

A

Data [7:0]

NACK

P

15.4.1.5. WR

Figure 19: RR command

Important in this command is that the register address to be read needs to be shifted left by two bits. To read
register 0x12 for example, the SDA byte becomes 0x48.

S

I2C addr [W]

A

0x60

A

Data [15:8]

A

Data [7:0]

A

Register << 2

A

SR

I2C addr [R]

A

Status

NACK

P

Figure 20: WR command

REVISION 011 – SEP 24, 2024
3901090393

Page 26 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

15.4.2. I2C Timing Specification

All timings are referred to the levels found in Table 6: General Electrical Specifications.

Electrical Parameter

SCL Clock Frequency
SCL Clock Low Time
SCL Clock High Time
SDA Setup Time
SDA Data Hold Time

SDA and SCL Rise Time

SDA and SCL Fall Time

START Condition Hold Time
REPEATED START Condition Setup Time
STOP Condition Setup Time
Bus Free Time Between STOP and
START Condition

Symbol

f (SCL)
tw (SCLL)
tw (SCLH)
tsu (SDA)
th (SDA)
tr (SDA)
tr (SCL)
tr (SDA)
tr (SCL)
th (ST)
tsu (SR)
tsu (SP)

tw (SP:ST)

4.7
4
250

4
4.7
4

4.7

I2C Standard Mode

I2C Fast Mode

Min.

Max.  Min.

100

3.45

1.3
0.6
100
0

Max.
400

0.9

Unit

kHz
µs
µs
ns
µs

1000

20+0.1*Cb

(10)

300

ns

300

20+0.1*Cb

(10)

300

0.6
0.6
0.6

1.3

ns

µs
µs
µs

µs

Table 15: General I2C Timing Specification

REPEATED
START

tsu (SR)

STOP

START

tsu (SDA)

th (SDA)

tsu (SP)

tw (SP:ST)

tf (SDA)

START

tr (SDA)

SDA

SCL

th (ST)

tw (SCLL)

tw (SCLH)

tr (SCL)

tf (SCL)

Figure 21: I2C Timing Diagram

10 Where Cb is the total bus capacitance (in pF)

REVISION 011 – SEP 24, 2024
3901090393

Page 27 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

16. Memory Map
16.1. General Description

The  MLX90393  has  1kbit of  non-volatile  memory,  and  the  same  amount of  volatile memory. Each  memory
consists  out  of  64  addresses  containing  16  bit  words.  The  non-volatile  memory  has  automatic  2-bit  error
detection and 1-bit error correction capabilities per address. The handling of such corrections & detections is
explained in Section 15.2.

The memory is split in 2 areas:

  Customer area [address 0x00 to 0x1F]

  Melexis area [address 0x20 to 0x3F]

The RR and WR commands impact the volatile memory only, there no direct access possible to the non-volatile
memory. The customer area of the volatile memory is bidirectionally accessible to the customer; the Melexis
area  is  write-protected.  Only  modifications  in  the  blue  area  are  allowed  with  the  WR  command.  The
adjustments  in  the  customer  area  can  be  stored  in  the  permanent  non-volatile  memory  with  the  STORE
command  HS,  which  copies  the  entire  volatile  memory  including  the  Melexis  area  to  the  non-volatile  one.
With the HR command the non-volatile memory content can be recalled to the volatile memory, which can
restore any modifications due to prior WR commands. The HR step is performed automatically at start-up of
the ASIC, either through cold reset or warm reset with the RT command.

The above is graphically shown in Figure 22.

VOLATILE
MEMORY

NON-VOLATILE
MEMORY

CUSTOMER AREA

CUSTOMER AREA

STORE (HS)

MELEXIS AREA

MELEXIS AREA

RECALL (HR)

RR

WR

Figure 22: The memories of the MLX90393, their areas and the impacting commands.

The customer area houses 3 types of data:

  Analog configuration bits

  Digital configuration bits



Informative (free) bits

REVISION 011 – SEP 24, 2024
3901090393

Page 28 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

The latter can be filled with customer content freely, and covers the address span from (and including) 0x0A
to  0x1F,  a  total  of  352  bits.  The  memory  mapping  of  volatile  and  non-volatile  memory  on  address  level  is
identical. The volatile memory map is given in Figure 23.

The table below gives an overview of the customer area in the MLX90393’s NVRAM.

In the register map, the 16-bit words are split into 2 bytes for the sake of readability. The general format is
shown below in the yellow table.

Register

Bit 7

0x..

Bit 7
Bit 15 (MSB)

Bit 6

Bit 6
Bit 14

Bit 5

Bit 5
Bit 13

Bit 4

Bit 4
Bit 12

Bit 3

Bit 3
Bit 11

Bit 2

Bit 2
Bit 10

Bit 1

Bit 1
Bit 9

Bit 0

Bit 0 (LSB)
Bit 8

Register

Bit 7

Bit 6

Bit 5

Bit 4

Bit 3

Bit 2

Bit 1

Bit 0

Z-SERIES

GAIN_SEL

HALLCONF

ANA_RESERVED_LOW

BIST

BURST_SEL (zyxt)

TRIG_INT

COMM_MODE

BURST_DATA_RATE (BDR)
WOC_DIFF  EXT_TRG  TCMP_EN

BURST_SEL (zyxt)

RES_Y

RES_X

DIG_FILT

OSR

RES_Z

RES_Y

OSR2

SENS_TC_LT

SENS_TC_HT

OFFSET_X
OFFSET_X

OFFSET_Y
OFFSET_Y

OFFSET_Z

OFFSET_Z

WOXY_THRESHOLD
WOXY_THRESHOLD

WOZ_THRESHOLD
WOZ_THRESHOLD

WOT_THRESHOLD

WOT_THRESHOLD

FREE

0x00h

0x01h

0x02h

0x03h

0x04h

0x05h

0x06h

0x07h

0x08h

0x09h

0x0Ah
…
0x1Fh

Figure 23: Customer area memory map.

The non-volatile memory can only be written (HS store command) if pin VDD is supplied with 3.3V minimum,
otherwise  the  write  sequence  cannot  be  performed  in  a  reliable  way.  Additionally,  this  HS  command  was
designed to be used as one-time calibration, but not as multi write-cycle memory within the application. In
case memory is written within the application, the number of write cycles should be kept to a minimum. There
is no limit to the write cycles in the volatile memory (WR write command).

REVISION 011 – SEP 24, 2024
3901090393

Page 29 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

16.2. Parameter Description

The meaning of each customer accessible parameter is explained in this section. The customer area of both
the volatile and the non-volatile memory can be written through standard SPI and I2C communication, within
the application.  No external high-voltages are  needed to perform such operations,  nor access to  dedicated
pins  that  need  to  be  grounded  in  the  application.  Note  that  the  default  settings  are  “illegal”  in  the  filter
settings.

Parameter

Description

ANA_RESERVED_LOW

Reserved IO trimming bits

BIST

Z_SERIES

Enabled the on-chip coil, applying a Z-field [Built-In Self Test]

Enable all plates for Z-measurement

GAIN_SEL[2:0]

Analog chain gain setting, factor 5 between min and max code

HALLCONF[3:0]

Hall plate spinning rate adjustment

Default

0x00

0x0

0x0

0x7

0xC

TRIG_INT_SEL

Puts TRIG_INT pin in TRIG mode when cleared, INT mode otherwise

0x0

COMM_MODE[1:0]

Allow only SPI [10b], only I2C [11b] or both [0Xb] according to CS pin

0x0

WOC_DIFF

Sets the Wake-up On Change based on Δ{sample(t),sample(t-1)}

EXT_TRIG

TCMP_EN

Allows external trigger inputs when set, if TRIG_INT_SEL = 0

Enables on-chip sensitivity drift compensation

BURST_SEL[3:0]

Defines the MDATA in burst mode if SB command argument = 0

BURST_DATARATE[6:0]

Defines TINTERVAL as BURST_DATA_RATE * 20ms

OSR2[1:0]

Temperature sensor ADC oversampling ratio

RES_XYZ[5:0]

Selects the desired 16-bit output value from the 19-bit ADC

DIG_FILT[1:0]

Digital filter applicable to ADC

OSR[1:0]

Magnetic sensor ADC oversampling ratio

SENS_TC_HT[7:0]

Sensitivity drift compensation factor for T < TREF

SENS_TC_LT[7:0]

Sensitivity drift compensation factor for T > TREF

OFFSET_i[15:0]

Constant offset correction, independent for i = X, Y, Z

0x0

0x0

0x0

0x0

0x00

0x0

0x00

0x0

0x0

Trimmed

Trimmed

0x0000

WOi_THRESHOLD[15:0]  Wake-up On Change threshold, independent for i = X, Y, Z and T

0x0000

Table 16: NVRAM parameter description

REVISION 011 – SEP 24, 2024
3901090393

Page 30 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

16.2.1. ANA_RESERVED_LOW

Reserved bits for analog trimming at Melexis factory. Do not modify.

16.2.2. BIST

Enables (1) or disables (0) the built in self-test coil. In normal operation set to 0. A measurement with this coil
enabled shows a change in magnetic field sensed on the Z-axis.

16.2.3. Z_Series

Enables series connection of hall plates for Z axis measurement. In normal operation set to 0.

REVISION 011 – SEP 24, 2024
3901090393

Page 31 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

16.2.4. GAIN_SEL[2:0]

Sets the analog gain to the desired value. The sensitivity is dependent on the axis (the X- and Y-axis have higher
sensitivity,  compared  with  the  Z-axis,  expressed  in  LSB/µT)  as  well  as  the  setting  of  the  RES_XYZ[5:0]
parameter. The relationship is given in the below table.

Table for HALLCONF(11) = 0xC, sensitivity in µT/LSB, TC off, T=25°C:

GAIN_SEL

0
1
2
3
4
5
6
7

RES = 0

RES = 1

RES = 2

RES = 3

SENSXY
0.751
0.601
0.451
0.376
0.300
0.250
0.200
0.150

SENSZ
1.210
0.968
0.726
0.605
0.484
0.403
0.323
0.242

SENSXY
1.502
1.202
0.901
0.751
0.601
0.501
0.401
0.300

SENSZ
2.420
1.936
1.452
1.210
0.968
0.807
0.645
0.484

SENSXY
3.004
2.403
1.803
1.502
1.202
1.001
0.801
0.601

SENSZ
4.840
3.872
2.904
2.420
1.936
1.613
1.291
0.968

SENSXY
6.009
4.840
3.605
3.004
2.403
2.003
1.602
1.202

SENSZ
9.680
7.744
5.808
4.840
3.872
3.227
2.581
1.936

Table 17: Sensitivity table for given gain and resolution selection for HALLCONF=0xC

Table for HALLCONF(11) = 0xC, sensitivity in µT/LSB, TC off, T=35°C:

GAIN_SEL

0
1
2
3
4
5
6
7

RES = 0

RES = 1

RES = 2

RES = 3

SENSXY
0.787
0.629
0.472
0.393
0.315
0.262
0.210
0.157

SENSZ
1.267
1.014
0.760
0.634
0.507
0.422
0.338
0.253

SENSXY
1.573
1.258
0.944
0.787
0.629
0.524
0.419
0.315

SENSZ
2.534
2.027
1.521
1.267
1.014
0.845
0.676
0.507

SENSXY
3.146
2.517
1.888
1.573
1.258
1.049
0.839
0.629

SENSZ
5.068
4.055
3.041
2.534
2.027
1.689
1.352
1.014

SENSXY
6.292
5.034
3.775
3.146
2.517
2.097
1.678
1.258

SENSZ
10.137
8.109
6.082
5.068
4.055
3.379
2.703
2.027

Table 18: Sensitivity table for given gain and resolution selection for HALLCONF=0xC

11 For HALLCONF = 0x0, the sensitivity scales with a factor 98/75. For example (0.150µT/LSB with HALLCONF 0xC
becomes 0.196µT/LSB with HALLCONF 0x0)

REVISION 011 – SEP 24, 2024
3901090393

Page 32 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

16.2.5. HALLCONF[3:0]

Modifies  the  hall  plate  spinning  (2-phase  vs  4-phase)  which  has  an  effect  on  the  minimum  sampling  rate
achievable.  Some  configurations  of  OSR  and  DIG_FILT  are  not  permitted.  The  cells  shown  in  red  are  not
permitted with HALL_CONF=0xC (default) but are allowed when HALL_CONF=0x0.

Typical TCONV(TXYZ)
for OSR2=0x0 [ms]

T
L
I
F
_
G
D

I

0
1
2
3
4
5
6
7

OSR

3
2
1
0
5.30
3.00
1.84
1.27
6.84
3.76
2.23
1.46
9.91
5.30
3.00
1.84
16.05
8.37
4.53
2.61
28.34
4.15
14.52
7.60
52.92
7.22  13.75  26.80
13.36  26.04  51.38  102.07
25.65  50.61  100.53  200.37

Table 19: TCONV as a function of OSR & DIG_FILT

Maximum ODR
for OSR2=0x0 [Hz]

T
L
I
F
_
G
D

I

0
1
2
3
4
5
6
7

OSR

2

0

1
716.9  493.0  303.4
622.7  408.0  241.5
493.0  303.4  171.5
348.0  200.6  108.6
62.6
219.2  119.6
33.9
125.9  66.1
17.7
34.9
68.0
9.0
18.0
35.4

3
171.5
133.0
91.8
56.6
32.1
17.2
8.9
4.5

Table 20: Maximum Output Data Rate (ODR) as a function of OSR & DIG_FILT

16.2.6. TRIG_INT_SEL

When set to 0 the TRIG_INT pin is in trigger mode. When set to 1 the TRIG_INT pin acts as an interrupt pin.

16.2.7. COMM_MODE[1:0]

When set to 0x2 only SPI communication is allowed. When set to 0x3 only I2C communication is allowed. When
set to 0x0 or 0x1 both communication modes can be used but the selection is made by the CS pin.

16.2.8. WOC_DIFF

When wake-on-change mode is enabled this parameter defines the mode to use. When enabled, a comparison
on  the  current  measurement  is  made  with  the  previous  measurement.  When  disabled,  the  first  initial
measurement is used as a reference.

REVISION 011 – SEP 24, 2024
3901090393

Page 33 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

16.2.9. EXT_TRIG

Allows for external trigger events when set to 1 and TRIG_INT_SEL = 0. When enabled an acquisition will start
with the external trigger pin detects a high value. Acquisitions will continue to be triggered until the EXT_TRIG
pin is brought low.

16.2.10. TCMP_EN

Enables (1) or disables (0) the on-chip sensitivity drift compensation. Enabling the temperature compensation
will  influence  the  way  the  magnetic  values  are  encoded  and  transmitted  to  the  system  microcontroller  as
shown in the table below.

TCMP_EN = 0x0

TCMP_EN = 0x1

ABA

RANGE

i

S
E
R

0

1

±215

±215

2  ±22000

3  ±11000

TYPE
2’s complement
0µT = 0LSB
2’s complement
0µT = 0LSB
unsigned
0µT = 215LSB
unsigned
0µT = 214LSB

RANGE

±215

±215

TYPE
unsigned
0µT = 215LSB
unsigned
0µT = 215LSB

N/A

Table 21: Output Range and Type as a function of TCMP_EN and RES_XYZ={RESX,RESY,RESZ}

16.2.11. BURST_SEL[3:0]

Defines the axes that will be converted in burst mode if the SB command argument is 0.

16.2.12. OSR2[1:0]

Selects the temperature sensor ADC oversampling ratio

16.2.13. RES_XYZ[5:0]

See  16.2.4  for  the  relationship  between  the  gain  and  resolution.  Additionally,  section  16.2.10  for  the
relationship between RES_XYZ and the output data format.

16.2.14. DIG_FILT[1:0]

See 16.2.5 for the selection of DIG_FILT and the impact on conversion time.

16.2.15. OSR[1:0]

Oversampling ratio for the magnetic measurements. See 16.2.5 for the selection of OSR

16.2.16. SENS_TC_HT[7:0]

Sensitivity drift compensation factor for T > TREF

16.2.17. SENS_TC_LT[7:0]

Sensitivity drift compensation factor for T < TREF

REVISION 011 – SEP 24, 2024
3901090393

Page 34 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

16.2.18. OFFSET_i[15:0]

Constant offset correction, independent of temperature, and  programmable  for each individual  axis where
i=X, Y, or Z.

16.2.19. WOi_THRESHOLD[15:0]

Wake-on-change threshold. Independently programmable for each magnetic axis (i=X, Y, Z) and temperature
(i=T)

REVISION 011 – SEP 24, 2024
3901090393

Page 35 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

17. Recommended Application Diagram

1.1 I2C

A1     A0        I2C Address
-------------------------------------
Vss   Vss      0001100R/W
Vss   Vdd     0001101R/W
Vdd   Vss     0001110R/W
Vdd   Vdd     0001111R/W

0
A

1
A

MLX90393

R1=R2=10K
C1=C2=0.1uF

VDDIO
(1.71V - VDD)

R1

C2

R2

I2C

VDD
(2.2V - 3.6V)

C1

MCU

Trigger

Interrupt/DRDY

VDDIO

SDA/MOSI

SCL/SCLK

MS/CS

VDD

VSS

INT/TRG

INT

Figure 24: I2C recommended schematic

1.2 SPI

0
A

1
A

Short on PCB
for 3-wire SPI

MLX90393

VDDIO
(1.71V - VDD)

C1=C2=0.1uF

C2

VDD
(2.2V - 3.6V)

C1

SPI

MCU

Trigger

Interrupt/DRDY

VDDIO

MISO

SDA/MOSI

SCL/SCLK

MS/CS

VDD

VSS

INT/TRG

INT

Figure 25: 3/4wire SPI recommended schematic

REVISION 011 – SEP 24, 2024
3901090393

Page 36 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

18. Packaging Specification
18.1. QFN-16

The MLX90393 shall be delivered in a QFN-16 package as shown below in Figure 26.

18.1.1. Package dimensions and sensitive spot location

Figure 26: QFN-16 - Package Outline Drawing

The sensing elements – Hall plates with the patented IMC technology – are located in the center of the die, which on its turn
is located in the center of the package.

REVISION 011 – SEP 24, 2024
3901090393

Page 37 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

18.1.2. QFN-16 - Pinout and Marking

Marking :

Part Number MLX90393 (3 digits)
Die Version (1 digit)

393

A

1234

Lot number: First 4 digits

5

YWW

Assembly Year (Y) and week (WW)
5th number of lot number (1 digit)

0
A

12

1
A

11

VSS

13

VDD

15

393A
1234
5YWW

8

VDD_IO

7

6

5

INT/TRG

MISO

SDA/MOSI

1
T
N

I

2
S
C
/
S
M

3
K
L
C
S
/
L
C
S

Figure 27: QFN-16 Pinout and Marking – Top view

REVISION 011 – SEP 24, 2024
3901090393

Page 38 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

18.2. UDTFN-8 package

The MLX90393 shall be delivered in a UTDFN-8 package as shown below in Figure 28:

18.2.1. Package dimensions and sensitive spot location

Y

Y

Z

Z

X
X

Figure 28: UTDFN-8 - Package Outline Drawing

REVISION 011 – SEP 24, 2024
3901090393

Page 39 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

18.2.2. UTDFN-8 - Pinout and Marking

Figure 29: UTDFN-8 – Pinout and Marking (-011 version)

Figure 30: UTDFN-8 – Pinout and Marking (-014 version)

REVISION 011 – SEP 24, 2024
3901090393

Page 40 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

19. Standard Information

Our  products  are  classified  and  qualified  regarding  soldering  technology,  solderability  and  moisture  sensitivity  level
according to standards in place in Semiconductor industry.

For  further  details  about  test  method  references  and  for  compliance  verification  of  selected  soldering  method  for
product integration, Melexis recommends reviewing on our web site the General Guidelines soldering recommendation.
For  all  soldering  technologies  deviating  from  the  one  mentioned  in  above  document  (regarding  peak  temperature,
temperature gradient, temperature profile, etc.), additional classification and qualification tests have to be agreed upon
with Melexis.

For package technology embedding trim and form post-delivery capability, Melexis recommends to consult the dedicated
trim & form recommendation application note: lead trimming and forming recommendations

Melexis is contributing to global environmental conservation by promoting lead free solutions. For more information on
qualifications of RoHS compliant products (RoHS = European directive on the Restriction Of the use of certain Hazardous
Substances) please visit the quality page on our website: http://www.melexis.com/en/quality-environment

20. ESD Precautions
Electronic semiconductor products are sensitive to Electro Static Discharge (ESD).
Always observe Electro Static Discharge control procedures whenever handling semiconductor products.

REVISION 011 – SEP 24, 2024
3901090393

Page 41 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

21. Revision History

Date
11-Nov-2014

Revision
001

Remark
  First Document Release

16-Feb-2015

002

  Changed Ordering Code to indicate QFN wettable flanks
  Update Document number
  Added description of yellow cells in Table 1 and Table 2.

13-Jul-2017

003

  Added additional ordering codes for up to 16 sensors on the same

28-May-2019

004

bus and their description in Table 2

  Added E temperature code for -40°C capable products and the

associated update of the operating range in chapter 3

  Updated template to new Melexis format

  UTDFN-8 Package / Pinout/ Marking
  Updated sensitivity tables
  Additional Communication commands details
  Functional flowchart updated
  Timings and current consumption updated

08-Jan-2020

006

  Additional specifications of Idd, IdletoStby, Idd, Active and

14-Jan-2021

007

Idd,Conv_end

  RR + WR in I2C: typo (one bit->two bits)
  Sensitivity chapter: footer, and footnote corrected; uT to µT.

Added note that sensitivity increase is in LSB/µT.

  RM commands: wrong explanation
  RES_XYZ[5:0] and DIG_FILT[1:0]: corrected cross references
  OSR[1:0]: link to HALLCONF added



I2C timing diagram
I2C address of UTDFN (was 0001100, now 0010000), in both
option codes and table (I2C chapter)

  BIST: some more explanation

13-Jul-2022

008

  Added version -111
  Pin number (8) missing in figure “QFN-16 Pinout and Marking –

18-Jan-2023

009

Top view”

  UTDFN coordinate system rotated 90 degrees
  Exposed pad (QFN-16 and UTDFN-8) explanation
  us to µs

  Added version SLQ ABA-014
  UTDFN package marking update
  Correct temperature range in SLW ABA-111

REVISION 011 – SEP 24, 2024
3901090393

Page 42 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

20-Jul-2023

010

  SENB pin changed to MS pin

  Error bit additional clarification

  Default NVRAM content added

  RT command and RS bit clarified

  Block diagram change

24-Sep-2024

011

  Added timing specification on INT pin

REVISION 011 – SEP 24, 2024
3901090393

Page 43 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

22. Contact
For the latest version of this document visit www.melexis.com/MLX90393

For additional information, www.melexis.com/contact

REVISION 011 – SEP 24, 2024
3901090393

Page 44 of 45

MLX90393
Triaxis® Magnetic Node

Datasheet

23. Disclaimer
The  content  of  this  document  is  believed  to  be  correct  and  accurate.  However, the  content  of  this  document  is  furnished  "as  is"  for
informational  use  only  and  no  representation,  nor  warranty  is  provided  by  Melexis  about  its  accuracy,  nor  about  the  results  of  its
implementation. Melexis assumes no responsibility or liability for any errors or inaccuracies that may appear in this document. Customer will
follow the practices contained in this document under its sole responsibility. This documentation is in fact provided without warranty, term,
or condition of any kind, either implied or expressed, including but not limited to warranties of merchantability, satisfactory quality, non-
infringement,  and  fitness  for  purpose.  Melexis,  its  employees  and  agents  and  its  affiliates'  and  their  employees  and  agents  will  not  be
responsible  for  any  loss,  however  arising,  from  the  use  of,  or  reliance  on  this  document.  Notwithstanding  the  foregoing,  contractual
obligations expressly undertaken in writing by Melexis prevail over this disclaimer.

This document is subject to change without notice, and should not be construed as a commitment by Melexis. Therefore, before placing
orders or prior to designing the product into a system, users or any third party should obtain the latest version of the relevant information.
Users or any third party must determine the suitability of the product described in this document for its application, including the level of
reliability required and determine whether it is fit for a particular purpose.

This document as well as the product here described may be subject to export control regulations. Be aware that export might require a prior
authorization  from  competent  authorities.  The  product  is  not  designed, authorized  or  warranted  to  be  suitable  in  applications  requiring
extended temperature range and/or unusual environmental requirements. High reliability applications, such as medical life-support or life-
sustaining equipment or avionics application are specifically excluded by Melexis. The product may not be used for the following applications
subject to export control regulations: the development, production, processing, operation, maintenance, storage, recognition or proliferation
of:

1. chemical, biological or nuclear weapons, or for the development, production, maintenance or storage of missiles for such
weapons;
2. civil firearms, including spare parts or ammunition for such arms;
3. defense related products, or other material for military use or for law enforcement;
4.  any  applications  that,  alone  or  in  combination  with  other  goods,  substances  or  organisms  could  cause  serious  harm  to
persons or goods and that can be used as a means of violence in an armed conflict or any similar violent situation.

No license nor any other right or interest is granted to any of Melexis' or third party's intellectual property rights.

If  this  document  is  marked  “restricted”  or  with  similar  words,  or  if  in  any  case  the  content  of  this  document  is  to  be  reasonably
understood as being confidential, the recipient of this document shall not communicate, nor disclose to any third party, any part of
the document without Melexis’  express written  consent. The recipient  shall  take all necessary  measures  to  apply and  preserve  the
confidential character of the document. In particular, the recipient shall (i) hold document in confidence with at least the same degree
of care by which it maintains the confidentiality of its own proprietary and confidential information, but no less than reasonable care;
(ii) restrict the disclosure of the document solely to its employees for the purpose for which this document was received, on a strictly
need  to  know  basis  and  providing  that  such  persons  to  whom  the  document  is  disclosed  are  bound  by  confidentiality  terms
substantially similar to those in this disclaimer; (iii) use the document only in connection with the purpose for which this document
was  received,  and  reproduce  document  only  to  the  extent  necessary  for  such  purposes;  (iv)  not  use  the  document  for  commercial
purposes or to the detriment of Melexis or its customers. The confidentiality obligations set forth in this disclaimer will have indefinite
duration and in any case they will be effective for no less than 10 years from the receipt of this document.

This disclaimer will be governed by and construed in accordance with Belgian law and any disputes relating to this disclaimer will be
subject to the exclusive jurisdiction of the courts of Brussels, Belgium.

The invalidity or ineffectiveness of any of the provisions of this disclaimer does not affect the validity or effectiveness of the other
provisions.
The previous versions of this document are repealed.

Melexis © - No part of this document may be reproduced without the prior written consent of Melexis.  (2024)

IATF 16949 and ISO 14001 Certified

REVISION 011 – SEP 24, 2024
3901090393

Page 45 of 45