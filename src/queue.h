/* 
	queue.h
*/

/*
	A Queue contains:	
		container		A pointer to an array of integers.
		capacity		Size of the container array.
		size				The current number of enqueued integers.
		head				The index of queue head in container.
		tail				The index of queue tail in container.
*/
struct queue {
	int * container;
	int capacity, size, head, tail;
};

typedef struct queue * Queue;

Queue queueinit(int i);
int queueisempty(Queue q);
int queueisfull(Queue q);
int enqueue(Queue q, int i); 
int dequeue(Queue q);
static int increment(Queue q, int index);
int queueprint(Queue q);
int queuefree(Queue q);

int queuetest(void);
