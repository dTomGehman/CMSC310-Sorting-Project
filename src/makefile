# vim: set noexpandtab:
tester: tester.o selectionsort.o quicksort.o mergesort.o
	gcc tester.o selectionsort.o quicksort.o mergesort.o -o tester

testerobj: tester.c
	gcc -c tester.c

selectionsort: selectionsort.c
	gcc -c selectionsort.c -O3

quicksort: quicksort.c
	gcc -c quicksort.c -O3

mergesort: mergesort.c
	gcc - c mergesort.c -03

clean:
	rm tester *.o

