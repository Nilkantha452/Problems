/* Add two numbers represented in two linked list. */
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

ListNode* RemoveLeadingZeros(ListNode* head)
{
    ListNode* p = head;
    while (p)
    {
        if (p->val == 0)
        {
            head = head->next;
        }
        else
        {
            break;
        }
        p = p->next;
    }
    return head;
}

ListNode* reverseList(ListNode* head)
{
    struct ListNode* p = head, * q = nullptr, * r = nullptr;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

ListNode* AddTwoListNumber(ListNode* head1, ListNode* head2)
{
    ListNode* h1 = RemoveLeadingZeros(head1);
    ListNode* h2 = RemoveLeadingZeros(head2);
    if (h1 == nullptr && h2 == nullptr)
    {
        return new ListNode(0);
    }
    ListNode* n1 = reverseList(h1);
    ListNode* n2 = reverseList(h2);
    ListNode* dummy = new ListNode(-1);
    ListNode* dummyCurr = dummy;
    int carry = 0;
    while (n1 != nullptr || n2 != nullptr)
    {
        int sum = carry;
        if (n1)
        {
            sum += n1->val;
        }
        if (n2)
        {
            sum += n2->val;
        }
        carry = sum / 10;
        int num = sum % 10;
        ListNode* newNode = new ListNode(num);
        dummyCurr->next = newNode;
        dummyCurr = dummyCurr->next;
        if (n1)
        {
            n1 = n1->next;
        }
        if (n2)
        {
            n2 = n2->next;
        }
    }
    if (carry)
    {
        ListNode* newNode = new ListNode(carry);
        dummyCurr->next = newNode;
    }
    return reverseList(dummy->next);
}



int main()
{
    int arr1[] = { 5, 6, 0, 1 };
    int arr2[] = { 7, 2, 1 };
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    ListNode* head1 = MakeListEx(arr1, n1);
    ListNode* head2 = MakeListEx(arr2, n2);
    ListNode* AddedList = AddTwoListNumber(head1, head2);
    PrintList(AddedList);
    return 0;
}