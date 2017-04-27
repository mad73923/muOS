/*
 * core.h
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#ifndef PORTS_ARM_CM4_STM32L476RG_INC_CORE_H_
#define PORTS_ARM_CM4_STM32L476RG_INC_CORE_H_

#include "stm32l4xx.h"
#include "muOSTypes.h"

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

volatile uint32_t currentTask;
extern taskControlBlock tcb[2];

__attribute__( ( always_inline ) ) __STATIC_INLINE void muOS_dispatcher(void){
	__asm(
			"push {r4}\n"
			"push {r5}\n"
			"push {r6}\n"
			"push {r7}\n"
			"push {r8}\n"
			"push {r9}\n"
			"push {r10}\n"
			"push {r11}\n"
			);

	__asm("str sp, [%0]" :: "r" (&tcb[currentTask].stackPointer));
	currentTask = (currentTask+1)%2;
	__asm("ldr sp, [%0]" :: "r" (&tcb[currentTask].stackPointer));
	__asm(
			"pop {r11}\n"
			"pop {r10}\n"
			"pop {r9}\n"
			"pop {r8}\n"
			"pop {r7}\n"
			"pop {r6}\n"
			"pop {r5}\n"
			"pop {r4}\n"
			);
	__enable_irq();
	__asm("BX LR");
}

void muOS_core_stack_init(taskControlBlock* tcb);

#endif /* PORTS_ARM_CM4_STM32L476RG_INC_CORE_H_ */
