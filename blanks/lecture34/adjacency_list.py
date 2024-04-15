#!/usr/bin/env python3

''' adjacency_list.py

Represent graph as adjaceny list.
'''

import sys
from collections import defaultdict

# Types

AdjacencyList = dict

# Functions

def read_graph(stream) -> AdjacencyList:
    # Read number of vertices (n) and number of edges (m)
    try:
        n, m = map(int, stream.readline().split())
    except ValueError:
        return {}

    # Initialize empty adjacency list
    pass

    # Read each edge and update adjacency list
    pass

        # Update both directions since graph is undirected

# Main Execution

def main(stream=sys.stdin) -> None:
    graph = read_graph(stream)

    for vertex, neighbors in (graph.items()):
        print(f'{vertex}: {(neighbors)}')

if __name__ == '__main__':
    main()
