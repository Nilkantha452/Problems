/* Sort 0, 1 and 2 nodes in a linked list. */
#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode* MakeList(int arr[], int n)
{
    ListNode* start = new ListNode(-1);
    ListNode* startCurr = start;
    for (int i = 0; i < n; i++)
    {
        ListNode* newNode = new ListNode(arr[i]);
        startCurr->next = newNode;
        startCurr = startCurr->next;
    }
    return start->next;
}

void PrintList(ListNode* head)
{
    ListNode* p = head;
    while (p)
    {
        std::cout << p->val << " ";
        p = p->next;
    }
}

ListNode* SortZeroOneTwo(ListNode* head)
{
    ListNode* zeroStart = new ListNode(-1);
    ListNode* oneStart = new ListNode(-1);
    ListNode* twoStart = new ListNode(-1);
    ListNode* zeroCurr = zeroStart, * oneCurr = oneStart, * twoCurr = twoStart;
    ListNode* p = head;
    while (p)
    {
        if (p->val == 0)
        {
            zeroCurr->next = p;
            p = p->next;
            zeroCurr = zeroCurr->next;
            zeroCurr->next = nullptr;
        }
        else if (p->val == 1)
        {
            oneCurr->next = p;
            p = p->next;
            oneCurr = oneCurr->next;
            oneCurr->next = nullptr;
        }
        else
        {
            twoCurr->next = p;
            p = p->next;
            twoCurr = twoCurr->next;
            twoCurr->next = nullptr;
        }
    }
    if (oneStart->next == nullptr)
    {
        zeroCurr->next = twoStart->next;
    }
    else
    {
        zeroCurr->next = oneStart->next;
        oneCurr->next = twoStart->next;
    }
    return zeroStart->next;
}

int main()
{
    int arr[] = { 0, 1, 1, 1, 0, 1, 1, 0 };
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = MakeList(arr, n);
    ListNode* ans = SortZeroOneTwo(head);
    PrintList(ans);
}