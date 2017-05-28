/*
 * memoryManagement.h
 *
 *  Created on: 24.05.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_MEMORYMANAGEMENT_H_
#define MUOS_INC_MEMORYMANAGEMENT_H_

#include "muOSTypes.h"
#include "core.h"

typedef uint32_t (*memoryAlgorithm)(uint32_t);
void memoryManagement_initModule(memoryAlgorithm m);

void* alloc(uint32_t size);
void free(uint32_t *ptr);
uint8_t memcopy(uint32_t *origin, uint32_t *destination);

#define numberOfSegments 512

#endif /* MUOS_INC_MEMORYMANAGEMENT_H_ */
