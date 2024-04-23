#!/usr/bin/env python3

import doctest
# import mypy.api
import unittest

from itertools import zip_longest
from math      import isclose

import bst
from bst import Node, BST

# BST Unit Tests

class BSTTests(unittest.TestCase):
    ''' Node Unit Tests '''
    Total  = 5
    Points = 0

    Tree1  = Node('E', 5, 0, 
                  Node('C', 3, 0, 
                       Node('B', 2), 
                       Node('D', 4)), 
                  Node('G', 7, 0, 
                       Node('F', 6), 
                       Node('H', 8)))
    
    Tree2  = Node('D', 4, 0, 
                  Node('B', 2, 0, 
                       None, 
                       Node('C', 3)), 
                  Node('F', 6, 0, 
                       Node('E', 5), 
                       Node('H', 8, 0, 
                            Node('G', 7))))

    @classmethod
    def setupClass(cls):
        cls.Points = 0

    @classmethod
    def tearDownClass(cls):
        print()
        print(f'   Score {cls.Points:.2f} / {cls.Total:.2f}')
        print(f'  Status {"Success" if isclose(cls.Points, cls.Total) else "Failure"}')

    def test_00_search(self):
        for tree in (self.Tree1, self.Tree2):
            t = BST(tree)
            for key in 'BCDEFGH':
                self.assertTrue(t._search(t.root, key))
                BSTTests.Points += 0.025

            for key in 'AI':
                self.assertFalse(t._search(t.root, key))
                BSTTests.Points += 0.0375

        BSTTests.Points += 0.1875

    def test_01_contains(self):
        for tree in (self.Tree1, self.Tree2):
            t = BST(tree)
            for key in 'BCDEFGH':
                self.assertTrue(key in t)
                BSTTests.Points += 0.025

            for key in 'AI':
                self.assertFalse(key in t)
                BSTTests.Points += 0.0375

        BSTTests.Points += 0.1875

    def test_02_lookup(self):
        for tree in (self.Tree1, self.Tree2):
            t = BST(tree)
            for key in 'BCDEFGH':
                value = ord(key) - ord('A') + 1
                self.assertEqual(t._lookup(t.root, key), value)
                BSTTests.Points += 0.025

            for key in 'AI':
                with self.assertRaises(KeyError):
                    t._lookup(t.root, key)
                BSTTests.Points += 0.0375

        BSTTests.Points += 0.1875

    def test_03_getitem(self):
        for tree in (self.Tree1, self.Tree2):
            t = BST(tree)
            for key in 'BCDEFGH':
                value = ord(key) - ord('A') + 1
                self.assertEqual(t[key], value)
                BSTTests.Points += 0.025

            for key in 'AI':
                with self.assertRaises(KeyError):
                    t[key]
                BSTTests.Points += 0.0375

        BSTTests.Points += 0.1875

    def test_04_insert(self):
        for string, tree in (('ECGBDHF', self.Tree1), ('DFBEHCG', self.Tree2)):
            t = BST()
            for key in string:
                value  = ord(key) - ord('A') + 1
                t.root = t._insert(t.root, key, 0)          # Insert
                t.root = t._insert(t.root, key, value)      # Update
            self.assertEqual(t.root, tree)
            BSTTests.Points += 0.25

        BSTTests.Points += 0.1875

    def test_05_setitem(self):
        for string, tree in (('ECGBDHF', self.Tree1), ('DFBEHCG', self.Tree2)):
            t = BST()
            for key in string:
                value  = ord(key) - ord('A') + 1
                t[key] = 0                                  # Insert
                t[key] = value                              # Update
            self.assertEqual(t.root, tree)
            BSTTests.Points += 0.25
        BSTTests.Points += 0.1875

    def test_06_walk(self):
        for string, tree in (('BCDEFGH', self.Tree1), ('BCDEFGH', self.Tree2)):
            t = BST(tree)
            for a, b in zip_longest(t._walk(t.root), [(k, ord(k) - ord('A') + 1) for k in string]):
                self.assertEqual(a, b)
            BSTTests.Points += 0.125
        BSTTests.Points += 0.1875

    def test_07_items(self):
        for string, tree in (('BCDEFGH', self.Tree1), ('BCDEFGH', self.Tree2)):
            t = BST(tree)
            for a, b in zip_longest(t.items(), [(k, ord(k) - ord('A') + 1) for k in string]):
                self.assertEqual(a, b)
            BSTTests.Points += 0.125
        BSTTests.Points += 0.1875

# Main Execution

if __name__ == '__main__':
    unittest.main()
