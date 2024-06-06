/* Count the length of the maximum subarray with sum K. */
#include <iostream>
#include <unordered_map>

/* Map approach. SC: O(N)*/
int MaxSubArrWithSumK(int arr[], int n, int k)
{
    std::unordered_map<int, int> mp;
    int sum = 0;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxCount = std::max(maxCount, i + 1);
        }
        if (mp.find(sum - k) != mp.end())
        {
            maxCount = std::max(maxCount, i - mp[sum - k]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return maxCount;
}

/* Sliding window approach SC: O(1). But this will only for positive number inputs. */
int MaxSubArrWithSumKSlidingWindow(int arr[], int n, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int maxCount = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum == k)
        {
            maxCount = std::max(maxCount, j - i + 1);
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
        }
        j++;
    }
    return maxCount;
}

int main()
{
    int arr[] = { 2, 3, 5, 7, 2, 3, 4, 1, 10 };
    int n = sizeof(arr) / sizeof(int);
    int k = 10;
    std::cout << MaxSubArrWithSumK(arr, n, k) << " " << MaxSubArrWithSumKSlidingWindow(arr, n, k);
    return 0;
}