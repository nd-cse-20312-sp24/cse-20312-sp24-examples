#!/usr/bin/env python3

from dataclasses import dataclass
from typing      import Optional
from random      import randint

import sys

# Classes

@dataclass
class Node:
    ''' Node Structure '''
    value:      str
    priority:   int
    left:       Optional['Node'] = None
    right:      Optional['Node'] = None

@dataclass
class Treap:
    ''' Tree Structure '''

    root:   Optional[Node] = None

    def __contains__(self, value: str) -> bool:
        return self.search(value)

    def search(self, value: str) -> bool:
        ''' Determine if value is in tree '''
        return self._search(self.root, value)

    def _search(self, node: Optional[Node], value: str) -> bool:
        ''' Determine if value is in tree (recursively) '''
        # Base case: Non-existent node
        if node is None:
            return False

        # Base case: Found Match
        if value == node.value:
            return True

        # Recursive: Go to left or right subtree based on value
        if value < node.value:
            return self._search(node.left, value)
        else:
            return self._search(node.right, value)

    def rotate_right(self, p: Node) -> Node:
        ''' Rotate the sub-tree at parent node to the right.

            P               CL
           / \             /  \
          CL CR     =>    GL   P
         /  \                 / \
        GL  GR              GR   CR
        '''

        # before
        cl = p.left
        gr = cl.right

        # after
        cl.right = p
        p.left   = gr
        return cl
    
    def rotate_left(self, p: Node) -> Node:
        ''' Rotate the sub-tree at parent node to the left.

            P               CR
           / \             /  \
          CL CR     =>    P   GR
            /  \         / \
           GL  GR       CL  GL
        '''
        
        # before
        cr = p.right
        gl = cr.left

        # after
        cr.left = p
        p.right = gl
        return cr
    
    def insert(self, value: str, priority: int) -> None:
        ''' Add value into tree '''
        try:
            self.root = self._insert(self.root, value, priority)
        except ValueError:
            pass

    def _insert(self, node: Optional[Node], value: str, priority: int) -> None:
        ''' Add value into tree (recursively) '''
        # Base case: Non-existent node, so create and return
        if node is None:
            return Node(value, priority)

        # Base case: Found Match, so raise exception
        if value == node.value:
            raise ValueError

        # Recursive: Go to left or right and update link
        if value < node.value:
            node.left  = self._insert(node.left, value, priority)
            if node.left.priority > node.priority:
                node = self.rotate_right(node)
        else:
            node.right = self._insert(node.right, value, priority)
            if node.right.priority > node.priority:
                node = self.rotate_left(node)

        # Return current node so we can re-link
        return node

    def print_inorder(self):
        ''' Print all nodes in tree '''
        self._print_inorder(self.root)
        print()

    def _print_inorder(self, node: Optional[Node]):
        ''' Print all nodes in tree (recursively) '''
        # Base case: Non-existent node
        if not node:
            return

        # Recursive: Go left, process node, go right
        self._print_inorder(node.left)
        print(node.value, end=' ')
        self._print_inorder(node.right)

    def _str(self, node: Optional[Node], level: int) -> str:
        string = ''
        # Base case: Non-existent node
        if not node:
            return string

        # Recursive: Print in order
        # Note right is printed first so it displays correctly in terminal
        string += self._str(node.right, level + 1)
        string += level * '       '
        string += f"({node.value}, {node.priority})\n"
        string += self._str(node.left, level + 1)
        return string

    def __str__(self) -> str:
        return self._str(self.root, 0)

# Main Execution

def main(stream=sys.stdin):
    t = Treap()

    # nodes = [('D', 60), ('F', 75), ('H', 14), ('C', 70), ('A', 55)]
    # for value, priority in nodes:
    #     t.insert(value, priority)
    #     print(t)
    #     print('----------------------------------')

    nodes = [('A', 1), ('B', 2), ('C', 1), ('D', 3), ('E', 1), ('F', 2), ('G', 1)]
    for value, priority in nodes:
        t.insert(value, priority)
    print(t)

    # for c in 'ABCDEFGHIJKLMNO':
    #     t.insert(c, randint(1, 100))
    # print(t)
    # t.print_inorder()


if __name__ == '__main__':
    main()
