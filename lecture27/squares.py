#!/usr/bin/env python3

# Functions

def squares1(numbers):
    result = []
    for number in numbers:
        result.append(number ** 2)
    return result

def squares2(numbers):
    return [number ** 2 for number in numbers if number%2 == 0]
    # return [number ** 2 for number in numbers if number%2 == 0]

def squares3(numbers):
    for number in numbers:
        yield number ** 2

# Main Execution

def main():
    numbers = squares3(range(10))
    for square in numbers:
        print(square)

    print('length:     ',   len(numbers)) # Error!
    print('numbers[0]: ', numbers[0])   # Error!

if __name__ == '__main__':
    main()
