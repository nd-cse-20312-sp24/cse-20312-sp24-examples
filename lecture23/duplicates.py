#!/usr/bin/env python3

import random

# Constants

NUMBERS_MAX = 1<<12

# Functions

def make_random_array(n=NUMBERS_MAX):
    return [
        random.randint(0, NUMBERS_MAX*NUMBERS_MAX)
        for _ in range(n)
    ]

def has_duplicates_set(numbers):
    seen = set()
    for number in numbers:
        if number in seen:
            return True
        seen.add(number)
    return False

def has_duplicates_sorting(numbers):
    numbers.sort()
    for index in range(1, len(numbers)):
        if numbers[index] == numbers[index - 1]:
            return True
    return False

# Main Execution

def main():
    has_duplicates = has_duplicates_set
    numbers        = make_random_array()
    print("Yeah" if has_duplicates(numbers) else "Nope")

if __name__ == '__main__':
    main()
