/* Count the number of subsequence with sum K */
#include <iostream>
#include <vector>

int helper(int arr[], int i, int sum, int k, int n, std::vector<int> vec)
{
    if (i == n)
    {
        if (sum == k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    sum += arr[i];
    vec.push_back(arr[i]);
    int l = helper(arr, i + 1, sum, k, n, vec);
    sum -= arr[i];
    vec.pop_back();
    int r = helper(arr, i + 1, sum, k, n, vec);
    return l + r;
}

int NumberOfSubSeq(int arr[], int n, int k)
{
    int sum = 0;
    std::vector<int> vec;
    return helper(arr, 0, sum, k, n, vec);
}

int main()
{
    int arr[] = { 2, 3, 1, 3, 1, 4 };
    int n = sizeof(arr) / sizeof(int);
    int k = 5;
    std::cout << NumberOfSubSeq(arr, n, k);
    return 0;
}