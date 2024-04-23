#!/usr/bin/env python3

import doctest
import io
import unittest
import unittest.mock

from itertools import zip_longest
from math      import dist, isclose

import sim_city

# SimCity Unit Tests

class SimCityTests(unittest.TestCase):
    ''' SimCity Unit Tests '''
    Total  = 3
    Points = 0

    Input1 = [(1.0, 1.0), (2.0, 2.0), (2.0, 4.0)]
    Input2 = [(1.0, 1.0), (2.0, 2.0), (1.0, 2.0), (2.0, 1.0)]
    Input3 = [(0.0, 1.0), (2.0, 3.0), (4.0, 1.0), (1.0, 2.0), (5.0, 2.0)]
    Input4 = [
        (0.0, 1.0), (2.0, 3.0), (4.0, 1.0), (1.0, 2.0), (5.0, 2.0),
        (1.0, 0.0), (3.0, 2.0), (1.0, 4.0), (2.0, 5.0), (2.0, 1.0),
    ]
    Input5 = [
        (0.0, 1.0), (2.0, 3.0), (4.0, 1.0), (1.0, 2.0), (5.0, 2.0),
        (1.0, 0.0), (3.0, 2.0), (1.0, 4.0), (2.0, 5.0), (2.0, 1.0),
        (3.0, 4.0), (4.0, 3.0), (2.5, 2.5), (1.2, 3.4), (4.0, 5.0),
        (1.1, 0.3), (2.4, 5.2), (0.9, 9.0), (1.5, 5.1), (6.9, 9.6),
    ]

    @classmethod
    def setupClass(cls):
        cls.Points = 0

    @classmethod
    def tearDownClass(cls):
        print()
        print(f'   Score {cls.Points:.2f} / {cls.Total:.2f}')
        print(f'  Status {"Success" if isclose(cls.Points, cls.Total) else "Failure"}')

    def test_00_read_points(self):
        cases = (self.Input1, self.Input2, self.Input3, self.Input4, self.Input5)

        for inputs in cases:
            points = [(i, x, y) for i, (x, y) in enumerate(inputs)]
            stream = io.StringIO(
                f'{len(inputs)}\n' + '\n'.join(' '.join(map(str, i)) for i in inputs) + '\n',
            )
            self.assertEqual(sim_city.read_points(stream), points)
            SimCityTests.Points += 0.5/len(cases)

        SimCityTests.Points += 0.25

    def test_01_build_graph(self):
        cases = (self.Input1, self.Input2, self.Input3, self.Input4, self.Input5)

        for inputs in cases:
            points = [(i, x, y) for i, (x, y) in enumerate(inputs)]
            graph  = {
                v1: {v2: dist((x1, y1), (x2, y2)) for v2, x2, y2 in points if v1 != v2}
                for v1, x1, y1 in points
            }
            self.assertEqual(sim_city.build_graph(points), graph)
            SimCityTests.Points += 0.5/len(cases)

        SimCityTests.Points += 0.25

    def test_02_construct_mst(self):
        cases = (
            (self.Input1, {1: 0, 2: 1}),
            (self.Input2, {2: 0, 1: 2, 3: 0}),
            (self.Input3, {3: 0, 1: 3, 2: 1, 4: 2}),
            (self.Input4, {3: 0, 1: 3, 5: 0, 6: 1, 2: 6, 4: 2, 7: 1, 8: 7, 9: 3}),
            (self.Input5, {
                1: 13,
                2: 6,
                3: 0,
                4: 2,
                5: 15,
                6: 12,
                7: 13,
                8: 18,
                9: 15,
                10: 16,
                11: 4,
                12: 1,
                13: 3,
                14: 10,
                15: 0,
                16: 8,
                17: 18,
                18: 7,
                19: 14,
            }),
        )
        for inputs,edges in cases:
            points = [(i, x, y) for i, (x, y) in enumerate(inputs)]
            graph  = {
                v1: {v2: dist((x1, y1), (x2, y2)) for v2, x2, y2 in points if v1 != v2}
                for v1, x1, y1 in points
            }
            self.assertEqual(sim_city.construct_mst(graph), edges)
            SimCityTests.Points += 0.5/len(cases)

        SimCityTests.Points += 0.25

    def test_03_main(self):
        cases  = (
            (self.Input1, '3.41'),
            (self.Input2, '3.00'),
            (self.Input3, '7.07'),
            (self.Input4, '12.73'),
            (self.Input5, '27.08'),
        )
        stream = io.StringIO(''.join(
            f'{len(inputs)}\n' + '\n'.join(' '.join(map(str, i)) for i in inputs) + '\n'
            for inputs, _ in cases
        ))
        expecteds = [f'MST: {total}' for _, total in cases]

        with unittest.mock.patch('sys.stdout', new=io.StringIO()) as outputs:
            sim_city.main(stream)
            for output, expected in zip_longest(outputs.getvalue().splitlines(), expecteds):
                self.assertEqual(output, expected)
                SimCityTests.Points += 0.5/len(cases)

        SimCityTests.Points += 0.25

# Main Execution

if __name__ == '__main__':
    unittest.main()

