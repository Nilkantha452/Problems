/* Delete a node from a different positions of a linked list */

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

ListNode* DeleteHead(ListNode* head)
{
    ListNode* tempNode = head;
    head = head->next;
    tempNode->next = nullptr;
    delete tempNode;
    return head;
}

ListNode* DeleteLastNode(ListNode* head)
{
    ListNode* curr = head;
    while (curr->next->next != nullptr)
    {
        curr = curr->next;
    }
    ListNode* tempNode = curr->next;
    curr->next = nullptr;
    delete tempNode;
    return head;
}

ListNode* SearchAndDelete(ListNode* head, int x)
{
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr && curr->val != x)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
    {
        std::cout << "Element not found!";
        return head;
    }
    ListNode* tempNode = curr;
    prev->next = curr->next;
    delete curr;
}

int main()
{
    int arr[] = { 1, 2, 4, 5, 7, 9, 10 };
    int n = sizeof(arr) / sizeof(int);
    ListNode* head = MakeList(arr, n);
    PrintList(head);
    ListNode* h = DeleteLastNode(head);
    PrintList(h);
    return 0;
}