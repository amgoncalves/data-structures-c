/*
	stack.c

	Linked list backed implementation of a pushdown stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack.h"

/*
	Return a pointer to the head of a new, empty stack if malloc is successful.
	Otherwise, return NULL.
*/
Stack
stackinit(int d)
{
	Stack S;
	S = malloc(sizeof *S);
	if (!S) {
		fprintf(stderr, "Malloc fail.\n");
		return NULL;	
	}
	S->Head = NULL;
	S->maxsize = d;
	S->currentsize = 0;
	return S;
}

/*
	Return 1 if stack is empty, 0 otherwise.
*/
int
stackisempty(Stack S)
{
	return (S->Head == NULL) && (S->currentsize == 0);
}

/*
	Return 1 if stack is full, 0 otherwise.
*/
int
stackisfull(Stack S)
{
	return S->currentsize >= S->maxsize;
}

/*
	Push new integer onto top of stack.
*/
void
push(Stack S, int d)
{
	if (stackisfull(S)) {
		fprintf(stderr, "Push failed, Stack is full.\n");
		return;
	}
	Node *p;
	p = makenode(d, S->Head);
	if (!p) {
		fprintf(stderr, "Push failed, malloc error.\n");
		return;
	}
	S->Head = p;
	S->currentsize++;
}

/*
	Pop integer from top of stack.
*/
int
pop(Stack S)
{
	if (stackisempty(S)) {
		fprintf(stderr, "Pop failed, Stack is empty.\n");
		return -1;
	}
	int d;
	struct node *p;
	p = S->Head;
	d = p->data;
	S->Head = p->next;
	free(p);
	S->currentsize--;
	return d;
}

/*
	Reverse contents of a stack.
*/
Stack
reversestack(Stack S)
{
	if (stackisempty(S)) {
		fprintf(stderr, "Stack is empty.\n");
		return S;
	}
	Node *p, *prev, *next;
	prev = NULL;
	for (p = S->Head; p; p = next) {
		next = p->next;		
		p->next = prev;
		prev = p;
	}
	S->Head = prev;
	return S;
}

/*
	Cleanup a stack list, return pointer to the empty stack.
*/
Stack
freestack(Stack S)
{
	if (stackisempty(S)) {
		fprintf(stderr, "Stack is empty.\n");
		return NULL;
	}
	struct node *p, *q;
	for (p = S->Head; p; p = q) {
		q = p->next;
		free(p);
	}
	S->currentsize = 0;
	return S;
}

/*
	Print contents of a stack with stats for debugging.
	Return 1 if successful, otherwise return 0.
*/
int
stackprint(Stack S)
{
	if (!S) {
		fprintf(stderr, "Stack must be initialized before printing.\n");
		return 0;
	}
	printf("Stack current size: %d | Max size: %d\n", S->currentsize, S->maxsize);
	if (stackisempty(S)) {
		puts("Stack is empty.");
		return 1;	
	}
	Node *p;
	for (p = S->Head; p; p = p->next)
		if (!nodepr(p))
			return 0;
	if (stackisfull(S))
		puts("Stack is full.");
	return 1;
}

/*
	Run stack module test:
		- Initialize new stack with specified size.
		- Fill stack with integers using push().
		- Empty stack using pop():
			-- Print "Bilbo" when an integer divisible by 3 is popped.
			-- Print "Baggins" when an integer divisible by 5 is popped.
			-- Print "BilboBaggins" when an integer divisible by 3 and 5 is popped. 
		- Free stack.

	Return 1 if test is successful, 0 otherwise.
*/
int
stacktest(void)
{
	int i, j, size;
	size = 15;
	Stack S;
	S = NULL;
	S = stackinit(size);
	if (!S)
		return 0;
	for (i = 1; i <= size; i++)
		push(S, i);
	S = reversestack(S);
	while (S->currentsize > 0) {
		j = pop(S);
		if (j % 3 == 0 && j % 5 == 0)
			puts("BilboBaggins");
		else if (j % 3 == 0)
			puts("Bilbo");
		else if (j % 5 == 0)
			puts("Baggins");
	}
	if (!stackisempty(S)) {
		fprintf(stderr, "Pop error, stack is not empty.\n");
		freestack(S);
		free(S);
		return 0;
	}
	free(S);
	return 1;
}
