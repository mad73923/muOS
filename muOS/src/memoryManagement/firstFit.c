/*
 * firstFit.c
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */


#include "memoryManagementInternal.h"
#include "memoryManagementAlgos.h"

uint32_t firstFit(uint16_t size){
	MemoryRequest memoryRequest;
	memoryManagement_initMemoryRequest(&memoryRequest, size);
	uint32_t memId = 0;
	while(memId = memoryManagement_next(&memoryRequest)){
		memoryRequest.memId = memId;
		return memoryManagement_alloc(&memoryRequest);
	}
	return NULL;
}
