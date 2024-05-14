/* Print all the divisors of a number. */
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

std::vector<int> FindDivisors(int n)
{
    /* This method is taking O(N) time where N is the number.
    * Which is much bigger, not an efficiant approach. */
    std::vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

std::vector<int> FindDivisorsEfficient(int n)
{
    /* This is an efficient approach, where TC is O(sqrt(N)) + O(logn) where N is the number and n is the
    * number of divisors.
    */
    std::vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != (n / i))
            {
                ans.push_back(n / i);
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 36;
    std::vector<int> ans = FindDivisorsEfficient(36);
    std::cout << "Divisors of " << n << " are : ";
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}