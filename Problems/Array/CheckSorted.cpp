/* Check if an array is sorted or not. */
#include <iostream>

//bool isSorted(int arr[], int n)
//{
//	bool isInscreasing = true;
//	if (n == 1)
//	{
//		return true;
//	}
//	if (arr[1] > arr[0])
//	{
//		isInscreasing = true;
//	}
//	else
//	{
//		isInscreasing = false;
//	}
//	if (isInscreasing)
//	{
//		for (int i = 1; i < n; i++)
//		{
//			if (arr[i] < arr[i - 1])
//			{
//				return false;
//			}
//		}
//	}
//	else
//	{
//		for (int i = 1; i < n; i++)
//		{
//			if (arr[i] > arr[i - 1])
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}

bool isSorted(int arr[], int n)
{
	bool isIncreasing = true, isDecreasing = true;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			isIncreasing = false;
		}
		if (arr[i] > arr[i - 1])
		{
			isDecreasing = false;
		}
	}
	return isIncreasing || isDecreasing;
}
int main()
{
	int arr[5] = { 2, 5, 6, 7, 9 };
	int n = sizeof(arr) / sizeof(int);
	bool res = isSorted(arr, n);
	if (res)
	{
		std::cout << "This array is sorted";
	}
	else
	{
	std::cout << "This array is not sorted";
	}
	return 0;
}