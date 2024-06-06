/* Find the maximum subarray sum in an array.(Kadane's Alogrithm) */
#include <iostream>
#include <climits>

int MaxSubArraySum(int arr[], int n)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << MaxSubArraySum(arr, n);
    return 0;
}