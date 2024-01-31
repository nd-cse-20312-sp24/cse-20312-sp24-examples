CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=

all:		array_test unit_array

%.o:		%.c array.h
	$(CC) $(CFLAGS) -c -o $@ $<

array_test:	array_test.o array.o
	$(LD) $(LDFLAGS) -o $@ $^

unit_array:	unit_array.o array.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f array_test unit_array *.o
