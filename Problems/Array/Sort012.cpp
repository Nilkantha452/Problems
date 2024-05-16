/* Sort 0, 1, 2 in an array without using sort function. */

#include <iostream>

void sort012(int arr[], int n)
{
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        if (arr[j] == 0)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[j] == 1)
        {
            j++;
        }
        else
        {
            std::swap(arr[j], arr[k]);
            k--;
        }
    }
}

int main()
{
    int arr[] = { 0 ,2, 0, 1, 0, 2 , 0, 1 };
    int n = sizeof(arr) / sizeof(int);
    sort012(arr, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}