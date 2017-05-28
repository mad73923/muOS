/*
 * memoryManagementTest.c
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */

#include "memoryManagement.h"
#include "../../muOS/src/memoryManagement/memoryManagementInternal.h"
#include "../inc/testTasks.h"
#include "../../muOS/inc/task.h"
#include "../../muOS/inc/exceptions.h"

void initMemoryManagementTest(){
	muOS_task_init(&tcb[0], memoryManagementTestTask, stack1, stacksize, 0);
}

void alloc5_free_alloc5(){
	Segment* seg1 = (Segment*) alloc(5);
	free(seg1);
	Segment* seg2 = (Segment*) alloc(5);

	if(seg1 != seg2){
		kernelPanic();
	}
}

void tooSmallGap(){
	Segment* seg1 = (Segment*) alloc(4);
	Segment* seg2 = (Segment*) alloc(4);
	Segment* seg3 = (Segment*) alloc(4);
	free(seg2);
	Segment* seg4 = (Segment*) alloc(5);

	if(seg2 == seg4){
		kernelPanic();
	}
}

void fittingGap(){
	Segment* seg1 = (Segment*) alloc(5);
	Segment* seg2 = (Segment*) alloc(5);
	Segment* seg3 = (Segment*) alloc(5);
	free(seg2);
	Segment* seg4 = (Segment*) alloc(5);

	if(seg2 != seg4){
		kernelPanic();
	}
}

void outOfMemory(){
	Segment* seg1 = (Segment*) alloc(800);
	Segment* seg2 = (Segment*) alloc(10000);
	if(seg2 != NULL){
		kernelPanic();
	}

}

void memcopyTest(){
	uint16_t testValue = 555;
	uint16_t* origin = (uint16_t*) alloc(2);
	uint16_t* destination = (uint16_t*) alloc(2);
	*origin = testValue;
	memcopy(origin, destination);
	if(*destination != testValue){
		kernelPanic();
	}
}

void memoryManagementTestTask(){
	alloc5_free_alloc5();
	memoryManagement_wipe();

	tooSmallGap();
	memoryManagement_wipe();

	fittingGap();
	memoryManagement_wipe();

	outOfMemory();
	memoryManagement_wipe();

	memcopyTest();
	memoryManagement_wipe();

	//beerOS_reboot();
	while(1);
}
