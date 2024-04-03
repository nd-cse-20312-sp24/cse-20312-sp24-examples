#!/usr/bin/env python3

# Functions

def squares1(numbers):
    pass

def squares2(numbers):
    pass

def squares3(numbers):
    pass

# Main Execution

def main():
    numbers = squares1(range(1_000_000))
    for square in numbers:
        print(square)

    print(len(numbers)) # Error!
    print(numbers[0])   # Error!

if __name__ == '__main__':
    main()
