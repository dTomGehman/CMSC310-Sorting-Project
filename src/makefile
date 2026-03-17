# vim: set noexpandtab:
tester: tester.o selectionsort.o quicksort.o
	gcc tester.o selectionsort.o quicksort.o -o tester

testerobj: tester.c
	gcc -c tester.c

selectionsort: selectionsort.c
	gcc -c selectionsort.c -O3

quicksort: quicksort.c
	gcc -c quicksort.c -O3

clean:
	rm tester *.o

