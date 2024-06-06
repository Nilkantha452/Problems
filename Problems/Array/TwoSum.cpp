/* Find two variables in an array which sumed up to a value K */
#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::pair<int, int>> FindTwoSum(int arr[], int n, int k)
{
    std::unordered_set<int> st;
    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.find(k - arr[i]) != st.end())
        {
            ans.push_back({ arr[i], k - arr[i] });
        }
        st.insert(arr[i]);
    }
    return ans;
}

int main()
{
    int arr[] = { 3, 1, 5, 6, 7, 2, 4 };
    int n = sizeof(arr) / sizeof(int);
    int k = 8;
    std::vector<std::pair<int, int>> ans = FindTwoSum(arr, n, k);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i].first << " " << ans[i].second << std::endl;
    }
    return 0;
}