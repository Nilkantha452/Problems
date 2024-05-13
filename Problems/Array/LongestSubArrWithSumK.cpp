/* Find the longest subarray with sum K. */

#include <iostream>
#include <unordered_map>

int LongestSubArray(int arr[], int n, int k)
{
    /* This solution is valid for both positive and negative number. If only positive numbers are there,
    * it is better to use sliding window approach.
    */
    int sum = 0;
    int MaxLen = 0;
    std::unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            MaxLen = std::max(MaxLen, i + 1);
        }
        if (mp.find(sum - k) != mp.end())
        {
            MaxLen = std::max(MaxLen, i - mp[sum - k]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return MaxLen;
}

int LongestSubArraySlidingWindow(int arr[], int n, int k)
{
    /* This code is valid for only positive integers. */
    int i = 0, j = 0, sum = 0;
    int maxLen = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum == k)
        {
            maxLen = std::max(maxLen, j - i + 1);
        }
        while (sum > k)
        {
            sum -= arr[i];
            i++;
        }
        j++;
    }
    return maxLen;
}

int main()
{
    int arr[] = { 2,3,5,1,9 };
    int K = 10;
    int n = sizeof(arr) / sizeof(int);
    std::cout << "The longest subarray with sum " << K << " is : " << LongestSubArray(arr, n, K);
    return 0;
}