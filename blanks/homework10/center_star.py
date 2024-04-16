#!/usr/bin/env python3

''' center_star.py - Center Star '''

import io
import sys

from graph import AdjacencyMatrix, read_adjacency_matrix

# Functions

def find_center(graph: AdjacencyMatrix) -> int:
    ''' Find center vertex of star graph.

    >>> find_center(read_adjacency_matrix(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 2\\n')))
    2
    '''
    pass

# Main Execution

def main(stream=sys.stdin) -> None:
    ''' For each graph in stream, determine which vertex is the center of the
    star graph, and print it out.

    >>> main(io.StringIO('4\\n3\\n1 2\\n2 3\\n4 2\\n'))
    Vertex 2 is the center
    '''
    pass

if __name__ == '__main__':
    main()
