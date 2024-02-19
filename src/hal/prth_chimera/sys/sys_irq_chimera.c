/******************************************************************************
 *        
 * MODULE NAME:    sys_irq_chimera.c
 * PROJECT CODE:   BlueStream
 * DESCRIPTION:    Chimera (XR7) Hardware Interrupt Interface
 * MAINTAINER:     Ivan Griffin
 * CREATION DATE:  09 August 1999
 *
 * SOURCE CONTROL: $Id: sys_irq_chimera.c,v 1.4 2004/07/07 14:30:49 namarad Exp $
 *
 * LICENSE:
 *     This source code is copyright (c) 2000-2004 Ceva Inc.
 *     All rights reserved.
 *
 * REVISION HISTORY:
 *    09 Aug 1999 -   IG       -  Initial Version
 *    11 Oct 2000 -   IG       -  split sys_irq into Chimera specific code
 *                                and common code -- this is for the
 *                                Chimera platform
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
#include"include.h"


#define IRQ_JALAPENO       0x0004
#define XR7_UART2_IRQ      0x0010
#define IRQ_UART  XR7_UART2_IRQ

#define IRQ_JALAPENO_CTRL  0x306028
#define IRQ_JALAPENO_CLR   0x30602a

//__INLINE__ static u_int32 _SYSirq_Get_Status_FIQ(void)
//{
 //   u_int32 status =  *(u_int16*)XR7_FIQ_ST_ADDR;
//	status &= 0xffff;

//    return (status);
//}
