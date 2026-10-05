/*
 * File: CabinTempController.h
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

#ifndef RTW_HEADER_CabinTempController_h_
#define RTW_HEADER_CabinTempController_h_
#include <stddef.h>
#include <string.h>
#ifndef CabinTempController_COMMON_INCLUDES_
# define CabinTempController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CabinTempController_COMMON_INCLUDES_ */

#include "CabinTempController_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T Temp_Sensor;                /* '<Root>/Temp_Sensor' */
  real32_T Setpoint_Temp;              /* '<Root>/Setpoint_Temp' */
} ExtU_CabinTempController_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real32_T Fan_Speed_Demand;           /* '<Root>/Fan_Speed_Demand' */
  boolean_T Sensor_Fault;              /* '<Root>/Sensor_Fault' */
} ExtY_CabinTempController_T;

/* Parameters (auto storage) */
struct P_CabinTempController_T_ {
  real32_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S2>/Constant'
                                        */
  real32_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S1>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_CabinTempController_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_CabinTempController_T CabinTempController_P;

/* External inputs (root inport signals with auto storage) */
extern ExtU_CabinTempController_T CabinTempController_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_CabinTempController_T CabinTempController_Y;

/* Model entry point functions */
extern void CabinTempController_initialize(void);
extern void CabinTempController_step(void);
extern void CabinTempController_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CabinTempController_T *const CabinTempController_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CabinTempController'
 * '<S1>'   : 'CabinTempController/CabinTemp_Algorithm'
 * '<S2>'   : 'CabinTempController/CabinTemp_Algorithm/Compare To Constant'
 * '<S3>'   : 'CabinTempController/CabinTemp_Algorithm/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_CabinTempController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
