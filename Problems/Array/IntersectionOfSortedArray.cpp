/* Find Intersection of two arrays. */
#include <iostream>
#include <vector>
std::vector<int> FindIntersection(std::vector<int>& arr1, std::vector<int>& arr2, int m, int n)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] == arr2[j])
        {
            if (res.size() != 0 || res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return res;
}

int main()
{
    std::vector<int> arr1 { 1, 2, 2, 3, 4, 5, 6, 7, 10 };
    std::vector<int> arr2 { 1, 2, 2, 5, 12 };
    int m = sizeof(arr1) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);
    vector<int> res = FindIntersection(arr1, arr2, m, n);
    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << " ";
    }
    return 0;
    
}