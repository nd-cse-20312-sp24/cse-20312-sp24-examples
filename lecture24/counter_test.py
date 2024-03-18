#!/usr/bin/env python3

import unittest

import counter 

# Unit Tests

class CounterTest(unittest.TestCase):
    ''' Counter Unit Tests '''

    def test_00_constructor(self):
        c = counter.Counter()
        self.assertEqual(c.value, 0)
        
        c = counter.Counter(10)
        self.assertEqual(c.value, 10)

    def test_01_increment(self):
        c = counter.Counter()
        self.assertEqual(c.value, 0)

        for i in range(1, 10):
            c.increment()
            self.assertEqual(c.value, i)
            
        c = counter.Counter()
        self.assertEqual(c.value, 0)
        c.increment(5)
        self.assertEqual(c.value, 5)

    def test_02_count(self):
        c = counter.Counter()
        self.assertEqual(c.value, 0)

        for i in range(1, 10):
            c.increment()
            self.assertEqual(c.count, i)
            
        c = counter.Counter()
        self.assertEqual(c.count, 0)
        c.increment(5)
        self.assertEqual(c.count, 5)
    
    def test_03_str(self):
        c = counter.Counter()
        self.assertEqual(c.value, 0)
        self.assertEqual(str(c), 'Counter(0)')
        
        c = counter.Counter(10)
        self.assertEqual(c.value, 10)
        self.assertEqual(str(c), 'Counter(10)')

# Main Execution

if __name__ == '__main__':
    unittest.main()
