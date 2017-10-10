/**
 * @author: Alexander Mark Thompson
 * @title: Queue Library File
 * @description: Functions to structure a queue with a singly linked list.
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "sll.h"

/**
 * Function to create a new queue with a singly linked list.
 */
queue *newQueue(void (*d)(FILE *, void *))
{
	queue *newQueueStruct = (queue *)malloc(sizeof(queue));
	newQueueStruct->queueStruct = newSLL(d);
	return newQueueStruct;
}

/**
 * Function to enqueing data into the queue.
 * @param items [queue]
 * @param value [value of the node]
 */
void enqueue(queue *items, void *value)
{
	if(!items->queueStruct->size)
	{
		insertSLL(items->queueStruct, 0, value);
		return;
	}
	insertSLL(items->queueStruct, items->queueStruct->size, value);
}

/**
 * Function to dequeue a node.
 * @param  items [queue]
 * @return       [the node being removed]
 */
void *dequeue(queue *items)
{
	return removeSLL(items->queueStruct, 0);
}

/**
 * Function to get the first value of the queue.
 * @param  items [queue]
 * @return       [head's value]
 */
void *peekQueue(queue *items)
{
	return items->queueStruct->head->value;
}

/**
 * Function to get the size of a queue
 * @param  items [queue]
 * @return       [int]
 */
int sizeQueue(queue *items)
{
	return (items->queueStruct->size);
}

void unionQueue(queue *recipient, queue *donor) 
{
     unionSLL(recipient->queueStruct, donor->queueStruct);
}

/**
 * Function to display the queue
 * @param fp    [where to display the data]
 * @param items [queue]
 */
void displayQueue(FILE *fp, queue *items)
{
	displaySLL(fp, items->queueStruct);
}