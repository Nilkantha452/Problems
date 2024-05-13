/* Find the number of Maximum Consecutive Ones in an array. */
#include <iostream>

int FindMaxConsecutiveOne(int arr[], int n)
{
    int maxOne = 0, countOne = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            countOne++;
        }
        else
        {
            countOne = 0;
        }
        maxOne = std::max(maxOne, countOne);
    }
    return maxOne;
}

int main()
{
    int arr[] = { 1, 2, 1, 1, 1, 1, 3, 4, 1, 1, 1, 1, 1, 1, 2, 1, 1 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << "Maximum consecutive ones in the array : " << FindMaxConsecutiveOne(arr, n);
    return 0;
}