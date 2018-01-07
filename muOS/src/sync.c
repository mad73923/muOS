/*
 * sync.c
 *
 *  Created on: 09.06.2017
 *      Author: matthias
 */

#include "sync.h"

void semaphore_init(semaphore* sema, uint32_t cntInit){
	sema->semaCnt = cntInit;
	linkedList_init(&sema->waitingTasks);
	linkedList_init(&sema->freedBy);
}

void semaphore_request(semaphore* sema){
	uint32_t state = muOS_criticalSection_enter();
	while(sema->semaCnt <= 0){
		muOS_task_queueWaitingTask(&sema->waitingTasks, currentTask);
		scheduler_blockedByRessourceRequest(&sema->freedBy);
		muOS_criticalSection_leave(state);
		muOS_task_yield();
		state = muOS_criticalSection_enter();
	}
	sema->semaCnt --;
	muOS_criticalSection_leave(state);
}

void semaphore_release(semaphore* sema){
	uint32_t state = muOS_criticalSection_enter();
	sema->semaCnt ++;
	muOS_task_wakeupLinkedTasks(&sema->waitingTasks);
	scheduler_ressourceReleased(&sema->freedBy);
	muOS_criticalSection_leave(state);
}

void signal_init(signal* sig){
	linkedList_init(&sig->waitingTasks);
	linkedList_init(&sig->freedBy);
}

void signal_wait(signal* sig){
	uint32_t state = muOS_criticalSection_enter();
	muOS_task_queueWaitingTask(&sig->waitingTasks, currentTask);
	scheduler_blockedByRessourceRequest(&sig->freedBy);
	muOS_criticalSection_leave(state);
	muOS_task_yield();
}

void signal_send(signal* sig){
	uint32_t state = muOS_criticalSection_enter();
	muOS_task_wakeupLinkedTasks(&sig->waitingTasks);
	scheduler_ressourceReleased(&sig->freedBy);
	muOS_criticalSection_leave(state);
}
