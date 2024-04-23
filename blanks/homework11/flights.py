#!/usr/bin/env python3

''' flights.py - Flights '''

import io
import sys

from collections import defaultdict
from heapq       import heappop, heappush
from typing      import Iterator, Optional

# Types

Graph = dict[int, dict[int, int]]
Plan  = dict[int, int]

# Functions

def read_graph(stream=sys.stdin) -> Optional[tuple[int, int, Graph]]:
    ''' Read origin, destination, and graph from stream.

    >>> read_graph(io.StringIO('0 2 3\\n0 1 100\\n1 2 50\\n0 2 365\\n'))
    (0, 2, defaultdict(<class 'dict'>, {0: {1: 100, 2: 365}, 1: {2: 50}}))
    '''
    pass

def find_cheapest_flight_plan(origin: int, destination: int, graph: Graph) -> tuple[int, Plan]:
    ''' Find the cheapest flight plan in the graph going from origin to the
    destination.

    >>> find_cheapest_flight_plan(0, 2, {0: {1: 100, 2: 365}, 1: {2: 50}})
    (150, {1: 0, 2: 1})
    '''
    pass

def flight_plan(origin: int, destination: int, plan: Plan) -> Iterator[int]:
    ''' Recursively generate stops from origin to destination in specified
    flight plan.

    >>> list(flight_plan(0, 2, {1: 0, 2: 1}))
    [0, 1, 2]
    '''
    pass

# Main Execution

def main(stream=sys.stdin) -> None:
    ''' For each origin, destination, graph input in stream, find the cheapest
    flight plan, and then print the cost and plan.

    >>> main(io.StringIO('0 2 3\\n0 1 100\\n1 2 50\\n0 2 365\\n'))
    Cost: $150, Plan: 0 -> 1 -> 2
    '''
    while data := read_graph(stream):
        origin, destination, graph = data
        cost, plan = find_cheapest_flight_plan(origin, destination, graph)
        stops = flight_plan(origin, destination, plan)
        print(f'Cost: ${cost}, Plan: {" -> ".join(map(str, stops))}')

if __name__ == '__main__':
    main()