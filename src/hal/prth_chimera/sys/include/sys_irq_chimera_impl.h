#ifndef _PARTHUS_SYS_IRQ_CHIMERA_IMPL
#define _PARTHUS_SYS_IRQ_CHIMERA_IMPL


/***********************************************************************
 *
 * MODULE NAME:    sys_irq_chimera_impl.h
 * PROJECT CODE:   BlueStream
 * MAINTAINER:     John Sheehy
 * DATE:           Header placed here on 24th April 2001
 *
 * SOURCE CONTROL: $Id: sys_irq_chimera_impl.h,v 1.5 2004/07/07 14:30:50 namarad Exp $
 *
 * LICENCE:
 *    This source code is copyright (c) 2001-2004 Ceva Inc.
 *    All rights reserved.
 *
 * REVISION HISTORY:
 *                 Initial date - see sys_irq.h
 *                 Fixed for new transport plane (clean UART choice 
 *                 mechanism) and cleaned up by JS 
 *
 ***********************************************************************/
#include "sys_types.h"
#include "sys_config.h"
#include "sys_irq.h"

#include "BK3231S_reg.h"
//#include "hcit_chimera_16550_serial.h"


//#define XR7_FIQ_MAP_ADDR   0x1021c
//#define XR7_FIQ_MSK_ADDR   0x10204
//#define XR7_IRQ_MAP_ADDR   0x10218
//#define XR7_IRQ_MSK_ADDR   0x10214
//#define XR7_INTCFG_ADDR    0x1022c
//#define XR7_IRQCLR_ADDR    0x10228
//#define XR7_FIQ_ST_ADDR    0x10200
//#define XR7_IRQ_ST_ADDR    0x1020C

//#define IRQ_JALAPENO       0x0004
//#define XR7_UART1_IRQ      0x0008
//#define XR7_UART2_IRQ      0x0010


//#if XR7_HCIT_UART == 1
//#define IRQ_HCIT_UART XR7_UART1_IRQ
//#elif XR7_HCIT_UART == 2
//#define IRQ_HCIT_UART XR7_UART2_IRQ
//#endif

//#define IRQ_JALAPENO_CTRL  0x306028
//#define IRQ_JALAPENO_CLR   0x30602a


//__INLINE__ u_int32 _SYSirq_Get_Status_FIQ(void)
//{
 //   u_int32 status =  *(u_int16*)XR7_FIQ_ST_ADDR;
//	status &= 0xffff;

//   return (status);
 // return 0;
//}

static inline void _SYSirq_Clear_IRQ(u_int32 status)
{
  //  *(u_int16*)XR7_IRQCLR_ADDR = status;
    REG_AHB0_ICU_INT_STATUS_FLAG=status;
  
}

#endif	/* _PARTHUS_SYS_IRQ_CHIMERA_IMPL */
