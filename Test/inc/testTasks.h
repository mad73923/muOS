/*
 * testTasks.h
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */

#ifndef TEST_INC_TESTTASKS_H_
#define TEST_INC_TESTTASKS_H_

#include "muOSTypes.h"

#define stacksize 250

extern void (*initNextTest)(void);

extern uint32_t stack1[stacksize];
extern uint32_t stack2[stacksize];

void initMemoryManagementTest();
void memoryManagementTestTask();

void initLinkedListTest();
void linkedListTestTask();

#endif /* TEST_INC_TESTTASKS_H_ */
