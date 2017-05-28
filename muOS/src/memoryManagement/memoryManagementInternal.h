/*
 * memoryManagementInternal.h
 *
 *  Created on: 24.05.2017
 *      Author: matthias
 */

#ifndef MEMORYMANAGEMENT_MEMORYMANAGEMENTINTERNAL_H_
#define MEMORYMANAGEMENT_MEMORYMANAGEMENTINTERNAL_H_

#include "muOSTypes.h"
#include "memoryManagement.h"

typedef struct{
	uint32_t prev: 12;
	uint32_t next: 12;
	uint32_t size: 8;
}MemoryHead;

typedef struct{
	uint32_t memId;
	uint8_t requestSize;
	uint32_t gapSize;
}MemoryRequest;

typedef struct{
	MemoryHead memoryHead;
}Segment;

//typedef uint32_t (*memoryAlgorithm)(uint32_t);

//void memoryManagement_initModule(memoryAlgorithm m);

void memoryManagement_wipe();
uint32_t memoryManagement_next(MemoryRequest *memoryRequest);
void memoryManagement_initModule(memoryAlgorithm m);
void* memoryManagement_alloc(MemoryRequest *memoryRequest);
void memoryManagement_initMemoryRequest(MemoryRequest *memoryRequest, uint8_t size);


#endif /* MEMORYMANAGEMENT_MEMORYMANAGEMENTINTERNAL_H_ */
