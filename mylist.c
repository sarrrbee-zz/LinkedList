#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"
 
/*
 * Create a node that holds the given data pointer,
 * and add the node to the front of the list.
 *
 * Note that this function does not manage the lifetime of the object
 * pointed to by 'data'.
 * 
 * It returns the newly created node on success and NULL on failure.
 */
struct Node *addFront(struct List *list, void *data) {
	struct Node *currentHead = list->head;
	struct Node *node = malloc(sizeof(struct Node));
	if (node == NULL)
	{
		perror("malloc returned NULL\n");
		return NULL;
	}
	if (!currentHead) // head is null pointer
	{
		node->next = 0;
		node->data = data;
	}
	else
	{
		node->next = currentHead;
		node->data = data;
	}
	list->head = node;
	return node;
}

/*
 * Traverse the list, calling f() with each data item.
 */
void traverseList(struct List *list, void (*f)(void *)) {
	struct Node *node = list->head;
	while (node) // not null pointer
	{
		f((void *)(node->data));
		node = node->next; // move to next node 
	}
}

/*
 * Flip the sign of the double value pointed to by 'data' by
 * multiplying -1 to it and putting the result back into the memory
 * location.
 */
void flipSignDouble(void *data) {
	double *d = (double *) data;
	*d = *d * -1;
}

/*
 * Traverse the list, comparing each data item with 'dataSought' using
 * 'compar' function.  ('compar' returns 0 if the data pointed to by
 * the two parameters are equal, non-zero value otherwise.)
 *
 * Returns the first node containing the matching data, 
 * NULL if not found.
 */
struct Node *findNode(struct List *list, const void *dataSought,
	int (*compar)(const void *, const void *)) {
	struct Node *node = list->head;
	const void *data;
	while (node) // keep going so long as node not null 
	{
		data = node->data;
		if (!compar(data, dataSought))
		{
			return node;
		}
		else
		{
			node = node->next;
		}
	}
	return NULL;
}


/*
 * Compare two double values pointed to by the two pointers.
 * Return 0 if they are the same value, 1 otherwise.
 */
int compareDouble(const void *data1, const void *data2) {
	double d1 = *(double *)data1;
	double d2 = *(double *)data2;
	if (d1 == d2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
 * Remove the first node from the list, deallocate the memory for the
 * ndoe, and return the 'data' pointer that was stored in the node.
 * Returns NULL is the list is empty.
 */
void *popFront(struct List *list) {
	if(isEmptyList(list))
	{
		return NULL;
	}
	else 
	{
		struct Node *node = list->head; // first node
		struct Node *nextNode = node->next; // second node
		list->head = nextNode; // head now points to second node
		void *d = node->data; // hold on to data
		free(node);
		return d;
	}
}

/*
 * Remove all nodes from the list, deallocating the memory for the
 * nodes.  You can implement this function using popFront().
 */
void removeAllNodes(struct List *list) {
	while (!isEmptyList(list))
	{
		popFront(list);
	}
}

/*
 * Create a node that holds the given data pointer,
 * and add the node right after the node passed in as the 'prevNode'
 * parameter.  If 'prevNode' is NULL, this function is equivalent to
 * addFront().
 *
 * Note that prevNode, if not NULL, is assumed to be one of the nodes
 * in the given list.  The behavior of this function is undefined if
 * prevNode does not belong in the given list.
 *
 * Note that this function does not manage the lifetime of the object
 * pointed to by 'data'.
 * 
 * It returns the newly created node on success and NULL on failure.
 */
struct Node *addAfter(struct List *list, 
	struct Node *prevNode, void *data) {
	if (prevNode == 0)
	{
		addFront(list, data);
	}
	else 
	{
		struct Node *node = malloc(sizeof(struct Node)); // allocate space
		if (node == NULL)
		{
			perror("malloc returned NULL\n");
			return NULL;
		}
		node->next = prevNode->next;
		node->data = data;
		prevNode->next = node;	
	}

	return (findNode(list, data, &compareDouble)); // will make sure the new node is in the list
}

/* 
 * Reverse the list.
 *
 * Note that this function reverses the list purely by manipulating
 * pointers.  It does NOT call malloc directly or indirectly (which
 * means that it does not call addFront() or addAfter()).
 *
 * Implementation hint: keep track of 3 consecutive nodes (previous,
 * current, next) and move them along in a while loop.  Your function
 * should start like this:


      struct Node *prv = NULL;
      struct Node *cur = list->head;
      struct Node *nxt;

      while (cur) {
          ......


 * And at the end, prv will end up pointing to the first element of
 * the reversed list.  Don't forget to assign it to list->head.
 */
void reverseList(struct List *list) {
	struct Node *prv = NULL;
	struct Node *cur = list->head;
	struct Node *nxt;

	while (cur)
	{
		nxt = cur->next; // save for later reference - the next node
		cur->next = prv; // next now points to the one before it
		prv = cur; // prev is now the one you were looking at
		cur = nxt; // cur is now the one to the right
	}
	list->head = prv;
}



