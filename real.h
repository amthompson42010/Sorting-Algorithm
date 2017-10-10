/**
 * @author: Alexander Mark Thompson
 * @title: CS 201 - Assignment 1 - Real Numbers Header File
 * @description: File that sets up the structure for the real number
 * 				 functions used in real.c.
 */

#include <stdio.h>

#ifndef _REAL_H_
#define _REAL_H_

typedef struct real {
     double value;
} real;

extern real *newReal(double);
extern double getReal(real *);
extern double setReal(real *, double);
extern void displayReal(FILE *, void *);
extern int compareReal(void *, void *);
extern void freeReal(real *);

#endif
