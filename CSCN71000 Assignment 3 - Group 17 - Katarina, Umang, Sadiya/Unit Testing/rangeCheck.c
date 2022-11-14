#include "testingConstants.h"
#include "rangeCheck.h"
// --------------------------------------------
// This is the function we want to test …
// --------------------------------------------
int rangeCheck(int checkNumber, int min, int max)
{
	int response = NOT_IN_RANGE;

	if ((checkNumber >= min) && (checkNumber <= max))
	{
		response = IN_RANGE;
	}
	return response;
}