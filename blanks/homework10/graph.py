#!/usr/bin/env python3

''' graph.py - Graph Utilities

Each graph is in the following format:

    4   # Number of vertices
    3   # Number of edges
    1 2 # Edge 1
    2 3 # Edge 2
    4 2 # Edge 3
'''

import io
import sys

from typing import Iterator

# Types

AdjacencyMatrix = list[list[int]]
AdjacencyList   = dict[int, list[int]]

# Functions

def read_adjacency_matrix(stream=sys.stdin) -> AdjacencyMatrix:
    ''' Read graph from stream into adjacency matrix.

    >>> read_adjacency_matrix(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 2\\n'))
    [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 0], [0, 1, 0, 0]]
    '''
    pass

def read_adjacency_list(stream=sys.stdin) -> AdjacencyList:
    ''' Read graph from stream into adjacency list.

    >>> read_adjacency_list(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 2\\n'))
    {1: [2], 2: [1, 3, 4], 3: [2], 4: [2]}
    '''
    pass

def read_adjacency_lists(stream=sys.stdin) -> Iterator[AdjacencyList]:
    ''' Generate adjacency lists from graphs in stream.

    >>> next(read_adjacency_lists(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 2\\n')))
    {1: [2], 2: [1, 3, 4], 3: [2], 4: [2]}
    '''
    pass
