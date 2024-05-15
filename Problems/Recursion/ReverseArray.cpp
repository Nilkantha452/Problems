/* Reverse an array using recursion */
#include <iostream>

void ReverseArray(int arr[], int i, int j)
{
    if (i >= j)
    {
        return;
    }
    std::swap(arr[i], arr[j]);
    ReverseArray(arr, i + 1, j - 1);
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 6, 8 };
    int n = sizeof(arr) / sizeof(int);
    ReverseArray(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}