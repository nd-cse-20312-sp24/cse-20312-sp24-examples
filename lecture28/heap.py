#!/usr/bin/env python3

def bubble_up(heap: list[int], index: int) -> None:
    parent = (index - 1) // 2
    # while not at root and current node < parent
    while index > 0 and heap[index] > heap[parent]:
        heap[index], heap[parent] = heap[parent], heap[index]
        index = parent
        parent = (index - 1) // 2
        
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
    heap.append(val)
    # while new val is less than parent, bubble up
    bubble_up(heap, len(heap) - 1)

def heappop(heap: list[int]) -> int:
    if len(heap) == 1:
        return heap.pop()
    
    result = heap[0]
    heap[0] = heap.pop()
    bubble_down(heap, 0)
    return result

if __name__ == '__main__':
    # heap = [6, 5, 2, 2, 3]

    # print('Pushing')
    # heappush(heap, 8)
    # print(heap)

    # print('Popping')
    # top = heappop(heap)
    # print(heap)

    lst = [7, 3, 4, 1, 6, 5, 2]
    heap = []
    for i in lst:
        heappush(heap, i)
    print('heap:       ', heap)

    sorted_lst = []
    while heap:
        sorted_lst.append(heappop(heap))
    print('sorted_lst: ', sorted_lst)

