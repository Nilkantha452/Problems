/* Reverse a number. */

#include <iostream>

int ReverseNumber(int n)
{
    /* Time Complexity is O(log10N) */
    int result = 0;
    while (n)
    {
        int temp = n % 10;
        result = (result * 10) + temp;
        n = n / 10;
    }
    return result;
}

int main()
{
    int n = 7789;
    std::cout << "The reverse of the number " << n << " is : " << ReverseNumber(n);
    return 0;
}