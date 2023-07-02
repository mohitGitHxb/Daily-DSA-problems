#include <bits/stdc++.h>
using namespace std;
/*

*Problem*
https://practice.geeksforgeeks.org/problems/postorder-traversal-iterative/1

*Explanation*

& The function first initializes an empty vector `postOrder` to store the postorder traversal of the tree. It then checks if the root of the tree is `NULL`. If it is, the function returns an empty vector.

& Next, the function initializes two empty stacks `s1` and `s2`. It pushes the root of the tree onto stack `s1`.

& Then, it enters a while loop that continues until stack `s1` is empty. Inside the loop, it sets `root` to the top element of stack `s1` and pops it from the stack. It then pushes `root` onto stack `s2`. If the left child of `root` is not `NULL`, it pushes it onto stack `s1`. If the right child of `root` is not `NULL`, it also pushes it onto stack `s1`.

& After the first while loop, the function enters another while loop that continues until stack `s2` is empty. Inside the loop, it pushes the data of the top element of stack `s2` onto vector `postOrder` and pops it from the stack.

& After the second while loop, the function returns vector `postOrder`.

The intuition behind this code is that it uses two stacks to simulate the recursive postorder traversal of a binary tree. Stack `s1` is used to keep track of nodes that need to be visited, while stack `s2` is used to store nodes in reverse postorder. In each iteration of the first while loop, the function visits a node and pushes its children onto stack `s1`. It also pushes the node itself onto stack `s2`. This continues until all nodes have been visited. Then, in each iteration of the second while loop, the function pops a node from stack `s2` and adds its data to vector `postOrder`. Since stack `s2` stores nodes in reverse postorder, popping them from the stack produces nodes in postorder.

The time complexity of this function is O(N) since it visits all N nodes in the binary tree once. The space complexity is O(N) since it uses two stacks that can each store up to N/2 nodes.

 */
struct Node
{
    int data;
    Node *left;
    Node *right;
};
vector<int> postOrder(Node *root)
{
    // code here
    vector<int> postOrder;
    if (!root)
        return {};
    stack<Node *> s1, s2;
    s1.emplace(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.emplace(root);
        if (root->left != NULL)
        {
            s1.emplace(root->left);
        }
        if (root->right != NULL)
        {
            s1.emplace(root->right);
        }
    }
    while (!s2.empty())
    {
        postOrder.push_back(s2.top()->data);
        s2.pop();
    }
    return postOrder;
}
int main()
{
    return 0;
}