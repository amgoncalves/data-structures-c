/*
	linkedlist.c

	Implementation of a singly linked list data structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"

/*
	Takes an integer and creates a linked list with number of nodes equal to i. 
	Returns a pointer to the head of the linked list.
*/
List
listmakerec(int i) 
{
	if (i <= 0)
		return NULL;
	return makenode(i, listmakerec(i - 1));
}

/*
	Takes a pointer to the head of a list and frees each node in the list. 
	Returns a pointer to freed space in memory.		
*/
List
listfree(List l) 
{
	if (!l) {
		fprintf(stderr, "List is empty.\n");
		return NULL;
	}	
	Node *p;
	Node *q;
	for (p = l; p; p = q) {
		q = p->next;
		freenode(p);
	}
	return p;
}

/*
	Takes a pointer to the head of a linked list and reverses the direction of each node's next pointer.
	Returns a pointer to the head of the reversed list.
*/
List
listreverse(List l)
{
	if (!l) {
		fprintf(stderr, "List is empty.\n");
		return NULL;
	}	
	Node *p, *next, *prev;
	prev = NULL;
	for (p = l; p; p = next) {
		next = p->next;
		p->next = prev;
		prev = p;
	}
	return prev;
}

/*
	Insert an integer into a numerically sorted list.
	List head is lowest value, list tail is the greatest.
*/
List
listinsertsort(List l, int i)
{
	Node *p, *q, *prev;
	p = makenode(i, NULL);
	if (!p) {
		fprintf(stderr, "Could not insert int, malloc error.\n");
		return l;
	}
	/* Check if int should be inserted at list head. */
	q = l;
	if (q->data >= i) {
		p->next = l;
		l = p;
		return l;
	}
	/* Search for int within list. */
	prev = q;
	for (q = l->next; q; q = q->next) {
		if (q->data >= i) {
			p->next = q;
			prev->next = p;
			break;
		}
		prev = q;
	}
	/* Check if int should be inserted at list tail. */
	if (!q)
		prev->next = p;
	return l;
}

/*
	Print a list for debugging. 
*/
int
listprint(List l)
{
	Node *p;
	if (!l) {
		fprintf(stderr, "List is empty.\n");
		return 0;
	}
	puts("Printing linked list:");
	for (p = l; p; p = p->next)
		if (!nodepr(p))
			return 0;
	return 1;
}

/*
	Run linked list module test:
		- Make list of 10 nodes.
		- Print list.
		- Reverse node order.
		- Add the following integers: 1, 10, 105, 0, -20
		- Print list.
		- Free list.
		- Attempt to print empty list.

	Return 1 if test is successful, 0 otherwise.
*/
int
listtest(void)
{
	List l;
	int arr[] = { 1, 10, 105, 0, -20 };
	int i, arrsize = 5;
	l = listmakerec(10);
	if (!l)
		return 0;
	if (!listprint(l))
		return 0;
	l = listreverse(l);
	for (i = 0; i < arrsize; i++) 
		l = listinsertsort(l, arr[i]);
	if (!listprint(l))
		return 0;
	l = listfree(l);
	if (listprint(l))
		return 0;
	free(l);
	return 1;
}
