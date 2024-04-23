#!/usr/bin/env python3

import doctest
# import mypy.api
import unittest

from copy      import deepcopy
from itertools import zip_longest

import treap
from treap import Node, Treap

# Treap Unit Tests

class TreapTests(unittest.TestCase):
    ''' Node Unit Tests '''
    Total  = 3
    Points = 0

    Tree1  = Node('B', 2, 0, 
                  Node('A', 1), 
                  Node('C', 3))
    
    Tree2  = Node('A', 1, 0, 
                  None, 
                  Node('B', 2, 0, 
                       None, 
                       Node('C', 3)))
    
    Tree3  = Node('C', 3, 0, 
                  Node('B', 2, 0, 
                       Node('A', 1)))

    Tree4  = Node('D', 4, 0, 
                  Node('B', 2, 0, 
                       Node('A', 1), 
                       Node('C', 3)), 
                  Node('E', 5))
    
    Tree5  = Node('B', 2, 0, 
                  Node('A', 1), 
                  Node('D', 4, 0, 
                       Node('C', 3), 
                       Node('E', 5)))

    Tree6  = Node('F', 1, 76, 
                  Node('C', 3, 70, 
                       Node('A', 4, 55), 
                       Node('D', 0, 60)), 
                  Node('H', 2, 14))
    
    Input6 = (('D', 60), ('F', 76), ('H', 14), ('C', 70), ('A', 55))

    Tree7  = Node('E', 1, 50, 
                  Node('D', 3, 30), 
                  Node('G', 2, 25, 
                       Node('F', 0, 10)))
    
    Input7 = (('F', 10), ('E', 50), ('G', 25), ('D', 30))

    @classmethod
    def setupClass(cls):
        cls.Points = 0

    @classmethod
    def tearDownClass(cls):
        print()
        print(f'   Score {cls.Points:.2f} / {cls.Total:.2f}')
        print(f'  Status {"Success" if cls.Points >= cls.Total else "Failure"}')

    def test_00_rotate_left(self):
        for old, new in ((self.Tree1, self.Tree3), (self.Tree2, self.Tree1), (self.Tree5, self.Tree4)):
            self.assertEqual(Treap._rotate_left(deepcopy(old)), new)
            TreapTests.Points += 0.125
        TreapTests.Points += 0.25

    def test_01_rotate_right(self):
        for old, new in ((self.Tree1, self.Tree2), (self.Tree3, self.Tree1), (self.Tree4, self.Tree5)):
            self.assertEqual(Treap._rotate_right(deepcopy(old)), new)
            TreapTests.Points += 0.125
        TreapTests.Points += 0.25

    def test_02_insert(self):
        for pairs, tree in ((self.Input6, self.Tree6), (self.Input7, self.Tree7)):
            t = Treap()
            for value, (key, priority) in enumerate(pairs):
                t.root = t._insert(t.root, key, value, priority)
            self.assertEqual(t.root, tree)
            TreapTests.Points += 0.25
        TreapTests.Points += 0.25

    def test_03_setitem(self):
        def is_max_heap(node):
            if not node:
                return True

            if (node.left and node.priority < node.left.priority) or (node.right and node.priority < node.right.priority):
                return False

            return is_max_heap(node.left) and is_max_heap(node.right)

        strings = ['dontspeak', 'nodoubt', 'tragickingdom']
        for string in strings:
            t = Treap()
            for key in string:
                t[key] = 0          # Insert
                t[key] = ord(key)   # Update

            keys   = [key for key, _ in t.items()]
            values = [value for _, value in t.items()]
            self.assertEqual(keys, sorted(set(string)))
            self.assertEqual(values, [ord(key) for key in sorted(set(string))])
            self.assertTrue(is_max_heap(t.root))
            TreapTests.Points += 0.25
        TreapTests.Points += 0.25

# Main Execution

if __name__ == '__main__':
    unittest.main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
