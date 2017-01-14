/* node.h */

/*
	A Node contains:
		data  An integer.
		next  A pointer to the next node.
*/
struct node { 
	int data; 
  struct node * next;
};

typedef struct node Node;

Node * makenode(int i, Node *p);
int freenode(Node *p);
int nodeprint(Node *p);
int nodepr(Node *p);

int nodetest(void);
