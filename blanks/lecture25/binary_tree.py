#!/usr/bin/env python3

# Binary Tree in Python based on https://www.programiz.com/dsa/binary-tree

class Node:
    def __init__(self, val, left, right):
        pass

    # Traverse preorder
    def traversePreOrder(self):
        pass

    # Traverse inorder
    def traverseInOrder(self):
        pass

    # Traverse postorder
    def traversePostOrder(self):
        pass

    def traversePreOrderStack(self):
        pass

    def traverseBFS(self):
        pass

                
root = Node(1, None, None)

print("Pre order Traversal: ", end="")
root.traversePreOrder()
print("\nIn order Traversal: ", end="")
root.traverseInOrder()
print("\nPost order Traversal: ", end="")
root.traversePostOrder()
print("\nPre order Traversal Stack: ", end="")
root.traversePreOrderStack()
print("\nBFS Traversal: ", end="")
root.traverseBFS()
print()