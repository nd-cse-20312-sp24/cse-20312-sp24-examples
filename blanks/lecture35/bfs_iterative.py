#!/usr/bin/env python3

''' bfs_iterative.py 

Perform a BFS traversal of graph using iteration.
'''

from collections import defaultdict, deque
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

def bfs(graph: Graph, vertex: int) -> None:
    frontier = deque([vertex])      # Vertices we can visit
    visited  = set()                # Vertices we have already visited

    while frontier:
        vertex = frontier.popleft()

        if vertex in visited:
            continue

        visited.add(vertex)

        print(vertex)

        for neighbor in graph[vertex]:
            frontier.append(neighbor)

# Main Execution

def main(stream=sys.stdin):
    graph = read_graph(stream)

    bfs(graph, min(graph.keys()))

if __name__ == '__main__':
    main()
