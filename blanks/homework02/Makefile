CC = gcc
CFLAGS=	-Wall -std=gnu99 -g
LD = gcc
LDFLAGS = 

test:		
	@$(MAKE) -sk test-all

test-all: test-string_methods test-string_dups

test-string_methods: unit_string_methods
	./test_string_methods.sh

test-string_dups: string_dups
	./test_string_dups.sh

all: unit_string_methods string_dups

#--------- Do not modify above this line -----------------

# TODO: Pattern rule to compile object (.o) files from .c files

unit_string_methods: string_methods.o unit_string_methods.o
	$(LD) $(LDFLAGS) -o $@ $^

# TODO: Rule to build executable string_dups by linking
# string_dups.o and string_methods.o

clean:
	rm *.o unit_string_methods string_dups