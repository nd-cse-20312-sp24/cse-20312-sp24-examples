CC=		gcc
CFLAGS=		-Wall -g -std=gnu99
SOURCES=	$(wildcard *.c)
TARGETS=	$(SOURCES:.c=)

all:	$(TARGETS)

%:	%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS) *.o
