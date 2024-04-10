#!/usr/bin/env python3

from dataclasses import dataclass
from typing      import Optional

import sys

# Classes

@dataclass
class Node:
    ''' Node Structure '''
    value:  int
    left:   Optional['Node'] = None
    right:  Optional['Node'] = None

@dataclass
class Tree:
    ''' Tree Structure '''

    root:   Optional[Node] = None

    def __contains__(self, value: int) -> bool:
        pass

    def search(self, value: int) -> bool:
        ''' Determine if value is in tree '''
        pass

    def _search(self, node: Optional[Node], value) -> bool:
        ''' Determine if value is in tree (recursively) '''
        # Base case: Non-existent node
        if node is None:
            pass

        # Base case: Found Match
        if value == node.value:
            pass

        # Recursive: Go to left or right subtree based on value
        pass

    def insert(self, value) -> None:
        ''' Add value into tree '''
        try:
            self.root = self._insert(self.root, value)
        except ValueError:
            pass

    def _insert(self, node: Optional[Node], value) -> None:
        ''' Add value into tree (recursively) '''
        # Base case: Non-existent node, so create and return
        pass

        # Base case: Found Match, so raise exception
        pass

        # Recursive: Go to left or right and update link
        pass

        # Return current node so we can re-link
        pass

    def print(self):
        ''' Print all nodes in tree '''
        self._print(self.root)

    def _print(self, node: Optional[Node]):
        ''' Print all nodes in tree (recursively) '''
        # Base case: Non-existent node
        if not node:
            return

        # Recursive: Go left, process node, go right
        self._print(node.left)
        print(node.value)
        self._print(node.right)

    def _print(self, node: Optional[Node]):
        ''' Print all nodes in tree (recursively) '''
        # Base case: Non-existent node
        if not node:
            return

        # Recursive: Go left, process node, go right
        self._print(node.left)
        print(node.value, end=' ')
        self._print(node.right)

    def __str__(self) -> str:
        return self._str(self.root, 0)
    
    def _str(self, node: Optional[Node], level: int) -> str:
        string = ''
        # Base case: Non-existent node
        if not node:
            return string

        # Recursive: Print in order
        # Note right is printed first so it displays correctly in terminal
        string += self._str(node.right, level + 1)
        string += level * '    '
        string += f"{node.value}\n"
        string += self._str(node.left, level + 1)
        return string


# Main Execution

def main(stream=sys.stdin):
    ''' For each line, insert each number into tree, search for items, and then
    print tree '''

    for line in stream:
        strs = line.split()                 # Split line into individual strings
        ints = [int(s) for s in strs]       # Convert each string into an int
        tree = Tree()

        for number in ints:                 # Insert ints into tree
            tree.insert(number)

        tree.print()
        print(tree)

        for number in range(max(ints) + 1): # Search for ints in tree
            print(number, tree.search(number))

if __name__ == '__main__':
    main()
