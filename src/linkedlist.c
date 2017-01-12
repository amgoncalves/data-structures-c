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
listmake(int i) 
{
	if (i <= 0)
		return NULL;
	return makenode(i, listmake(i - 1));
}

/*
	Takes a pointer to the head of a list and frees each node in the list. 
	Returns a pointer to freed space in memory.		
*/
List
listfree(List L) 
{
	if (!L) {
		fprintf(stderr, "List is empty.\n");
		return NULL;
	}	
	node *p;
	node *q;
	for (p = L; p; p = q) {
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
listreverse(List L)
{
	if (!L) {
		fprintf(stderr, "List is empty.\n");
		return NULL;
	}	
	node *p, *next, *prev;
	prev = NULL;
	for (p = L; p; p = next) {
		next = p->next;
		p->next = prev;
		prev = p;
	}
	return prev;
}

/*
	Print a list for debugging. 
*/
int
listprint(List L)
{
	node *p;
	if (!L) {
		fprintf(stderr, "List is empty.\n");
		return 0;
	}
	puts("Printing linked list:");
	for (p = L; p; p = p->next)
		if (!nodepr(p))
			return 0;
	return 1;
}

/*
	Run linked list module test:
		- Make list of 10 nodes.
		- Print list.
		- Reverse node order.
		- Print list.
		- Free list.
		- Attempt to print empty list.

	Return 1 if test is successful, 0 otherwise.
*/
int
listtest(void)
{
	List L;
	L = listmake(10);
	if (!L)
		return 0;
	if (!listprint(L))
		return 0;
	L = listreverse(L);
	if (!listprint(L))
		return 0;
	L = listfree(L);
	if (listprint(L))
		return 0;
	return 1;
}
