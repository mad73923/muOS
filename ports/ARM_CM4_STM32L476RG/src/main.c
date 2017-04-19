/*
 * main.c
 *
 *  Created on: 19.04.2017
 *      Author: matthias
 */

#include "muOS.h"

int main(void){
	muOS_hardware_setup();
	muOS_hardware_int_systick_enable();
	while(1);
}
