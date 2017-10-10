OBJSS = integer.o sll.o test-integer.o
OBJSD = integer.o dll.o test-dll.o
OBJSQ = integer.o queue.o test-queue.o sll.o
OBJSK = integer.o stack.o test-stack.o dll.o
OOPTS = -Wall -Wextra -g -c -std=c99
LOPTS = -Wall -Wextra -g
SQOBJS = sqsort.o comparator.o reader.o string.o real.o integer.o scanner.o sll.o dll.o stack.o queue.o

sqsort: scanner.o integer.o reader.o real.o string.o queue.o sll.o stack.o dll.o comparator.o sqsort.o
	gcc $(LOPTS) -o sqsort $(SQOBJS)

test-sll : $(OBJSS)
	gcc $(LOPTS) -o test-sll $(OBJSS)

test-dll : $(OBJSD)
	gcc $(LOPTS) -o test-dll $(OBJSD)

test-queue : $(OBJSQ)
	gcc $(LOPTS) -o test-queue $(OBJSQ)

test-stack : $(OBJSK)
	gcc $(LOPTS) -o test-stack $(OBJSK)

sqsort.o: sqsort.c comparator.h stack.h queue.h
	gcc $(OOPTS) sqsort.c

comparator.o: comparator.c comparator.h integer.h string.h real.h
	gcc $(OOPTS) comparator.c

string.o: string.c string.h
	gcc $(OOPTS) string.c

real.o: real.c real.h
	gcc $(OOPTS) real.c

reader.o: reader.c reader.h
	gcc $(OOPTS) reader.c

scanner.o: scanner.c scanner.h
	gcc $(OOPTS) scanner.c

sll.o : sll.c sll.h
	gcc $(OOPTS) sll.c

dll.o : dll.c dll.h
	gcc $(OOPTS) dll.c

queue.o : queue.c queue.h sll.c
	gcc $(OOPTS) queue.c

stack.o : stack.c stack.h dll.c
	gcc $(OOPTS) stack.c

integer.o : integer.c integer.h
	gcc $(OOPTS) integer.c

test-dll.o : test-dll.c integer.h dll.h
	gcc $(OOPTS) test-dll.c

test-queue.o : test-queue.c integer.h sll.c queue.h
	gcc $(OOPTS) test-queue.c

test-stack.o : test-stack.c integer.h dll.c queue.h
	gcc $(OOPTS) test-stack.c

test-sll.o : test-integer.c integer.c sll.c
	gcc $(OOPTS) test-integer.c

clean   :
	rm -f *.o test-sll test-dll test-queue test-stack sqsort

test :
	make
	echo
	echo "testing -v option"
	./sqsort -v
	echo
	echo
	echo "testing singly linked list"
	make test-sll
	./test-sll
	echo
	echo "testing doubly linked list"
	make test-dll
	./test-dll
	echo
	echo "testing queue"
	make test-queue
	./test-queue
	echo
	echo "testing stack"
	make test-stack
	./test-stack
	echo
	echo "testing sorting alogrithm with ints"
	./sqsort -d int_test
	echo
	echo "testing sorting algorithm with same ints"
	./sqsort -d test_same_ints
	echo
	echo "testing sorting algorithm with reals"
	./sqsort -r real_test
	echo
	echo "testing sorting algorithm with strings"
	./sqsort -s string_test
	echo
