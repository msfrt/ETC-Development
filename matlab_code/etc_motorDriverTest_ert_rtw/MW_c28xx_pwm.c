#include "c2000BoardSupport.h"
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"
#include "F2837xS_GlobalPrototypes.h"
#include "rtwtypes.h"
#include "etc_motorDriverTest.h"
#include "etc_motorDriverTest_private.h"

void config_ePWM_GPIO (void)
{
  EALLOW;
  ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 1;

  /*-- Configure pin assignments for ePWM8 --*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO14 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1; /* Configure GPIOGPIO14 as EPWM8A*/
  GpioCtrlRegs.GPAGMUX1.bit.GPIO15 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1; /* Configure GPIOGPIO15 as EPWM8B*/

  /*--- Configure pin assignments for TZn ---*/
  EDIS;
}
