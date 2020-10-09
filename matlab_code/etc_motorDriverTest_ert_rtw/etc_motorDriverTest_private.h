/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: etc_motorDriverTest_private.h
 *
 * Code generated for Simulink model 'etc_motorDriverTest'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Oct  8 23:17:39 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_etc_motorDriverTest_private_h_
#define RTW_HEADER_etc_motorDriverTest_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

void InitAdcB (void);
void config_ADCB_SOC0 (void);
extern uint16_T MW_adcBInitFlag;

#endif                           /* RTW_HEADER_etc_motorDriverTest_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
