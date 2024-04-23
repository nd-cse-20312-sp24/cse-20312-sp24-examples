library.o:  	library.c library.h
	$(CC) $(CFLAGS) -o library.o -c library.c

main.o:     	main.c library.h
	$(CC) $(CFLAGS) -o main.o -c main.c

program:    	main.o library.o
	$(CC) $(LDFLAGS) -o program main.o library.o
