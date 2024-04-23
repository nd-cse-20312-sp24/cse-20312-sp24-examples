#!/usr/bin/env python3

import doctest
import io
import unittest
import unittest.mock

from itertools import zip_longest
from math      import isclose

import passcode

# Passcode Unit Tests

class PasscodeTests(unittest.TestCase):
    ''' Passcode Unit Tests '''
    Total     = 3
    Points    = 0

    Input1    = [352, 154, 542, 315, 152]
    Graph1    = {3: {1, 5}, 5: {2, 4}, 1: {5}, 4: {2}}
    Degrees1  = {3: 0, 1: 1, 5: 2, 2: 2, 4: 1}
    Ordering1 = [3, 1, 5, 4, 2]

    Input2    = [219, 183, 804, 376, 43, 904, 357, 857, 206, 180, 983, 284, 843]
    Graph2    = {
        0: {4, 6},
        1: {8, 9},
        2: {0, 1, 8},
        3: {5, 7},
        4: {3},
        5: {7},
        7: {6},
        8: {0, 3, 4, 5},
        9: {0, 8},
    }
    Degrees2  = {2: 0, 0: 3, 1: 1, 8: 3, 9: 1, 3: 2, 4: 2, 5: 2, 6: 2, 7: 2}
    Ordering2 = [2, 1, 9, 8, 0, 4, 3, 5, 7, 6]

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
            (self.Input1, self.Graph1),
            (self.Input2, self.Graph2),
        )

        for inputs, graph in cases:
            stream = io.StringIO('\n'.join(f'{code:03d}' for code in inputs) + '\n')
            self.assertEqual(passcode.read_graph(stream), graph)
            PasscodeTests.Points += 0.5/len(cases)

        PasscodeTests.Points += 0.25

    def test_01_compute_degrees(self):
        cases = (
            (self.Graph1, self.Degrees1),
            (self.Graph2, self.Degrees2),
        )

        for graph, degrees in cases:
            self.assertEqual(passcode.compute_degrees(graph), degrees)
            PasscodeTests.Points += 0.5/len(cases)

        PasscodeTests.Points += 0.25

    def test_02_find_passcode(self):
        cases = (
            (self.Graph1, self.Ordering1),
            (self.Graph2, self.Ordering2),
        )

        for graph, ordering in cases:
            self.assertEqual(passcode.find_passcode(graph), ordering)
            PasscodeTests.Points += 0.5/len(cases)

        PasscodeTests.Points += 0.25

    def test_03_main(self):
        cases  = (
            (self.Input1, self.Ordering1),
            (self.Input2, self.Ordering2),
        )

        for inputs, ordering in cases:
            stream = io.StringIO('\n'.join(f'{code:03d}' for code in inputs) + '\n')

            with unittest.mock.patch('sys.stdout', new=io.StringIO()) as outputs:
                passcode.main(stream)
                self.assertEqual(outputs.getvalue().strip(), ''.join(map(str, ordering)))
                PasscodeTests.Points += 0.5/len(cases)

        PasscodeTests.Points += 0.25

# Main Execution

if __name__ == '__main__':
    unittest.main()

