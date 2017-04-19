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

__attribute__( ( always_inline ) ) __STATIC_INLINE void muOS_dispatcher(void){
	uint32_t irq_status = muOS_criticalSection_enter();

	muOS_criticalSection_leave(irq_status);

}

#endif /* PORTS_ARM_CM4_STM32L476RG_INC_CORE_H_ */
