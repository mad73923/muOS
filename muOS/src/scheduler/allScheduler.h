/*
 * allScheduler.h
 *
 *  Created on: 04.06.2017
 *      Author: matthias
 */

#ifndef SCHEDULER_ALLSCHEDULER_H_
#define SCHEDULER_ALLSCHEDULER_H_

#include "muOSTypes.h"
#include "scheduler.h"
#include "linkedList.h"
#include "linkedListTypes.h"

extern volatile LinkedList allTasksList;

extern void (*scheduler_NextTask)(void);
extern void (*scheduler_enqueueTask)(taskControlBlock* task);
extern void (*scheduler_blockedByRessourceRequest)(LinkedList* ressource);
extern void (*scheduler_ressourceReleased)(LinkedList* ressource);

void scheduler_initSimpleRR();
//void scheduler_initPrioRR();
//void scheduler_initPrioInheritance();


#endif /* SCHEDULER_ALLSCHEDULER_H_ */
