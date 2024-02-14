%.o: %.c
	gcc -Wall -g -c -o $@ $^

unit_circular: unit_circular.o circular.o
	gcc -o $@ $^

pointer_chase_list: pointer_chase_list.o
	gcc -o $@ $^

pointer_chase_hash_table: pointer_chase_list.o
	gcc -o $@ $^

print_circular: print_circular.o circular.o
	gcc -o $@ $^

clean:
	rm -f unit_circular pointer_chase_list pointer_chase_hash_table print_circular *.o 
