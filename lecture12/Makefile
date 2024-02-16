all:		test_search

%.o: %.c
	gcc -g -Wall -c -o $@ $<

test_search: test_search.o linear_search.o binary_search.o array.o
	gcc -g -Wall -o $@ $^

clean:
	rm -f test_search *.o
