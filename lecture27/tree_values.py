#!/usr/bin/env python3

# Classes

from dataclasses import dataclass
from typing      import Iterator, Optional

@dataclass
class Node:
    value:  str
    left:   Optional['Node'] = None
    right:  Optional['Node'] = None

# Functions

def tree_values1(root: Optional[Node]) -> list[str]:
    if not root:
        return []

    return (
        tree_values1(root.left) + [root.value] + tree_values1(root.right)
    )

def tree_values2(root: Optional[Node]) -> Iterator[str]:
    if not root:
        return
    
    left_values = tree_values2(root.left)
    right_values = tree_values2(root.right)

    yield left_values
    yield root.value
    yield right_values

# def tree_values2(root: Optional[Node]) -> Iterator[str]:
#     if not root:
#         return
    
#     left_values = tree_values2(root.left)
#     right_values = tree_values2(root.right)

#     for value in left_values: yield value
#     yield root.value
#     for value in right_values: yield value

# def tree_values2(root: Optional[Node]) -> Iterator[str]:
#     if not root:
#         return
    
#     yield from tree_values2(root.left)
#     yield root.value
#     yield from tree_values2(root.right)

# Main Execution

def main():
    tree = Node('V',
        Node('A', Node('P'), Node('R')),
        Node('M', Node('I'), Node('E'))
    )

    # for value in tree_values1(tree):
    #     print(value)

    print()
    
    for value in tree_values2(tree):
        print(value)

if __name__ == '__main__':
    main()
