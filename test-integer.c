

#include <stdio.h>
   #include <stdlib.h>
   #include "sll.h"
   #include "integer.h"

   static void showItems(sll *items)
       {
       printf("The items are ");
       displaySLL(stdout,items);
       printf(".\n");
       }

   int main(int argc,char **argv)
       {
        sll *a = newSLL(displayInteger);
        insertSLL(a,0,newInteger(83));
        insertSLL(a,0,newInteger(86));
        insertSLL(a,0,newInteger(77));
        insertSLL(a,0,newInteger(15));
        insertSLL(a,0,newInteger(93));
        insertSLL(a,0,newInteger(35));
        insertSLL(a,0,newInteger(86));
        insertSLL(a,0,newInteger(92));
        insertSLL(a,0,newInteger(49));
        insertSLL(a,0,newInteger(21));
        displaySLL(stdout,a);
       }