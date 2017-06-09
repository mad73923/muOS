/*
 * core.c
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#include "core.h"

const uint32_t task_numberOfRegisters = 16;

volatile uint8_t hardRestart __attribute__ ((section (".noinit")));

__attribute__ ((naked)) void SysTick_Handler(void){
	__asm("NOP");
	muOS_dispatcher();
}

void muOS_core_stack_init(taskControlBlock* tcb){
	// set SP
	tcb->stackPointer = tcb->stackBegin + tcb->stackSize - task_numberOfRegisters -2;

	// set R7
	tcb->stackBegin[tcb->stackSize-14] = &tcb->stackBegin[tcb->stackSize-1];

	// set PSR
	tcb->stackBegin[tcb->stackSize-3] = 0x1000200;

	// set PC
	tcb->stackBegin[tcb->stackSize-4] = tcb->taskFunction;

	// set LR
	tcb->stackBegin[tcb->stackSize-5] = -7;
}

void muOS_start(taskControlBlock* startTask){
	currentTask = startTask;
	startTask->stackPointer = startTask->stackBegin + (startTask->stackSize-1-1);
	startTask->stackBegin[startTask->stackSize-1-1] = startTask->taskFunction;
	muOS_hardware_systick_reset();
	muOS_hardware_systick_int_enable();
	__asm("ldr sp, [%0]" :: "r" (&startTask->stackPointer));
	__asm("pop {pc}");
}

void muOS_core_dispatcher_trigger(void){
	SCB->ICSR |= SCB_ICSR_PENDSTSET_Msk;
}

void muOS_core_reboot(void){
	hardRestart = 0;
	muOS_criticalSection_enter();
	NVIC_SystemReset();
}
