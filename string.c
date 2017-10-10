/**
 * @author: Alexander Mark Thompson
 * @title: CS 201 - Assignment 1 - String File
 * @description: Functions to modify a string.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "string.h"

extern void Fatal(char *, ...);

/**
 * Function to create a new String.
 * @param  x [char]
 * @return   [string]
 */
string *newString(char *x) {
     string *p = malloc(sizeof(string));
     if(p == 0) { Fatal("out of memory\n"); }
     p->value = malloc(sizeof(strlen(x)));
     strcpy(p->value, x);
     return p;
}

/**
 * Function to get a string's value
 * @param  v [string]
 * @return   [string's value]
 */
char *getString(string *v) {
     return v->value;
}

/**
 * Function to set a String's Value.
 * @param  v [string]
 * @param  x [value]
 * @return   [a string with the new value]
 */
char *setString(string *v, char *x) {
     char *old = malloc(sizeof(strlen(v->value)));
     strcpy(old, v->value);
     free(v->value);
     v->value = malloc(sizeof(strlen(x)));
     strcpy(v->value, x);
     return old;
}

/**
 * Function to display a string.
 * @param fp [a file that is passed in]
 * @param v  [a void type value]
 */
void displayString(FILE *fp, void *v) {
     fprintf(fp, "\"%s\"", getString((string *) v));
}

/**
 * Function to free a string from memory.
 * @param v [string]
 */
void freeString(string *v) {
     free(v);
}
