CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=
TARGETS=	table_test

all:		$(TARGETS)

%.o:		%.c
	$(CC) $(CFLAGS) -c -o $@ $<

table_test:	table_test.o table.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f table_test *.o
