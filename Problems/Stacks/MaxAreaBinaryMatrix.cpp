/* Find the maximum area in a binary matrix formed by 1 */
#include <iostream>
#include <vector>
#include <stack>

#define MAX 100

std::vector<int> LastSmallerElement(std::vector<int>& arr, int n)
{
    std::stack<std::pair<int, int>> st;
    std::vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans[i] = -1;
            st.push({ arr[i], i });
        }
        else if (arr[i] > st.top().first)
        {
            ans[i] = st.top().second;
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
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top().second;
            }
            st.push({ arr[i], i });
        }
    }
    return ans;
}

std::vector<int> NextSmallerElement(std::vector<int>& arr, int n)
{
    std::vector<int> ans(n);
    std::stack<std::pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            ans[i] = n;
            st.push({ arr[i], i });
        }
        else if (arr[i] > st.top().first)
        {
            ans[i] = st.top().second;
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
                ans[i] = n;
            }
            else
            {
                ans[i] = st.top().second;
            }
            st.push({ arr[i], i });
        }
    }
    return ans;
}

int MAH(std::vector<int>& arr, int n)
{
    int maxArea = 0;
    std::vector<int> left = LastSmallerElement(arr, n);
    std::vector<int> right = NextSmallerElement(arr, n);
    for (int i = 0; i < n; i++)
    {
        maxArea = std::max(maxArea, ((right[i] - left[i] - 1) * arr[i]));
    }
    return maxArea;
}

int FindMaxArea(int M[MAX][MAX], int n, int m)
{
    /*
    * Make this 2d matrix to 1d array. And then caculate the Maximum Area of Histogram for every row.
    */
    int maxArea = 0;
    std::vector<int> temp(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                temp[j]++;
            }
            else
            {
                temp[j] = 0;
            }
        }
        maxArea = std::max(maxArea, MAH(temp, m));
    }
    return maxArea;
}

int main()
{
    int M[MAX][MAX] = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    int n = 4, m = 5;
    std::cout << FindMaxArea(M, n, m);
    return 0;
}