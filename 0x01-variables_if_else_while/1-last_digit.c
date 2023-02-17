#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/* betty style doc for function main goes there */
/**
 * main - Entry point
 *
 * Retur: Always 0 (success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */

	int m;

	m = n % 10;
	if (m > 5)
		printf("Last digit of %d is %d ad is greater than 5\n", n, m);
	if (m == 0)
		printf("Last digit of %d is %d ad is 0\n", n, m);
	if (m < 6 && m != 0)
		print("Last digit of %d is %d ad is less than 6 ad not 0\n", n, m);
	return (0);
}
