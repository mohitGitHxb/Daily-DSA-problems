#include <bits/stdc++.h>
using namespace std;
class DifferentViewsOfTree
{
public:
    /*
    @ TOP G View
    &- The code implements the top view of a binary tree.
&- The algorithm utilizes a breadth-first search (BFS) approach to traverse the tree level by level.
&- It uses a queue to store pairs of nodes and their corresponding horizontal distances from the root.
&- A map is used to keep track of the nodes for each horizontal distance.
&- The root node is pushed into the queue with a horizontal distance of 0.
&- While the queue is not empty, the algorithm performs the following steps:
&- Dequeue a pair from the front of the queue, consisting of a node and its horizontal distance.
&- If the current horizontal distance does not exist in the map, insert the node's data into the map with the horizontal distance as the key.
&- If the node has a left child, enqueue a pair with a horizontal distance decremented by 1 and the left child.
&- If the node has a right child, enqueue a pair with a horizontal distance incremented by 1 and the right child.
&- After the BFS traversal, the map contains the top view nodes for each horizontal distance.
&- Extract the nodes from the map in ascending order of their horizontal distances and store them in a vector.
&- Return the vector containing the top view nodes.

~ The intuition behind this algorithm is to traverse the binary tree in a level-wise manner, keeping track of the horizontal distances of the nodes. By storing only the first encountered node for each horizontal distance in the map, the algorithm captures the nodes visible from the top view of the tree. Finally, the nodes are extracted from the map and returned as the top view vector.

* O(NlogN) T.C | O(N) S.C

     */

    vector<int> topView(Node *root)
    {
        // Your code here
        if (!root)
            return {};
        queue<pair<int, Node *>> q;
        vector<int> ans;
        map<int, int> mp;
        q.push({0, root});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *node = it.second;
            int x = it.first;
            if (mp.find(x) == mp.end())
                mp[x] = node->data;
            if (node->left)
                q.push({x - 1, node->left});
            if (node->right)
                q.push({x + 1, node->right});
        }
        for (auto &it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
    /*
    @ Bottom G view

     */
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        if (!root)
            return {};
        queue<pair<int, Node *>> q;
        vector<int> ans;
        q.emplace(0, root);
        map<int, int> mp;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first;
            Node *p = it.second;
            mp[x] = p->data;
            if (p->left)
                q.emplace(x - 1, p->left);
            if (p->right)
                q.emplace(x + 1, p->right);
        }
        for (auto &i : mp)
            ans.emplace_back(i.second);
        return ans;
    }
    /*
    @ Right View
     */
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        queue<pair<TreeNode *, int>> q;
        map<int, TreeNode *> mp;
        q.emplace(root, 0);
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int y = it.second;
            mp[y] = it.first;
            if (it.first->left)
                q.emplace(it.first->left, y + 1);
            if (it.first->right)
                q.emplace(it.first->right, y + 1);
        }
        for (auto &k : mp)
            ans.emplace_back(k.second->val);
        return ans;
    }
    /*
    @ Left view of the tree
     */
    void leftViewTree(Node *root, vector<int> &ans, int level)
    {
        if (!root)
            return;
        if (level == ans.size())
            ans.emplace_back(root->data);
        leftViewTree(root->left, ans, level + 1);
        leftViewTree(root->right, ans, level + 1);
    }
};
int main(){
    return 0;
}