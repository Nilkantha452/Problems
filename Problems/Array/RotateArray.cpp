/* Left Rotate an array by one place. */
#include <iostream>
#include <algorithm>

void LeftRotateByD(int arr[], int n, int d)
{
	/*If we want to reverse array from 3rd place to 7th place we need to use
	* std::reverse(arr + 2, arr + 8)
	* The last index should be plus one.
	* 1 2 3 4 5 6 7 -> std::reverse(arr + 2, arr + 5) -> 1 2 5 4 3 6 7
	*/
	d = d % n;
	std::reverse(arr, arr + n - d);
	std::reverse(arr + n - d, arr + n);
	std::reverse(arr, arr + n);
}

void RightRotateByD(int arr[], int n, int d)
{
	d = d % n;
	std::reverse(arr, arr + d);
	std::reverse(arr + d, arr + n);
	std::reverse(arr, arr + n);
}

int main()
{
	int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(int);
	int d = 3;
	LeftRotateByD(arr, n, d);
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}