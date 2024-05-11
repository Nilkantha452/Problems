/* Find the Union of two sorted Arrays. */
#include <iostream>
#include <vector>
std::vector<int> mergeArray(std::vector<int>& arr1, std::vector<int>& arr2, int m, int n)
{
	int i = 0, j = 0;
	std::vector<int> res;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
		{
			if (res.size() == 0 || res.back() != arr1[i])
			{
				res.push_back(arr1[i]);
			}
			i++;
		}
		else
		{
			if (res.size() == 0 || res.back() != arr2[j])
			{
				res.push_back(arr2[j]);
			}
			j++;
		}
	}
	for (; i < m; i++)
	{
		if (res.size() == 0 || res.back() != arr1[i])
		{
			res.push_back(arr1[i]);
		}
	}
	for (; j < n; j++)
	{
		if (res.size() == 0 || res.back() != arr2[j])
		{
			res.push_back(arr2[j]);
		}
	}
	return res;
}

int main()
{
	std::vector<int> arr1{ 2,2,2 };
	std::vector<int> arr2{ 2 };
	int m = arr1.size();
	int n = arr2.size();
	std::vector<int> mergedArray = mergeArray(arr1, arr2, m, n);
	for (int i = 0; i < mergedArray.size(); i++)
	{
		std::cout << mergedArray[i] << " ";
	}
	return 0;
}