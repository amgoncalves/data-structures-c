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
	Stack s;
	s = malloc(sizeof *s);
	if (!s) {
		fprintf(stderr, "Malloc fail.\n");
		return NULL;	
	}
	s->head = NULL;
	s->capacity = d;
	s->size = 0;
	return s;
}

/*
	Return 1 if stack is empty, 0 otherwise.
*/
int
stackisempty(Stack s)
{
	return (s->head == NULL) && (s->size == 0);
}

/*
	Return 1 if stack is full, 0 otherwise.
*/
int
stackisfull(Stack s)
{
	return s->size >= s->capacity;
}

/*
	Push new integer onto top of stack.
*/
void
push(Stack s, int d)
{
	if (stackisfull(s)) {
		fprintf(stderr, "Push failed, Stack is full.\n");
		return;
	}
	Node *p;
	p = makenode(d, s->head);
	if (!p) {
		fprintf(stderr, "Push failed, malloc error.\n");
		return;
	}
	s->head = p;
	s->size++;
}

/*
	Pop integer from top of stack.
*/
int
pop(Stack s)
{
	if (stackisempty(s)) {
		fprintf(stderr, "Pop failed, Stack is empty.\n");
		return -1;
	}
	int d;
	Node *p;
	p = s->head;
	d = p->data;
	s->head = p->next;
	free(p);
	s->size--;
	return d;
}

/*
	Reverse contents of a stack.
*/
Stack
reversestack(Stack s)
{
	if (stackisempty(s)) {
		fprintf(stderr, "Stack is empty.\n");
		return s;
	}
	Node *p, *prev, *next;
	prev = NULL;
	for (p = s->head; p; p = next) {
		next = p->next;		
		p->next = prev;
		prev = p;
	}
	s->head = prev;
	return s;
}

/*
	Cleanup a stack list, return pointer to the empty stack.
*/
Stack
freestack(Stack s)
{
	if (stackisempty(s)) {
		fprintf(stderr, "Stack is empty.\n");
		return NULL;
	}
	Node *p, *q;
	for (p = s->head; p; p = q) {
		q = p->next;
		free(p);
	}
	s->size = 0;
	return s;
}

/*
	Print contents of a stack with stats for debugging.
	Return 1 if successful, otherwise return 0.
*/
int
stackprint(Stack s)
{
	if (!s) {
		fprintf(stderr, "Stack must be initialized before printing.\n");
		return 0;
	}
	printf("Stack current size: %d | Max size: %d\n", s->size, s->capacity);
	if (stackisempty(s)) {
		puts("Stack is empty.");
		return 1;	
	}
	Node *p;
	for (p = s->head; p; p = p->next)
		if (!nodepr(p))
			return 0;
	if (stackisfull(s))
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
	Stack s;
	s = NULL;
	s = stackinit(size);
	if (!s)
		return 0;
	for (i = 1; i <= size; i++)
		push(s, i);
	s = reversestack(s);
	while (s->size > 0) {
		j = pop(s);
		if (j % 3 == 0 && j % 5 == 0)
			puts("BilboBaggins");
		else if (j % 3 == 0)
			puts("Bilbo");
		else if (j % 5 == 0)
			puts("Baggins");
	}
	if (!stackisempty(s)) {
		fprintf(stderr, "Pop error, stack is not empty.\n");
		freestack(s);
		free(s);
		return 0;
	}
	free(s);
	return 1;
}
