/**
 * @author: Alexander Mark Thompson
 * @title: Queue Header File
 * @description: Sets up a structure for a Queue, as 
 * 				 well as public functions that will be used to edit
 * 				 a queue.
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "sll.h"
#include <stdio.h>

/**
 * Structure for a queue.
 * Has pointers for the head node, tail node, queue's size, and 
 * display function. The head and tail nodes are sin
 */
typedef struct queue
{
	sll *queueStruct;
} queue;

extern queue *newQueue(void (*d)(FILE *, void *));
extern void enqueue(queue *items, void *value);
extern void *dequeue(queue *items);
extern void *peekQueue(queue *items);
extern int sizeQueue(queue *items);
extern void displayQueue(FILE *fp, queue *items);
extern void unionQueue(queue *recipient, queue *donor);

#endif