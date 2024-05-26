/* Number of ways to reach the Nth stair when someone can jump 1st or 2nd step. */
#include <iostream>
#include <vector>

int ClimbStairs(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    int l = ClimbStairs(n - 1);
    int r = ClimbStairs(n - 2);
    return l + r;
}

int ClimbStairsMemoization(int n, std::vector<int>& dp)
{
    if (n == 0) return 1;
    if (n == 1)  return 1;
    if (dp[n] != -1) return dp[n];
    int l = ClimbStairsMemoization(n - 1, dp);
    int r = ClimbStairsMemoization(n - 2, dp);
    return dp[n] = l + r;
}

int ClimbStairsTablulation(int n, std::vector<int>& dp)
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 10;
    std::cout << ClimbStairs(n);
    std::vector<int> dp(n + 1, -1);
    //std::cout << ClimbStairsMemoization(n, dp);
    std::cout << ClimbStairsTablulation(n, dp);
    return 0;
}