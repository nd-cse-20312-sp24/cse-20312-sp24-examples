#!/usr/bin/env python3

''' tree_height.py

Find the height of a binary tree using divide and conquer.

'''

from dataclasses import dataclass
from typing      import Optional

# Classes

@dataclass
class Node:
    value:  int
    left:   Optional['Node'] = None
    right:  Optional['Node'] = None

# Functions

def tree_height(node: Optional[Node]) -> int:
    ''' Use divide and conquer to compute the minimum of binary tree '''
    # Base Case: Invalid Node
    if node is None:
        return 0

    # Divide and Conquer: Recursively solve left and right sub-trees
    left_height  = tree_height(node.left)
    right_height = tree_height(node.right)

    # Combine: Add one to the max of left and right heights
    return max(left_height, right_height) + 1

# Main Execution

def main() -> None:
    # Create tree
    root = Node(7,
        Node(6,
                Node(4, 
                        Node(1), 
                        None),
                None),
        Node(5,
                Node(3),
                Node(2),
    ))

    # Compute height of tree
    print(tree_height(root))

if __name__ == '__main__':
    main()
