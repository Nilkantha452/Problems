/* Find a number which is occuring more than N/2 times in an array. (Moore's Voting Algorithm) */
#include <iostream>

int MajorityElement(int arr[], int n)
{
    int count = 0;
    int currElement = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            currElement = arr[i];
        }
        if (arr[i] == currElement)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    if (count > 0)
    {
        return currElement;
    }
    return -1;
}

int main()
{
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 5, 6, 3, 3, 2, 2, 4, 2, 2, 2 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << MajorityElement(arr, n);
    return 0;
}