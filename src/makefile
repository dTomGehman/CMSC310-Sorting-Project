# vim: set noexpandtab:
tester: tester.o selectionsort.o
	gcc tester.o selectionsort.o -o tester

testerobj: tester.c
	gcc -c tester.c

selectionsort: selectionsort.c
	gcc -c selectionsort.c

clean:
	rm tester *.o

