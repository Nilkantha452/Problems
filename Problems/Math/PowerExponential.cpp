/* Calculate the exponential of a given number */

#include <iostream>

int calculateExponential(int x, int n)
{
    int result = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            result = result * x;
            n = n - 1;
        }
        else
        {
            x = x * x;
            n = n / 2;
        }
    }
    return result;
}

int main()
{
    int x = 10;
    int n = 5;
    std::cout << x << " to the power " << n << " is : " << calculateExponential(x, n);
    return 0;
}