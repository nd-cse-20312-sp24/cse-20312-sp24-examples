CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
LD=		gcc
LDFLAGS=
TARGETS=	unit_stack stack_test pbb_matched

all:		$(TARGETS)

%.o:		%.c stack.h
	$(CC) $(CFLAGS) -c -o $@ $<

unit_stack:	unit_stack.o stack.o array.o
	$(LD) $(LDFLAGS) -o $@ $^

stack_test:	stack_test.o stack.o array.o
	$(LD) $(LDFLAGS) -o $@ $^

pbb_matched:	pbb_matched.o stack.o array.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(TARGETS) *.o
