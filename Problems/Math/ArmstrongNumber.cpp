/* Check whether a number is a Armstrong number or not.
* An Armstrong number, also known as a narcissistic number, is a number that is equal to the
* sum of its own digits each raised to the power of the number of digits in the number.
*/

#include <iostream>
#include <math.h>

bool isArmstrong(int N)
{
    int original = N;
    int sum = 0;
    int n = 0;
    while (N)
    {
        n++;
        N = N / 10;
    }
    N = original;
    while (N)
    {
        int temp = N % 10;
        sum = sum + (int)pow(temp, n);
        N = N / 10;
    }
    if (sum == original)
    {
        return true;
    }
    return false;
}


int main()
{
    int n = 153;
    if (isArmstrong(n))
    {
        std::cout << n << " is an Armstrong number.";
    }
    else
    {
        std::cout << n << " is not an Armstrong number.";
    }
    return 0;
}