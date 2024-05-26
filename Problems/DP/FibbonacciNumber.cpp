/* Find the Nth Fibbonacci Number using DP. */
#include <iostream>
#include <vector>

int FibbonacciNumber(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return FibbonacciNumber(n - 1) + FibbonacciNumber(n - 2);
}

int FibbonacciNumberMemoization(int n, std::vector<int>& dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1) return dp[n];
    else
    {
        return dp[n] = FibbonacciNumberMemoization(n - 1, dp) + FibbonacciNumberMemoization(n - 2, dp);
    }
}

int FibbonacciNumberTabulation(int n, std::vector<int>& dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 6;
    std::vector<int> dp(n + 1, -1);
    //std::cout << FibbonacciNumber(n);
    //std::cout << FibbonacciNumberMemoization(n, dp);
    std::cout << FibbonacciNumberTabulation(n, dp);
    return 0;
}