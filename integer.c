/**
 * @author: Alexander Mark Thompson
 * @title: CS 201 - Assignment 1 - Integer File
 * @description: File that contains functions that are used to modify
 *               integers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include "integer.h"

extern void Fatal(char *,...);

/**
 * Function that sets up a new Integer.
 */
integer *
newInteger(int x)
    {
    integer *p = malloc(sizeof(integer));
    if (p == 0) Fatal("out of memory\n");
    p->value = x;
    return p;
    }

/**
 * Function to get the value of an integer.
 */
int 
getInteger(integer *v)
    {
    return v->value;
    }

/**
 * Function to set an integer's value.
 */
int 
setInteger(integer *v,int x)
    {
    int old = v->value;
    v->value = x;
    return old;
    }

/**
 * Function that displays an integer.
 */
void 
displayInteger(FILE *fp,void *v)
    {
    fprintf(fp,"%d",getInteger((integer *) v));
    }

/**
 * Function to free an integer from memory.
 */
void
freeInteger(integer *v)
    {
    free(v);
    }

/**
 * Function to return an eror message.
 */
void
Fatal(char *fmt, ...)
    {
    va_list ap;

    fprintf(stderr,"An error occured: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);

    exit(-1);
    }