#include <iostream>
#include <climits>
#include <vector>
int MinEnergyToReachEnd(int arr[], int idx, int k)
{
    if (idx == 0)
    {
        return 0;
    }
    int mini = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (idx - i >= 0)
        {
            int l = MinEnergyToReachEnd(arr, idx - i, k) + std::abs(arr[idx] - arr[idx - i]);
            mini = std::min(mini, l);
        }

    }
    return mini;
}

int MinEnergyToReachEndMemoization(int arr[], int idx, int k, std::vector<int>& dp)
{
    if (idx == 0)
    {
        return 0;
    }
    int mini = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (idx - i >= 0)
        {
            if (dp[idx] != -1)
            {
                return dp[idx];
            }
            int l = MinEnergyToReachEndMemoization(arr, idx - i, k, dp) + std::abs(arr[idx] - arr[idx - i]);
            mini = std::min(mini, l);
        }
    }
    return dp[idx] = mini;
}

int MinEnergyToReachEndTabulation(int arr[], int n, int k, std::vector<int>& dp)
{
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int l = dp[i - j] + std::abs(arr[i] - arr[i - j]);
                mini = std::min(mini, l);
            }
        }
        dp[i] = mini;
    }
    return dp[n];
}

int main()
{
    int arr[] = { 10, 30, 20, 10, 20 };
    int n = sizeof(arr) / sizeof(int);
    int k = 4;
    std::cout << MinEnergyToReachEnd(arr, n - 1, k);

    std::vector<int> dp(n, -1);
    std::cout << MinEnergyToReachEndMemoization(arr, n - 1, k, dp);

    std::vector<int> dpp(n, -1);
    std::cout << MinEnergyToReachEndTabulation(arr, n - 1, k, dpp);
    return 0;
}