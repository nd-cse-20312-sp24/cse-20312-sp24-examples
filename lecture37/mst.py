#!/usr/bin/env python3

''' mst.py

Example of Prim's algorithm.
'''

import collections
import heapq
import sys

# Types

Graph = dict[str, dict[str, int]]

# Build Graph

def read_graph() -> Graph:
    graph: Graph = collections.defaultdict(dict)
    for line in sys.stdin:
        source, target, weight = line.split()
        graph[source][target] = int(weight)
        graph[target][source] = int(weight)
    return graph

# Compute MST

def compute_mst(graph: Graph, origin: str) -> dict[str, str]:

    # frontier is priority queue of tuples (distance, vertex, source),
    # where source is the predecessor of the current vertex
    frontier = [(0, origin, origin)]

    # visited is a dict of {vertex:source, }
    visited  = {}

    while frontier:
        weight, vertex, source = heapq.heappop(frontier)

        if vertex in visited:
            continue

        # add vertex:source to the visited list
        visited[vertex] = source

        for neighbor, weight in graph[vertex].items():
            if not neighbor in visited:
                heapq.heappush(frontier, (weight, neighbor, vertex))

    del visited[origin]
    return visited

# Main Execution

def main() -> None:
    graph  = read_graph()
    origin = min(graph)

    # MST
    mst   = compute_mst(graph, origin)
    edges = sorted(sorted(t) for t in mst.items())

    mst_length = sum(graph[s][t] for s, t in edges)
    print(f'MST length = {mst_length}')
    print('MST edges')
    for source, target in edges:
        print(source, target)

if __name__ == '__main__':
    main()
