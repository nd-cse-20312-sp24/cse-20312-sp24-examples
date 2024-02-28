CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=
TARGETS=	map_test

all:		$(TARGETS)

%.o:		%.c
	$(CC) $(CFLAGS) -c -o $@ $<

map_test:	pair.o hash.o map.o map_test.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f map_test *.o
