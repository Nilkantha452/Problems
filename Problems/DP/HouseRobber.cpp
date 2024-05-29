/* You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
* the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
* it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money
* you can rob tonight without alerting the police.
*
* Input: nums = [1,2,3,1]
* Output: 4
*/
#include <iostream>
#include <vector>

int MaxMoneySteal(int arr[], int idx)
{
    if (idx == 0)
    {
        return arr[0];
    }
    if (idx < 0)
    {
        return 0;
    }
    int l = MaxMoneySteal(arr, idx - 1);
    int r = arr[idx] + MaxMoneySteal(arr, idx - 2);
    return std::max(l, r);
}

int MaxMoneyStealMemoization(int arr[], int idx, std::vector<int>& dp)
{
    if (idx == 0)
    {
        return arr[0];
    }
    if (idx < 0)
    {
        return 0;
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int notTake = MaxMoneyStealMemoization(arr, idx - 1, dp);
    int take = arr[idx] + MaxMoneyStealMemoization(arr, idx - 2, dp);
    return dp[idx] = std::max(notTake, take);
}

int MaxMoneyStealTable(int arr[], int n, std::vector<int>& dp)
{
    dp[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        int notTake = dp[i - 1];
        int take = arr[i];
        if (i - 2 >= 0)
        {
            take += dp[i - 2];
        }
        dp[i] = std::max(take, notTake);
    }
    return dp[n];
}

int main()
{
    int arr[] = { 1, 2, 3, 1 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << MaxMoneySteal(arr, n - 1);

    std::vector<int> dp(n, -1);
    std::cout << MaxMoneyStealMemoization(arr, n - 1, dp);

    std::vector<int> dpp(n, -1);
    std::cout << MaxMoneyStealTable(arr, n - 1, dpp);
    return 0;
}