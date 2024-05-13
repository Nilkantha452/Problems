/* Create a linked list from an array. And print it. */

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
    if (n == 0) return nullptr;
    ListNode* newNode = new ListNode(arr[0]);
    ListNode* head = newNode;
    ListNode* curr = head;
    for (int i = 1; i < n; i++)
    {
        ListNode* newN = new ListNode(arr[i]);
        curr->next = newN;
        curr = curr->next;
    }
    return head;
}

/* This is another function to create a list using dummy node. */
ListNode* MakeListEx(int arr[], int n)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    for (int i = 0; i < n; i++)
    {
        ListNode* newNode = new ListNode(arr[i]);
        curr->next = newNode;
        curr = curr->next;
    }
    return dummy->next;
}

void PrintList(ListNode* head)
{
    ListNode* curr = head;
    if (curr == nullptr)
    {
        std::cout << "List is Empty!" << std::endl;
    }
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
}

ListNode* ReverseList(ListNode* head)
{
    /* Iterative Approach */
    ListNode* p = head, * q = nullptr, * r = nullptr;
    while (p != nullptr)
    {
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    return q;
}

ListNode* ReverseListRecurr(ListNode* head)
{
    /* Recursive approach */
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode* newHead = ReverseListRecurr(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 7, 9, 10, 12 };
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = MakeList(arr, n);
    PrintList(head);
    ListNode* rev = ReverseListRecurr(head);
    std::cout << std::endl;
    PrintList(rev);
    return 0;
}