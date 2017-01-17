/*
	queue.c

	Implementation of a circular, FIFO queue data structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

/*
	Initialize a new Queue.
	Returns a pointer to allocated space in memory for a Queue with capacity i.
*/
Queue
queueinit(int i)
{
	Queue q;
	q = malloc(sizeof q);
	q->container = malloc(i * sizeof q->container);
	if (!q) {
		fprintf(stderr, "Malloc fail.\n");
		return NULL;
	}
	q->capacity = i;
	int j;
	for (j = 0; j < q->capacity; j++)
		q->container[j] = -999;
	q->size = 0;
	q->head = 0;
	q->tail = 0;
	return q;
}

/*
	Returns 1 if queue is empty, 0 otherwise.
*/
int 
queueisempty(Queue q) 
{
	return q->size == 0;
}

/*
	Returns 1 if queue is full, 0 otherwise.
*/
int
queueisfull(Queue q)
{
	return q->size >= q->capacity;
}
/*
	Enqueue a node at the queue's tail using the circular method.
	Return 1 if successful, 0 otherwise.
*/
int 
enqueue(Queue q, int i) 
{
	if (queueisfull(q)) {
		fprintf(stderr, "Enqueue error: queue is full.\n");
		return 0;
	}
	/*
	if (!isdigit(i)) {
		fprintf(stderr, "Cannot enqueue a non-digit.\n");
		return 0;
	}
	*/ 
	q->container[q->tail] = i;
	q->tail = increment(q, q->tail);
	q->size++;
	return 1;
}

/*
	Return incremented index if within array bounds, 0 otherwise.
*/
static int
increment(Queue q, int index)
{
	if (index++ >= q->capacity)
		return 0;
	return index++;
}

/*
	Dequeue an integer at head index.
	Return the integer if successful.
*/
int
dequeue(Queue q) 
{
	int i;
	assert(!queueisempty(q));
	i = q->container[q->head];
	q->container[q->head] = -999;
	q->head = increment(q, q->head);
	q->size--;
	return i;
}

/*
	Deallocate memory for a queue pointer and its container array.
	Return 1 if successful, 0 otherwise.
*/
int
queuefree(Queue q) {
	if (!q) {
		fprintf(stderr, "Cannot free unallocated Queue.\n");
		return 0;
	}
	puts("Freeing container");
	free(q->container);
	puts("Freeing queue");
	free(q);
	return 1;
}

/*
	Print a queue for debugging.
*/
int
queueprint(Queue q) 
{
	int i;
	if (queueisempty(q)) {
		puts("Queue is empty.");
		return 1;
	}
	puts("Printing Queue:");
	for (i = q->head; i != q->tail; i = increment(q, i))
		printf("Index %d: %d\n", i, q->container[i]);
	puts("Printing Queue stats:");
	printf("Queue size: %d\n", q->size);
	return 1;
}

/*
	Run queue module test:
		- Initialize new queue with specified size.
		- Enqueue and dequeue integer a.
		- Enqueue integers 1 through 15.
		- Empty queue using dequeue():
			-- Print "Blue" when an integer divisible by 3 is dequeued.
			-- Print "Red" when an integer divisible by 5 is dequeued.
			-- Print "Purple" when an integer divisible by 3 and 5 is dequeued.
		- Free queue.

	Return 1 if test is successful, 0 otherwise.
*/
int
queuetest(void)
{
	Queue q; 
	int i, j, a, size;
	size = 15;
	a = -1;
	q = queueinit(size);
	if (!q)
		return 0;
	if (!queueisempty(q) && !queueisfull(q))
		return 0;
	if (!enqueue(q, a) || dequeue(q) != -1)
		return 0;
	for (i = 1; i <= size; i++) 
		enqueue(q, i);
	if (!queueprint(q))
		return 0;
	while (!queueisempty(q)) {
			j = dequeue(q);
		if (j % 3 == 0 && j % 5 == 0)
			puts("Purple");
		else if (j % 3 == 0)
			puts("Blue");
		else if (j % 5 == 0)
			puts("Red");
	}
	if (!queuefree(q))
		return 0;
	return 1;
}
