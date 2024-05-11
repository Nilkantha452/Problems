/* Find the missing number in an array from 1 to N */

#include <iostream>

int findMissing(int arr[], int N)
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            res ^= arr[i];
        }
        res ^= (i + 1);
    }
    return res;
}

int main()
{
    int arr[] = { 1, 4, 2, 5, 6, 7 };
    int N = 7;
    std::cout << "The missing number from 1 to " << N << " is : " << findMissing(arr, N);
    return 0;
}