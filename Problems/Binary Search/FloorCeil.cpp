/* Write two methods to find Floor and ceil of an element from an array.
* The floor of x is the largest element in the array which is smaller than or equal to x.
* The ceiling of x is the smallest element in the array greater than or equal to x.
* 
* https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401
*/
#include <iostream>

int getFloor(int arr[], int n, int val)
{
    int i = 0, j = n - 1, mid = -1, ans = n;
    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] < val)
        {
            ans = mid;
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return ans;
}

int getCeil(int arr[], int n, int val)
{
    return std::lower_bound(arr, arr + n, val) - arr;
}

int main()
{
    int arr[] = { 1, 3, 5, 6, 7, 8, 9, 10, 13 };
    int val = 12;
    int n = sizeof(arr) / sizeof(int);
    std::cout << "Floor of " << val << " is : " << getFloor(arr, n, val);
    std::cout << "Ceil of " << val << " is : " << getCeil(arr, n, val);
    return 0;
}