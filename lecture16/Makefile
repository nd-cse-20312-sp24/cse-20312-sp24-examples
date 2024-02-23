all: sort_driver

%.o: %.c
	gcc -Wall -std=gnu99 -O2 -c -o $@ $^

sort_driver: 	utils.o sort_driver.o \
				bubblesort.o selectionsort.o insertionsort.o \
				mergesort.o quicksort.o
	gcc -o $@ $^

clean:
	rm -f *.o sort_driver

