#include <stdio.h>
   #include <stdlib.h>
   #include "queue.h"
   #include "integer.h"

   int main()
       {
       queue *a = newQueue(displayInteger);
    enqueue(a,newInteger(86));
    dequeue(a);
    enqueue(a,newInteger(35));
    enqueue(a,newInteger(92));
    dequeue(a);
    enqueue(a,newInteger(27));
    enqueue(a,newInteger(59));
    enqueue(a,newInteger(26));
    dequeue(a);
    enqueue(a,newInteger(36));
    enqueue(a,newInteger(68));
    dequeue(a);
    enqueue(a,newInteger(30));
    enqueue(a,newInteger(23));
    enqueue(a,newInteger(35));
    enqueue(a,newInteger(2));
    dequeue(a);
    enqueue(a,newInteger(67));
    enqueue(a,newInteger(56));
    enqueue(a,newInteger(42));
    dequeue(a);
    dequeue(a);
    enqueue(a,newInteger(37));
    enqueue(a,newInteger(24));
    enqueue(a,newInteger(70));
    enqueue(a,newInteger(26));
    enqueue(a,newInteger(80));
    enqueue(a,newInteger(73));
    enqueue(a,newInteger(70));
    enqueue(a,newInteger(81));
    displayQueue(stdout,a);
       }