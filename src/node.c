/* node.c */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Returns a pointer to allocated space in memory for a node. */
node *
makenode(int i, node *p) 
{
	node *q;
	q = malloc(sizeof *q);
	if (!q) {
		fprintf(stderr, "Malloc error.\n");
		return NULL;
	}
	q->data = i;
	q->next = p;
	return q;
}

/* Frees space allocated for a node. */
int 
freenode(node *p)
{
	if (!p) {
		fprintf(stderr, "Cannot free empty node.\n");
		return 2;
	}
	free(p);
	return 0;
}

/*
	Make node, print node information, and delete node.

	Return 0 if test passed.
	Return 1 if makenode failed.
	Return 2 if freenode failed.
*/
int 
nodetest(void)
{
	node *p;
	p = makenode(10, NULL);
	if (!p)
		return 1;
	nodeprint(p);
	nodepr(p);
	return freenode(p);
}

/* Print node details. */
int
nodeprint(node *p)
{
	if (!p) {
		fprintf(stderr, "Cannot print info for nonexistent node.\n");
		return 1;
	}
	printf("Node %p: data: %d, next: %p\n", p, p->data, p->next);
	return 0;
}

/* Abbreviated nodeprint. */
int
nodepr(node *p)
{
	if (!p) {
		fprintf(stderr, "Cannot print info for nonexistent node.\n");
		return 1;
	}
	printf("%d | %p\n", p->data, p->next);
	return 0;
}


