#!/usr/bin/env python3

import unittest

import stack

# Unit Tests

class StackTest(unittest.TestCase):
    ''' Stack Unit Tests '''

    def test_00_constructor(self):
        s = stack.Stack()
        self.assertEqual(s.data, [])
        
        d = [1, 2, 3]
        s = stack.Stack(d)
        self.assertEqual(s.data, d)

    def test_01_push(self):
        s = stack.Stack()
        self.assertEqual(s.data, [])

        d = [1, 2, 3]
        for n in d:
            s.push(n)
        self.assertEqual(s.data, d)

    def test_02_pop(self):
        s = stack.Stack()
        self.assertEqual(s.data, [])

        d = [1, 2, 3]
        for n in d:
            s.push(n)
        self.assertEqual(s.data, d)

        for i, _ in enumerate(d, 1):
            self.assertEqual(s.pop(), d[-i])
    
    def test_03_empty(self):
        s = stack.Stack()
        self.assertEqual(s.data, [])
        self.assertTrue(s.empty())

        d = [1, 2, 3]
        for n in d:
            s.push(n)
        self.assertEqual(s.data, d)
        self.assertFalse(s.empty())

        for i, _ in enumerate(d, 1):
            self.assertFalse(s.empty())
            self.assertEqual(s.pop(), d[-i])
            
        self.assertTrue(s.empty())
    
    def test_04_top(self):
        s = stack.Stack()
        self.assertEqual(s.data, [])
        self.assertTrue(s.empty())
        self.assertRaises(IndexError, s.top)

        d = [1, 2, 3]
        for n in d:
            s.push(n)
            self.assertEqual(s.top(), n)
        self.assertEqual(s.data, d)
        self.assertFalse(s.empty())

        for i, _ in enumerate(d, 1):
            self.assertFalse(s.empty())
            self.assertEqual(s.top(), d[-i])
            self.assertEqual(s.pop(), d[-i])
            
        self.assertTrue(s.empty())
        self.assertRaises(IndexError, s.top)
    
    def test_05_str(self):
        s = stack.Stack()
        self.assertEqual(s.data, [])
        self.assertEqual(str(s), 'Stack([])')
        self.assertTrue(s.empty())
        self.assertRaises(IndexError, s.top)

        d = [1, 2, 3]
        for n in d:
            s.push(n)
            self.assertEqual(s.top(), n)
        self.assertEqual(str(s), 'Stack([1, 2, 3])')
        self.assertEqual(s.data, d)
        self.assertFalse(s.empty())

        for i, _ in enumerate(d, 1):
            self.assertFalse(s.empty())
            self.assertEqual(s.top(), d[-i])
            self.assertEqual(s.pop(), d[-i])
            
        self.assertEqual(str(s), 'Stack([])')
        self.assertTrue(s.empty())
        self.assertRaises(IndexError, s.top)

# Main Execution

if __name__ == '__main__':
    unittest.main()
