/**
 * @author: Alexander Mark Thompson
 * @title: CS 201 - Assignment 1 - Integer Header File
 * @description: Sets up the functions that will be used to modify
 * 				 integers.
 */

#include <stdio.h>

#ifndef __INTEGER_INCLUDED__
#define __INTEGER_INCLUDED__

typedef struct integer
    {
    int value;
    } integer;

extern integer *newInteger(int);
extern int getInteger(integer *);
extern int setInteger(integer *,int);
extern void displayInteger(FILE *,void *);
extern int compareInteger(void *,void *);
extern void freeInteger(integer *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif
