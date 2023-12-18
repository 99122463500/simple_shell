#include <stdio.h>

/**
 * calculate_factorial - Calculate the factorial of a non-negative integer.
 * @n: The number for which factorial is calculated.
 *
 * Return: The factorial of n.
 */
unsigned long long calculate_factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * calculate_factorial(n - 1);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	int number;

	/* Prompt the user to enter a number */
	printf("Enter a non-negative integer: ");
	scanf("%d", &number);

	/* Check if the number is non-negative */
	if (number < 0)
	{
		printf("Please enter a non-negative integer.\n");
		return 1; /* Return an error code */
	}

	/* Calculate and display the factorial */
	printf("The factorial of %d is: %llu\n", number, calculate_factorial(number));

	return 0;
}

