/*
 * semaphoreTest.c
 *
 *  Created on: 09.06.2017
 *      Author: matthias
 */

#include "sync.h"
#include "../inc/testTasks.h"

volatile semaphore dummySema;
volatile semaphore dummySema2;
volatile semaphore dummySema3;

static volatile int task1Cnt = 0;
static volatile int task2Cnt = 0;
static volatile int task3Cnt = 0;

void initSemaphoreTest(){
	muOS_task_init(semaphoreTestTask, stack1, stacksize, 1);
	muOS_task_init(semaphoreTestTask, stack2, stacksize, 1);
	muOS_task_init(semaphoreTestTask, stack3, stacksize, 1);
	//initNextTest = &initSignalTest;
}

void semaphoreTestTask(){
	if(currentTask->id == 0){
		semaphore_init(&dummySema, 1);
		semaphore_init(&dummySema2, 0);
		semaphore_init(&dummySema3, 0);
	}
	asm volatile ("nop");
	while(1){
		if(currentTask->id == 0){
			semaphore_request(&dummySema);
			task1Cnt++;
			semaphore_release(&dummySema2);
		}else if(currentTask->id == 1){
			semaphore_request(&dummySema2);
			task2Cnt++;
			semaphore_release(&dummySema3);
		}else if(currentTask->id == 2){
			semaphore_request(&dummySema3);
			task3Cnt++;
			semaphore_release(&dummySema);
		}
		asm volatile ("nop");
		if(task1Cnt - task2Cnt > 1 || task1Cnt - task2Cnt < -1){
			kernelPanic();
		}
		if(task2Cnt - task3Cnt > 1 || task2Cnt - task3Cnt < -1){
			kernelPanic();
		}
		if(task3Cnt > 3){
			break;
		}
	}
	while(1);
}
