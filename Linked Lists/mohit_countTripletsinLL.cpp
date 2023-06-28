#include<bits/stdc++.h>
using namespace std;

/* 
@ Problem 
https://practice.geeksforgeeks.org/problems/87f12e5c728d69a5322634776b54c75897d14daa/1

This code is used to find the number of triplets in a sorted linked list whose sum is equal to a given value x. The code uses an unordered map to store the data value of each node in the linked list as the key and the node itself as the value. Then, it uses two nested loops to iterate over all pairs of nodes in the linked list. For each pair of nodes, it calculates their sum and checks if there is a third node in the unordered map whose data value is equal to x minus the sum of the first two nodes. If such a node is found, it increments the count variable. Finally, it returns count/3 because each triplet is counted three times.

The time complexity of this code is O(n^2) where n is the number of nodes in the linked list because it uses two nested loops to iterate over all pairs of nodes. The space complexity is O(n) because it uses an unordered map to store n nodes.

It’s important to note that this code assumes that the linked list is sorted, but it doesn’t actually use this property. Also, this code could be optimized by using a two-pointer approach instead of using an unordered map.
 */

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;    
    }
};

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    int count = 0;
    unordered_map<int,Node*> mp;
    Node* curr,*first,*second;
    for(curr = head;curr!=NULL;curr=curr->next)
        mp[curr->data] = curr;
    for(first = head;first!=NULL;first=first->next){
        for(second = first->next; second!=NULL; second=second->next){
            int sum = first->data + second->data;
            if(mp.find(x-sum)!=mp.end() && mp[x-sum]!=first && mp[x-sum]!=second){
                count++;
            }
        }
    }
    return count/3;
} 

int main(){
    return 0;
}