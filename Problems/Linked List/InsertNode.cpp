/* Insert a node at different places in a linked list */

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

ListNode* InsertAtBegining(ListNode* head, ListNode* node)
{
    node->next = head;
    head = node;
    return head;
}

ListNode* InsertAtEnd(ListNode* head, ListNode* node)
{
    ListNode* curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = node;
    return head;
}

ListNode* SearchAndInsert(ListNode* head, ListNode* node)
{
    /* This is only applicable for Sorted List. */
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr && curr->val < node->val)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
    {
        prev->next = node;
    }
    else if (curr == head)
    {
        node->next = head;
        head = node;
    }
    else
    {
        prev->next = node;
        node->next = curr;
    }
    return head;
}

ListNode* InsertAtMiddle(ListNode* head, ListNode* node)
{
    ListNode* prev = nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        int data = slow->val;
    }
    node->next = prev->next;
    prev->next = node;
    return head;
}
int main()
{
    int arr[] = { 1, 2, 4, 5, 7, 9 };
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = MakeList(arr, n);
    ListNode* nd = new ListNode(0);
    ListNode* h = InsertAtMiddle(head, nd);
    PrintList(h);
    return 0;
}