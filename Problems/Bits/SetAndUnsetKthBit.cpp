/* Set and Unset the Kth bit of a number. */
#include <iostream>

int UnsetKthBit(int n, int k)
{
    return (n & (~(1 << k)));
}

int SetKthBit(int n, int k)
{
    return (n | (1 << k));
}

int main()
{
    int n = 63;
    int k = 3;
    std::cout << "After unsetting " << k << "'th bit, the number is : " << UnsetKthBit(n, k) << std::endl;
    std::cout << "After setting " << k << "'th bit, the number is : " << SetKthBit(n, k);
    return 0;
}