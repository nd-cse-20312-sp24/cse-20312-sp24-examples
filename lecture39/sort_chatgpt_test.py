#!/usr/bin/env python3

import unittest
import sort_chatgpt

class SortTest(unittest.TestCase):
    def test_sort(self):
        test_list = [3, 1, 5, 7, 4, 9, 8, 2, 10, 6]
        sort_chatgpt.sort(test_list)
        self.assertEqual(test_list, list(range(1,11)))

if __name__ == '__main__':
    unittest.main()