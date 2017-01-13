/* linkedlist.h */

typedef Node * List;

List listmakerec(int i);
List listfree(List l);
List listreverse(List l);
List listinsertsort(List l, int i);
int listprint(List l);

int listtest(void);
