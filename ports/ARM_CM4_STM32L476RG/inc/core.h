/*
 * core.h
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#ifndef PORTS_ARM_CM4_STM32L476RG_INC_CORE_H_
#define PORTS_ARM_CM4_STM32L476RG_INC_CORE_H_

#include "stm32l4xx.h"

__attribute__( ( always_inline ) ) __STATIC_INLINE uint32_t muOS_criticalSection_enter(void){
	uint32_t status = __get_PRIMASK();
	__disable_irq();
	return status;
}

__attribute__( ( always_inline ) ) __STATIC_INLINE void muOS_criticalSection_leave(uint32_t status){
	if(!status){
		__enable_irq();
	}
}

//volatile uint32_t currentTask = 0;

__attribute__( ( always_inline ) ) __STATIC_INLINE void muOS_dispatcher(void){
	__asm(
			"push {r0}\n"
			"push {r1}\n"
			"push {r2}\n"
			"push {r3}\n"
			"push {r4}\n"
			"push {r5}\n"
			"push {r6}\n"
			"push {r7}\n"
			"push {r8}\n"
			"push {r9}\n"
			"push {r10}\n"
			"push {r11}\n"
			"push {r12}\n"

			"push {LR}\n"

			"mrs  r0, xPSR\n"
			"push {r0}\n"
			"mrs  r0, PRIMASK\n"
			"push {r0}\n"
			"mrs  r0, FAULTMASK\n"
			"push {r0}\n"
			"mrs  r0, BASEPRI\n"
			"push {r0}\n"
			"mrs  r0, CONTROL\n"
			"push {r0}\n"
			);

	__asm(
			"pop {r0}\n"
			"msr  CONTROL, r0\n"
			"pop {r0}\n"
			"msr  BASEPRI, r0\n"
			"pop {r0}\n"
			"msr  FAULTMASK, r0\n"
			"pop {r0}\n"
			"msr  PRIMASK, r0\n"
			"pop {r0}\n"
			"msr  xPSR, r0\n"

			"pop {LR}\n"

			"pop {r12}\n"
			"pop {r11}\n"
			"pop {r10}\n"
			"pop {r9}\n"
			"pop {r8}\n"
			"pop {r7}\n"
			"pop {r6}\n"
			"pop {r5}\n"
			"pop {r4}\n"
			"pop {r3}\n"
			"pop {r2}\n"
			"pop {r1}\n"
			"pop {r0}\n"
			);
	__enable_irq();
	__asm("BX LR");
}

#endif /* PORTS_ARM_CM4_STM32L476RG_INC_CORE_H_ */
