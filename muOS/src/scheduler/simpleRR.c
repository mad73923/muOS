/*
 * simpleRR.c
 *
 *  Created on: 04.06.2017
 *      Author: matthias
 */

#include "muOSTypes.h"
#include "allScheduler.h"

void simpleRR_nextTask(){
	uint32_t task;
	uint32_t numberOfTasks = linkedList_length(&allTasksList);
	do{
		task = (currentTask->id + 1)% numberOfTasks;
		linkedList_get(&allTasksList, task, &currentTask);
	}while (currentTask->state == WAITING);
}

void simpleRR_enqueueTask(taskControlBlock* task){

}

void simpleRR_blockedByRessourceRequest(LinkedList* resFreedBy){

}

void simpleRR_ressourceReleased(LinkedList* resFreedBy){

}

void scheduler_initSimpleRR(){
	scheduler_NextTask = &simpleRR_nextTask;
	scheduler_enqueueTask = &simpleRR_enqueueTask;
	scheduler_blockedByRessourceRequest = &simpleRR_blockedByRessourceRequest;
	scheduler_ressourceReleased = &simpleRR_ressourceReleased;
}
