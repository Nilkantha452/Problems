/* Print all the sub-sequence of an array using recursion. If the array is {1, 2, 3} then the sub-sequences
* will be: {}, {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3}, {1, 2, 3}
*/

#include <iostream>
#include <vector>

void getAllSubSequence(int arr[], int i, int n, std::vector<int> temp, std::vector<std::vector<int> >& ans)
{
    if (i >= n)
    {
        ans.push_back(temp);
        for (int i = 0; i < temp.size(); i++)
        {
            std::cout << temp[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    /* Take case */
    temp.push_back(arr[i]);
    getAllSubSequence(arr, i + 1, n, temp, ans);

    /* Not take case */
    temp.pop_back();
    getAllSubSequence(arr, i + 1, n, temp, ans);
}

int main()
{
    int arr[] = { 1, 2, 3 };
    int n = sizeof(arr) / sizeof(int);
    std::vector<int> temp;
    std::vector<std::vector<int>> ans;
    getAllSubSequence(arr, 0, n, temp, ans);
    return 0;
}
