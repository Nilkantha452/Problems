/* Count Number of digits in a number */

#include <iostream>
#include <math.h>
int CountDigits(int n)
{
    /* Time Complexity is O(log10n)*/
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

int countDigitConstTime(int n)
{
    /* Const Time complexity. */
    return log10(n) + 1;
}

int main()
{
    int n = 7789;
    std::cout << "Number of digits in " << n << " is : " << countDigitConstTime(n);
    return 0;
}