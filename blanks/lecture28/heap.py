#!/usr/bin/env python3

def bubble_up(heap: list[int], index: int) -> None:
    pass
        
def bubble_down(heap: list[int], index: int) -> None:
    length = len(heap)
    left_child = 2*index + 1
    # while not at a leaf node
    while left_child < length:
        right_child = left_child + 1
        high_child = left_child
        if right_child < length and heap[right_child] > heap[left_child]:
            high_child = right_child
        if heap[high_child] > heap[index]:
            heap[index], heap[high_child] = heap[high_child], heap[index]
            index = high_child
            left_child = 2*index + 1
        else:
            return

def heappush(heap: list[int], val: int) -> None:
    pass

def heappop(heap: list[int]) -> int:
    pass

if __name__ == '__main__':
    heap = [6, 5, 2, 2, 3]

    print('Pushing')
    heappush(heap, 8)
    print(heap)

    print('Popping')
    top = heappop(heap)
    print(heap)

    # sort a list using heap sort
    lst = [7, 3, 4, 1, 6, 5, 2]
    

