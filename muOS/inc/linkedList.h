/*
 * linkedList.h
 *
 *  Created on: 28.05.2017
 *      Author: matthias
 */

#ifndef MUOS_INC_LINKEDLIST_H_
#define MUOS_INC_LINKEDLIST_H_

#include "muOSTypes.h"
#include "memoryManagement.h"
#include "linkedListTypes.h"
#include "core.h"
#include "exceptions.h"

typedef struct ListItem{
	struct ListItem *next;
	uint8_t *this;
}ListItem;

void linkedList_initModule(void);

uint8_t linkedList_init(LinkedList *linkedList);

uint8_t linkedList_add(LinkedList *linkedList, void *item, uint8_t index);
uint8_t linkedList_append(LinkedList *linkedList, void *item);
//uint8_t insertafter_linkedlist(linkedlist *linkedlist, void *item);
//uint8_t insertbefore_linkedlist(linkedlist *linkedlist, void *item);

void linkedList_remove(LinkedList *linkedList, uint8_t index);
uint8_t linkedList_removeItem(LinkedList *linkedList, void *item);
void linkedList_removeAll(LinkedList *linkedList);

uint8_t linkedList_first(LinkedList *linkedList, void **item);
uint8_t linkedList_last(LinkedList *linkedList, void **item);
uint8_t linkedList_get(LinkedList *linkedList, uint8_t index, void **item);
uint8_t linkedList_iter(LinkedList *linkedList, void **item);

uint32_t linkedList_length(LinkedList *linkedList);
uint8_t linkedList_contains(LinkedList *linkedList, void *item);


#endif /* MUOS_INC_LINKEDLIST_H_ */
