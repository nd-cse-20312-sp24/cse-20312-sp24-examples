#!/usr/bin/env python3

from dataclasses import dataclass

# Class

@dataclass
class Counter:
    value: int = 0

    def increment(self, n: int=1) -> None:
        self.value += n

    @property
    def count(self) -> int:
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
