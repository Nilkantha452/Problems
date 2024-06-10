/* Check is a number is power of 2 or not. */
#include <iostream>

bool isPowerOfTwo(int n)
{
    if ((n & (n - 1)) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int n = 64;
    if (isPowerOfTwo(n))
    {
        std::cout << n << " is power of 2";
    }
    else
    {
        std::cout << n << " is not power of 2";
    }
    return 0;
}