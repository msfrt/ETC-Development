/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: etc_megaMotoTest.h
 *
 * Code generated for Simulink model 'etc_megaMotoTest'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Sep 30 21:43:04 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_etc_megaMotoTest_h_
#define RTW_HEADER_etc_megaMotoTest_h_
#include <stddef.h>
#ifndef etc_megaMotoTest_COMMON_INCLUDES_
# define etc_megaMotoTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* etc_megaMotoTest_COMMON_INCLUDES_ */

#include "etc_megaMotoTest_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_etc_megaMotoTest_T {
  const char_T *errorStatus;
};

/* Model entry point functions */
extern void etc_megaMotoTest_initialize(void);
extern void etc_megaMotoTest_step(void);
extern void etc_megaMotoTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_etc_megaMotoTest_T *const etc_megaMotoTest_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 */

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
 * '<Root>' : 'etc_megaMotoTest'
 */
#endif                                 /* RTW_HEADER_etc_megaMotoTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
