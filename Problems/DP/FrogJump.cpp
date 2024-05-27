/* Minimum amount of energy required to reach the end of the road.
* There are N stairs, numbered 1,2,…, N. For each i (1≤i≤N), the height of stair i is hi. There is a frog who is initially
* on stair 1. He will repeat the following action some number of times to reach stair N: If the frog is currently on stair
* jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi −hj∣ is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches stair N.
*/
#include <iostream>
#include <climits>
#include <vector>

int MinPossibleTotalCost(int arr[], int idx)
{
    if (idx == 0)
    {
        return 0;
    }
    if (idx == 1)
    {
        return std::abs(arr[0] - arr[1]);
    }
    int l = MinPossibleTotalCost(arr, idx - 1) + std::abs(arr[idx] - arr[idx - 1]);
    int r = MinPossibleTotalCost(arr, idx - 2) + std::abs(arr[idx] - arr[idx - 2]);
    return std::min(l, r);
}

int MinPossibleTotalCostMemoization(int arr[], int idx, std::vector<int>& dp)
{
    if (idx == 0)
    {
        return 0;
    }
    if (idx == 1)
    {
        return std::abs(arr[0] - arr[1]);
    }
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    int l = MinPossibleTotalCostMemoization(arr, idx - 1, dp) + std::abs(arr[idx] - arr[idx - 1]);
    int r = MinPossibleTotalCostMemoization(arr, idx - 2, dp) + std::abs(arr[idx] - arr[idx - 2]);
    return dp[idx] = std::min(l, r);
}

int MinPossibleTotalCostTabulation(int arr[], int idx, std::vector<int>& dp)
{
    dp[0] = 0;
    dp[1] = std::abs(arr[1] - arr[0]);
    for (int i = 2; i <= idx; i++)
    {
        int l = dp[i - 1] + std::abs(arr[i] - arr[i - 1]);
        int r = dp[i - 2] + std::abs(arr[i] - arr[i - 2]);
        dp[i] = std::min(l, r);
    }
    return dp[idx];
}

int main()
{
    int arr[] = { 30, 20, 50, 10, 40, 20, 10, 10, 20, 10, 40, 30 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << MinPossibleTotalCost(arr, n - 1) << std::endl;

    std::vector<int> dp(n, -1);
    std::cout << MinPossibleTotalCostMemoization(arr, n - 1, dp) << std::endl;

    std::vector<int> dpp(n, -1);
    std::cout << MinPossibleTotalCostTabulation(arr, n - 1, dpp);
    return 0;
}