#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;
    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

/*

@ Problem
Clone a linked list with a random pointer
The intuition behind the code is to maintain a mapping between each original node and its corresponding cloned node. This mapping is stored in an unordered map, where the original node is the key and the cloned node is the value.

Here's how the code works:

    First, it checks if the given linked list is empty (i.e., head is NULL). If it is, it returns NULL since there's no list to copy.

    It initializes an unordered map called mp to store the mapping between original nodes and cloned nodes.

    The code then iterates through the original linked list using a pointer curr. In each iteration, it creates a new node with the same data as the current original node and adds it to the map mp with the current original node as the key.

    After creating the cloned nodes for all original nodes, the code performs a second iteration through the original linked list. In each iteration, it sets the next pointer of the cloned node to the corresponding cloned node of the next original node using the map mp. Similarly, it sets the arb pointer of the cloned node to the corresponding cloned node of the arb pointer of the original node.

    Finally, the code returns the cloned node corresponding to the original head node, which can be obtained from the map mp.

By using the map mp to maintain the mapping between original and cloned nodes, the code ensures that the cloned list is a deep copy with separate memory allocations for each node, while also correctly setting the next and arb pointers.

Overall, the code effectively creates a deep copy of the given linked list with the additional "arb" pointers by utilizing an unordered map to maintain the mapping between original and cloned nodes.

O(N) time and O(N) space

  */
class bruteForce
{
public:
    Node *copyList(Node *head)
    {
        // Write your code here
        if (!head)
            return head;
        unordered_map<Node *, Node *> mp;
        for (Node *curr = head; curr != NULL; curr = curr->next)
        {
            mp[curr] = new Node(curr->data);
        }
        for (Node *curr = head; curr != NULL; curr = curr->next)
        {
            Node *cloned = mp[curr];
            cloned->next = mp[curr->next];
            cloned->arb = mp[curr->arb];
        }
        return mp[head];
    }
};

/*

@ Problem
 Clone a linked list with a random pointer [hard]
@ Explanation

O(N) Time and O(1) Space
    First, it checks if the given linked list is empty (i.e., head is NULL). If it is, it returns NULL since there's no list to copy.

    The code then iterates through the original linked list using a pointer current. In each iteration, it creates a new node with the same data as the current original node and inserts it after the current original node. This is done by assigning the next pointer of the current original node to the newly created node, and assigning the next pointer of the newly created node to the next node in the original list. This effectively creates a duplicate copy of each node in the original list.

    After creating the duplicate nodes, the code performs another iteration through the list to set the arb pointers of the newly created nodes. For each original node, it sets the arb pointer of its corresponding duplicate node to the next node of the original node's arb pointer. This is done by checking if the original node's arb pointer is not NULL. If it is not NULL, the arb pointer of the duplicate node is set to the next node of the original node's arb pointer. This step ensures that the arb pointers of the duplicate nodes correctly point to the corresponding duplicate nodes.

    The code then separates the original and duplicate linked lists by updating the next pointers of the original nodes and the duplicate nodes. It starts by setting two pointers original and copy to the respective heads of the original and duplicate lists. It also keeps a temporary pointer temp to track the head of the duplicate list.
        In each iteration, it updates the next pointer of the original node to skip the next node (which is the duplicate node), effectively removing the duplicate node from the original list.
        Similarly, it updates the next pointer of the duplicate node to either skip the next duplicate node (if it exists) or NULL (if it doesn't exist), effectively removing the original node from the duplicate list.
        It continues this process until either the original list or the duplicate list reaches the end.

    Finally, it returns the head of the duplicate list, which is stored in the temp pointer.

By following these steps, the code effectively creates a deep copy of the given linked list with the additional "arb" pointers. It achieves this by iteratively duplicating each node in the original list, setting the "arb" pointers of the duplicate nodes to the appropriate nodes, and then separating the original and duplicate lists while updating the "next" pointers.

Note: The code assumes that the original list and the duplicate list have the same number of nodes, and it does not modify the original list.
 */

class optimized
{
    Node *copyList(Node *head)
    {
        // Write your code here
        if (!head)
            return head;
        Node *current = head;
        while (current != NULL)
        {
            Node *temp = current->next;
            current->next = new Node(current->data);
            current->next->next = temp;
            current = temp;
        }
        current = head;

        // Setting random pointers to new nodes

        while (current != NULL)
        {

            current->next->arb = (current->arb) ? current->arb->next : current->arb;
            current = current->next->next;
        }
        Node *original = head;
        Node *copy = head->next;
        Node *temp = copy;

        while (original != NULL && copy != NULL)
        {
            original->next = original->next->next;
            copy->next = (copy->next != NULL) ? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }
        return temp;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}
