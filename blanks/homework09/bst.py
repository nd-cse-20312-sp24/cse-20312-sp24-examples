#!/usr/bin/env python3

''' bst.py - Binary Search Tree '''

from dataclasses import dataclass
from typing      import Iterator, Optional

# Classes

@dataclass
class Node:
    key:        str
    value:      int
    priority:   float = 0.0
    left:       Optional['Node'] = None
    right:      Optional['Node'] = None

@dataclass
class BST:
    root:   Optional[Node] = None

    def _search(self, node: Optional[Node], key: str) -> bool:
        ''' Search binary search tree starting at node for key.

        >>> bst = BST(Node('E', 5, 0, Node('C', 3, 0, Node('B', 2), Node('D', 4)), Node('G', 7, 0, Node('F', 6), Node('H', 8))))
        >>> all(bst._search(bst.root, k) for k in 'BCDEFGH')
        True

        >>> any(bst._search(bst.root, k) for k in 'AI')
        False
        '''
        pass

    def __contains__(self, key: str) -> bool:
        ''' Return whether or not key is in the Binary Search Tree.

        >>> bst = BST(Node('E', 5, 0, Node('C', 3, 0, Node('B', 2), Node('D', 4)), Node('G', 7, 0, Node('F', 6), Node('H', 8))))
        >>> all(k in bst for k in 'BCDEFGH')
        True

        >>> any(k in bst for k in 'AI')
        False
        '''
        pass

    def _lookup(self, node: Optional[Node], key: str) -> int:
        ''' Lookup value corresponding to key in binary search tree starting at
        node.

        >>> bst = BST(Node('E', 5, 0, Node('C', 3, 0, Node('B', 2), Node('D', 4)), Node('G', 7, 0, Node('F', 6), Node('H', 8))))
        >>> [bst._lookup(bst.root, k) for k in 'BCDEFGH']
        [2, 3, 4, 5, 6, 7, 8]

        >>> bst._lookup(bst.root, 'A')
        Traceback (most recent call last):
        KeyError
        '''
        pass
    
    def __getitem__(self, key: str) -> int:
        ''' Get value corresponding to key in binary search tree.

        >>> bst = BST(Node('E', 5, 0, Node('C', 3, 0, Node('B', 2), Node('D', 4)), Node('G', 7, 0, Node('F', 6), Node('H', 8))))
        >>> [bst[k] for k in 'BCDEFGH']
        [2, 3, 4, 5, 6, 7, 8]

        >>> bst['A']
        Traceback (most recent call last):
        KeyError
        '''
        pass

    def _insert(self, node: Optional[Node], key: str, value: int) -> Node:
        ''' Insert key, value pair into binary search tree starting at node.

        >>> bst = BST()
        >>> bst._insert(bst.root, 'E', 5)
        Node(key='E', value=5, priority=0.0, left=None, right=None)
        '''
        pass

    def __setitem__(self, key: str, value: int) -> None:
        ''' Set value corresponding to key in binary search tree.

        >>> bst = BST()
        >>> bst['E'] = 5
        >>> bst.root
        Node(key='E', value=5, priority=0.0, left=None, right=None)

        >>> bst['D'] = 4
        >>> bst.root
        Node(key='E', value=5, priority=0.0, left=Node(key='D', value=4, priority=0.0, left=None, right=None), right=None)
        '''
        pass

    def _walk(self, node: Optional[Node]) -> Iterator[tuple[str, int]]:
        ''' Walk binary search tree to generate all key, value pairs.

        >>> bst = BST(Node('E', 5, 0, Node('C', 3, 0, Node('B', 2), Node('D', 4)), Node('G', 7, 0, Node('F', 6), Node('H', 8))))
        >>> list(bst._walk(bst.root))
        [('B', 2), ('C', 3), ('D', 4), ('E', 5), ('F', 6), ('G', 7), ('H', 8)]
        '''
        pass
    
    def items(self) -> Iterator[tuple[str, int]]:
        ''' Generate all key, value pairs in binary search tree.

        >>> bst = BST(Node('E', 5, 0, Node('C', 3, 0, Node('B', 2), Node('D', 4)), Node('G', 7, 0, Node('F', 6), Node('H', 8))))
        >>> list(bst.items())
        [('B', 2), ('C', 3), ('D', 4), ('E', 5), ('F', 6), ('G', 7), ('H', 8)]
        '''
        pass

    def _str(self, node: Optional[Node], level: int) -> str:
        ''' Recursive helper function to generate a pretty-printed string representation of a BST
        '''
        string = ''
        # Base case: Non-existent node
        if not node:
            return string

        # Recursive: Print in order
        # Note right is printed first so it displays correctly in terminal
        string += self._str(node.right, level + 1)
        string += level * '          '
        string += f"({node.key}, {node.value}, {node.priority})\n"
        string += self._str(node.left, level + 1)
        return string

    def __str__(self) -> str:
        ''' Magic method to generate a pretty printed string representation of a BST
        
        >>> bst = BST(Node('E', 5, 0, Node('C', 3, 0, Node('B', 2), Node('D', 4)), Node('G', 7, 0, Node('F', 6), Node('H', 8))))
        >>> print(bst, end='')
                            (H, 8, 0.0)
                  (G, 7, 0)
                            (F, 6, 0.0)
        (E, 5, 0)
                            (D, 4, 0.0)
                  (C, 3, 0)
                            (B, 2, 0.0)
        '''
        return self._str(self.root, 0)