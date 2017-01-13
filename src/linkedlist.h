/* linkedlist.h */

typedef Node * List;

List listmakerec(int i);
List listfree(List L);
List listreverse(List L);
List listinsertsort(List L, int i);
int listprint(List L);

int listtest(void);
