#include <iostream>
#include <climits>
int largestElement(int arr[], int n)
{
	/* We need to pass n, because since int arr[] is a pointer to the array,
	* if we do sizeof here we will get the size of a pointer. For vector it
	* is different, it is an object we can use size() method anywhere to get
	* number of elements in a vector.
	*/
	int largest = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		largest = std::max(largest, arr[i]);
	}
	return largest;
}

int main()
{
	int arr[5] = { 4, 2, 1, 6, 9 };
	int n = sizeof(arr) / sizeof(int);
	std::cout << "Largest Element is : " << largestElement(arr, n);
}