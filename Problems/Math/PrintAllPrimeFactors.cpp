/* Print All the prime factors of a number. */
#include <iostream>
#include <vector>

bool isPrime(int n)
{
    int divisorCnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisorCnt++;
            if (n / i != i)
            {
                divisorCnt++;
            }
        }
        if (divisorCnt > 2)
        {
            return false;
        }
    }
    if (divisorCnt == 2)
    {
        return true;
    }
    return false;
}

std::vector<int> getPrimeFactors(int n)
{
    std::vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrime(i))
            {
                ans.push_back(i);
            }
            if (n / i != i)
            {
                if (isPrime(n / i))
                {
                    ans.push_back(n / i);
                }
            }
        }
    }
    return ans;
}

std::vector<int> getPrimeEx(int n)
{
    std::vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);

        }
        while (n % i == 0)
        {
            n = n / i;
        }
    }
    return ans;
}

int main()
{
    int n = 34;
    std::vector<int> ans = getPrimeEx(n);
    std::cout << "The Prime factors of " << n << " are : ";
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}