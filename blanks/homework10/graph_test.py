#!/usr/bin/env python3

import doctest
import io
import unittest

from itertools import zip_longest
from math      import isclose

import graph
from graph import (
    AdjacencyMatrix,
    AdjacencyList,
    read_adjacency_matrix,
    read_adjacency_list,
    read_adjacency_lists,
)

# Graph Unit Tests

class GraphTests(unittest.TestCase):
    ''' Graph Unit Tests '''
    Total  = 3
    Points = 0

    Graph1 = '4\n3\n1 2\n2 3\n4 2\n'
    AM1    = [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 0], [0, 1, 0, 0]]

    Graph2 = '5\n4\n1 2\n5 1\n1 3\n1 4\n'
    AM2    = [[0, 1, 1, 1, 1], [1, 0, 0, 0, 0], [1, 0, 0, 0, 0], [1, 0, 0, 0, 0], [1, 0, 0, 0, 0]]

    Graph3 = '5\n4\n1 2\n5 1\n1 3\n2 4\n'
    AM3    = [[0, 1, 1, 0, 1], [1, 0, 0, 1, 0], [1, 0, 0, 0, 0], [0, 1, 0, 0, 0], [1, 0, 0, 0, 0]]

    Graph4 = '4\n3\n1 2\n2 3\n4 1\n'
    AL4    = {1: [2, 4], 2: [1, 3], 3: [2], 4: [1]}

    Graph5 = '4\n2\n1 2\n3 4\n'
    AL5    = {1: [2], 2: [1], 3: [4], 4: [3]}

    Graph6 = '10\n7\n1 2\n6 8\n8 1\n10 6\n7 5\n3 6\n6 2\n'
    AL6    = {
        1: [2, 8],
        2: [1, 6],
        3: [6],
        4: [],
        5: [7],
        6: [8, 10, 3, 2],
        7: [5],
        8: [6, 1],
        9: [],
        10: [6]
    }

    @classmethod
    def setupClass(cls):
        cls.Points = 0

    @classmethod
    def tearDownClass(cls):
        print()
        print(f'   Score {cls.Points:.2f} / {cls.Total:.2f}')
        print(f'  Status {"Success" if isclose(cls.Points, cls.Total) else "Failure"}')

    def test_00_read_adjacency_matrix(self):
        cases = (
            (io.StringIO(self.Graph1), self.AM1),
            (io.StringIO(self.Graph2), self.AM2),
            (io.StringIO(self.Graph3), self.AM3),
        )

        for stream, adj_matrix in cases:
            self.assertEqual(read_adjacency_matrix(stream), adj_matrix)
            GraphTests.Points += 1/len(cases)

        GraphTests.Points += 0.5

    def test_01_read_adjacency_list(self):
        cases = (
            (io.StringIO(self.Graph4), self.AL4),
            (io.StringIO(self.Graph5), self.AL5),
            (io.StringIO(self.Graph6), self.AL6),
        )

        for stream, adj_list in cases:
            self.assertEqual(read_adjacency_list(stream), adj_list)
            GraphTests.Points += 1/len(cases)*0.5

        GraphTests.Points += 0.5

    def test_02_read_adjacency_lists(self):
        stream    = io.StringIO(self.Graph4 + self.Graph5 + self.Graph6)
        expecteds = (self.AL4, self.AL5, self.AL6)

        for result, expected in zip_longest(read_adjacency_lists(stream), expecteds):
            self.assertEqual(result, expected)
            GraphTests.Points += 1/len(expecteds)*0.5

# Main Execution

if __name__ == '__main__':
    unittest.main()
