https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1?page=1&category[]=Binary%20Search%20Tree&curated[]=7&sortBy=submissions


T.C. - O(N)
S.C - O(N)

In this question we have to find a dead end in BST. Dead end is basically a leaf node after which any node can't be inserted in bst.

Intuition: 
In this question we have to search for a node for which its root -> data +1 and root -> data - 1 already exists in bst. One point to be noted that in bst should contain positive integer greater than zero so if there is 1 at leaf node then root -> data - 1 will be zero which disobeyed greater than zero wali condition. So if there is 1 at leaf node we will keep root ->data else we will do root -> data -1



Example : 

              8
            /   \ 
           7     10
         /      /   \
        2      9     13

In this example 9 is dead end u can't insert at node after 9 as u can't insert value greater than 9 because  if we insert a nide at right side of 9  then the data of node should be greater than 9 but less than 10(parent of 9) which does exist. 
We can't insert a node at left side of 9 because for left subtree values should be greater than 8 and for left side values should be less than 9 hence no such values exist.

Code :

void fun(Node* root, unordered_map<int, bool> &visited, bool &ans){
    if(!root){
        return;
    }
    
    visited[root-> data] =1;
    
    if(!root -> left && !root -> right){
        int xp1 = root -> data + 1;
        int xm1 = root -> data -1 ==0? root-> data : root -> data -1;
        if(visited.find(xp1) != visited.end() && visited.find(xm1) != visited.end()){
            ans = true;
            return;
        }
    }
    fun(root -> left, visited, ans);
    fun(root -> right, visited, ans);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    bool ans = false;
    unordered_map<int, bool> visited;
    fun(root, visited, ans);
    return ans;
}
