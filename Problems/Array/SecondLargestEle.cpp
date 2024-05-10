/* Find Second Largest Element in an Array without sorting. */

#include <iostream>
#include <climits>

int SecondLargestEle(int arr[], int n)
{
	int largest = INT_MIN, secondLargest = largest;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > largest)
		{
			secondLargest = largest;
			largest = arr[i];
		}
		else if ((largest > arr[i]) && (arr[i] > secondLargest))
		{
			secondLargest = arr[i];
		}
	}
	return secondLargest;
}
/*Similar implementation can be done for Second Smallest Element.
* int SecondSmallestElement(int arr[], int n)
* {
*	int smallest = INT_MAX, secondSmallest = INT_MAX;
*	for (int i = 0; i < n; i++)
*	{
*		if (arr[i] < smallest)
*		{
*			secondSmallest = smallest;
*			smallest = arr[i];
*		}
*		else if ((arr[i] > smallest) && (arr[i] < secondSmallest))
*		{
*			secondSmallest = arr[i];
*		}
*	}
*	return secondSmallest;
* }
*/
int main()
{
	int arr[10] = { 3, 6, 2, 8, 9, 2, 4, 2, 1, 5 };
	int n = sizeof(arr) / sizeof(int);
	std::cout << "Second largest element is : " << SecondLargestEle(arr, n);
	return 0;
}