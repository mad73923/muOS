/*
 * init.h
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */

#ifndef MUOS_INIT_H_
#define MUOS_INIT_H_



#define TEST

#ifdef TEST
//#include "../../Test/src/test.c"
#else
#include "main.c"
#endif

#include "memoryManagement.h"
#include "../src/memoryManagement/memoryManagementAlgos.h"
#include "linkedList.h"
#include "hardware.h"

#endif /* MUOS_INIT_H_ */
