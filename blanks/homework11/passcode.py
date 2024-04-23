#!/usr/bin/env python3

import io
import sys

from collections import defaultdict, deque
from heapq       import heappop, heappush
from typing      import Iterator, Optional

# Types

Graph   = dict[int, set[int]]
Degrees = dict[int, int]

# Functions

def read_graph(stream=sys.stdin) -> Graph:
    ''' Read code samples into graph (adjacency set). 

    >>> read_graph(io.StringIO('352\\n154\\n542\\n315\\n152\\n'))
    defaultdict(<class 'set'>, {3: {1, 5}, 5: {2, 4}, 1: {5}, 4: {2}})
    '''
    pass

def compute_degrees(graph: Graph) -> Degrees:
    ''' Compute the incoming degrees of each vertex in graph. 

    >>> compute_degrees({3: {1, 5}, 5: {2, 4}, 1: {5}, 4: {2}})
    defaultdict(<class 'int'>, {3: 0, 1: 1, 5: 2, 2: 2, 4: 1})
    '''
    pass

def find_passcode(graph: Graph) -> list[int]:
    ''' Determine the passcode from graph using topological sort.

    >>> find_passcode({3: {1, 5}, 5: {2, 4}, 1: {5}, 4: {2}})
    [3, 1, 5, 4, 2]
    '''
    pass

# Main Execution

def main(stream=sys.stdin) -> None:
    ''' Read the code samples into a graph, find the passcode using topological
    sort, and print out the full passcode. 

    >>> main(io.StringIO('352\\n154\\n542\\n315\\n152\\n'))
    31542
    '''
    graph    = read_graph(stream)
    passcode = find_passcode(graph)
    print(''.join(map(str, passcode)))

if __name__ == '__main__':
    main()