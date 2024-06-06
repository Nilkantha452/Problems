/* Count the number of elements which is forming a maximum consecutive sequence. */
#include <iostream>
#include <vector>
#include <unordered_set>

int MaxConsecutiveSubSequence(int arr[], int n)
{
    if (n == 0) return 0;
    std::unordered_set<int> st;
    int maxCount = 1;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int temp = it;
            int count = 1;
            while (st.find(temp + 1) != st.end())
            {
                count++;
                temp++;
            }
            maxCount = std::max(maxCount, count);
        }
    }
    return maxCount;
}

int main()
{
    int arr[] = { 2, 4, 3, 1, 5, 6, 102, 100, 101, 103, 105, 104, 106 };
    int n = sizeof(arr) / sizeof(int);
    std::cout << MaxConsecutiveSubSequence(arr, n);
    return 0;
}