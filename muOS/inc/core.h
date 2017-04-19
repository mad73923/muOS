/*
 * core.h
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_CORE_H_
#define MUOS_INC_CORE_H_

#include "stm32l4xx.h"

__STATIC_INLINE void muOS_dispatcher(void);
__STATIC_INLINE uint32_t muOS_criticalSection_enter(void);
__STATIC_INLINE void muOS_criticalSection_leave(uint32_t status);

#endif /* MUOS_INC_CORE_H_ */
