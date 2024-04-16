#!/usr/bin/env python3

''' reddit_groups.py - Reddit Groups '''

import io
import sys

from typing import Iterator
from graph  import AdjacencyList, read_adjacency_list, read_adjacency_lists

# Functions

def walk_graph(graph: AdjacencyList, origin: int) -> set[int]:
    ''' Perform traversal of graph from origin and return set of visited
    vertices.

    >>> walk_graph(read_adjacency_list(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 1\\n')), 1)
    {1, 2, 3, 4}
    '''
    pass

def find_groups(graph: AdjacencyList) -> Iterator[list[int]]:
    ''' Find isolated groups in graph, generating each group one at a time.

    >>> list(find_groups(read_adjacency_list(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 1\\n'))))
    [[1, 2, 3, 4]]
    '''
    pass

# Main Execution

def main(stream=sys.stdin) -> None:
    ''' For each graph in stream, find the number of isolated graphs, and print
    them out in sorted order.

    >>> main(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 1\\n'))
    Graph 1:
    1 2 3 4
    '''
    pass

if __name__ == '__main__':
    main()
