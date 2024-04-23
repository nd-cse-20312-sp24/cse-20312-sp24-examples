#!/usr/bin/env python3

import collections
import doctest
import io
# import mypy.api
import unittest
import unittest.mock

import anagrams

# Anagrams Unit Tests

class AnagramsTests(unittest.TestCase):
    ''' Anagrams Unit Tests '''
    Total  = 2
    Points = 0
    Cases  = (
        ('Anna', 'naan', True),
        ('gram', 'GraN', False),
        ('taco', 'cat', False),
        ('SiLeNt', 'listen', True),
        ('banANA', 'aNaNaB', True),
    )

    @classmethod
    def setupClass(cls):
        cls.Points = 0

    @classmethod
    def tearDownClass(cls):
        print()
        print(f'   Score {cls.Points:.2f} / {cls.Total:.2f}')
        print(f'  Status {"Success" if cls.Points >= cls.Total else "Failure"}')

    def test_00_count_letters(self):
        strings = ('nodoubt', 'dontspeak', 'tragickingdom', 'spiderwebs')
        for string in strings:
            counts1 = anagrams.count_letters(string)
            counts2 = collections.Counter(string)
            self.assertTrue(counts1.items(), sorted(counts2.items()))
            AnagramsTests.Points += 0.125
        AnagramsTests.Points += 0.2

    def test_01_is_anagram(self):
        for word1, word2, expected in self.Cases:
            self.assertEqual(anagrams.is_anagram(word1, word2), expected)
            AnagramsTests.Points += 0.1
        AnagramsTests.Points += 0.2
    
    def test_02_main(self):
        input_string  = '\n'.join(f'{word1} {word2}' for word1, word2, _ in self.Cases) + '\n'
        output_string = '\n'.join(f'{word1} and {word2} are {"" if expected else "not "}anagrams!' for word1, word2, expected in self.Cases) + '\n'
        with unittest.mock.patch('sys.stdout', new=io.StringIO()) as output:
            anagrams.main(io.StringIO(input_string))
            self.assertEqual(output.getvalue(), output_string)
            AnagramsTests.Points += 0.5
        AnagramsTests.Points += 0.1

# Main Execution

if __name__ == '__main__':
    unittest.main()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
