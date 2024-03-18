#!/usr/bin/env python3

import sys

# Main Execution

def main(arguments=sys.argv[1:]):
    ''' Compute the average of all the command line arguments.
    
    >>> main('1 2 3'.split())
    Average of [1, 2, 3] is 2.0
    
    >>> main('3 9 6'.split())
    Average of [3, 6, 9] is 6.0
    '''
    numbers = []
    for argument in arguments:
        try:
            numbers.append(int(argument))
        except ValueError:
            pass

    try:
        average = sum(numbers) / len(numbers)
        print(f'Average of {sorted(numbers)} is {average}')
    except ZeroDivisionError:
        pass

if __name__ == '__main__':
    main()
