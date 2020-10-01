#include "c2000BoardSupport.h"
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"
#include "F2837xS_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "etc_megaMotoTest.h"
#include "etc_megaMotoTest_private.h"

void init_board ()
{
  DisableDog();
  EALLOW;
  CpuSysRegs.PCLKCR0.bit.DMA = 1;
  EDIS;

#ifdef CPU1

  EALLOW;

  //enable pull-ups on unbonded IOs as soon as possible to reduce power consumption.
  GPIO_EnableUnbondedIOPullups();
  CpuSysRegs.PCLKCR13.bit.ADC_A = 1;
  CpuSysRegs.PCLKCR13.bit.ADC_B = 1;
  CpuSysRegs.PCLKCR13.bit.ADC_C = 1;
  CpuSysRegs.PCLKCR13.bit.ADC_D = 1;

  //check if device is trimmed
  if (*((Uint16 *)0x5D1B6) == 0x0000) {
    //device is not trimmed, apply static calibration values
    AnalogSubsysRegs.ANAREFTRIMA.all = 31709;
    AnalogSubsysRegs.ANAREFTRIMB.all = 31709;
    AnalogSubsysRegs.ANAREFTRIMC.all = 31709;
    AnalogSubsysRegs.ANAREFTRIMD.all = 31709;
  }

  CpuSysRegs.PCLKCR13.bit.ADC_A = 0;
  CpuSysRegs.PCLKCR13.bit.ADC_B = 0;
  CpuSysRegs.PCLKCR13.bit.ADC_C = 0;
  CpuSysRegs.PCLKCR13.bit.ADC_D = 0;
  EDIS;
  InitSysPll(XTAL_OSC,40,0,1);

  //Turn on all peripherals
  //InitPeripheralClocks();
  EALLOW;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER1 = 1;
  CpuSysRegs.PCLKCR0.bit.CPUTIMER2 = 1;
  CpuSysRegs.PCLKCR0.bit.HRPWM = 1;
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
  CpuSysRegs.PCLKCR1.bit.EMIF1 = 1;
  CpuSysRegs.PCLKCR1.bit.EMIF2 = 1;
  EDIS;

#endif

  EALLOW;

  /* Configure low speed peripheral clocks */
  ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 0U;
  EDIS;

  /* Disable and clear all CPU interrupts */
  DINT;
  IER = 0x0000;
  IFR = 0x0000;
  InitPieCtrl();
  InitPieVectTable();
  InitCpuTimers();

  /* initial GPIO qualification settings.... */
  EALLOW;
  GpioCtrlRegs.GPAQSEL1.all = 0x0;
  GpioCtrlRegs.GPAQSEL2.all = 0x0;
  GpioCtrlRegs.GPBQSEL1.all = 0x0;
  GpioCtrlRegs.GPBQSEL2.all = 0x0;
  GpioCtrlRegs.GPCQSEL1.all = 0x0;
  GpioCtrlRegs.GPCQSEL2.all = 0x0;
  GpioCtrlRegs.GPDQSEL1.all = 0x0;
  GpioCtrlRegs.GPDQSEL2.all = 0x0;
  GpioCtrlRegs.GPEQSEL1.all = 0x0;
  GpioCtrlRegs.GPEQSEL2.all = 0x0;
  GpioCtrlRegs.GPFQSEL1.all = 0x0;
  EDIS;
}
