/* Find the amount of water stored using array. */
#include <iostream>
#include <vector>
#include <climits>

int RainWaterStored(int arr[], int n)
{
    std::vector<int> leftMax(n);
    std::vector<int> rightMax(n);
    int waterStored = 0;
    int maxL = INT_MIN, maxR = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxL = std::max(maxL, arr[i]);
        leftMax[i] = maxL;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        maxR = std::max(maxR, arr[i]);
        rightMax[i] = maxR;
    }
    for (int i = 0; i < n; i++)
    {
        waterStored += (std::min(leftMax[i], rightMax[i]) - arr[i]);
    }
    return waterStored;
}

int main()
{
    int arr[] = { 3, 7, 0, 0, 2, 0, 4, 7 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << "Amount of stored water : " << RainWaterStored(arr, n);
    return 0;
}