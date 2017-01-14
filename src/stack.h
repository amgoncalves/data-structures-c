/* stack.h */

/*
	A stack contains:
		head     A pointer to the last Node pushed onto the stack or NULL if the stack is empty.
		capacity An integer representing the maximum number of Nodes allowed in the stack.
		size An integer representing the current number of Nodes in the stack.
*/
struct stack {
	Node * head;	
	int capacity;
	int size;
};

typedef struct stack * Stack;

Stack stackinit(int d);
int stackisempty(Stack s);
int stackisfull(Stack s);
void push(Stack s, int d);
int pop(Stack s);
Stack reversestack(Stack s);
Stack freestack(Stack s);
int stackprint(Stack s);

int stacktest(void);
