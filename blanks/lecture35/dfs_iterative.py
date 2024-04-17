#!/usr/bin/env python3

''' dfs_iterative.py 

Perform a DFS traversal of graph using iteration.
'''

from collections import defaultdict
import sys

# Types

Graph = dict[int, list[int]]

# Functions

def read_graph(stream=sys.stdin) -> Graph:
    graph = defaultdict(list)

    for line in stream:
        source, target = map(int, line.split())
        graph[source].append(target)

    return graph

def dfs(graph: Graph, vertex: int) -> None:
    frontier = [vertex]             # Vertices we can visit
    visited  = set()                # Vertices we have already visited

    pass

# Main Execution

def main(stream=sys.stdin):
    graph = read_graph(stream)

    dfs(graph, min(graph.keys()))

if __name__ == '__main__':
    main()
