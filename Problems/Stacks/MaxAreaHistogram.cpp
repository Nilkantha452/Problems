#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> NearestLeftSmallElement(long long arr[], int n)
{
    std::stack<std::pair<long long, int>> st;
    std::vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans.push_back(-1);
            st.push({ arr[i], i });
        }
        else if (st.size() > 0 && arr[i] > st.top().first)
        {
            ans.push_back(st.top().second);
            st.push({ arr[i], i });
        }
        else
        {
            while (st.size() > 0 && arr[i] <= st.top().first)
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top().second);
            }
            st.push({ arr[i], i });
        }
    }
    return ans;
}

std::vector<int> NearestRightSmallElement(long long arr[], int n)
{
    std::stack<std::pair<long long, int>> st;
    std::vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            ans.push_back(n);
            st.push({ arr[i], i });
        }
        else if (st.size() > 0 && arr[i] > st.top().first)
        {
            ans.push_back(st.top().second);
            st.push({ arr[i], i });
        }
        else
        {
            while (st.size() > 0 && arr[i] <= st.top().first)
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(n);
            }
            else
            {
                ans.push_back(st.top().second);
            }
            st.push({ arr[i], i });
        }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

long long getMaxArea(long long arr[], int n)
{

    std::vector<int> left = NearestLeftSmallElement(arr, n);

    std::vector<int> right = NearestRightSmallElement(arr, n);

    std::vector<long long> width(n);
    long long maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        width[i] = arr[i] * width[i];
        maxArea = std::max(maxArea, width[i]);
    }
    return maxArea;
}

int main()
{
    long long arr[] = { 6,2,5,4,5,1,6 };
    int n = sizeof(arr) / sizeof(long long);
    std::cout << getMaxArea(arr, n);
}