/**
 * @author: Alexander Mark Thompson
 * @title: Singly Linked List Header File
 * @description: Sets up classes for a node of a singly linked list,
 * 				a class for the linked list itself, and sets up the 
 * 				functions that are to be used in the main SLL file.
*/
#ifndef SLL_H_
#define SLL_H_

#include <stdio.h>
/**
 * Class for a Node for a Singly Linked List.
 * The Node should have values for the node's value
 * and a pointer to the next node in the linked list.
 */
typedef struct sllNode
{
	void *value;
	struct sllNode *next;
} sllNode;

/**
 * Class for the actual Singly Linked List.
 * The list has a head, tail, and size value.
 */
typedef struct sll
{
	sllNode *head;
	sllNode *tail;
	int size;
	void (*display)(FILE *, void *);
} sll;

extern sll *newSLL(void (*d)(FILE *, void *));
extern void insertSLL(sll *list, int index, void *value);

// Stored as a pointer because it needs to return a generic value
extern void *removeSLL(sll *list, int index); 
extern void unionSLL(sll *recipient, sll *donor_list);
extern void *getSLL(sll *items, int index);
extern int sizeSLL(sll *list);
extern void displaySLL(FILE *, sll *list);

#endif