/*
 * test.c
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */

#include "../inc/test.h"

void (*initNextTest)(void);

uint32_t stack1[stacksize];
uint32_t stack2[stacksize];
uint32_t stack3[stacksize];

void (*initNextTest)(void) __attribute__ ((section (".noinit"))) = &initMemoryManagementTest;
void (*scheduler_init)(void) = &scheduler_initSimpleRR;

int run(void)
{
	if(hardRestart){
		hardRestart = 0;
		initNextTest = &initMemoryManagementTest;
	}
	initNextTest();
	scheduler_init();
	//initIdleTask();
	//initHardware();

	//taskControlBlock* startTask;
	//linkedList_get(&allTasksList, 0, &startTask);

	muOS_start(&tcb[0]);

    while(1)
    {
		kernelPanic();
    }
}
