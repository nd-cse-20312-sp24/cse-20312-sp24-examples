test:		
	@$(MAKE) -sk test-all

test-all: test-list test-merge_sort

test-list:	unit_list
	./test_list.sh

test-merge_sort: merge_sort
	./test_merge_sort.sh

all: unit_list merge_sort

#--------- Do not modify anything above this line! -----------------

# TODO: pattern rule to build any object file (%.o) from its corresponding 
# C source file (%.c).  
%.o: 

#TODO: rule to build executable unit_list
unit_list: 

#TODO: rule to build executable merge sort
merge_sort: 

#TODO: rule to remove all .o files and executables unit_list and merge_sort
clean:
