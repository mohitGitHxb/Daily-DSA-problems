#include <bits/stdc++.h>
using namespace std;

//^ 14 Add 1 to number represented by a linked list
class Add1toLL
{
private:
    struct Node
    {
        int data;
        struct Node *next;

        Node(int x)
        {
            data = x;
            next = NULL;
        }
    };

public:
    /*
    @ Recursive approach
&  The solve function is a recursive helper function that performs the addition operation. It takes a current node as input and returns the carry value (either 0 or 1) after adding 1 to the number represented by the subsequent nodes.

&  The base case of the recursion is when the current node's next pointer is NULL, indicating the last digit of the number. In this case, it checks if the current digit is 9. If it is 9, it changes the digit to 0 and returns 1 as the carry. If it is not 9, it increments the digit by 1 and returns 0 as the carry.

&  For non-base cases, it recursively calls the solve function for the next node and stores the returned carry value. If the carry is 1, it performs the same logic as the base case, changing the digit to 0 if it is 9 and returning 1 as the carry. Otherwise, it increments the digit by 1 and returns 0 as the carry.

&  The addOne function is the main function that calls the solve function on the head node of the linked list. It also handles the case where the final carry is 1. If the carry is 1, it creates a new node with a value of 1 and sets its next pointer to the original head. It then returns this new node as the new head of the linked list.

&  The overall process is similar to adding 1 to a number manually, starting from the least significant digit and propagating the carry to the more significant digits if necessary.

&  Note: The code assumes that the input linked list is not empty.

&  The time complexity of the code is O(n), where n is the number of nodes in the linked list, as it needs to traverse the entire linked list.

    ! O(Nodes) T.C | O(Nodes) S.C
     */
    int solve(Node *curr)
    {
        if (curr->next == NULL)
        {
            if (curr->data == 9)
            {
                curr->data = 0;
                return 1;
            }
            else
            {
                curr->data++;
                return 0;
            }
        }
        int carry = solve(curr->next);
        if (carry == 1)
        {
            if (curr->data == 9)
            {
                curr->data = 0;
                return 1;
            }
            else
            {
                curr->data++;
                return 0;
            }
        }
        return carry;
    }
    // Node *addOne(Node *head)
    // {
    //     int getCarry = solve(head);
    //     if (getCarry == 1)
    //     {
    //         Node *temp = new Node(1);
    //         temp->next = head;
    //         return temp;
    //     }
    //     return head;
    // }

    /*
    @ Storing the value of rightmost 9
    &1. The function addOne takes a linked list head as input and returns the modified linked list after adding 1 to the number represented by the linked list.
&2. Two pointers, notNine and end, are initialized to the head of the linked list.
&3. A while loop is used to traverse the linked list until the end node is reached (i.e., end->next is NULL).
&4. Inside the loop, if the current node's data is not equal to 9, the notNine pointer is updated to point to the current node. This helps keep track of the rightmost non-nine digit in the linked list.
&5. Finally, end is updated to point to the last node of the linked list.
&6. At this point, we have identified the rightmost non-nine digit or the last node in the linked list.
&7. If the data of the last node (end->data) is equal to 9, it means all the digits in the linked list are nines.
&8. In such a case, the value of the rightmost non-nine digit is incremented by 1 (notNine->data = notNine->data + 1), and the notNine pointer is moved to the next node.
&9. Then, a while loop is used to traverse the remaining nodes starting from notNine and set their data to 0, effectively changing all the nines to zeros.
&10. If the data of the last node is not 9, it means we can simply increment its value by 1 (end->data = end->data + 1).
&11. Finally, the modified linked list is returned.

The intuition behind this code is to find the rightmost non-nine digit (or the last node) in the linked list and increment its value by 1. If all the digits in the linked list are nines, we need to propagate the carry by incrementing the value of the rightmost non-nine digit and setting all the subsequent digits to zero.

Using this approach, the code efficiently handles cases where the linked list contains consecutive nines or has a mix of non-nine and nine digits.

Please note that the code assumes the input linked list represents a non-negative integer, and it does not consider cases where the resulting number exceeds the range of integer representation.

     */
    Node *addOne(Node *head)
    {
        Node *notNine = head, *end = head;
        while (end->next)
        {
            if (end->data != 9)
                notNine = end;
            end = end->next;
        }
        if (end->data == 9)
        {
            notNine->data = notNine->data + 1;
            notNine = notNine->next;
            while (notNine)
            {
                notNine->data = 0;
                notNine = notNine->next;
            }
        }
        else
        {
            end->data = end->data + 1;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
