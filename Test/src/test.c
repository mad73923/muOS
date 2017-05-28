/*
 * test.c
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */

#include "../inc/test.h"

void (*initNextTest)(void);

uint32_t stack1[250];
uint32_t stack2[250];

taskControlBlock tcb[2];

int run(void)
{
//	initNextTest = &initLinkedListTest;
	//initNextTest();

/*
#ifdef RebootTest
	initTask(1, task1Stack, rebootTestTask, stacksize);
#endif
*/


	//initIdleTask();
	//initHardware();

	//taskControlBlock* startTask;
	//linkedList_get(&allTasksList, 0, &startTask);
	//initMemoryManagementTest();
	initLinkedListTest();
	muOS_start(&tcb[0]);

    while(1)
    {
		kernelPanic();
    }
}
