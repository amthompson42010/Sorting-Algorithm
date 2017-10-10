/**
 * @author: Alexander Mark Thompson
 * @title: Singly Linked List Library
 * @description: C program that sets up a library for a Singly Linked List.
 */

#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

// Creates a new Singly Linked List node with a given value
static sllNode *newSLLNode(void *value);

// Nodes to used in the inserts and deletes
sllNode *newNode, *current, *temp;

/**
 * Function used to create a new Singly Linked List.
 *
 * @params - Display function
 * @returns - Sinlgly Linked List
 */
sll *newSLL(void (*d)(FILE *,void *))
{
    sll *items = (sll *) malloc(sizeof(sll));
    if (items == 0)
    {
        fprintf(stderr,"out of memory");
        exit(-1);
    }

    // Initializing properties.
    items->head = 0;
    items->tail = 0;
    items->size = 0;
    items->display = d;
    return items;
}

/**
 * Inserts into a Singly Linked List
 * @param items [singly linked list]
 * @param index [integer for the index to insert]
 * @param value [value of node]
 */
void insertSLL(sll *items, int index, void *value)
{
    if((items->size == 0) && (index == 0))
    {
        items->head = newSLLNode(value);
        items->tail = items->head;
        items->head->next = 0;
        ++items->size;
    }
    else if(items->size > 0)
    {
        if(index == 0)
        {
            sllNode *newNode = newSLLNode(value);
            newNode->next = items->head;

            items->head = newNode;

            ++items->size;
        }
        else if(index == items->size)
        {
            sllNode *newNode = newSLLNode(value);
            newNode->next = 0;

            items->tail->next = newNode;
            items->tail = newNode;

            ++items->size;
        }
        else
        {
            sllNode *newNode = newSLLNode(value);

            sllNode *current = items->head;
            int counter = 0;

            while(counter < index - 1)
            {
                current = current->next;
                ++counter;
            }

            newNode->next = current->next;
            current->next = newNode;

            ++items->size;
        }
    }

}

/**
 * Function to remove a node from a singly linked list.
 * @param  items [singly linked list]
 * @param  index [index value of node to be deleted]
 * @return       [deleted node's value]
 */
void *removeSLL(sll *items, int index)
{
    if(index == 0)
    {
        void *value = items->head->value;

        sllNode *temp = items->head;
        items->head = items->head->next;

        free(temp);

        --items->size;

        return value;
    }
    else if(index == items->size - 1)
    {
        void *value = items->tail->value;

        sllNode *temp = items->tail;
        sllNode *current = items->head;
        int counter = 0;

        while(counter < items->size - 2)
        {
            current = current->next;
            ++counter;
        }

        items->tail = current;
        items->tail->next = 0;

        free(temp);

        --items->size;
        return value;
    }
    else
    {
        sllNode *current = items->head;
        int counter = 0;

        while(counter < index - 1)
        {
            current = current->next;
            ++counter;
        }

        void *value = current->next->value;

        sllNode *temp = current->next;

        current->next = current->next->next;

        free(temp);

        --items->size;
        return value;
    }
}

/**
 * Function to join two singly linked lists.
 * @param recipient  [singly linked list]
 * @param donor_list [singly linked list]
 */
void unionSLL(sll *recipient, sll *donor)
{
    if(donor->size == 0)
    {
        return;
    }
    else if(recipient->size == 0)
    {
        recipient->head = donor->head;
        recipient->tail = donor->tail;
        recipient->size = donor->size;
        donor->head = donor->tail = 0;
        donor->size = 0;
        return;
    }
    else
    {
        recipient->tail->next = donor->head;
        recipient->tail = donor->tail;
        recipient->size += donor->size;

        donor->head = donor->tail = 0;
        donor->size = 0;
    }
}

void *getSLL(sll *items, int index)
{
    current = items->head;
    int count = 0;

    if(index == 0)
    {
        return current->value;
    }
    else if(index == items->size)
    {
        return items->tail->value;
    }
    else
    {
        while(count < index)
        {
            // Walking through the list.
            current = current->next;
            count++;
        }
        return current->next->value;
    }
}

/**
 * Function to get the size of a singly linked list.
 * @param  items [singly linked list]
 * @return       [int]
 */
int sizeSLL(sll *items)
{
    return items->size;
}

/**
 * Function to display a singly linked list.
 * @param fp    [where to display the data]
 * @param items [singly linked list]
 */
void displaySLL(FILE *fp, sll *items)
{
    if(items->size == 0)
    {
        fprintf(fp, "[]");
    }
    else if(items->size == 1)
    {
        fprintf(fp, "[");
        items->display(fp, items->head->value);
        fprintf(fp, "]");
    }
    else
    {
        fprintf(fp, "[");
        sllNode *current = items->head;
        while(1) {
            items->display(fp, current->value);
            if(current->next == 0)
            {
                break;
            }
            else
            {
                fprintf(fp,",");
                current = current->next;
            }
        }
        fprintf(fp, "]");
    }
}


/**
 * Function to create a new singly linked list node
 * @param  val [value of node]
 * @return     [singly linked list node]
 */
static sllNode *newSLLNode(void *val)
{
    sllNode *node = (sllNode *) malloc(sizeof(sllNode));
    if(!node) 
    { 
        fprintf(stderr, "out of memory"); exit(-1); 
    }
    node->value = val;
    node->next = 0;
    return node;
}
