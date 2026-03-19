# vim: set noexpandtab:

all: datagen datatrans

datagen: datagen.c
	gcc datagen.c -o datagen

datatrans:  datatrans.c ../src/quicksort.c
	gcc datatrans.c ../src/quicksort.c -o datatrans

clean:
	rm datagen datatrans
	if [ -f *.dat ]; then rm *.dat; fi

