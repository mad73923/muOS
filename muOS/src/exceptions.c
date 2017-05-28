/*
 * exceptions.c
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */


#include "exceptions.h"

void kernelPanic(){
	muOS_criticalSection_enter();
	uint32_t calledAt = __builtin_return_address(0);
	while(1){
		asm volatile ("nop");
	}
}
