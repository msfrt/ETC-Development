/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: etc_megaMotoTest.c
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

#include "etc_megaMotoTest.h"
#include "etc_megaMotoTest_private.h"

/* Real-time model */
RT_MODEL_etc_megaMotoTest_T etc_megaMotoTest_M_;
RT_MODEL_etc_megaMotoTest_T *const etc_megaMotoTest_M = &etc_megaMotoTest_M_;

/* Model step function */
void etc_megaMotoTest_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void etc_megaMotoTest_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(etc_megaMotoTest_M, (NULL));
}

/* Model terminate function */
void etc_megaMotoTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
