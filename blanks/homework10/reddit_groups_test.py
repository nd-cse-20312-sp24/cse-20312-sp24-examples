#!/usr/bin/env python3

import doctest
import io
import unittest
import unittest.mock

from itertools import zip_longest
from math      import isclose
from graph     import AdjacencyList, read_adjacency_matrix

import reddit_groups

# RedditGroups Unit Tests

class RedditGroupsTests(unittest.TestCase):
    ''' Reddit Groups Unit Tests '''
    Total  = 4
    Points = 0

    Graph1 = '4\n3\n1 2\n2 3\n4 1\n'
    AL1    = {1: [2, 4], 2: [1, 3], 3: [2], 4: [1]}
    Walks1 = [(1, {1, 2, 3, 4})]

    Graph2 = '4\n2\n1 2\n3 4\n'
    AL2    = {1: [2], 2: [1], 3: [4], 4: [3]}
    Walks2 = [(1, {1, 2}), (3, {3, 4})]

    Graph3 = '10\n7\n1 2\n6 8\n8 1\n10 6\n7 5\n3 6\n6 2\n'
    AL3    = {
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
    Walks3 = [(1, {1, 2, 3, 6, 8, 10}), (4, {4}), (5, {5, 7}), (9, {9})]

    @classmethod
    def setupClass(cls):
        cls.Points = 0

    @classmethod
    def tearDownClass(cls):
        print()
        print(f'   Score {cls.Points:.2f} / {cls.Total:.2f}')
        print(f'  Status {"Success" if isclose(cls.Points, cls.Total) else "Failure"}')

    def test_00_walk_graph(self):
        cases = (
            (self.AL1, *self.Walks1[0]),
            (self.AL2, *self.Walks2[0]),
            (self.AL2, *self.Walks2[1]),
            (self.AL3, *self.Walks3[0]),
            (self.AL3, *self.Walks3[1]),
            (self.AL3, *self.Walks3[2]),
            (self.AL3, *self.Walks3[3]),
        )

        for graph, origin, group in cases:
            self.assertEqual(reddit_groups.walk_graph(graph, origin), group)
            RedditGroupsTests.Points += 1/len(cases)

        RedditGroupsTests.Points += 0.5

    def test_01_find_groups(self):
        cases = (
            (self.AL1, self.Walks1),
            (self.AL2, self.Walks2),
            (self.AL3, self.Walks3),
        )

        for graph, groups in cases:
            for group, expected in zip_longest(reddit_groups.find_groups(graph), groups):
                self.assertEqual(group, sorted(expected[1]))
            RedditGroupsTests.Points += 1/len(cases)

        RedditGroupsTests.Points += 0.5

    def test_02_main(self):
        stream    = io.StringIO(self.Graph1 + self.Graph2 + self.Graph3)
        expecteds = []

        for index, walks in enumerate((self.Walks1, self.Walks2, self.Walks3), 1):
            expecteds.append(f'Graph {index}:')
            for origin, group in walks:
                expecteds.append(f'{" ".join(map(str, group))}')

        with unittest.mock.patch('sys.stdout', new=io.StringIO()) as outputs:
            reddit_groups.main(stream)
            for output, expected in zip_longest(outputs.getvalue().splitlines(), expecteds):
                self.assertEqual(output, expected)
                RedditGroupsTests.Points += 1/len(expecteds)

# Main Execution

if __name__ == '__main__':
    unittest.main()
