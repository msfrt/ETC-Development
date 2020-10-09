/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: etc_motorDriverTest_types.h
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

#ifndef RTW_HEADER_etc_motorDriverTest_types_h_
#define RTW_HEADER_etc_motorDriverTest_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_e_dsp_private_SlidingWindowAv_T
#define typedef_e_dsp_private_SlidingWindowAv_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[49];
  real_T pCumRevIndex;
} e_dsp_private_SlidingWindowAv_T;

#endif                               /*typedef_e_dsp_private_SlidingWindowAv_T*/

#ifndef typedef_e_dsp_private_SlidingWindow_h_T
#define typedef_e_dsp_private_SlidingWindow_h_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[4];
  real_T pCumRevIndex;
} e_dsp_private_SlidingWindow_h_T;

#endif                               /*typedef_e_dsp_private_SlidingWindow_h_T*/

#ifndef typedef_c_cell_wrap_etc_motorDriverTe_T
#define typedef_c_cell_wrap_etc_motorDriverTe_T

typedef struct {
  uint32_T f1[8];
} c_cell_wrap_etc_motorDriverTe_T;

#endif                               /*typedef_c_cell_wrap_etc_motorDriverTe_T*/

#ifndef typedef_dsp_simulink_MovingAverage_et_T
#define typedef_dsp_simulink_MovingAverage_et_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  c_cell_wrap_etc_motorDriverTe_T inputVarSize;
  e_dsp_private_SlidingWindowAv_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_et_T;

#endif                               /*typedef_dsp_simulink_MovingAverage_et_T*/

#ifndef typedef_dsp_simulink_MovingAverage_h_T
#define typedef_dsp_simulink_MovingAverage_h_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  c_cell_wrap_etc_motorDriverTe_T inputVarSize;
  e_dsp_private_SlidingWindow_h_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_h_T;

#endif                                /*typedef_dsp_simulink_MovingAverage_h_T*/

/* Parameters (default storage) */
typedef struct P_etc_motorDriverTest_T_ P_etc_motorDriverTest_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_etc_motorDriverTest_T RT_MODEL_etc_motorDriverTest_T;

#endif                             /* RTW_HEADER_etc_motorDriverTest_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
