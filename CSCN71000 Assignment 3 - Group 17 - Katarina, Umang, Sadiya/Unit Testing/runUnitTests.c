#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "testingConstants.h"
#include "unitTest.h"

// ------------------------------------------------
// Then we develop our mainline testHarness
// which tests the function via the front-end
// ------------------------------------------------
int main(void)
{

	// set up a nice output table so we can view the results
	printf("Unit test for rangeCheck()\n");
	printf("%10s%15s%15s%15s%20s%10s\n", "Type", "Value", "Min", "Max", "Result", "Test");

	// ====================================================
	// Functional Testing : Normal Testing 
	// ====================================================
	testRC("Functional", 10, 1, 100, IN_RANGE);
	testRC("Functional", 14, 10, 100, IN_RANGE);
	testRC("Functional", -7, -15, -3, IN_RANGE);
	// …

		// ====================================================
		// Exception Testing
		// ====================================================
	testRC("Exception", -3, 4, 18, NOT_IN_RANGE);
	testRC("Exception", -1000, -100, 30000, NOT_IN_RANGE);
	// …

		// ====================================================
		// Boundary Testing
		// ====================================================
	testRC("Boundary", 5, 5, 10, IN_RANGE);
	testRC("Boundary", 10, 5, 10, IN_RANGE);
	testRC("Boundary", 5 + 1, 5, 10, IN_RANGE);
	testRC("Boundary", 5 - 1, 5, 10, NOT_IN_RANGE);
	testRC("Boundary", INT_MIN, INT_MIN, INT_MAX, IN_RANGE);
	testRC("Boundary", INT_MAX, INT_MIN, INT_MAX, IN_RANGE);
	testRC("Boundary", INT_MIN, INT_MIN + 1, INT_MAX, NOT_IN_RANGE);
	testRC("Boundary", INT_MIN + 1, INT_MIN + 1, INT_MAX, IN_RANGE);


	return 0;
}
