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
	return freenode(p);
}
