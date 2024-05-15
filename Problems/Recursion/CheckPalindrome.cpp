/* Check if a string is palindrome or not using recursion */
#include <iostream>
#include <string>

bool CheckPalindrome(std::string str, int i, int j)
{
    if (i >= j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        return CheckPalindrome(str, i + 1, j - 1);
    }
}

int main()
{
    std::string str = "abcba";
    std::cout << CheckPalindrome(str, 0, str.size() - 1);
    return 0;
}