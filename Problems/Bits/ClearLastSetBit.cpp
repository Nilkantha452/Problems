/* Clear the last set bit. */
#include <iostream>

int ClearLastSetBit(int n)
{
    return (n & (n - 1));
}

int main()
{
    int n = 30;
    std::cout << "After clearing last set bit is: " << ClearLastSetBit(n);
    return 0;
}