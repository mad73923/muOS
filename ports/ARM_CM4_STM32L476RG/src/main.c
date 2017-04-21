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

const int numberOfRegisters = 13;

void task1(void);
void task2(void);

int main(void){
	muOS_hardware_setup();
	muOS_hardware_int_systick_enable();

	tcb[0].id = 0;
	tcb[0].stackBegin = stack1;
	tcb[0].stackSize = 256;
	tcb[0].state = READY;
	tcb[0].stackPointer = tcb[0].stackBegin + tcb[0].stackSize;
	tcb[0].stackPointer[tcb[0].stackSize-1] = task1;

	tcb[1].id = 1;
	tcb[1].stackBegin = stack2;
	tcb[1].stackSize = 256;
	tcb[1].state = READY;
	tcb[1].stackPointer = tcb[1].stackBegin + tcb[1].stackSize - numberOfRegisters;
	tcb[0].stackPointer[tcb[0].stackSize-1] = task2;

	__asm("BX LR");

	while(1);
}

void task1(void){
	while(1){
		__asm("NOP");
	}
}

void task2(void){
	while(1){
		__asm("NOP");
	}
}
