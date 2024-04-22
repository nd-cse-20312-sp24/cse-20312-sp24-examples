#!/usr/bin/env python3

''' mst.py

Example of Dijkstra's algorithm.
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

# Compute SSSP

def compute_sssp(graph: Graph, origin: str) -> dict[str, str]:
    
    # frontier is priority queue of tuples (distance, vertex, source),
    # where source is the predecessor of the current vertex
    frontier = [(0, origin, origin), ]

    # visited is a dict of {vertex:source, }
    visited  = {}

    while frontier:
        distance, vertex, source = heapq.heappop(frontier)

        if vertex in visited:
            continue

        # add vertex:source to the visited list
        visited[vertex] = source

        for neighbor, weight in graph[vertex].items():
            if not neighbor in visited:
                heapq.heappush(frontier, (distance + weight, neighbor, vertex))

    del visited[origin]
    return visited

def reconstruct_path(visited: dict[str, str], origin: str, destination: str) -> list[str]:
    path = []
    curr = destination

    while curr != origin:
        path.append(curr)
        curr = visited[curr]

    path.append(origin)
    return reversed(path)


# Main Execution

def main() -> None:
    graph  = read_graph()
    origin = min(graph)

    # SSSP
    sssp  = compute_sssp(graph, origin)
    print('SSSP')
    for target in sorted(graph)[1:]:
        path = reconstruct_path(sssp, origin, target)
        print(f'{origin} -> {target} = {" ".join(path)}')

if __name__ == '__main__':
    main()
