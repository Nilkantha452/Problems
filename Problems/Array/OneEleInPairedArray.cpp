/* Find a single element in an array where all the elements present twice. */

#include <iostream>

int FindSingleElement(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = { 1, 2, 1, 4, 5, 4, 3, 5, 3 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << "The element that is present only one time is : " << FindSingleElement(arr, n); // Output : 2
    return 0;
}