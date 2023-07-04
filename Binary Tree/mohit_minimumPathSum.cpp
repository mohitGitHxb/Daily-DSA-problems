#include <bits/stdc++.h>

using namespace std;
/*
    *problem*
    https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

    *explanation*

    The solve function takes a TreeNode pointer root and a reference to an integer maxi (initialized to a very small value) as parameters.

    If root is nullptr, indicating an empty node, the function returns 0.

    The function recursively calls solve on the left and right subtrees of root, storing the returned values in the variables left and right, respectively. The values are calculated by taking the maximum between 0 and the result of the recursive calls. This ensures that negative values are not considered in the path sum.

    The maximum path sum that includes the current root node is calculated as left + right + root->val. This is compared with the current maximum sum maxi, and the greater value is stored in maxi. This step finds the maximum sum path that includes the current node.

    The function returns the maximum path sum starting from the current root node, which is calculated as root->val + max(right, left). This step considers whether to include the current node in the path sum or not, by choosing the maximum between the sums of the left and right subtrees.

    The maxPathSum function initializes the maxi variable to a very small value.

    It calls the solve function with the root node and the maxi variable as parameters. This updates the maxi variable with the maximum path sum in the tree.

    Finally, the maxi variable, which now holds the maximum path sum, is returned as the result of the function.

The time complexity of this code is O(N), where N is the number of nodes in the binary tree. This is because we perform a DFS traversal of the tree, visiting each node once.

The space complexity is O(H), where H is the height of the binary tree. This is because the recursion stack will have at most H frames at any given time, corresponding to the maximum depth of the tree. In the worst case, when the tree is skewed, the height can be equal to N, resulting in a space complexity of O(N). However, in a balanced tree, the height is typically logarithmic in the number of nodes, resulting in a space complexity of O(log N).

 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode *root, int &maxi)
{
    if (!root)
        return 0;
    int left = max(0, solve(root->left, maxi));
    int right = max(0, solve(root->right, maxi));
    maxi = max(maxi, left + right + root->val);
    return root->val + max(right, left);
}
int maxPathSum(TreeNode *root)
{
    int maxi = -1e8;
    solve(root, maxi);
    return maxi;
}
int main()
{
    return 0;
}