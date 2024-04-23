#!/usr/bin/env python3

''' sim_city.py - Sim City '''

import io
import sys

from collections import defaultdict
from heapq       import heappop, heappush
from math        import dist
from typing      import Iterator, Optional

# Types

Graph  = dict[int, dict[int, float]]
Points = list[tuple[int, float, float]]
Edges  = dict[int, int]

# Functions

def read_points(stream=sys.stdin) -> Points:
    ''' Read stream of points into a list.

    >>> read_points(io.StringIO('3\\n1.0 1.0\\n2.0 2.0\\n2.0 4.0\\n'))
    [(0, 1.0, 1.0), (1, 2.0, 2.0), (2, 2.0, 4.0)]
    '''
    pass

def build_graph(points: Points) -> Graph:
    ''' Construct graph from points.

    >>> build_graph([(0, 1.0, 1.0), (1, 2.0, 2.0), (2, 2.0, 4.0)])
    defaultdict(<class 'dict'>, {0: {1: 1.4142135623730951, 2: 3.1622776601683795}, 1: {0: 1.4142135623730951, 2: 2.0}, 2: {0: 3.1622776601683795, 1: 2.0}})
    '''
    pass

def construct_mst(graph) -> Edges:
    ''' Construct the minimum spanning tree of the graph.

    >>> construct_mst({0: {1: 1.4142135623730951, 2: 3.1622776601683795}, 1: {0: 1.4142135623730951, 2: 2.0}, 2: {0: 3.1622776601683795, 1: 2.0}})
    {1: 0, 2: 1}
    '''
    
    pass

# Main Execution

def main(stream=sys.stdin) -> None:
    ''' For each input in stream, read the points, build a graph, construct the
    minimum spanning tree, and then output the cost of the MST.

    >>> main(io.StringIO('3\\n1.0 1.0\\n2.0 2.0\\n2.0 4.0\\n'))
    MST: 3.41
    '''
    while points := read_points(stream):
        graph = build_graph(points)
        edges = construct_mst(graph)
        total = sum(graph[p1][p2] for p1, p2 in edges.items())
        print(f'MST: {total:.2f}')

if __name__ == '__main__':
    main()