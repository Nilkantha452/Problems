/* Extract the k'th bit in a number. */
#include <iostream>

int ExtractKthBit(int n, int k)
{
    return ((n >> k) & 1);
}

int main()
{
    int n = 63;
    int k = 3;
    std::cout << k << "'th bit is: " << ExtractKthBit(n, k);
    return 0;
}