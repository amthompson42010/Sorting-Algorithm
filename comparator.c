#include <stdio.h>
#include <stdlib.h>
#include "real.h"
#include <string.h>
#include "integer.h"
#include "string.h"
#include "comparator.h"

/**
 * Function to compare integers
 * @param  a [void type that will be casted as an int]
 * @param  b [void type that will be casted as an int]
 * @return   [a number that tells the int's status
 *            compared to the second int]
 */
int intComparator(void *a, void *b) {

     // casts a and b as ints
     int v1 = getInteger(a);
     int v2 = getInteger(b);

     /**
      Sets 0, -1, or 1 based off status. I do not believe
      it matters on the order that the numbers are as long 
      as it is kept straight in the code. For this I used 
      0 to indicate the values are equal, 1 to indicate
      whether value a is less than b, and -1 to indicate
      whether a is greater than b.
      */
     if(v1 == v2)
     {
        return 0;
     } else if(v1 < v2) {
        return -1;
     } else {
        return 1;
     }
}

/**
 * Function to compare real numbers
 * @param  a [void type that will be casted as a real]
 * @param  b [void type that will be casted as a real]
 * @return   [a number that tells the real's status compared
 *            to the second real]
 */
int realComparator(void *a, void *b) {

     // casts a and b as reals
     double v1 = getReal(a);
     double v2 = getReal(b);

     /**
      Sets 0, -1, or 1 based off status. I do not believe
      it matters on the order that the numbers are as long 
      as it is kept straight in the code. For this I used 
      0 to indicate the values are equal, 1 to indicate
      whether value a is less than b, and -1 to indicate
      whether a is greater than b.
      */
     if(v1 == v2) {
          return 0;
     } else if(v1 < v2) {
          return -1;
     } else {
          return 1;
     }
}

/**
 * Function to compare strings.
 * @param  a [void type that will be casted as a string]
 * @param  b [void type that will be casted as a string]
 * @return   [a number that tells the string's status 
 *            compared to the second string using strcmp.]
 */
int stringComparator(void *a, void *b) {
     char *v1; char *v2;

     // casts a and b to strings
     v1 = getString(a);
     v2 = getString(b);
     return strcmp(v1, v2);
}
