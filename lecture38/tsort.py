#!/usr/bin/env python3

''' tsort.py

Use Kahn's algorithm to perform a topological sort on a Makefile.
'''

import collections
import sys

# Types

Graph = dict[str, set[str]]

# Functions

def read_graph() -> Graph:
    graph: Graph = collections.defaultdict(set)

    for line in sys.stdin:
        if ':' not in line:
            continue

        targets_string, sources_string = line.split(':')
        targets = targets_string.split()
        sources = sources_string.split()

        for source in sources:
            graph[source].update(targets)

    return graph

def compute_degrees(graph: Graph) -> dict[str, int]:
    # degrees is a dictionary {vertex:incoming_edges}
    # default value is 0
    degrees: dict[str, int] = collections.defaultdict(int)

    for source, targets in graph.items():
        # make sure source has an entry, even if it has no targets
        degrees[source]
        for target in targets:
            # Creates an entry with value 0 before incrementing
            degrees[target] += 1

    return degrees

def topological_sort(graph: Graph) -> list[str]:
    degrees  = compute_degrees(graph)
    frontier = [v for v, d in degrees.items() if d == 0]
    visited  = []

    while frontier:
        vertex = frontier.pop()
        visited.append(vertex)

        for neighbor in graph[vertex]:
            degrees[neighbor] -= 1
            if degrees[neighbor] == 0:
                frontier.append(neighbor)

    return visited

# Main Execution

def main() -> None:
    graph    = read_graph()
    vertices = topological_sort(graph)

    if len(vertices) == len(graph):
        print(' '.join(vertices))
    else:
        print('There is a cycle!')

if __name__ == '__main__':
    main()
