/*
	main.c

	Main method in data-structures-c.
	Runs all tests from data structures modules.
*/
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Run all tests. */
void
alltests(void)
{
	printf("%s node test\n", nodetest() ? "Passed" : "Failed");

}

int
main(void)
{
	alltests();
	return 0;
}
