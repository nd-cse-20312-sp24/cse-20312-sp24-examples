#!/usr/bin/env python3

# Binary Tree in Python based on https://www.programiz.com/dsa/binary-tree

class Node:
    def __init__(self, val, left, right):
        self.left = left
        self.right = right
        self.val = val

    # Traverse preorder
    def traversePreOrder(self):
        print(self.val, end=' ')
        if self.left:
            self.left.traversePreOrder()
        if self.right:
            self.right.traversePreOrder()

    # Traverse inorder
    def traverseInOrder(self):
        if self.left:
            self.left.traverseInOrder()
        print(self.val, end=' ')
        if self.right:
            self.right.traverseInOrder()

    # Traverse postorder
    def traversePostOrder(self):
        if self.left:
            self.left.traversePostOrder()
        if self.right:
            self.right.traversePostOrder()
        print(self.val, end=' ')

    def traversePreOrderStack(self):
        stack = []
        stack.append(self)
        while stack:
            node = stack.pop()
            print(node.val, end=' ')
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

    def traverseBFS(self):
        queue = []
        queue.append(self)
        while queue:
            node = queue.pop(0)
            print(node.val, end=' ')
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

                
root = Node(1, 
            Node(2,
                 Node(4,
                      None,
                      None),
                 Node(5,
                      None,
                      None)),
            Node(3,
                 Node(6,
                      None,
                      None),
                 Node(7,
                      None,
                      None)))

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