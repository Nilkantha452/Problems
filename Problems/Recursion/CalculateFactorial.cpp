/* Calculate the factorial of a number. */

#include<iostream>

/* Functional recursion */
int CalculateFactorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * CalculateFactorial(n - 1);
}

/* Parameterised Recursion */
void CalculateFactorial(int& result, int n)
{
    if (n == 1)
    {
        return;
    }
    result = result * n;
    CalculateFactorial(result, n - 1);
}

int main()
{
    int n = 6;
    int result = 1;
    CalculateFactorial(result, n);
    std::cout << result;

    std::cout << std::endl;

    std::cout << CalculateFactorial(n);
    return 0;
}