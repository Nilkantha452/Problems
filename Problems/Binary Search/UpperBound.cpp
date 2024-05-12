/* Find the upper bound of a number from a sorted array.
* The upper bound in a sorted array is the index of the first value that is greater than a given value. 
* If the greater value does not exist then the answer is 'n', Where 'n' is the size of the array.
* For input of 10, 20, 30, 40, 50, 60 upper bound of 45 is 50.
* std::upper_bound(arr.begin(), arr.end(), val) can be used to find the upper bound.
* 
* https://www.naukri.com/code360/problems/implement-upper-bound_8165383?leftPanelTabValue=PROBLEM
*/
#include <iostream>

int getUpperBound(int arr[], int n, int val)
{
    int i = 0, j = n - 1, mid = -1, ans = n;
    while (i <= j)
    {
        mid = i + (j - i) / 2;
        if (arr[mid] <= val)
        {
            i = mid + 1;
        }
        else
        {
            ans = mid;
            j = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int val = 45;
    int n = sizeof(arr) / sizeof(int);
    std::cout << "The upper bound of " << val << " is : " << getUpperBound(arr, n, val);
    return 0;
}