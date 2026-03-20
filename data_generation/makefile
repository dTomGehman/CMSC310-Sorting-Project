# vim: set noexpandtab:

all: datagen datatrans

datagen: datagen.c
	gcc datagen.c -o datagen

datatrans:  datatrans.c ../src/quicksort.c
	gcc datatrans.c ../src/quicksort.c -o datatrans

clean:
	if [ -f datagen ]; then rm datagen; fi
	if [ -f datatrans ]; then rm datatrans; fi
	if [ -f *.dat ]; then rm *.dat; fi
	if [ -d ../data ]; then rm -rf ../data; fi

