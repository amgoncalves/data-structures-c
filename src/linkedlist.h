/* linkedlist.h */

/*
	A linked list is a pointer to the head of a list of Nodes.
*/
typedef Node * List;

List listmakerec(int i);
List listfree(List l);
List listreverse(List l);
List listinsertsort(List l, int i);
int listprint(List l);

int listtest(void);
