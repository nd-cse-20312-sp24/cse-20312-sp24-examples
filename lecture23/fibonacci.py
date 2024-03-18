#!/usr/bin/env python3

import sys

# Functions

def fibonacci(n, cache={0: 0, 1: 1, 2: 1}):
    ''' Compute the nth Fibonacci number (using memoization).

    >>> [fibonacci(i) for i in range(1, 10)]
    [1, 1, 2, 3, 5, 8, 13, 21, 34]
    '''
    if n not in cache: 
        cache[n] = fibonacci(n - 1, cache) + fibonacci(n - 2, cache)
    return cache[n]

# Main Execution

def main():
    for line in sys.stdin:
        n = int(line)
        print(f'fibonacci({n}) = {fibonacci(n)}')

if __name__ == '__main__':
    main()
