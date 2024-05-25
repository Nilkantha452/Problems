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

int main()
{
	int arr[] = { 2, 3, 1, 3, 1, 4 };
	int n = sizeof(arr) / sizeof(int);
	int k = 5;
	PrintSubSeqWithSumK(arr, n, k);
	return 0;
}