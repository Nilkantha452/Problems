/* 
* The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to
* calculate the span of the stock’s price for all N days. The span Si of the stock’s price on a given day i is defined as
* the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is
* less than or equal to its price on the given day.
* 
* Input: N = 7, price[] = [100 80 60 70 60 75 85]
* Output: 1 1 1 2 1 4 6
*/


#include <iostream>
#include <stack>
#include <vector>

std::vector<int> StockSpan(int arr[], int n)
{
    std::stack<int> st;
    std::vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.size() == 0)
        {
            ans.push_back(1);
            st.push(i);
        }
        else if (st.size() > 0 && arr[i] < arr[st.top()])
        {
            ans.push_back(1);
            st.push(i);
        }
        else
        {
            while (st.size() > 0 && arr[i] >= arr[st.top()])
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                ans.push_back(1);
            }
            else
            {
                ans.push_back(i - st.top());
            }
            st.push(i);
        }
    }
    return ans;
}

int main()
{
    int arr[] = { 100, 80, 60, 70, 60, 75, 85 };
    int n = sizeof(arr) / sizeof(int);
    std::vector<int> ans = StockSpan(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}