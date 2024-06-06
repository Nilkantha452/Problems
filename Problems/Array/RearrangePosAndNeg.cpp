/* Rearrange the array elements by their sign without changing the order. */
#include <iostream>
#include <vector>

/* Save all the elements in alternate order. */
std::vector<int> RearrangeElements(int arr[], int n)
{
    std::vector<int> ans(n);
    int i = 0, j = 1;
    for (int k = 0; k < n; k++)
    {
        if (arr[k] < 0)
        {
            ans[i] = arr[k];
            i += 2;
        }
        else
        {
            ans[j] = arr[k];
            j += 2;
        }
    }
    return ans;
}

int main()
{
    int arr[] = { -1, -2, -4, -2, 4, 2, 1, 4 };
    int n = sizeof(arr) / sizeof(int);
    std::vector<int> ans = RearrangeElements(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i] << " ";
    }
    return 0;
}