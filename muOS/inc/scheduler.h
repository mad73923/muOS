/*
 * scheduler.h
 *
 *  Created on: 04.06.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_SCHEDULER_H_
#define MUOS_INC_SCHEDULER_H_

#include "../src/scheduler/allScheduler.h"
#include "linkedList.h"
#include "linkedListTypes.h"

void (*scheduler_NextTask)(void);
void (*scheduler_enqueueTask)(taskControlBlock* task);
void (*scheduler_blockedByRessourceRequest)(LinkedList* ressource);
void (*scheduler_ressourceReleased)(LinkedList* ressource);

#endif /* MUOS_INC_SCHEDULER_H_ */
