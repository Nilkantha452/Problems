/* Move Zeros to end without changing the order of nonzero numbers. */
#include <iostream>

void MoveZeros(int arr[], int n)
{
	int k = 0;
	while (k < n && arr[k])
	{
		k++;
	}
	for (int i = k + 1; i < n; i++)
	{
		if (arr[i] != 0)
		{
			swap(arr[i], arr[k]);
			k++;
		}
	}
}

int main()
{
	int arr[] = { 1, 0, 2, 0, 4, 0, 0, 4, 0, 1 };
	int n = sizeof(arr) / sizeof(int);
	MoveZeros(arr, n);
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}