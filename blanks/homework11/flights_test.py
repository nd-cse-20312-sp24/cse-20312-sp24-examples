#!/usr/bin/env python3

import doctest
import io
import unittest
import unittest.mock

from itertools import zip_longest
from math      import isclose

import flights

# Flights Unit Tests

class FlightsTests(unittest.TestCase):
    ''' Flights Unit Tests '''
    Total  = 4
    Points = 0

    Edges1 = [(0, 1, 100), (1, 2, 50), (0, 2, 365)]
    Graph1 = {0: {1: 100, 2: 365}, 1: {2: 50}}

    Edges2 = [(0, 1, 1), (0, 2, 5), (1, 2, 1), (2, 3, 1)]
    Graph2 = {0: {1: 1, 2: 5}, 1: {2: 1}, 2: {3: 1}}

    Edges3 = [
        (0, 1, 50), (0, 2, 200), (1, 2, 100), (1, 3, 50), (2, 5, 100), (2, 4, 50),
        (2, 3, 50), (3, 4, 200), (4, 6, 300), (5, 6, 50), (5, 0, 600), (6, 2, 50),
    ]
    Graph3 = {
        0: {1: 50, 2: 200},
        1: {2: 100, 3: 50},
        2: {5: 100, 4: 50, 3: 50},
        3: {4: 200},
        4: {6: 300},
        5: {6: 50, 0: 600},
        6: {2: 50}
    }

    @classmethod
    def setupClass(cls):
        cls.Points = 0

    @classmethod
    def tearDownClass(cls):
        print()
        print(f'   Score {cls.Points:.2f} / {cls.Total:.2f}')
        print(f'  Status {"Success" if isclose(cls.Points, cls.Total) else "Failure"}')

    def test_00_read_graph(self):
        cases = (
            (0, 1, self.Edges1, self.Graph1),
            (1, 2, self.Edges1, self.Graph1),
            (0, 1, self.Edges2, self.Graph2),
            (1, 2, self.Edges2, self.Graph2),
            (0, 1, self.Edges3, self.Graph3),
            (1, 2, self.Edges3, self.Graph3),
            (0, 5, self.Edges3, self.Graph3),
            (1, 6, self.Edges3, self.Graph3),
        )

        for origin, destination, edges, graph in cases:
            stream = io.StringIO(
                f'{origin} {destination} {len(edges)}\n' + '\n'.join(' '.join(map(str, e)) for e in edges) + '\n',
            )
            self.assertEqual(flights.read_graph(stream), (origin, destination, graph))
            FlightsTests.Points += 0.75/len(cases)
        
        FlightsTests.Points += 0.25

    def test_01_find_cheapest_flight_plan(self):
        cases = (
            (0, 2, self.Graph1, 150, {1: 0, 2: 1}),
            (0, 1, self.Graph1, 100, {1: 0}),
            (0, 2, self.Graph2, 2, {1: 0, 2: 1}),
            (0, 3, self.Graph2, 3, {1: 0, 2: 1, 3: 2}),
            (0, 1, self.Graph3, 50, {1: 0}),
            (0, 2, self.Graph3, 150, {1: 0, 2: 1, 3: 1}),
            (0, 3, self.Graph3, 100, {1: 0, 3: 1}),
            (0, 4, self.Graph3, 200, {1: 0, 2: 1, 3: 1, 4: 2}),
            (0, 5, self.Graph3, 250, {1: 0, 2: 1, 3: 1, 4: 2, 5: 2}),
            (0, 6, self.Graph3, 300, {1: 0, 2: 1, 3: 1, 4: 2, 5: 2, 6: 5}),
            (5, 4, self.Graph3, 150, {2: 6, 3: 2, 4: 2, 6: 5}),
            (5, 1, self.Graph3, 650, {0: 5, 1: 0, 2: 6, 3: 2, 4: 2, 6: 5}),
            (5, 3, self.Graph3, 150, {2: 6, 3: 2, 6: 5}),
        )

        for origin, destination, graph, cost, plan in cases:
            self.assertEqual(flights.find_cheapest_flight_plan(origin, destination, graph), (cost, plan))
            FlightsTests.Points += 0.75/len(cases)

        FlightsTests.Points += 0.25

    def test_02_flight_plan(self):
        cases = (
            (0, 2, {1: 0, 2: 1}, [0, 1, 2]),
            (0, 1, {1: 0}, [0, 1]),
            (0, 2, {1: 0, 2: 1}, [0, 1, 2]),
            (0, 3, {1: 0, 2: 1, 3: 2}, [0, 1, 2, 3]),
            (0, 1, {1: 0}, [0, 1]),
            (0, 2, {1: 0, 2: 1, 3: 1}, [0, 1, 2]),
            (0, 3, {1: 0, 2: 1, 3: 1}, [0, 1, 3]),
            (0, 4, {1: 0, 2: 1, 3: 1, 4: 2}, [0, 1, 2, 4]),
            (0, 5, {1: 0, 2: 1, 3: 1, 4: 2, 5: 2}, [0, 1, 2, 5]),
            (0, 6, {1: 0, 2: 1, 3: 1, 4: 2, 5: 2, 6: 5}, [0, 1, 2, 5, 6]),
            (5, 4, {2: 6, 3: 2, 4: 2, 6: 5}, [5, 6, 2, 4]),
            (5, 1, {0: 5, 1: 0, 2: 6, 3: 2, 4: 2, 6: 5}, [5, 0, 1]),
            (5, 3, {2: 6, 3: 2, 6: 5}, [5, 6, 2, 3]),
        )

        for origin, destination, plan, expected in cases:
            self.assertEqual(list(flights.flight_plan(origin, destination, plan)), expected)
            FlightsTests.Points += 0.75/len(cases)

        FlightsTests.Points += 0.25

    def test_03_main(self):
        cases  = (
            (0, 2, self.Edges1, 150, [0, 1, 2]),
            (0, 1, self.Edges1, 100, [0, 1]),
            (0, 2, self.Edges2, 2, [0, 1, 2]),
            (0, 3, self.Edges2, 3, [0, 1, 2, 3]),
            (0, 1, self.Edges3, 50, [0, 1]),
            (0, 2, self.Edges3, 150, [0, 1, 2]),
            (0, 3, self.Edges3, 100, [0, 1, 3]),
            (0, 4, self.Edges3, 200, [0, 1, 2, 4]),
            (0, 5, self.Edges3, 250, [0, 1, 2, 5]),
            (0, 6, self.Edges3, 300, [0, 1, 2, 5, 6]),
            (5, 4, self.Edges3, 150, [5, 6, 2, 4]),
            (5, 1, self.Edges3, 650, [5, 0, 1]),
            (5, 3, self.Edges3, 150, [5, 6, 2, 3]),
        )
        stream = io.StringIO(''.join(
            f'{o} {d} {len(edges)}\n' + '\n'.join(' '.join(map(str, e)) for e in edges) + '\n'
            for o, d, edges, *_ in cases
        ))
        expecteds = [
            f'Cost: ${cost}, Plan: {" -> ".join(map(str, plan))}' for *_, cost, plan in cases
        ]

        with unittest.mock.patch('sys.stdout', new=io.StringIO()) as outputs:
            flights.main(stream)
            for output, expected in zip_longest(outputs.getvalue().splitlines(), expecteds):
                self.assertEqual(output, expected)
                FlightsTests.Points += 0.75/len(cases)
        
        FlightsTests.Points += 0.25

# Main Execution

if __name__ == '__main__':
    unittest.main()

