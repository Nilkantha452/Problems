/* Find the next greater element of each integer of an array and return the ans array. */
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> NextGreaterElement(int arr[], int n)
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
        else if (st.size() > 0 && st.top() > arr[i])
        {
            ans[i] = st.top();
            st.push(arr[i]);
        }
        else
        {
            while (st.size() > 0 && st.top() <= arr[i])
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
    int arr[] = { 1, 3, 2, 4, 5, 8, 2 };
    int n = sizeof(arr) / sizeof(int);
    std::vector<int> ans = NextGreaterElement(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}