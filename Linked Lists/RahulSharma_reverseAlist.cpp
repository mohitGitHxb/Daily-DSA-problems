#include <bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/reverse-linked-list/

TC - O(N)
SC - O(1)
(Iterative Approach)

TC - O(N)
SC - O(N)
(Recursive Approach)

A function "reverseList" is prepared in which "head" pointer of node type is passed as an argument. Other three pointers are also made of node type. (Curr, nxtptr, prevptr). Curr is pointed to head pointer initially, and prevptr is pointed to NULL pointer. Then while loop is implemented till the "curr" pointer becomes NULL. Now point the "next" of the"curr" pointer to "prevptr". And increase   the prevptr and curr, by pointing the prevptr to curr, and pointing the curr to nxtptr. Finally return the head of the of the reversed linked list by returning prevptr.

Iterative approach */

struct ListNode
{
    int val;
    ListNode *next;
};
class Solution
{

public:
    ListNode *reverseList(ListNode *head)
    {

        ListNode *curr = head;

        ListNode *nxtptr;

        ListNode *prevptr = NULL;

        while (curr != NULL)
        {

            nxtptr = curr->next;

            curr->next = prevptr;

            prevptr = curr;

            curr = nxtptr;
        }
        return prevptr;
    }
};

// Recursive approach

class Solution2
{

public:
    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {

            return head;
        }

        ListNode *prev = NULL;

        ListNode *list2 = reverseList(head->next);

        head->next->next = head;

        head->next = prev;

        return list2;
    }
};

int main()
{
    return 0;
}