#include <bits/stdc++.h>
using namespace std;
/*

*Problem*
https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
*Explanation*
    The merge function is used to merge two sorted linked lists (left and right) into a single sorted linked list.
    Create a dummy node temp and a pointer res to keep track of the head of the merged list.
    Iterate through both left and right lists simultaneously until either one of them reaches the end.
    Compare the data of the current nodes in left and right. If the data in left is smaller, add the left node to the merged list, update temp, and move left to the next node in its list.
    If the data in right is smaller or equal, add the right node to the merged list, update temp, and move right to the next node in its list.
    Continue this process until one of the lists reaches the end.
    If there are any remaining nodes in either left or right, append them to the merged list.
    Return the bottom pointer of the res node, which points to the head of the merged list.

The flatten function recursively flattens the given hierarchical linked list by following these steps:

    If the given root node is either NULL or it has no next node, return the root itself (base case for recursion).
    Recursively flatten the rest of the linked list starting from root->next by calling flatten(root->next).
    Update the root node to point to the merged list of root and root->next by calling the merge function.
    Return the updated root.

The intuition behind this approach is to divide the problem into subproblems by recursively flattening the linked list and merging them in a sorted manner using the merge function. This approach leverages the merging property of the sorted linked lists to efficiently flatten the entire hierarchical linked list.

The time complexity of this code is O(N * M), where N is the total number of nodes in the linked list and M is the number of levels in the hierarchy. The space complexity is O(1) since the operations are performed in-place without using any additional data structures.
 */
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node *merge(Node *left, Node *right)
{
    Node *temp = new Node(0);
    Node *res = temp;
    while (left && right)
    {
        if (left->data < right->data)
        {
            temp->bottom = left;
            temp = temp->bottom;
            left = left->bottom;
        }
        else
        {
            temp->bottom = right;
            temp = temp->bottom;
            right = right->bottom;
        }
    }
    if (left)
        temp->bottom = left;
    else
        temp->bottom = right;
    return res->bottom;
}
Node *flatten(Node *root)
{
    if (!root || !root->next)
        return root;
    root->next = flatten(root->next);
    root = merge(root, root->next);

    return root;
}
int main(int argc, char const *argv[])
{

    return 0;
}
