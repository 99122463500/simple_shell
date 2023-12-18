#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;

    // Prompt the user to enter a number
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    // Check if the number is non-negative
    if (number < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Return an error code
    }

    // Calculate and display the factorial
    printf("The factorial of %d is: %llu\n", number, factorial(number));

    return 0;
}

