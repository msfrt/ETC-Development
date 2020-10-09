/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: etc_motorDriverTest.h
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

#ifndef RTW_HEADER_etc_motorDriverTest_h_
#define RTW_HEADER_etc_motorDriverTest_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef etc_motorDriverTest_COMMON_INCLUDES_
# define etc_motorDriverTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "c2000BoardSupport.h"
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"
#include "IQmathLib.h"
#include "F2837xS_gpio.h"
#endif                                /* etc_motorDriverTest_COMMON_INCLUDES_ */

#include "etc_motorDriverTest_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void config_ePWM_GPIO (void);

/* Block signals (default storage) */
typedef struct {
  real_T Divide2;                      /* '<S1>/Divide2' */
  real_T Current;                      /* '<S1>/Divide3' */
  real_T MovingAverage;                /* '<S1>/Moving Average' */
  real_T AveragedCurrent;              /* '<S1>/Moving Average1' */
  uint16_T ADC;                        /* '<S1>/ADC' */
  boolean_T DataTypeConversion4;       /* '<S1>/Data Type Conversion4' */
} B_etc_motorDriverTest_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  e_dsp_private_SlidingWindowAv_T gobj_0;/* '<S1>/Moving Average1' */
  e_dsp_private_SlidingWindowAv_T gobj_1;/* '<S1>/Moving Average1' */
  dsp_simulink_MovingAverage_h_T obj;  /* '<S1>/Moving Average' */
  dsp_simulink_MovingAverage_et_T obj_d;/* '<S1>/Moving Average1' */
  e_dsp_private_SlidingWindow_h_T gobj_0_b;/* '<S1>/Moving Average' */
  e_dsp_private_SlidingWindow_h_T gobj_1_o;/* '<S1>/Moving Average' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  int16_T FunctionCallSubsystem1_SubsysRa;/* '<Root>/Function-Call Subsystem1' */
  boolean_T objisempty;                /* '<S1>/Moving Average' */
  boolean_T objisempty_p;              /* '<S1>/Moving Average1' */
} DW_etc_motorDriverTest_T;

/* Parameters (default storage) */
struct P_etc_motorDriverTest_T_ {
  real_T Constant5_Value;              /* Expression: 2210
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 3300
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 4095
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 66
                                        * Referenced by: '<S1>/Constant8'
                                        */
  real_T Constant2_Value;              /* Expression: 0.0001
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_etc_motorDriverTest_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_etc_motorDriverTest_T etc_motorDriverTest_P;

/* Block signals (default storage) */
extern B_etc_motorDriverTest_T etc_motorDriverTest_B;

/* Block states (default storage) */
extern DW_etc_motorDriverTest_T etc_motorDriverTest_DW;

/* Model entry point functions */
extern void etc_motorDriverTest_initialize(void);
extern void etc_motorDriverTest_step(void);
extern void etc_motorDriverTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_etc_motorDriverTest_T *const etc_motorDriverTest_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<Root>' : 'etc_motorDriverTest'
 * '<S1>'   : 'etc_motorDriverTest/Function-Call Subsystem1'
 */
#endif                                 /* RTW_HEADER_etc_motorDriverTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
