/* node.h */

/*
	Each node structure contains:
	data  An integer.
	next  A pointer to the next node.
*/
struct node { 
	int data; 
  struct node *next;
};

typedef struct node node;

node * makenode(int i, node *p);
int freenode(node *p);
int nodetest(void);
