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

	tcb[0].id = 0;
	tcb[0].stackBegin = stack1;
	tcb[0].stackSize = 20;
	//tcb[0].state = READY;
	//canary
	tcb[0].stackBegin[0] = 0xAAAAAAAA;
	tcb[0].stackBegin[tcb[0].stackSize-1] = 0xAAAAAAAA;

	tcb[0].stackPointer = tcb[0].stackBegin + (tcb[0].stackSize-1);

	tcb[1].id = 1;
	tcb[1].stackBegin = stack2;
	tcb[1].stackSize = 20;
	//tcb[1].state = READY;
	//canary
	tcb[1].stackBegin[0] = 0xAAAAAAAA;
	tcb[1].stackBegin[tcb[1].stackSize-1] = 0xAAAAAAAA;

	tcb[1].stackPointer = tcb[1].stackBegin + (tcb[1].stackSize - numberOfRegisters-1);
	//R7
	tcb[1].stackBegin[tcb[1].stackSize-1-12] = &tcb[1].stackBegin[tcb[1].stackSize-1];
	//PSR
	tcb[1].stackBegin[tcb[1].stackSize-1-1] = 0x1000200;
	//PC
	tcb[1].stackBegin[tcb[1].stackSize-1-2] = task2;
	//LR
	tcb[1].stackBegin[tcb[1].stackSize-1-3] = -7;

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
