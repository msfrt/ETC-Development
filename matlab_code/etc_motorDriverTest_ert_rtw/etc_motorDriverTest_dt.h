/*
 * etc_motorDriverTest_dt.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "etc_motorDriverTest".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Oct  8 23:17:39 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(dsp_simulink_MovingAverage_h_T),
  sizeof(e_dsp_private_SlidingWindow_h_T),
  sizeof(dsp_simulink_MovingAverage_et_T),
  sizeof(e_dsp_private_SlidingWindowAv_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "dsp_simulink_MovingAverage_h_T",
  "e_dsp_private_SlidingWindow_h_T",
  "dsp_simulink_MovingAverage_et_T",
  "e_dsp_private_SlidingWindowAv_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&etc_motorDriverTest_B.Divide2), 0, 0, 4 },

  { (char_T *)(&etc_motorDriverTest_B.ADC), 5, 0, 1 },

  { (char_T *)(&etc_motorDriverTest_B.DataTypeConversion4), 8, 0, 1 }
  ,

  { (char_T *)(&etc_motorDriverTest_DW.gobj_0), 17, 0, 2 },

  { (char_T *)(&etc_motorDriverTest_DW.obj), 14, 0, 1 },

  { (char_T *)(&etc_motorDriverTest_DW.obj_d), 16, 0, 1 },

  { (char_T *)(&etc_motorDriverTest_DW.gobj_0_b), 15, 0, 2 },

  { (char_T *)(&etc_motorDriverTest_DW.Scope1_PWORK.LoggedData[0]), 11, 0, 3 },

  { (char_T *)(&etc_motorDriverTest_DW.FunctionCallSubsystem1_SubsysRa), 2, 0, 1
  },

  { (char_T *)(&etc_motorDriverTest_DW.objisempty), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&etc_motorDriverTest_P.Constant5_Value), 0, 0, 8 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] etc_motorDriverTest_dt.h */
