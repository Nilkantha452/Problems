/* You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the
* constraint that no two elements are adjacent in the given array/list.
*/
#include <iostream>
#include <vector>

int MaxSumNonAdj(int arr[], int idx)
{
    if (idx == 0)
    {
        return arr[0];
    }
    if (idx < 0)
    {
        return 0;
    }
    int l = MaxSumNonAdj(arr, idx - 1);
    int r = arr[idx] + MaxSumNonAdj(arr, idx - 2);
    return std::max(l, r);
}

int MaxSumNonAdjMemoization(int arr[], int idx, std::vector<int>& dp)
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
    int l = MaxSumNonAdjMemoization(arr, idx - 1, dp);
    int r = arr[idx] + MaxSumNonAdjMemoization(arr, idx - 2, dp);
    return dp[idx] = std::max(l, r);
}

int MaxSumNonAdjTable(int arr[], int n, std::vector<int>& dp)
{
    dp[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        int l = (i - 1) < 0 ? 0 : dp[i - 1];
        int r = arr[i] + ((i - 2) < 0 ? 0 : dp[i - 2]);
        dp[i] = std::max(l, r);
    }
    return dp[n];
}

int main()
{
    int arr[] = { 1, 2, 3, 1, 3, 5, 8, 1, 9 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << MaxSumNonAdj(arr, n - 1);

    std::vector<int> dp(n, -1);
    std::cout << MaxSumNonAdjMemoization(arr, n - 1, dp);

    std::vector<int> dpp(n, -1);
    std::cout << MaxSumNonAdjTable(arr, n - 1, dp);

    return 0;
}