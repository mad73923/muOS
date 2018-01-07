/*
 * linkedListTypes.h
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_LINKEDLISTTYPES_H_
#define MUOS_INC_LINKEDLISTTYPES_H_


typedef struct {
	struct ListItem *list;
	struct ListItem *current;
	uint32_t length;
	uint32_t currentIndex;
	uint8_t isIterating;
}LinkedList;

#endif /* MUOS_INC_LINKEDLISTTYPES_H_ */
