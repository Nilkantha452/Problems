/* Print the sum of N numbers using recursion. */

#include <iostream>

/* Parameterise Recursion */
void calculateSum(int& sum, int n)
{
    if (n == 0)
    {
        return;
    }
    sum += n;
    calculateSum(sum, n - 1);
}

/* Functional Recursion */

int calculateSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + calculateSum(n - 1);
}

int main()
{
    int n = 5;
    int sum = 0;
    calculateSum(sum, n);
    std::cout << sum;
    std::cout << std::endl;
    std::cout << calculateSum(n);
}