# Software Requirements Specification: Cabin Temperature Controller
## 1. System Overview
The Cabin Temperature Controller monitors cabin temperature relative to a target setpoint and calculates the required fan speed demand. It incorporates safety thresholds to detect temperature sensor faults and override fan operation when a fault occurs.
---
## 2. Inputs & Outputs
### Inputs
* **Temp_Sensor** (single): Measured cabin temperature in degrees Celsius (°C).
* **Setpoint_Temp** (single): Desired target temperature setpoint in degrees Celsius (°C).
### Outputs
* **Fan_Speed_Demand** (single): Calculated fan speed output.
* **Sensor_Fault** (boolean): High (1) when temperature reading is out of valid range, otherwise Low (0).
---
## 3. Calibration Parameters & Limits

| Parameter / Limit | Value | Description |
| :--- | :--- | :--- |
| **Temp_Min_Limit** | -20.0 °C | Minimum valid sensor operating threshold |
| **Temp_Max_Limit** | 60.0 °C | Maximum valid sensor operating threshold |
| **Kp_gain** | 10.0 | Proportional gain for temperature error |
| **Fault_Override_Val** | 0.0 | Safe fan speed command when fault is detected |

---
## 4. Functional Requirements
### 4.1 Sensor Fault Detection
* **REQ-FAULT-01 (Out of Bounds Low):** If `Temp_Sensor < -20.0 °C`, `Sensor_Fault` shall be set to `1` (True).
* **REQ-FAULT-02 (Out of Bounds High):** If `Temp_Sensor > 60.0 °C`, `Sensor_Fault` shall be set to `1` (True).
* **REQ-FAULT-03 (Normal Operation):** If `-20.0 °C <= Temp_Sensor <= 60.0 °C`, `Sensor_Fault` shall remain `0` (False).
### 4.2 Control Algorithm & Output
* **REQ-CTRL-01 (Error & Fan Demand Calculation):**
  When `Sensor_Fault == 0`, fan speed output shall be calculated as:
  `Fan_Speed_Demand = (Temp_Sensor - Setpoint_Temp) * 10.0`
* **REQ-CTRL-02 (Fault Override):**
  When `Sensor_Fault == 1`, `Fan_Speed_Demand` shall be overridden and forced to `0.0`.