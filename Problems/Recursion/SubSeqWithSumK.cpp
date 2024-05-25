/* Print all the subsequence with sum K */
#include <iostream>
#include <vector>

void helper(int arr[], int n, int i, std::vector<std::vector<int>>& ans, int sum, int k, std::vector<int> vec)
{
	if (i == n)
	{
		if (sum == k)
		{
			ans.push_back(vec);
			for (int i = 0; i < vec.size(); i++)
			{
				std::cout << vec[i] << " ";
			}
			std::cout << std::endl;
		}
		return;
	}
	vec.push_back(arr[i]);
	sum += arr[i];
	helper(arr, n, i + 1, ans, sum, k, vec);
	vec.pop_back();
	sum -= arr[i];
	helper(arr, n, i + 1, ans, sum, k, vec);
}

void PrintSubSeqWithSumK(int arr[], int n, int k)
{
	std::vector<std::vector<int>> ans;
	std::vector<int> vec;
	helper(arr, n, 0, ans, 0, k, vec);
}

bool helperSec(int arr[], int i, int n, int k, int sum, std::vector<int> vec, std::vector<int>& ans)
{
	if (i == n)
	{
		if (sum == k)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				ans.push_back(vec[i]);
				std::cout << vec[i] << " ";
			}
			std::cout << std::endl;
			return true;
		}
		else
		{
			return false;
		}

	}
	vec.push_back(arr[i]);
	sum += arr[i];
	if (helperSec(arr, i + 1, n, k, sum, vec, ans) == true)
	{
		return true;
	}
	vec.pop_back();
	sum -= arr[i];
	if (helperSec(arr, i + 1, n, k, sum, vec, ans) == true)
	{
		return true;
	}
	return false;
}

void PrintOneSubSeqWithSumK(int arr[], int n, int k)
{
	std::vector<int> ans;
	std::vector<int> vec;
	int sum = 0;
	bool x = helperSec(arr, 0, n, k, sum, vec, ans);
}

int main()
{
	int arr[] = { 2, 3, 1, 3, 1, 4 };
	int n = sizeof(arr) / sizeof(int);
	int k = 5;
	//PrintSubSeqWithSumK(arr, n, k);
	PrintOneSubSeqWithSumK(arr, n, k);
	return 0;
}