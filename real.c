/**
 * @author: Alexander Mark Thompson
 * @title: CS 201 - Assignment 1 - Real Numbers
 * @description: File with functions that are used to modify real
 *               numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include "real.h"

extern void Fatal(char *, ...);

/**
 * Function to create a new real number
 * @param  x [double number]
 * @return   [a real number]
 */
real *newReal(double x) {
     real *p = malloc(sizeof(real));
     if(p == 0) { Fatal("out of memory\n"); }
     p->value = x;
     return p;
}

/**
 * A function to get a real number's value.
 * @param  v [real number]
 * @return   [real number's value as a double]
 */
double getReal(real *v) {
     return v->value;
}

/**
 * Function to set the value of a real number.
 * @param  v [real number]
 * @param  x [double number]
 * @return   [double number that is the real number's value]
 */
double setReal(real *v, double x) {
     double old = v->value;
     v->value = x;
     return old;
}

/**
 * Function to display a real number.
 * @param fp [a file that is passed in]
 * @param v  [a void type value]
 */
void displayReal(FILE *fp, void *v) {
     fprintf(fp, "%lf", getReal((real *) v));
}

/**
 * Function to free a real number from memory
 * @param v [real number]
 */
void freeReal(real * v) {
     free(v);
}
