/*
 * File: CabinTempController.c
 *
 * Code generated for Simulink model 'CabinTempController'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Tue Sep 22 14:26:46 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Generic->64-bit Embedded Processor (LLP64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CabinTempController.h"
#include "CabinTempController_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_CabinTempController_T CabinTempController_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_CabinTempController_T CabinTempController_Y;

/* Real-time model */
RT_MODEL_CabinTempController_T CabinTempController_M_;
RT_MODEL_CabinTempController_T *const CabinTempController_M =
  &CabinTempController_M_;

/* Model step function */
void CabinTempController_step(void)
{
  boolean_T rtb_LogicalOperator;
  real32_T u0;

  /* Outputs for Atomic SubSystem: '<Root>/CabinTemp_Algorithm' */
  /* Logic: '<S1>/Logical Operator' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/Temp_Sensor'
   *  RelationalOperator: '<S2>/Compare'
   *  RelationalOperator: '<S3>/Compare'
   */
  rtb_LogicalOperator = ((CabinTempController_U.Temp_Sensor <
    CabinTempController_P.CompareToConstant_const) ||
    (CabinTempController_U.Temp_Sensor >
     CabinTempController_P.CompareToConstant1_const));

  /* Switch: '<S1>/Switch' */
  if (rtb_LogicalOperator) {
    /* Outport: '<Root>/Fan_Speed_Demand' incorporates:
     *  Constant: '<S1>/Constant'
     */
    CabinTempController_Y.Fan_Speed_Demand =
      CabinTempController_P.Constant_Value;
  } else {
    /* Gain: '<S1>/Gain' incorporates:
     *  Inport: '<Root>/Setpoint_Temp'
     *  Inport: '<Root>/Temp_Sensor'
     *  Sum: '<S1>/Subtract'
     */
    u0 = (CabinTempController_U.Setpoint_Temp -
          CabinTempController_U.Temp_Sensor) * CabinTempController_P.Gain_Gain;

    /* Saturate: '<S1>/Saturation' */
    if (u0 > CabinTempController_P.Saturation_UpperSat) {
      /* Outport: '<Root>/Fan_Speed_Demand' */
      CabinTempController_Y.Fan_Speed_Demand =
        CabinTempController_P.Saturation_UpperSat;
    } else if (u0 < CabinTempController_P.Saturation_LowerSat) {
      /* Outport: '<Root>/Fan_Speed_Demand' */
      CabinTempController_Y.Fan_Speed_Demand =
        CabinTempController_P.Saturation_LowerSat;
    } else {
      /* Outport: '<Root>/Fan_Speed_Demand' */
      CabinTempController_Y.Fan_Speed_Demand = u0;
    }

    /* End of Saturate: '<S1>/Saturation' */
  }

  /* End of Switch: '<S1>/Switch' */
  /* End of Outputs for SubSystem: '<Root>/CabinTemp_Algorithm' */

  /* Outport: '<Root>/Sensor_Fault' */
  CabinTempController_Y.Sensor_Fault = rtb_LogicalOperator;
}

/* Model initialize function */
void CabinTempController_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(CabinTempController_M, (NULL));

  /* external inputs */
  (void) memset((void *)&CabinTempController_U, 0,
                sizeof(ExtU_CabinTempController_T));

  /* external outputs */
  (void) memset((void *)&CabinTempController_Y, 0,
                sizeof(ExtY_CabinTempController_T));
}

/* Model terminate function */
void CabinTempController_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
