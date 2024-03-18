#!/usr/bin/env python3

import os

# Functions

def fizzbuzz(start=1, stop=100):
    for number in range(start, stop + 1):
        if number % 3 == 0 and number % 5 == 0:
            print('FizzBuzz')
        elif number % 3 == 0:
            print('Fizz')
        elif number % 5 == 0:
            print('Buzz')
        else:
            print(number)

def main():
    fizzbuzz()

if __name__ == '__main__':
    main()
