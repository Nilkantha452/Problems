/* Swap two variables without using an extra variable. */
#include <iostream>

void swap(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a = 4;
    int b = 5;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b;
    return 0;
}