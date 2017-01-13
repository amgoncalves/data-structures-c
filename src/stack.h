/* stack.h */

struct stack {
	Node * Head;	
	int maxsize;
	int currentsize;
};

typedef struct stack * Stack;

Stack stackinit(int d);
int stackisempty(Stack S);
int stackisfull(Stack S);
void push(Stack S, int d);
int pop(Stack S);
Stack reversestack(Stack S);
Stack freestack(Stack S);
int stackprint(Stack S);

int stacktest(void);
