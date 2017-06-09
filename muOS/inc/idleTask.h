/*
 * idleTask.h
 *
 *  Created on: 04.06.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_IDLETASK_H_
#define MUOS_INC_IDLETASK_H_

#include "core.h"
#include "task.h"
#include "muOSTypes.h"

#define idleTaskStackSize 512

void idleTask_init(void);

#endif /* MUOS_INC_IDLETASK_H_ */
