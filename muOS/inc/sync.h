/*
 * sync.h
 *
 *  Created on: 09.06.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_SYNC_H_
#define MUOS_INC_SYNC_H_

#include "linkedList.h"
#include "task.h"
#include "scheduler.h"

typedef volatile struct{
	LinkedList waitingTasks;
	LinkedList freedBy;
	int16_t semaCnt;
}semaphore;

typedef volatile struct{
	LinkedList waitingTasks;
	LinkedList freedBy;
}signal;

extern volatile uint8_t hardwareISR;
extern taskControlBlock* currentTask;

uint8_t enterCriticalSection();
void leaveCriticalSection(uint8_t oldState);

void semaphore_init(semaphore* sema, uint32_t cntInit);
void semaphore_request(semaphore* sema);
void semaphore_release(semaphore* sema);

void signal_init(signal* sig);
void signal_wait(signal* sig);
void signal_send(signal* sig);


#endif /* MUOS_INC_SYNC_H_ */
