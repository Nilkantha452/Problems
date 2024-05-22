/* Find the array of next smaller element present in it. */
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> NextSmallerElement(int arr[], int n)
{
    std::vector<int> ans(n);
    std::stack<int> st;
    for (int i = n - 1; i >= 0; i--)
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
    int arr[] = { 3, 1, 5, 6, 8, 2, 4, 1, 2 };
    int n = sizeof(arr) / sizeof(int);
    std::vector<int> ans = NextSmallerElement(arr, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}