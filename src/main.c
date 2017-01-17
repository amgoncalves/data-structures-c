/*
	main.c

	Main method in data-structures-c.
	Runs all tests from data structures modules.
*/
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"

/* Run all tests. */
void
alltests(void)
{
	printf("%s node test\n\n", nodetest() ? "Passed" : "Failed");
	printf("%s linked list test\n\n", listtest() ? "Passed" : "Failed");
	printf("%s stack test\n\n", stacktest() ? "Passed" : "Failed");
	printf("%s queue test\n\n", queuetest() ? "Passed" : "Failed");
}

int
main(void)
{
	alltests();
	return 0;
}
