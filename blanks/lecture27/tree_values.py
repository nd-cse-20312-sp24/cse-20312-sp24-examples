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
    pass

def tree_values2(root: Optional[Node]) -> Iterator[str]:
    pass

# Main Execution

def main():
    tree = Node('V',
        Node('A', Node('P'), Node('I')),
        Node('M', Node('R'), Node('E'))
    )

    for value in tree_values1(tree):
        print(value)

    # print()
    
    # for value in tree_values2(tree):
    #     print(value)

if __name__ == '__main__':
    main()
