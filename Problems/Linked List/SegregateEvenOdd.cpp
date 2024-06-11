/* Segregate Even and Odd numbers in a linked list, where odd numbers are at the front. */
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

ListNode* SegregateList(ListNode* head)
{
    ListNode* startOdd = new ListNode(-1);
    ListNode* startEven = new ListNode(-1);
    ListNode* currOdd = startOdd;
    ListNode* currEven = startEven;
    ListNode* p = head;
    while (p != nullptr)
    {
        if (p->val % 2)
        {
            currOdd->next = p;
            p = p->next;
            currOdd = currOdd->next;
            currOdd->next = nullptr;
        }
        else
        {
            currEven->next = p;
            p = p->next;
            currEven = currEven->next;
            currEven->next = nullptr;
        }
    }
    currOdd->next = startEven->next;
    return startOdd->next;
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 7, 9, 10, 13, 12 };
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = MakeListEx(arr, n);
    ListNode* node = SegregateList(head);
    PrintList(node);
    return 0;
}