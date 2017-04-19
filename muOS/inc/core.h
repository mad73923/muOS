/*
 * core.h
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_CORE_H_
#define MUOS_INC_CORE_H_

#include "stm32l4xx.h"

static inline void muOS_dispatcher(void);
static inline uint32_t muOS_criticalSection_enter(void);
static inline void muOS_criticalSection_leave(uint32_t status);

#endif /* MUOS_INC_CORE_H_ */
