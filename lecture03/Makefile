CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=	-L.
TARGETS=	duplicates1 duplicates2 duplicates3

all:	$(TARGETS)

duplicates%:	duplicates%.o library.o
	$(LD) $(LDFLAGS) -o $@ $^

%.o:	%.c library.h
	$(CC) $(CFLAGS) -c -o $@ $<

test-duplicates%:	duplicates%
	for i in $$(seq 1000); do ./$<; done | time -f "\nElapsed: %E" uniq -c

clean:
	rm -f $(TARGETS) *.o
