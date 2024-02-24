test:		
	@$(MAKE) -sk test-all

test-all: test-circular test-duplicates test-josephus

test-circular:	unit_circular
	./test_circular.sh

test-duplicates: duplicates
	./test_duplicates.sh

test-josephus: josephus
	./test_josephus.sh

all: unit_circular duplicates josephus

#--------- Do not modify anything above this line! -----------------

# TODO: Pattern rule to compile any object file from a C source file
# Use -g flag for debugging, -Wall flag for all warnings, and -c flag
# to compile to object files
%.o:

# TODO: Rule for linking executable unit_circular from object files
unit_circular:

# TODO: Rule for linking executable duplicates from object files
duplicates:

# TODO: Rule for linking executable josephus from object files
josephus:

# TODO: Rule to remove executables unit_circular, duplicates,
# and josephus and all object files
clean:

