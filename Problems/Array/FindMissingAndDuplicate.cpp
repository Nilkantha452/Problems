/* Find the missing and duplicate number from an array of 1 to N, */
#include <iostream>
#include <vector>

std::pair<int, int> FindMissingDuplicate(int arr[], int n)
{
    int num = 0;
    int one = 0;
    int zero = 0;
    int bit = 0;
    for (int i = 0; i < n; i++)
    {
        num ^= arr[i];
        num ^= (i + 1);
    }
    while ((num & 1) == 0)
    {
        bit++;
        num = num >> 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (((arr[i] >> bit) & 1) == 1)
        {
            one ^= arr[i];
        }
        else
        {
            zero ^= arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (((i >> bit) & 1) == 1)
        {
            one ^= i;
        }
        else
        {
            zero ^= i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (one == arr[i])
        {
            std::pair<int, int> p{ zero, one };
            return p;
        }
    }
    std::pair<int, int> p{ one, zero };
    return p;
}

int main()
{
    int arr[] = { 1, 3, 4, 4, 5, 6, 7, 8 };
    int n = sizeof(arr) / sizeof(int);
    std::pair<int, int> p = FindMissingDuplicate(arr, n);
    std::cout << "Missing element: " << p.first << " Duplicate element: " << p.second;
    return 0;
}