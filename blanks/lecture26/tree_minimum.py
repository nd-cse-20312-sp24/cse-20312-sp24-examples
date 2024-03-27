#!/usr/bin/env python3

''' tree_minimum.py

Find the minimum value in a binary tree using divide and conquer.

'''

from dataclasses import dataclass
from typing      import Optional
import sys

# Classes

@dataclass
class Node:
    value:  int
    left:   Optional['Node'] = None
    right:  Optional['Node'] = None

# Functions

def tree_minimum(node: Optional[Node]) -> int:
    ''' Use divide and conquer to compute the minimum of binary tree '''
    # Base Case: Invalid Node
    pass

    # Divide and Conquer: Recursively solve left and right sub-trees
    pass

    # Combine: Take minimum of current node and left and right minimums
    pass

# Main Execution

def main() -> None:
    # Create tree
    root = Node(7,
        Node(6,
                Node(4),
                None),
        Node(5,
                Node(3),
                Node(2),
    ))

    # Compute minimum of tree
    print(tree_minimum(root))

if __name__ == '__main__':
    main()
