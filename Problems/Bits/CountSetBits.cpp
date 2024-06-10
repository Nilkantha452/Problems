/* Count the number of set bits in a number. */
#include <iostream>

int CountSetBits(int n)
{
    int count = 0;
    while (n)
    {
        if ((n & 1) == 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n = 631;
    std::cout << "Number of set bits are: " << CountSetBits(n);
    return 0;
}