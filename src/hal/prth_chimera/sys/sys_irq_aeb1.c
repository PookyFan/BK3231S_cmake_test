/******************************************************************************
 *        
 * MODULE NAME:    sys_irq_aeb1.c
 * PROJECT CODE:   BlueStream
 * DESCRIPTION:    ARM AEB-1 Hardware Interrupt Interface
 * MAINTAINER:     Ivan Griffin
 * CREATION DATE:  09 August 1999
 *
 * SOURCE CONTROL: $Id: sys_irq_aeb1.c,v 1.4 2004/07/07 14:30:49 namarad Exp $
 *
 * LICENSE:
 *     This source code is copyright (c) 2000-2004 Ceva Inc.
 *     All rights reserved.
 *
 * REVISION HISTORY:
 *    09 Aug 1999 -   IG       -  Initial Version
 *    11 Oct 2000 -   IG       -  splitting IRQ handler up into common code
 *                                and platform specific code -- this is for
 *                                ARM AEB-1
 *
 ******************************************************************************/

/******************************************************************************
 *
 * Internal Helper Functions
 * these defines/functions eventually need to get split into a separate
 * file to support multiple ARM targets - the code that remains is
 * common to all ARM7 processors
 *
 ******************************************************************************/

#define AEB1_INT_CTRL_BASE        0xffffa800
#define AEB1_IRQSR                ((volatile u_int32 *)(AEB1_INT_CTRL_BASE + 0x14))
#define AEB1_FIQSR		          ((volatile u_int32 *)(AEB1_INT_CTRL_BASE + 0x18))
#define AEB1_UART1_IRQ		      0x0400
#define IRQ_JALAPENO              0x0002 
#define AEB1_IRQ_JALAPENO_CTRL    0x02000028 
#define AEB1_IRQ_JALAPENO_CLR     0x0200002a 
#define AEB1_IRQ_JALAPENO_ENABLE  0xffffffff

/* Inerrupt Enable Register */
#define AEB1_IRQER                ((volatile u_int32)(AEB1_INT_CTRL_BASE + 0x0c))
#define AEB1_FIQER		          ((volatile u_int32)(AEB1_INT_CTRL_BASE + 0x10))

/* Interrupt Clear Register */
#define AEB1_ICLR                 0xffffa808

/* Interrupt Configuration Register (External) */
#define AEB1_ICR0                 0xffffa800

#define IRQ_UART AEB1_UART1_IRQ

#include "sys_hal_types.h"

//__INLINE__ static u_int32 _SYSirq_Get_Status_FIQ(void)
//{
//    u_int32 status = *(u_int32*)AEB1_FIQSR;
  //  status &= 0xffff;

   // return (status);
//}
