CC = gcc
CFLAGS=	-Wall -g -std=gnu99
LD = gcc
LDFLAGS = 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

unit_duplicates: duplicates.o unit_duplicates.o
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm *.o unit_duplicates