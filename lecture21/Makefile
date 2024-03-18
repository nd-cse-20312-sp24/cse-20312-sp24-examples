CC=		gcc
CFLAGS=		-Wall -g -std=gnu99 -I../lecture07 -I../lecture16
LD=		gcc
LDFLAGS=
TARGETS=	counting_sort bucket_sort

all:		$(TARGETS)

%.o:		%.c
	$(CC) $(CFLAGS) -c -o $@ $<

counting_sort:	../lecture16/utils.o counting_sort.o
	$(LD) $(LDFLAGS) -o $@ $^

bucket_sort:	../lecture07/array.o ../lecture16/utils.o bucket_sort.o
	$(LD) $(LDFLAGS) -o $@ $^

benchmark:	$(TARGETS)
	@time -f "    Merge Sort: %E" ../lecture16/merge_sort
	@time -f "    Quick Sort: %E" ../lecture17/quick_sort
	@time -f " Counting Sort: %E" ./counting_sort
	@time -f "   Bucket Sort: %E" ./bucket_sort

clean:
	rm -f *.o $(TARGETS)
