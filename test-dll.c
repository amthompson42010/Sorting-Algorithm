#include <stdio.h>
   #include <stdlib.h>
   #include "dll.h"
   #include "integer.h"

   int main()
       {
       dll *a = newDLL(displayInteger);
    insertDLL(a,0,newInteger(83));
    insertDLL(a,0,newInteger(86));
    insertDLL(a,0,newInteger(77));
    insertDLL(a,0,newInteger(15));
    insertDLL(a,0,newInteger(93));
    insertDLL(a,0,newInteger(35));
    insertDLL(a,0,newInteger(86));
    for(int i = 0; i < 9993; i++)
    {
        insertDLL(a,0,newInteger(4));
    }
    for(int i = 0; i < 10000; i++)
    {
        insertDLL(a,sizeDLL(a),newInteger(1));
    }
    for(int i = 0; i < 19980; i++)
    {
        removeDLL(a,0);
    }
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    removeDLL(a,0);
    displayDLL(stdout,a);
       }