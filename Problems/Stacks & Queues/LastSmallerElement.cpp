/* Find the last smaller element array. */
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> LastSmallerElement(int arr[], int n)
{
    std::vector<int> ans(n);
    std::stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans[i] = -1;
            st.push(arr[i]);
        }
        else if (st.size() > 0 && arr[i] > st.top())
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        else
        {
            while (st.size() > 0 && arr[i] <= st.top())
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
    }
    return ans;
}

int main()
{
    int arr[] = { 1, 3, 2, 4, 5, 7, 3, 8, 2 };
    int n = sizeof(arr) / sizeof(int);
    std::vector<int> ans = LastSmallerElement(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}