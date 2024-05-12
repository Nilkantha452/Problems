/* Find the lower bound in an array.
* For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' 
* such that the value 'arr[idx]' is not less than 'x'.
* For input 10 20 30 40 50 the lower bound for 35 is 40 at index 3.
* 
* https://www.naukri.com/code360/problems/lower-bound_8165382?leftPanelTabValue=PROBLEM
* 
*/
#include <iostream>

int LowerBound(int arr[], int n, int val)
{
    /* std::lower_bound(arr.begin(), arr.end(), val) can be used to find the lower bound. */

    int i = 0, j = n - 1, mid = -1;
    int ans = n; // If the val is highest in the array, we will return the highest index + 1.
    while (i <= j)
    {
        mid = j + (i - j) / 2;

        if (arr[mid] >= val)
        {
            ans = mid;
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60, 70 };
    int val = 35;
    int n = sizeof(arr) / sizeof(int);
    std::cout << "Lower bound of " << val << " is : " << LowerBound(arr, n, val);
    return 0;
}