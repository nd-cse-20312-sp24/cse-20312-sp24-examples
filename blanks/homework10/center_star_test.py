#!/usr/bin/env python3

import doctest
import io
import unittest
import unittest.mock

from itertools import zip_longest
from math      import isclose
from graph     import AdjacencyList, read_adjacency_matrix

import center_star

# CenterStar Unit Tests

class CenterStarTests(unittest.TestCase):
    ''' Center Star Unit Tests '''
    Total   = 3
    Points  = 0

    Graph1  = '4\n3\n1 2\n2 3\n4 2\n'
    AM1     = [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 0], [0, 1, 0, 0]]
    Center1 = 2

    Graph2  = '5\n4\n1 2\n5 1\n1 3\n1 4\n'
    AM2     = [[0, 1, 1, 1, 1], [1, 0, 0, 0, 0], [1, 0, 0, 0, 0], [1, 0, 0, 0, 0], [1, 0, 0, 0, 0]]
    Center2 = 1

    Graph3  = '5\n4\n1 2\n5 1\n1 3\n2 4\n'
    AM3     = [[0, 1, 1, 0, 1], [1, 0, 0, 1, 0], [1, 0, 0, 0, 0], [0, 1, 0, 0, 0], [1, 0, 0, 0, 0]]
    Center3 = 0

    @classmethod
    def setupClass(cls):
        cls.Points = 0

    @classmethod
    def tearDownClass(cls):
        print()
        print(f'   Score {cls.Points:.2f} / {cls.Total:.2f}')
        print(f'  Status {"Success" if isclose(cls.Points, cls.Total) else "Failure"}')

    def test_00_find_center(self):
        cases = (
            (self.AM1, self.Center1),
            (self.AM2, self.Center2),
            (self.AM3, self.Center3),
        )

        for graph, center in cases:
            self.assertEqual(center_star.find_center(graph), center)
            CenterStarTests.Points += 1/len(cases)

        CenterStarTests.Points += 0.5

    def test_01_main(self):
        stream    = io.StringIO(self.Graph1 + self.Graph2 + self.Graph3)
        centers   = (self.Center1, self.Center2, self.Center3)
        expecteds = (
            f'Vertex {v} is the center' if v else 'There is no center' for v in centers
        )

        with unittest.mock.patch('sys.stdout', new=io.StringIO()) as outputs:
            center_star.main(stream)
            for output, expected in zip_longest(outputs.getvalue().splitlines(), expecteds):
                self.assertEqual(output, expected)
                CenterStarTests.Points += 1/len(centers)

        CenterStarTests.Points += 0.5

# Main Execution

if __name__ == '__main__':
    unittest.main()
