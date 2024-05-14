/* Check if a number is prime or not. */

#include <iostream>

bool IsPrime(int n)
{
    if (n == 1 || n == 0) return true;
    int cntDivisor = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != 1)
            {
                return false;
            }
            cntDivisor++;
            if (i != n / i)
            {
                cntDivisor++;
            }
        }
    }
    if (cntDivisor == 2)
    {
        return true;
    }
    return false;
}

int main()
{
    int n = 37;
    std::cout << n;
    if (IsPrime(n))
    {
        std::cout << " is a prime number.";
    }
    else
    {
        std::cout << " is not a prime number";
    }
    return 0;
}