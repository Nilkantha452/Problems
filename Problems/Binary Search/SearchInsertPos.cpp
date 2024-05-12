/* Search Insert Position in a sorted array.
* You are given a sorted array arr of distinct values and a target value x.
* You need to search for the index of the target value in the array.
* If the value is present in the array, then return its index.
* Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.
* In this 1,2,4,7 the number 6 can be inserted at index 3.
* 
* https://leetcode.com/problems/search-insert-position/description/
*/

#include <iostream>

int InsertPosition(int arr[], int n, int val)
{
    // This is simply to find the lower bound of the value.
    return std::lower_bound(arr, arr + n, val) - arr;
}

int main()
{
    int arr[] = { 1, 2, 4, 7 };
    int val = 6;
    int n = sizeof(arr) / sizeof(int);
    std::cout << "The Insert Position of " << val << " is : " << InsertPosition(arr, n, val);
}