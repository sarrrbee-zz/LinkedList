# LinkedList - Class Project Instructions:
Your job is to implement a generic singly linked list that can hold
any data type.  The interface has been specified and provided to you
in a header file called mylist.h.  So your job is to write mylist.c
that implements each function whose prototype is included in mylist.h.
Specifically, you are asked to write the following functions:

    struct Node *addFront(struct List *list, void *data)

    void traverseList(struct List *list, void (*f)(void *))

    void flipSignDouble(void *data)

    int compareDouble(const void *data1, const void *data2)

    struct Node *findNode(struct List *list, const void *dataSought,
            int (*compar)(const void *, const void *))

    void *popFront(struct List *list)

    void removeAllNodes(struct List *list)

    struct Node *addAfter(struct List *list, 
            struct Node *prevNode, void *data)

    void reverseList(struct List *list)

The header file contains detailed comments specifying the behavior of
the functions.  Your implementation should follow the specified
behavior.

In addition, I provide you with a test driver program, mylist-test.c, which
produces the following output for a correctly implemented linked list:

    testing addFront(): 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
    testing flipSignDouble(): -9.0 -8.0 -7.0 -6.0 -5.0 -4.0 -3.0 -2.0 -1.0 
    testing flipSignDouble() again: 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
    testing findNode(): OK
    popped 9.0, the rest is: [ 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
    popped 8.0, the rest is: [ 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
    popped 7.0, the rest is: [ 6.0 5.0 4.0 3.0 2.0 1.0 ]
    popped 6.0, the rest is: [ 5.0 4.0 3.0 2.0 1.0 ]
    popped 5.0, the rest is: [ 4.0 3.0 2.0 1.0 ]
    popped 4.0, the rest is: [ 3.0 2.0 1.0 ]
    popped 3.0, the rest is: [ 2.0 1.0 ]
    popped 2.0, the rest is: [ 1.0 ]
    popped 1.0, the rest is: [ ]
    testing addAfter(): 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 
    popped 1.0, and reversed the rest: [ 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 ]
    popped 9.0, and reversed the rest: [ 2.0 3.0 4.0 5.0 6.0 7.0 8.0 ]
    popped 2.0, and reversed the rest: [ 8.0 7.0 6.0 5.0 4.0 3.0 ]
    popped 8.0, and reversed the rest: [ 3.0 4.0 5.0 6.0 7.0 ]
    popped 3.0, and reversed the rest: [ 7.0 6.0 5.0 4.0 ]
    popped 7.0, and reversed the rest: [ 4.0 5.0 6.0 ]
    popped 4.0, and reversed the rest: [ 6.0 5.0 ]
    popped 6.0, and reversed the rest: [ 5.0 ]
    popped 5.0, and reversed the rest: [ ]

This model output is also provided to you in mylist-test-output.txt.  

I recommend you implement the functions in the order listed, and test each
function as you go.  You can start by commenting out the code in main() of
mylist-test.c and uncomment the code one block at a time to test each list
function you implemented, comparing your output with that of
mylist-test-output.txt.  The 'diff' UNIX command may come in handy.

Note that mylist-test.c may not test every single function.  You are still
responsible for correct implementations of all functions.

Don't forget to run valgrind at each step to make sure you don't have a
memory bug, and don't forget to include the valgrind output in your
README.txt when you're done.
