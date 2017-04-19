/*
 * core.c
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#include "core.h"

void __attribute__ ((naked)) SysTick_Handler(void){
	asm("NOP");
	//muOS_dispatcher();
}


static inline void muOS_dispatcher(void){
	uint32_t irq_status = muOS_criticalSection_enter();

	muOS_criticalSection_leave(irq_status);

}

static inline uint32_t muOS_criticalSection_enter(void){
	uint32_t status = __get_PRIMASK();
	__disable_irq();
	return status;
}

static inline void muOS_criticalSection_leave(uint32_t status){
	if(status)
		__enable_irq();
}
