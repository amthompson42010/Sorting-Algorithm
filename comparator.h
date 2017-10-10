/**
 * @author: Alexander Mark Thompson
 * @title: CS 201 - Assignment 1 - Comparator Header File
 * @description: Sets up the structure for the comparator.c file.
 */

#include "integer.h"
#include "real.h"
#include "string.h"
#include <stdlib.h>
#include <string.h>

#ifndef _COMPARATOR_H_
#define _COMPARATOR_H_

typedef int (*Comparator)(void*,void*);

int intComparator(void *, void *);
int realComparator(void *, void *);
int stringComparator(void *, void *);

#endif
