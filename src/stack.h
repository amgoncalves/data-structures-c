/* stack.h */

struct stack {
	Node * head;	
	int maxsize;
	int currentsize;
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
