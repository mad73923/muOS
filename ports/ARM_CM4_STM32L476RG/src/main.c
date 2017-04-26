/*
 * main.c
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#include "muOS.h"

volatile uint32_t stack1[256];
volatile uint32_t stack2[256];

taskControlBlock tcb[2];

const int numberOfRegisters = 16;

void task1(void);
void task2(void);

int main(void){
	muOS_hardware_setup();
	//muOS_hardware_int_systick_enable();

	currentTask = 0;

	muOS_task_init(&tcb[0], task1, stack1, 25);
	muOS_task_init(&tcb[1], task2, stack2, 25);

	tcb[0].stackPointer = tcb[0].stackBegin + (tcb[0].stackSize-1);

	__asm("ldr sp, [%0]" :: "r" (&tcb[currentTask].stackPointer));
	__asm("bl task1");

	while(1);
}

void task1(void){
	muOS_hardware_int_systick_enable();
	while(1){
		__asm("NOP");
	}
}

void task2(void){
	while(1){
		__asm("NOP");
	}
}
