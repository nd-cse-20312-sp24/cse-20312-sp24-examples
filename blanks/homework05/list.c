#include "list.h"

/**
* Allocate a Node and initialize its value and next pointer
* @param val  value
* @param next next pointer
* @return pointer to new Node
*/
Node *node_create(int val, Node *next) {

    return NULL;
}

/**
 * Free a Node
 * @param n  Node to free
*/
void node_delete(Node *n) { 

}

/**
 * Recursively delete a linked list of Nodes
 * @param n  head of list of Nodes
*/
void list_delete(Node *head) {

}

/**
 * Append a node to the head of a linked list of Nodes
 * @param head  head of the linked list of Nodes
 * @param val   value of new Node
 * @return new head of list
*/
Node *list_append_head(Node *head, int val) { 
    return NULL;
}

/**
 * Recursively append a node to the tail of a linked list of Nodes
 * @param head  head of list
 * @param val   value of new Node
 * @return new head of list (for when list is originally empty)
 * 
 * Note that this is just for practice with recursion.  In reality, it
 * is more efficient to use a variable to keep track of the tail
 * of a linked list if you need to append values at that end.
*/
Node *list_append_tail(Node *head, int val) {
    return NULL;
}

/**
* Recursively print the Nodes in a linked list in order from
* head to tail 
* @param head   head of list
**/
void list_print(Node *head) {

}

/**
 * Split a linked list of Nodes into two sublists, left and right
 * @param head  head of original list
 * @param left  Returns the head of the left sublist via a pointer
 * @param right Returns the value of the right sublist via a pointer
 * 
 * Hints and considerations:
 * 
 * To find the middle of the list, iteratively send 2 pointers down the list,
 * a "fast" pointer that advances by 2 nodes with each iteration and a slow"
 * pointer that advances by 1 node with each iteration.  When the fast pointer
 * reaches the end of the list, the "slow" pointer will be in the middle.  When checking
 * if the fast pointer has reached the end of the list, you may need to check both the current
 * value of fast and fast->next to account for whether the list has an odd or even number of nodes
 * and to avoid running of the end of the list and dereferencing a null pointer.
 * 
 * Make sure that both the left and right subtrees are proper linked lists terminated
 * by null pointers
 * 
 * The unit tests assume that if there is an odd number of nodes, then the left subtree
 * will be 1 node longer that the right subtree and if there is an even number of nodes
 * then the left and right subtrees will be the same length.  This should happen naturally if
 * you follow the fast/slow pointer chasing approach described above.
 * 
 * Note that when calling this function, you need to pass the addresses of the heads of the
 * left and right subtrees as arguments and properly derefernce these addresses to modify
 * the heads of these lists
*/
void list_split(Node *head, Node **left, Node **right) {
    // Handle case where list has fewer than 2 Nodes (no need to split)

    // Process to split list (with 2 or more Nodes)

}

/**
 * Merge left and right subtrees into a single linked list
 * @param left  head of left subtree
 * @param right head of right subtree
 * @return head of merged linked list
 *
 * Follow the same process used in class for merging two arrays,
 * only apply it to a linked list.  You will want to define a variable
 * that keeps track of the tail of the merged list so that you don't
 * have to traverse the list everytime you want to append a Node to
 * the tail (as you had to with the recursive form of list_append_tail,
 * which is inefficient in practice)
*/
Node *list_merge(Node *left, Node *right) {
    assert(left || right);

    // if left or right is empty, simply return the other

    // Get the first element

    // Until left or right is empty add smallest head from either to tail of
    // merged list

    // Attach remainder of left or right and return

    // Return the result
    return NULL;
}

/**
 * Use merge sort to sort a linked list in increasing order
 * @param head  head of list to be sorted
 * @return head of sorted list
 * 
 * Use the same recursive algorthm that was used in class for an array,
 * except applied to a linked list.
*/
Node *list_merge_sort(Node *head) {
    // Base case: list is empty or only has 1 node
    // Return the head without sorting

    // Recursive merge sort

    return NULL;
}