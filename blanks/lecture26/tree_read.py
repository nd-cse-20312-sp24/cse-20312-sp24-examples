#!/usr/bin/env python3

''' tree_read.py

Read in tree in BFS format using divide and conquer.

'''
from __future__  import annotations  # need this to avoid typing error
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

def tree_read(array: list[int], index: int=0) -> Optional[Node]:
    ''' Use divide and conquer to read binary tree in BFS format '''
    # Base Case: Invalid Node
    pass

    # Divide and Conquer and Combine
    pass

# Main Execution

def main() -> None:
    ''' For each line, read the BFS tree and print out the root node '''
    pass

if __name__ == '__main__':
    main()
