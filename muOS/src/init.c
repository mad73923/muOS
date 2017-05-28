/*
 * init.c
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */

#include "init.h"

int main(void){
	muOS_hardware_setup();

	memoryManagement_initModule(firstFit);
	linkedList_initModule();
	return run();
}
