/*
 * scheduler.c
 *
 *  Created on: 04.06.2017
 *      Author: matthias
 */

#include "scheduler.h"

taskControlBlock* currentTask;

void (*scheduler_NextTask)(void) = NULL;
void (*scheduler_enqueueTask)(taskControlBlock* task) = NULL;
void (*scheduler_blockedByRessourceRequest)(LinkedList* ressource) = NULL;
void (*scheduler_ressourceReleased)(LinkedList* ressource) = NULL;

void scheduler_callNextTask(void){
	scheduler_NextTask();
}
