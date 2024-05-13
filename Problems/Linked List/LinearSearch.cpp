/*Find length & Find an element in a linked list. */

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

int Length(ListNode* head)
{
    int result = 0;
    ListNode* curr = head;
    while (curr != nullptr)
    {
        result++;
        curr = curr->next;
    }
    return result;
}

ListNode* findNode(ListNode* head, int x)
{
    ListNode* curr = head;
    while (curr && curr->val != x)
    {
        curr = curr->next;
    }
    if (curr)
    {
        return curr;
    }
    else
    {
        return nullptr;
    }
    return nullptr;
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 7, 9, 10 };
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = MakeList(arr, n);
    PrintList(head);
    std::cout << std::endl << Length(head) << std::endl;
    ListNode* node = findNode(head, 4);
    std::cout << "found " << node->val;
    return 0;
}