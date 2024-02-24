CC=	gcc
CFLAGS=	-Wall -std=gnu99 -g
LD=	gcc
LDFLAGS=

test:		
	@$(MAKE) -sk test-all

test-all:	test-array test-stack test-set test-rpn test-palindromic

test-array:	unit_array
	./test_array.sh

test-stack:	unit_stack
	./test_stack.sh

test-set: unit_set
	./test_set.sh

test-rpn: rpn
	./test_rpn.sh

test-palindromic: palindromic
	./test_palindromic.sh

all:		rpn unit_array unit_set palindromic

#--------- Do not modify anything above this line -----------------

# TODO: Pattern rule for object files

# TODO: Rule for unit_array

# TODO: Rule for unit_stack

# TODO: Rule for unit_set

# TODO: Rule for rpn

# TODO: Rule for palindromic

clean:
	rm -f rpn palindromic unit_array unit_stack unit_set *.o *.o
