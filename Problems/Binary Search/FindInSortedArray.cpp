/* Find a number in a sorted array. */

#include <iostream>
int BinarySearch(int arr[], int n, int target)
{
	int i = 0, j = n - 1;
	int mid = -1;
	while (i <= j)
	{
		mid = j + (i - j) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] < target)
		{
			i = mid + 1;
		}
		else
		{
			j = mid - 1;
		}
	}
	return -1;
}

int helper(int arr[], int i, int j, int target)
{
	if (i > j) return -1;
	int mid = j + (i - j) / 2;
	if (arr[mid] == target)
	{
		return mid;
	}
	if (arr[mid] < target)
	{
		return helper(arr, mid + 1, j, target);
	}
	else
	{
		return helper(arr, i, mid - 1, target);
	}
	return -1;
}

int BinarySearchRecursive(int arr[], int n, int target)
{
	return helper(arr, 0, n - 1, target);
}

int main()
{
	int arr[] = { 1, 2, 5, 7, 9, 10, 13, 15, 18, 20 };
	int target = 12;
	int n = sizeof(arr) / sizeof(int);
	int idx = BinarySearch(arr, n, target);
	if (idx == -1)
	{
		std::cout << "Element is not found";
	}
	else
	{
		std::cout << "Element is found at index : " << idx;
	}
	return 0;
}