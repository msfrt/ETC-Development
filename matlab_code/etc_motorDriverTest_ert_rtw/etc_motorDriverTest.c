/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: etc_motorDriverTest.c
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

#include "etc_motorDriverTest.h"
#include "etc_motorDriverTest_private.h"
#include "etc_motorDriverTest_dt.h"

/* Block signals (default storage) */
B_etc_motorDriverTest_T etc_motorDriverTest_B;

/* Block states (default storage) */
DW_etc_motorDriverTest_T etc_motorDriverTest_DW;

/* Real-time model */
RT_MODEL_etc_motorDriverTest_T etc_motorDriverTest_M_;
RT_MODEL_etc_motorDriverTest_T *const etc_motorDriverTest_M =
  &etc_motorDriverTest_M_;

/* Forward declaration for local functions */
static void etc_motorD_SystemCore_release_h(dsp_simulink_MovingAverage_h_T *obj);
static void etc_motorDr_SystemCore_delete_h(dsp_simulink_MovingAverage_h_T *obj);
static void matlabCodegenHandle_matlabCod_h(dsp_simulink_MovingAverage_h_T *obj);
static void etc_motorDri_SystemCore_release(dsp_simulink_MovingAverage_et_T *obj);
static void etc_motorDriv_SystemCore_delete(dsp_simulink_MovingAverage_et_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_et_T *obj);
uint16_T MW_adcBInitFlag = 0;
static void etc_motorD_SystemCore_release_h(dsp_simulink_MovingAverage_h_T *obj)
{
  e_dsp_private_SlidingWindow_h_T *obj_0;
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1L) {
      obj_0->isInitialized = 2L;
    }

    obj->NumChannels = -1L;
  }
}

static void etc_motorDr_SystemCore_delete_h(dsp_simulink_MovingAverage_h_T *obj)
{
  etc_motorD_SystemCore_release_h(obj);
}

static void matlabCodegenHandle_matlabCod_h(dsp_simulink_MovingAverage_h_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    etc_motorDr_SystemCore_delete_h(obj);
  }
}

static void etc_motorDri_SystemCore_release(dsp_simulink_MovingAverage_et_T *obj)
{
  e_dsp_private_SlidingWindowAv_T *obj_0;
  if ((obj->isInitialized == 1L) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1L) {
      obj_0->isInitialized = 2L;
    }

    obj->NumChannels = -1L;
  }
}

static void etc_motorDriv_SystemCore_delete(dsp_simulink_MovingAverage_et_T *obj)
{
  etc_motorDri_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_et_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    etc_motorDriv_SystemCore_delete(obj);
  }
}

/* Model step function */
void etc_motorDriverTest_step(void)
{
  /* local block i/o variables */
  uint16_T rtb_DataTypeConversion2;
  uint16_T rtb_DataTypeConversion;
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[4];
  real_T z;
  real_T csumrev_0[49];
  int16_T z_tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(etc_motorDriverTest_DW.FunctionCallSubsystem1_SubsysRa);

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem1'
   */
  /* S-Function (c2802xadc): '<S1>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcbRegs.ADCSOCFRC1.bit.SOC0 = 1;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
    asm(" RPT #75 || NOP");
    etc_motorDriverTest_B.ADC = (AdcbResultRegs.ADCRESULT0);
  }

  /* MATLABSystem: '<S1>/Moving Average' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion3'
   */
  if (etc_motorDriverTest_DW.obj.TunablePropsChanged) {
    etc_motorDriverTest_DW.obj.TunablePropsChanged = false;
  }

  if (etc_motorDriverTest_DW.obj.pStatistic->isInitialized != 1L) {
    etc_motorDriverTest_DW.obj.pStatistic->isSetupComplete = false;
    etc_motorDriverTest_DW.obj.pStatistic->isInitialized = 1L;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSum = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumRevIndex = 1.0;
    etc_motorDriverTest_DW.obj.pStatistic->isSetupComplete = true;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSum = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumRevIndex = 1.0;
  }

  cumRevIndex = etc_motorDriverTest_DW.obj.pStatistic->pCumRevIndex;
  csum = etc_motorDriverTest_DW.obj.pStatistic->pCumSum;
  csumrev[0] = etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[0];
  csumrev[1] = etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[1];
  csumrev[2] = etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[2];
  csumrev[3] = etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[3];
  csum += (real_T)etc_motorDriverTest_B.ADC;
  z_tmp = (int16_T)cumRevIndex - 1;
  z = csumrev[z_tmp] + csum;
  csumrev[z_tmp] = etc_motorDriverTest_B.ADC;
  if (cumRevIndex != 4.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    csumrev[2] += csumrev[3];
    csumrev[1] += csumrev[2];
    csumrev[0] += csumrev[1];
  }

  etc_motorDriverTest_DW.obj.pStatistic->pCumSum = csum;
  etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[0] = csumrev[0];
  etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[1] = csumrev[1];
  etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[2] = csumrev[2];
  etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[3] = csumrev[3];
  etc_motorDriverTest_DW.obj.pStatistic->pCumRevIndex = cumRevIndex;
  etc_motorDriverTest_B.MovingAverage = z / 5.0;

  /* End of MATLABSystem: '<S1>/Moving Average' */

  /* Product: '<S1>/Divide2' incorporates:
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Constant7'
   *  Product: '<S1>/Divide1'
   *  Sum: '<S1>/Sum'
   */
  etc_motorDriverTest_B.Divide2 = (etc_motorDriverTest_B.MovingAverage -
    etc_motorDriverTest_P.Constant5_Value) *
    (etc_motorDriverTest_P.Constant6_Value /
     etc_motorDriverTest_P.Constant7_Value);

  /* Product: '<S1>/Divide3' incorporates:
   *  Constant: '<S1>/Constant8'
   */
  etc_motorDriverTest_B.Current = etc_motorDriverTest_B.Divide2 /
    etc_motorDriverTest_P.Constant8_Value;

  /* MATLABSystem: '<S1>/Moving Average1' */
  if (etc_motorDriverTest_DW.obj_d.TunablePropsChanged) {
    etc_motorDriverTest_DW.obj_d.TunablePropsChanged = false;
  }

  if (etc_motorDriverTest_DW.obj_d.pStatistic->isInitialized != 1L) {
    etc_motorDriverTest_DW.obj_d.pStatistic->isSetupComplete = false;
    etc_motorDriverTest_DW.obj_d.pStatistic->isInitialized = 1L;
    etc_motorDriverTest_DW.obj_d.pStatistic->pCumSum = 0.0;
    etc_motorDriverTest_DW.obj_d.pStatistic->pCumRevIndex = 1.0;
    etc_motorDriverTest_DW.obj_d.pStatistic->isSetupComplete = true;
    etc_motorDriverTest_DW.obj_d.pStatistic->pCumSum = 0.0;
    memset(&etc_motorDriverTest_DW.obj_d.pStatistic->pCumSumRev[0], 0, 49U *
           sizeof(real_T));
    etc_motorDriverTest_DW.obj_d.pStatistic->pCumRevIndex = 1.0;
  }

  cumRevIndex = etc_motorDriverTest_DW.obj_d.pStatistic->pCumRevIndex;
  csum = etc_motorDriverTest_DW.obj_d.pStatistic->pCumSum;
  for (z_tmp = 0; z_tmp < 49; z_tmp++) {
    csumrev_0[z_tmp] = etc_motorDriverTest_DW.obj_d.pStatistic->pCumSumRev[z_tmp];
  }

  csum += etc_motorDriverTest_B.Current;
  z_tmp = (int16_T)cumRevIndex - 1;
  z = csumrev_0[z_tmp] + csum;
  csumrev_0[z_tmp] = etc_motorDriverTest_B.Current;
  if (cumRevIndex != 49.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (z_tmp = 47; z_tmp >= 0; z_tmp--) {
      csumrev_0[z_tmp] += csumrev_0[z_tmp + 1];
    }
  }

  etc_motorDriverTest_DW.obj_d.pStatistic->pCumSum = csum;
  memcpy(&etc_motorDriverTest_DW.obj_d.pStatistic->pCumSumRev[0], &csumrev_0[0],
         49U * sizeof(real_T));
  etc_motorDriverTest_DW.obj_d.pStatistic->pCumRevIndex = cumRevIndex;
  etc_motorDriverTest_B.AveragedCurrent = z / 50.0;

  /* End of MATLABSystem: '<S1>/Moving Average1' */
  /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  cumRevIndex = floor(etc_motorDriverTest_P.Constant3_Value);
  if (rtIsNaN(cumRevIndex) || rtIsInf(cumRevIndex)) {
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = fmod(cumRevIndex, 256.0);
  }

  rtb_DataTypeConversion2 = (int16_T)cumRevIndex & 255U;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion2' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  cumRevIndex = floor(etc_motorDriverTest_P.Constant1_Value);
  if (rtIsNaN(cumRevIndex) || rtIsInf(cumRevIndex)) {
    cumRevIndex = 0.0;
  } else {
    cumRevIndex = fmod(cumRevIndex, 256.0);
  }

  rtb_DataTypeConversion = (int16_T)cumRevIndex & 255U;

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (c2802xpwm): '<S1>/ePWM' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  {
    EPwm8Regs.TBPRD = (uint16_T)(etc_motorDriverTest_P.Constant2_Value * 1.0E+8 /
      1 / 1);
  }

  /*-- Update CMPA value for ePWM8 --*/
  {
    EPwm8Regs.CMPA.bit.CMPA = (uint16_T)((uint32_T)EPwm8Regs.TBPRD *
      rtb_DataTypeConversion2 * 0.01);
  }

  /*-- Update CMPB value for ePWM8 --*/
  {
    EPwm8Regs.CMPB.bit.CMPB = (uint16_T)((uint32_T)EPwm8Regs.TBPRD *
      rtb_DataTypeConversion * 0.01);
  }

  EPwm8Regs.CMPC = (uint16_T)((real_T)EPwm8Regs.TBPRD * 50.0 * 0.01);

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Constant: '<S1>/Constant4'
   */
  etc_motorDriverTest_B.DataTypeConversion4 =
    (etc_motorDriverTest_P.Constant4_Value != 0.0);

  /* S-Function (c280xgpio_do): '<S1>/Digital Output' */
  {
    if (etc_motorDriverTest_B.DataTypeConversion4)
      GpioDataRegs.GPBSET.bit.GPIO41 = 1;
    else
      GpioDataRegs.GPBCLEAR.bit.GPIO41 = 1;
  }

  etc_motorDriverTest_DW.FunctionCallSubsystem1_SubsysRa = 4;

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator1' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)etc_motorDriverTest_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(etc_motorDriverTest_M)!=-1) &&
        !((rtmGetTFinal(etc_motorDriverTest_M)-
           etc_motorDriverTest_M->Timing.taskTime0) >
          etc_motorDriverTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(etc_motorDriverTest_M, "Simulation finished");
    }

    if (rtmGetStopRequested(etc_motorDriverTest_M)) {
      rtmSetErrorStatus(etc_motorDriverTest_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  etc_motorDriverTest_M->Timing.taskTime0 =
    (++etc_motorDriverTest_M->Timing.clockTick0) *
    etc_motorDriverTest_M->Timing.stepSize0;
}

/* Model initialize function */
void etc_motorDriverTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)etc_motorDriverTest_M, 0,
                sizeof(RT_MODEL_etc_motorDriverTest_T));
  rtmSetTFinal(etc_motorDriverTest_M, -1);
  etc_motorDriverTest_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  etc_motorDriverTest_M->Sizes.checksums[0] = (3876982048U);
  etc_motorDriverTest_M->Sizes.checksums[1] = (902881315U);
  etc_motorDriverTest_M->Sizes.checksums[2] = (716302331U);
  etc_motorDriverTest_M->Sizes.checksums[3] = (3224893194U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    etc_motorDriverTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &etc_motorDriverTest_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[2] = (sysRanDType *)
      &etc_motorDriverTest_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[3] = (sysRanDType *)
      &etc_motorDriverTest_DW.FunctionCallSubsystem1_SubsysRa;
    rteiSetModelMappingInfoPtr(etc_motorDriverTest_M->extModeInfo,
      &etc_motorDriverTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(etc_motorDriverTest_M->extModeInfo,
                        etc_motorDriverTest_M->Sizes.checksums);
    rteiSetTPtr(etc_motorDriverTest_M->extModeInfo, rtmGetTPtr
                (etc_motorDriverTest_M));
  }

  /* block I/O */
  (void) memset(((void *) &etc_motorDriverTest_B), 0,
                sizeof(B_etc_motorDriverTest_T));

  /* states (dwork) */
  (void) memset((void *)&etc_motorDriverTest_DW, 0,
                sizeof(DW_etc_motorDriverTest_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    etc_motorDriverTest_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem1'
   */
  /* Start for S-Function (c2802xadc): '<S1>/ADC' */
  if (MW_adcBInitFlag == 0) {
    InitAdcB();
    MW_adcBInitFlag = 1;
  }

  config_ADCB_SOC0 ();

  /* Start for MATLABSystem: '<S1>/Moving Average' */
  etc_motorDriverTest_DW.obj.matlabCodegenIsDeleted = false;
  etc_motorDriverTest_DW.objisempty = true;
  etc_motorDriverTest_DW.obj.isInitialized = 1L;
  etc_motorDriverTest_DW.obj.NumChannels = 1L;
  etc_motorDriverTest_DW.gobj_0_b.isInitialized = 0L;
  etc_motorDriverTest_DW.obj.pStatistic = &etc_motorDriverTest_DW.gobj_0_b;
  etc_motorDriverTest_DW.obj.isSetupComplete = true;
  etc_motorDriverTest_DW.obj.TunablePropsChanged = false;

  /* Start for MATLABSystem: '<S1>/Moving Average1' */
  etc_motorDriverTest_DW.obj_d.matlabCodegenIsDeleted = false;
  etc_motorDriverTest_DW.objisempty_p = true;
  etc_motorDriverTest_DW.obj_d.isInitialized = 1L;
  etc_motorDriverTest_DW.obj_d.NumChannels = 1L;
  etc_motorDriverTest_DW.gobj_0.isInitialized = 0L;
  etc_motorDriverTest_DW.obj_d.pStatistic = &etc_motorDriverTest_DW.gobj_0;
  etc_motorDriverTest_DW.obj_d.isSetupComplete = true;
  etc_motorDriverTest_DW.obj_d.TunablePropsChanged = false;

  /* Start for S-Function (c2802xpwm): '<S1>/ePWM' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  EALLOW;
  CpuSysRegs.PCLKCR2.bit.EPWM8 = 1;
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;
  EDIS;

  /*** Initialize ePWM8 modules ***/
  {
    /*  // Time Base Control Register
       EPwm8Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm8Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select

       EPwm8Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select
       EPwm8Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm8Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm8Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm8Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm8Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm8Regs.TBCTL.all = (EPwm8Regs.TBCTL.all & ~0x3FFF) | 0x32;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm8Regs.TBPRD = 10000;           // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm8Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm8Regs.TBPHS.all = (EPwm8Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm8Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register
       EPwm8Regs.CMPCTL.bit.SHDWAMODE           = 0;  // Compare A Register Block Operating Mode
       EPwm8Regs.CMPCTL.bit.SHDWBMODE           = 0;  // Compare B Register Block Operating Mode
       EPwm8Regs.CMPCTL.bit.LOADAMODE           = 0;          // Active Compare A Load
       EPwm8Regs.CMPCTL.bit.LOADBMODE           = 0;          // Active Compare B Load
     */
    EPwm8Regs.CMPCTL.all = (EPwm8Regs.CMPCTL.all & ~0x5F) | 0x0;

    /* EPwm8Regs.CMPCTL2.bit.SHDWCMODE           = 0;  // Compare C Register Block Operating Mode

       EPwm8Regs.CMPCTL2.bit.SHDWDMODE           = 0;  // Compare D Register Block Operating Mode
     */
    EPwm8Regs.CMPCTL2.all = (EPwm8Regs.CMPCTL2.all & ~0x50) | 0x0;
    EPwm8Regs.CMPA.bit.CMPA = 0;       // Counter Compare A Register
    EPwm8Regs.CMPB.bit.CMPB = 0;       // Counter Compare B Register
    EPwm8Regs.CMPC = 5000;             // Counter Compare C Register
    EPwm8Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm8Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm8Regs.AQCTLB.all = 2310;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm8Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm8Regs.AQSFRC.all = (EPwm8Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm8Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm8Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm8Regs.AQCSFRC.all = (EPwm8Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm8Regs.DBCTL.bit.OUT_MODE             = 0;          // Dead Band Output Mode Control
       EPwm8Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm8Regs.DBCTL.bit.POLSEL               = 0;          // Polarity Select Control
       EPwm8Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
     */
    EPwm8Regs.DBCTL.all = (EPwm8Regs.DBCTL.all & ~0x803F) | 0x0;
    EPwm8Regs.DBRED.bit.DBRED = 0;
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm8Regs.DBFED.bit.DBFED = 0;
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm8Regs.ETSEL.bit.SOCAEN               = 0;          // Start of Conversion A Enable
       EPwm8Regs.ETSEL.bit.SOCASELCMP = 0;
       EPwm8Regs.ETSEL.bit.SOCASEL              = 0 ;          // Start of Conversion A Select
       EPwm8Regs.ETPS.bit.SOCAPRD               = 1;          // EPWM8SOCA Period Select

       EPwm8Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable

       EPwm8Regs.ETSEL.bit.SOCBSELCMP = 0;
       EPwm8Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm8Regs.ETPS.bit.SOCBPRD               = 1;          // EPWM8SOCB Period Select
       EPwm8Regs.ETSEL.bit.INTEN                = 0;          // EPWM8INTn Enable
       EPwm8Regs.ETSEL.bit.INTSELCMP = 0;
       EPwm8Regs.ETSEL.bit.INTSEL              = 1;          // Start of Conversion A Select

       EPwm8Regs.ETPS.bit.INTPRD                = 1;          // EPWM8INTn Period Select
     */
    EPwm8Regs.ETSEL.all = (EPwm8Regs.ETSEL.all & ~0xFF7F) | 0x1001;
    EPwm8Regs.ETPS.all = (EPwm8Regs.ETPS.all & ~0x3303) | 0x1101;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm8Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm8Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm8Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm8Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm8Regs.PCCTL.all = (EPwm8Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm8Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm8Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM8A
       EPwm8Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM8B
       EPwm8Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM8A action on DCAEVT1
       EPwm8Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM8A action on DCAEVT2
       EPwm8Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM8B action on DCBEVT1
       EPwm8Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM8B action on DCBEVT2
     */
    EPwm8Regs.TZCTL.all = (EPwm8Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm8Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm8Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm8Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm8Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm8Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm8Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm8Regs.TZEINT.all = (EPwm8Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm8Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm8Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm8Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm8Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm8Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm8Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm8Regs.DCACTL.all = (EPwm8Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm8Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm8Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm8Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm8Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm8Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm8Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm8Regs.DCBCTL.all = (EPwm8Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm8Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm8Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1;          // Digital Compare A Low COMP Input Select
       EPwm8Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm8Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1;          // Digital Compare B Low COMP Input Select





     */
    EPwm8Regs.DCTRIPSEL.all = (EPwm8Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x1010;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm8Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm8Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm8Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm8Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm8Regs.TZDCSEL.all = (EPwm8Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm8Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm8Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm8Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm8Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm8Regs.DCFCTL.all = (EPwm8Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm8Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm8Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm8Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm8Regs.DCCAPCTL.all = (EPwm8Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm8Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm8Regs.HRCNFG.bit.SELOUTB             = 0;          // EPWMB Output Selection Bit
     */
    EPwm8Regs.HRCNFG.all = (EPwm8Regs.HRCNFG.all & ~0xA0) | 0x0;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm8Regs.EPWMXLINK.bit.TBPRDLINK = 7;
    EPwm8Regs.EPWMXLINK.bit.CMPALINK = 7;
    EPwm8Regs.EPWMXLINK.bit.CMPBLINK = 7;
    EPwm8Regs.EPWMXLINK.bit.CMPCLINK = 7;
    EPwm8Regs.EPWMXLINK.bit.CMPDLINK = 7;
    EDIS;
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<S1>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFF3FFFF;
  GpioCtrlRegs.GPBDIR.all |= 0x200;
  EDIS;

  /* End of Start for S-Function (fcncallgen): '<Root>/Function-Call Generator1' */

  /* SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem1'
   */
  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
  if (etc_motorDriverTest_DW.obj.pStatistic->isInitialized == 1L) {
    etc_motorDriverTest_DW.obj.pStatistic->pCumSum = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
    etc_motorDriverTest_DW.obj.pStatistic->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S1>/Moving Average' */

  /* InitializeConditions for MATLABSystem: '<S1>/Moving Average1' */
  if (etc_motorDriverTest_DW.obj_d.pStatistic->isInitialized == 1L) {
    etc_motorDriverTest_DW.obj_d.pStatistic->pCumSum = 0.0;
    memset(&etc_motorDriverTest_DW.obj_d.pStatistic->pCumSumRev[0], 0, 49U *
           sizeof(real_T));
    etc_motorDriverTest_DW.obj_d.pStatistic->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S1>/Moving Average1' */
  /* End of SystemInitialize for S-Function (fcncallgen): '<Root>/Function-Call Generator1' */
}

/* Model terminate function */
void etc_motorDriverTest_terminate(void)
{
  /* Terminate for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem1'
   */
  /* Terminate for MATLABSystem: '<S1>/Moving Average' */
  matlabCodegenHandle_matlabCod_h(&etc_motorDriverTest_DW.obj);

  /* Terminate for MATLABSystem: '<S1>/Moving Average1' */
  matlabCodegenHandle_matlabCodeg(&etc_motorDriverTest_DW.obj_d);

  /* End of Terminate for S-Function (fcncallgen): '<Root>/Function-Call Generator1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
