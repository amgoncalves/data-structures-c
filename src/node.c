/*
	node.c

	Implementation for creating, initializing, deleting, and testing data structure nodes.
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/*
	Allocate space in memory for a node and initialize node variables.
	Return a pointer if successful, NULL otherwise.
*/
Node *
makenode(int i, Node *p) 
{
	Node *q;
	q = malloc(sizeof *q);
	if (!q) {
		fprintf(stderr, "Malloc error.\n");
		return NULL;
	}
	q->data = i;
	q->next = p;
	return q;
}

/* 
	Frees space allocated for a node.
	Return 1 if successful, 0 otherwise.
*/
int 
freenode(Node *p)
{
	if (!p) {
		fprintf(stderr, "Cannot free empty node.\n");
		return 0;
	}
	free(p);
	return 1;
}

/*
	Print node details for debugging.
*/
int
nodeprint(Node *p)
{
	if (!p) {
		fprintf(stderr, "Cannot print info for nonexistent node.\n");
		return 0;
	}
	printf("Node %p: data: %d, next: %p\n", p, p->data, p->next);
	return 1;
}

/*
	Abbreviated nodeprint.
*/
int
nodepr(Node *p)
{
	if (!p) {
		fprintf(stderr, "Cannot print info for nonexistent node.\n");
		return 0;
	}
	printf("%d | %p\n", p->data, p->next);
	return 1;
}

/*
	Run node module test: 
		- Make node.
		- Print node information.
		- Delete node.

	Return 1 if test is successful, 0 otherwise.
*/
int 
nodetest(void)
{
	Node *p;
	p = makenode(10, NULL);
	if (!p) {
		fprintf(stderr, "Node test failed on makenode.\n");
		return 0;
	}
	nodeprint(p);
	nodepr(p);
	if (!freenode(p)) {
		fprintf(stderr, "Node test failed on freenode.\n");
		return 0;
	}
	return 1; 
}
