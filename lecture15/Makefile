CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=

all:		bubble_sort insertion_sort selection_sort

%.o:		%.c
	$(CC) $(CFLAGS) -c -o $@ $<

bubble_sort:	bubble_sort.o utils.o
	$(LD) $(LDFLAGS) -o $@ $^

insertion_sort:	insertion_sort.o utils.o
	$(LD) $(LDFLAGS) -o $@ $^

selection_sort:	selection_sort.o utils.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f bubble_sort insertion_sort selection_sort *.o
