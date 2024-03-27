#!/usr/bin/env python3

# Binary Tree in Python with Array Representation
    
def left_child(index):
        return 2*index + 1

def right_child(index):
        return 2*index + 2

def parent(index):
        return (index - 1) // 2

tree = 'BINARY'

print(tree)
print(tree[0])
print(tree[left_child(0)])
print(tree[right_child(left_child(0))])
print(tree[parent(4)])
print(tree[parent(5)])


