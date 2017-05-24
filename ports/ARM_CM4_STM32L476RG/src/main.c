/*
 * main.c
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#include "muOS.h"

volatile uint32_t stack1[25];
volatile uint32_t stack2[25];

taskControlBlock tcb[2];

const int numberOfRegisters = 16;

volatile uint64_t cntT1, cntT2;

void task1(void);
void task2(void);

int main(void){
	muOS_hardware_setup();

	muOS_task_init(&tcb[0], task1, stack1, 25);
	muOS_task_init(&tcb[1], task2, stack2, 25);

	muOS_start(&tcb[0]);

	while(1);
}

void task1(void){
	while(1){
		while(SysTick->VAL>40);
		muOS_task_yield();
		cntT1++;
	}
}

void task2(void){
	while(1){
		__asm("NOP");
		cntT2++;
	}
}
