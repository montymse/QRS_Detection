#include "filterTester.h"
#include "filters.h"
#include "sensor.h"

void testLowPassFilter()
{
	int x[LOW_PASS_INPUT_SIZE] = { 0 };
	int y[LOW_PASS_OUTPUT_SIZE] = {0};
	int fail = 0;

	int inputCounter = 0;

	/* open the expected input file */
	FILE * ecgFile = openfile("ECG.txt");

	/* open the output file */
	FILE * lowOutFile = openfile("x_low.txt");

	/* loop until you reach the end of the file */
	while(!feof(ecgFile))
	{
		x[inputCounter%LOW_PASS_INPUT_SIZE] = getNextData(ecgFile);

		// stop it reading too far in the file (or last value is always 0 for empty line at end)
		if (feof(ecgFile))
		{
			break;
		}

		int filteredValue = lowPassFilter(y, x, inputCounter);
		y[inputCounter % LOW_PASS_OUTPUT_SIZE] = filteredValue;

		int nextInTestOutput = getNextData(lowOutFile);

		if (filteredValue != nextInTestOutput)
		{
			printf("Low pass filter test failed!\n");
			fail = 1;
			break;
		}

		inputCounter++;
	}

	if (fail == 0)
	{
		printf("Low pass filter test passed!\n");
	}

	/* close the files */
	fclose(ecgFile);
	fclose(lowOutFile);
}

void testHighPassFilter()
{
	int x[HIGH_PASS_INPUT_SIZE] = { 0 };
	int y[HIGH_PASS_OUTPUT_SIZE] = {0};

	int fail = 0;

	int inputCounter = 0;

	/* open the input file */
	FILE * lowTestFile = openfile("x_low.txt");

	/* open the expected output file */
	FILE * highOutFile = openfile("x_high.txt");

	/* loop until you reach the end of the file */
	while(!feof(lowTestFile))
	{
		x[inputCounter%HIGH_PASS_INPUT_SIZE] = getNextData(lowTestFile);

		// stop it reading too far in the file (or last value is always 0 for empty line at end)
		if (feof(lowTestFile))
		{
			break;
		}

		int filteredValue = highPassFilter(y, x, inputCounter);
		y[inputCounter % HIGH_PASS_OUTPUT_SIZE] = filteredValue;

		int nextInTestOutput = getNextData(highOutFile);

		if (filteredValue != nextInTestOutput)
		{
			printf("High pass filter test failed!\n");
			fail = 1;
			break;
		}

		inputCounter++;
	}

	if (fail == 0)
	{
		printf("High pass filter test passed!\n");
	}

	/* close the files */
	fclose(lowTestFile);
	fclose(highOutFile);
}

void testDerivativeFilter()
{
	int x[DERIVATIVE_INPUT_SIZE] = { 0 };

	int fail = 0;

	int inputCounter = 0;

	/* open the input file */
	FILE* highTestFile = openfile("x_high.txt");

	/* open the expected output file */
	FILE* derOutputFile = openfile("x_der.txt");

	/* loop until you reach the end of the file */
	while (!feof(highTestFile))
	{
		x[inputCounter % DERIVATIVE_INPUT_SIZE] = getNextData(highTestFile);

		// stop it reading too far in the file (or last value is always 0 for empty line at end)
		if (feof(highTestFile))
		{
			break;
		}

		int filteredValue = derivativeFilter(x, inputCounter);

		int nextInTestOutput = getNextData(derOutputFile);

		if (filteredValue != nextInTestOutput)
		{
			printf("Derivative filter test failed!\n");
			fail = 1;
			break;
		}

		inputCounter++;
	}

	if (fail == 0)
	{
		printf("Derivative filter test passed!\n");
	}

	/* close the files */
	fclose(highTestFile);
	fclose(derOutputFile);
}


void testSquaringFilter()
{
	int x[SQUARING_INPUT_SIZE] = { 0 };

	int fail = 0;

	int inputCounter = 0;

	/* open the input file */
	FILE* derTestFile = openfile("x_der.txt");

	/* open the expected output file */
	FILE* sqrOutputFile = openfile("x_sqr.txt");

	/* loop until you reach the end of the file */
	while (!feof(derTestFile))
	{
		x[inputCounter % SQUARING_INPUT_SIZE] = getNextData(derTestFile);

		// stop it reading too far in the file (or last value is always 0 for empty line at end)
		if (feof(derTestFile))
		{
			break;
		}

		int filteredValue = squaringFilter(x, inputCounter);

		int nextInTestOutput = getNextData(sqrOutputFile);

		if (filteredValue != nextInTestOutput)
		{
			printf("Squaring filter test failed!\n");
			fail = 1;
			break;
		}

		inputCounter++;
	}

	if (fail == 0)
	{
		printf("Squaring filter test passed!\n");
	}

	/* close the files */
	fclose(derTestFile);
	fclose(sqrOutputFile);
}

void testMwiFilter()
{
	int x[MOVING_WINDOW_INPUT_SIZE] = { 0 };

	int fail = 0;

	int inputCounter = 0;

	/* open the input file */
	FILE* sqrTestFile = openfile("x_sqr.txt");

	/* open the expected output file */
	FILE* mwiAfterTestFile = openfile("x_mwi_div_after.txt");

	/* loop until you reach the end of the file */
	while (!feof(sqrTestFile))
	{
		x[inputCounter % MOVING_WINDOW_INPUT_SIZE] = getNextData(sqrTestFile);

		// stop it reading too far in the file (or last value is always 0 for empty line at end)
		if (feof(sqrTestFile))
		{
			break;
		}

		int filteredValue = mwiFilter(x, inputCounter);

		int nextInTestOutput = getNextData(mwiAfterTestFile);

		if (filteredValue != nextInTestOutput)
		{
			printf("MWI filter test failed!\n");
			fail = 1;
			break;
		}

		inputCounter++;
	}

	if (fail == 0)
	{
		printf("MWI filter test passed!\n");
	}

	/* close the files */
	fclose(sqrTestFile);
	fclose(mwiAfterTestFile);
}

void testAllFiltersChainedTogether()
{
	int xInput[LOW_PASS_INPUT_SIZE] = { 0 };
	int yLowPass[LOW_PASS_OUTPUT_SIZE] = { 0 };
	int yHighPass[HIGH_PASS_OUTPUT_SIZE] = { 0 };
	int yDeriv[DERIVATIVE_OUTPUT_SIZE] = { 0 };
	int ySquare[SQUARING_OUTPUT_SIZE] = { 0 };

	int fail = 0;

	int inputCounter = 0;

	/* open the input file */
	FILE* ecgFile = openfile("ECG.txt");
	/* open the expected output file */
	FILE* mwiAfterTestFile = openfile("x_mwi_div_after.txt");

	/* loop until you reach the end of the file */
	while (!feof(ecgFile))
	{
		xInput[inputCounter % LOW_PASS_INPUT_SIZE] = getNextData(ecgFile);

		// stop it reading too far in the file (or last value is always 0 for empty line at end)
		if (feof(ecgFile))
		{
			break;
		}

		// run all filters in a chain, passing output from one as input for the next
		yLowPass[inputCounter % LOW_PASS_OUTPUT_SIZE] = lowPassFilter(yLowPass, xInput, inputCounter);
		yHighPass[inputCounter % HIGH_PASS_OUTPUT_SIZE] = highPassFilter(yHighPass, yLowPass, inputCounter);
		yDeriv[inputCounter % DERIVATIVE_OUTPUT_SIZE] = derivativeFilter(yHighPass, inputCounter);
		ySquare[inputCounter % SQUARING_OUTPUT_SIZE] = squaringFilter(yDeriv, inputCounter);
		int finalChainedOutput = mwiFilter(ySquare, inputCounter);

		int nextInTestOutput = getNextData(mwiAfterTestFile);

		if (finalChainedOutput != nextInTestOutput)
		{
			printf("All filters chained together test failed!\n");
			fail = 1;
			break;
		}

		inputCounter++;
	}

	if (fail == 0)
	{
		printf("All filters chained together test passed!\n");
	}

	/* close the files */
	fclose(ecgFile);
	fclose(mwiAfterTestFile);
}

void testFilters() {
		testLowPassFilter();
		testHighPassFilter();
		testDerivativeFilter();
		testSquaringFilter();
		testMwiFilter();
		testAllFiltersChainedTogether();
}
