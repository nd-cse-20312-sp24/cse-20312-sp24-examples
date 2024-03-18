#!/usr/bin/env python3

from dataclasses import dataclass

# Class

@dataclass
class Counter:
    value: int = 0

    def increment(self, n: int=1) -> None:
        ''' Increment internal value by n 

        >>> c = Counter()
        >>> c.increment()
        >>> c.value == 1
        True
        >>> c.increment(2)
        >>> c.value == 3
        True
        '''
        self.value += n

    @property
    def count(self) -> int:
        ''' Return internal value
        >>> c = Counter()
        >>> c.count
        0
        >>> c = Counter(10)
        >>> c.count
        10
        '''
        return self.value

    def __str__(self) -> str:
        return f'Counter({self.value})'

# Main Execution

def main():
    c1 = Counter()
    c2 = Counter(10)

    c1.increment()
    c2.increment()

    print(c1.count)
    print(c1)
    print(c2.count)
    print(c2)

if __name__ == '__main__':
    main()
