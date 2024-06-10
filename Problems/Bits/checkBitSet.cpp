/* Check if kth bit is set or not */
#include <iostream>

bool checkBitSet(int n, int k)
{
    if ((n >> k) & 1)
    {
        return true;
    }
    return false;
}

int main()
{
    int n = 16;
    int k = 3;
    if (checkBitSet(n, k))
    {
        std::cout << k << "'th bit is set";
    }
    else
    {
        std::cout << k << "'th bit is not set";
    }
    return 0;
}