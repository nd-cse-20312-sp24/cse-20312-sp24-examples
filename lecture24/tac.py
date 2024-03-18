#!/usr/bin/env python3

import sys

from stack import Stack

# Main Execution

def main():
    stack = Stack()
    for line in sys.stdin:
        stack.push(line.rstrip())

    while not stack.empty():
        print(stack.pop())

if __name__ == '__main__':
    main()
