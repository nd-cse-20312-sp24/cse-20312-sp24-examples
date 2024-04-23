#!/usr/bin/env python3

''' anagraphs.py - Anagrams '''

import sys

from treap import Treap

# Functions

def count_letters(s: str) -> Treap:
    ''' Count the occurrences of each letter in string (ignoring case).

    >>> list(count_letters('abacab').items())
    [('a', 3), ('b', 2), ('c', 1)]
    '''
    pass

def is_anagram(word1: str, word2: str) -> bool:
    ''' Determine if word1 and word2 are anagrams.

    >>> is_anagram('Anna', 'naan')
    True

    >>> is_anagram('gram', 'GraN')
    False
    '''
    pass

# Main Execution

def main(stream=sys.stdin) -> None:
    ''' For each pair of words on each line, determine if they are anagrams,
    and print out the result.

    >>> import io
    >>> main(io.StringIO('taco cat\\nanna naan\\nSiLeNt listen\\n'))
    taco and cat are not anagrams!
    anna and naan are anagrams!
    SiLeNt and listen are anagrams!
    '''
    pass

if __name__ == '__main__':
    main()

