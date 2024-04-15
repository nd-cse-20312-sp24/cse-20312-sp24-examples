#!/usr/bin/env python3

''' adjacency_matrix.py

Represent graph as adjaceny matrix.
'''

import sys

# Types

AdjacencyMatrix = list[list[int]]

# Functions

def read_graph(stream) -> AdjacencyMatrix:
    # Read number of vertices (n) and number of edges (m)
    try:
        n, m = map(int, stream.readline().split())
    except ValueError:
        return []

    # Initialize empty adjacency matrix
    graph = [[0]*n for _ in range(n)]

    # Read each edge and update adjacency matrix
    for _ in range(m):
        source, target = map(int, stream.readline().split())

        # Update both directions since graph is undirected
        graph[source][target] = 1
        graph[target][source] = 1

    return graph

# Main Execution

def main(stream=sys.stdin) -> None:
    graph = read_graph(stream)

    for row in graph:
        print(row)

if __name__ == '__main__':
    main()
