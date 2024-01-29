CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture07
LD=		gcc
LDFLAGS=
TARGETS=	stack_test pbb_matched

all:		$(TARGETS)

%.o:		%.c stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

stack_test:	stack_test.o stack.o ../lecture07/array.o
	$(LD) $(LDFLAGS) -o $@ $^

pbb_matched:	pbb_matched.o stack.o ../lecture07/array.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS) *.o
