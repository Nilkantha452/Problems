/* Remove duplicates from a Sorted array. */
#include <iostream>
#include <vector>
int RemoveDuplicates(std::vector<int>& vec)
{
	if (vec.size() <= 1) return;
	int j = 1;
	int element = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (element != vec[i])
		{
			vec[j] = vec[i];
			j++;
			element = vec[i];
		}
	}
	return j;
}

int main()
{
	std::vector<int> vec{ 1, 1, 2, 3, 4, 4, 4, 6, 6, 6 };
	int newSize = RemoveDuplicates(vec);
	for (int i = 0; i < newSize; i++)
	{
		std::cout << vec[i] << " ";
	}
	return 0;
}