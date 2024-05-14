/* Check if a number is palindrome or not. */

#include <iostream>

int CheckPalindrome(int n)
{
    int original = n;
    int reversed = 0;
    while (n)
    {
        int temp = n % 10;
        reversed = reversed * 10 + temp;
        n = n / 10;
    }
    if (original == reversed)
    {
        return true;
    }
    return false;
}

int main()
{
    int n = 1331;
    if (CheckPalindrome(n))
    {
        std::cout << n << " is a palindrome\n";
    }
    else
    {
        std::cout << n << " is not a palindrome\n";
    }
    return 0;
}