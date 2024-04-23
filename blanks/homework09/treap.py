#!/usr/bin/env python3

''' treap.py - Treap '''

from bst    import Node, BST
from random import random
from typing import Optional

# Classes

class Treap(BST):

    @staticmethod
    def _rotate_left(p) -> Node:
        ''' Rotate the sub-tree at parent node to the left.

            P               CR
           / \             /  \
          CL CR     =>    P   GR
            /  \         / \
           GL  GR       CL  GL

        >>> root = Node('E', 5, left=Node('D', 4), right=Node('F', 6))
        >>> Treap._rotate_left(root)
        Node(key='F', value=6, priority=0.0, left=Node(key='E', value=5, priority=0.0, left=Node(key='D', value=4, priority=0.0, left=None, right=None), right=None), right=None)
        '''
        pass
    
    @staticmethod
    def _rotate_right(p) -> Node:
        ''' Rotate the sub-tree at parent node to the right.

            P               CL
           / \             /  \
          CL CR     =>    GL   P
         /  \                 / \
        GL  GR              GR   CR

        >>> root = Node('E', 5, left=Node('D', 4), right=Node('F', 6))
        >>> Treap._rotate_right(root)
        Node(key='D', value=4, priority=0.0, left=None, right=Node(key='E', value=5, priority=0.0, left=None, right=Node(key='F', value=6, priority=0.0, left=None, right=None)))
        '''
        pass

    def _insert(self, node: Optional[Node], key: str, value: int, priority: Optional[float]=None) -> Node:
        ''' Insert key, value pair into binary search tree starting at node.

        >>> t = Treap()
        >>> t._insert(t.root, 'E', 5, 10)
        Node(key='E', value=5, priority=10, left=None, right=None)

        >>> t._insert(t.root, 'E', 5)   # doctest: +ELLIPSIS
        Node(key='E', value=5, priority=0..., left=None, right=None)
        '''
        pass
