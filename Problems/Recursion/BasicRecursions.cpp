/* 1. Print 1 to n using recursion.
*  2. Print n to 1 using recursion.
*  3. Print 1 to n using backtracking.
*  4. Print n to 1 using backtracking.

*/

#include <iostream>

void PrintOneToN(int i, int n)
{
    if (i == n + 1)
    {
        return;
    }
    std::cout << i << " ";
    PrintOneToN(i + 1, n);
}

void PrintNtoOne(int n)
{
    if (n == 0)
    {
        return;
    }
    std::cout << n << " ";
    PrintNtoOne(n - 1);
}

void PrintOneToNBack(int n)
{
    if (n == 0)
    {
        return;
    }
    PrintOneToNBack(n - 1);
    std::cout << n << " ";
}

void PrintNtoOneBack(int i, int n)
{
    if (i == n + 1)
    {
        return;
    }
    PrintNtoOneBack(i + 1, n);
    std::cout << i << " ";
}

int main()
{
    /* Print 1 to N */
    PrintOneToN(1, 10);

    std::cout << std::endl;

    /* Print N to 1 */
    PrintNtoOne(10);

    std::cout << std::endl;

    /* Print 1 to N backtracking */
    PrintOneToNBack(10);

    std::cout << std::endl;

    /* Print N to 1 backtracking */
    PrintNtoOneBack(1, 10);
}