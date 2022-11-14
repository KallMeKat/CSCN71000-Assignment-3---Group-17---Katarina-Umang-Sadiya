#include <stdio.h>
#include "testingConstants.h"
#include "unitTest.h"
#include "rangeCheck.h"

// ------------------------------------------
// So we develop our front end for testing
//   … this function acts as the entry point
//     for our mainline testHarness to get
//     at and call the function …
// ------------------------------------------
void testRC(char* testType, int value, int min, int max, int expectedResult)
{
	int	retCode = NOT_IN_RANGE;

	// let's call the rangeCheck() function first - so we can interpret the answer that 
	// comes back to output a more meaningful value

	retCode = rangeCheck(value, min, max);
	if (retCode == NOT_IN_RANGE)		// value not in range
	{
		printf("%10s%15d%15d%15d%20s", testType, value, min, max, "Not in Range");
	}
	else
	{
		printf("%10s%15d%15d%15d%20s", testType, value, min, max, "In Range");
	}

	// now determine if the retCode from rangeCheck() is what we expected according to our Test Plan
	//  - the purpose of the "expectedResult" parameter is for me (as the test case creator) to be able
	//    to capture what I think the correct/calculated answer (retCode) should be.  And this allows me
	//    to dynamically (at run-time) determine if the test behaved as I expected it to - thereby
	//    being able to report if the code that was being tested actually PASSED or FAILED the test

	if (retCode == expectedResult)
	{
		printf("%10s\n", "PASS");
	}
	else
	{
		printf("%10s\n", "FAIL");
	}
}
