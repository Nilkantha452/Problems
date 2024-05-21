/* Find the last Greater Element array. */
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> LastGreaterElement(int arr[], int n)
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
        else if (st.size() > 0 && arr[i] < st.top())
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        else
        {
            while (st.size() > 0 && arr[i] >= st.top())
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
    int arr[] = { 2, 1, 4, 5, 7, 3, 9, 10, 4, 6 };
    int n = sizeof(arr) / sizeof(int);
    std::vector<int> ans = LastGreaterElement(arr, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}