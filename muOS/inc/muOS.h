/*
 * muOS.h
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_MUOS_H_
#define MUOS_INC_MUOS_H_

#include "hardware.h"
#include "core.h"


// Dispatcher variables
volatile uint32_t isHardwareTriggered = 1;

// Task control block
typedef enum {READY, RUNNING, WAITING, KILLED} taskstate;

typedef volatile struct strucTCB{
	volatile uint32_t prio;
	volatile uint32_t id;
	volatile uint32_t* stackPointer;
	volatile uint32_t* stackBegin;
	volatile uint32_t stackSize;
	volatile uint32_t waitUntil;
	volatile uint32_t tmpPrio;
	volatile taskstate state;
}taskControlBlock;

#endif /* MUOS_INC_MUOS_H_ */
