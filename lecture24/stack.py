#!/usr/bin/env python3

''' Stack Data Structure '''

from dataclasses import dataclass, field

# Class

@dataclass
class Stack:
    data: list = field(default_factory=list)

    def push(self, value):
        self.data.append(value)

    def pop(self):
        return self.data.pop()
    
    def empty(self):
        return not self.data

    def top(self):
        return self.data[-1]

    def __str__(self):
        return f'Stack({self.data})'
