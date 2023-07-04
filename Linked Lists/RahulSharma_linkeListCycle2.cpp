#include <bits/stdc++.h>
using namespace std;

/* Problem link

https://leetcode.com/problems/linked-list-cycle-ii/

TC - O(N)
SC - O(1)

Approach

A function "detectCycle" is created and a "head" pointer of node type is passed as an argument. Two other pointers of node type are also created ("fast" & "slow") and are pointed to head pointer. A "While" loop is executed till fast pointer is not equal to NULL pointer and next of fast  pointer is not equal to NULL pointer. Then "fast" pointer is increased by pointing fast to next of next of fast ptr (fast pointer is increased by two steps) and the slow pointer is pointed to next of slow (slow is increased by one step). Check the existance of a cycle by putting condition if fast is equal to equal slow. If a cycle doesn't not exist return NULL pointer. If a cycle exists, then point the slow pointer to head and then increase both fast and slow pointer by one - one steps. Again when the slow and the fast pointer meets, that location represents the starting point of the cycle. Finally return the slow pointer as the final answer.  */

// Code

class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
    };

public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *fast = head;

        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {

            fast = fast->next->next;

            slow = slow->next;

            if (fast == slow)
            {

                slow = head;

                while (slow != fast)
                {

                    slow = slow->next;

                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

int main()
{
    return 0;
}