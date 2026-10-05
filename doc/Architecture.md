# Software Architecture Specification: Cabin Temperature Controller

## 1. Architecture Overview
The system consists of a top-level controller model (`CabinTempController.slx`), an algorithmic subsystem (`CabinTemp_Algorithm`), and a Software-in-the-Loop test bench (`CabinTempController_SIL.slx`).

---

## 2. Subsystem Breakdown (`CabinTemp_Algorithm`)

### 2.1 Fault Detection Logic
* **Compare To Constant (`< -20`):** Checks if `Temp_Sensor` is lower than lower limit (-20 °C).
* **Compare To Constant1 (`> 60`):** Checks if `Temp_Sensor` exceeds upper limit (60 °C).
* **Logical Operator (OR):** Combines both boundary checks to produce the `Sensor_Fault` flag output.

### 2.2 Demand Calculation Core
* **Subtract Block:** Computes temperature error as `Temp_Sensor - Setpoint_Temp`.
* **Gain Block (`10`):** Multiplies temperature error by a proportional factor of 10.
* **Saturation Block:** Enforces upper and lower boundary bounds on computed demand.
* **Switch Block:**
  * Control condition: Driven by `Sensor_Fault`.
  * If `Sensor_Fault == 0`: Passes output from Saturation block to `Fan_Speed_Demand`.
  * If `Sensor_Fault == 1`: Passes `Constant (0)` to `Fan_Speed_Demand`.

---

## 3. Verification Architecture (`CabinTempController_SIL.slx`)
* **Model-in-the-Loop (MIL) Block:** Direct algorithmic execution of `CabinTemp_Algorithm`.
* **Software-in-the-Loop (SIL) Block:** C-code auto-generated build (`CabinTempController_ert_rtw`) running via MEX function (`CabinTempController_sbs.mexw64`).
* **Bus Creator / Scope:** Compares MIL vs. SIL outputs in real time to verify code generation equivalence.