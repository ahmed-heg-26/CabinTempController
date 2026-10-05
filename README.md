CABIN TEMPERATURE CONTROLLER (MBD PROJECT)

OVERVIEW
This repository contains a Model-Based Development (MBD) implementation of a Cabin Temperature Controller in MATLAB and Simulink. The system calculates fan speed demand based on temperature setpoints and includes integrated safety logic for temperature sensor fault detection.

The project features Software-in-the-Loop (SIL) verification to compare algorithmic Model-in-the-Loop (MIL) outputs against auto-generated Embedded Coder C-code execution.


DIRECTORY STRUCTURE
- doc/
  - Architecture.md
  - Requirements.md
- models/
  - CabinTempController.slx
  - CabinTempController_SIL_vs_MIL.slx
- results/
  - Scope_result_SIL.JPG
- src/
  - CabinTempController.c
  - CabinTempController.h
  - CabinTempController_types.h
- .gitignore
- README.md


KEY FEATURES
* Proportional Fan Control: Calculates fan demand using the error between measured cabin temperature and target setpoint.
* Sensor Fault Detection: Monitors temperature inputs to ensure they remain within safe thresholds (-20 C to 60 C).
* Fault Override Logic: Overrides fan speed demand to 0 if a sensor fault is triggered.
* SIL Verification: Verifies auto-generated C-code execution against the MIL algorithm to ensure numerical equivalence.


HOW TO RUN
1. Open MATLAB and set your current working directory to the project folder:
   cd C:\MBD_Project\CabinTempController

2. Open the primary algorithm model:
   open_system('models/CabinTempController.slx')

3. Open and run the SIL verification testbench:
   open_system('models/CabinTempController_SIL.slx')
   sim('CabinTempController_SIL')

4. Double-click the Scope block inside CabinTempController_SIL.slx to view the MIL and SIL signal comparison.
