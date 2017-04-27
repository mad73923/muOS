/*
 * hardware.h
 *
 *  Created on: 15.04.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_HARDWARE_H_
#define MUOS_INC_HARDWARE_H_

/**
 * This function must be implemented by user.
 * It should set up the hardware (System clock, Flash Latency, etc)
 */
void muOS_hardware_setup(void);
void muOS_hardware_systick_int_enable(void);
void muOS_hardware_systick_reset(void);

#endif /* MUOS_INC_HARDWARE_H_ */
