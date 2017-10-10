

#include <stdio.h>
   #include <stdlib.h>
   #include "stack.h"
   #include "integer.h"

   int main()
       {
        stack *a = newStack(displayInteger);
    push(a,newInteger(156));
    push(a,newInteger(143));
    push(a,newInteger(182));
    push(a,newInteger(132));
    push(a,newInteger(89));
    push(a,newInteger(100));
    push(a,newInteger(46));
    push(a,newInteger(157));
    push(a,newInteger(50));
    push(a,newInteger(117));
    push(a,newInteger(22));
    pop(a);
    pop(a);
    push(a,newInteger(31));
    pop(a);
    pop(a);
    push(a,newInteger(117));
    push(a,newInteger(15));
    push(a,newInteger(36));
    push(a,newInteger(86));
    push(a,newInteger(130));
    push(a,newInteger(55));
    push(a,newInteger(87));
    push(a,newInteger(136));
    push(a,newInteger(97));
    pop(a);
    pop(a);
    pop(a);
    push(a,newInteger(43));
    push(a,newInteger(68));
    displayStack(stdout,a);
       }