#!/usr/bin/env python3

import unittest
import bst
from bst import Node, Tree

class BSTTests(unittest.TestCase):

    Tree1 = Tree(Node(4, None, None))

    Tree2 = Tree(Node(4, 
                      Node(2, None, None), 
                      Node(6, None, None)))
    
    Tree3 = Tree(Node(4, 
                      Node(2, 
                           Node(1, None, None), 
                           Node(3, None, None)), 
                      Node(6,
                           Node(5, None, None),
                           Node(7, None, None))))
    
    @classmethod
    def setupClass(cls):
        pass

    @classmethod
    def tearDownClass(cls):
        pass

    def test_search(self):
        pass

    def test_insert(self):
        t = Tree()
        t.insert(4)
        self.assertEqual(t, self.Tree1)
        t.insert(2)
        t.insert(6)
        self.assertEqual(t, self.Tree2)
        t.insert(1)
        t.insert(7)
        t.insert(3)
        t.insert(5)
        self.assertEqual(t, self.Tree3)

    def test_contains(self):
        pass

if __name__ == '__main__':
    unittest.main()

