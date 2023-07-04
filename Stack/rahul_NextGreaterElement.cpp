https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1?page=2&sortBy=submissions 

TC O(N)
SC O(N)
vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        reverse(arr.begin(), arr.end());
        vector<long long> ans;
        stack<long long> s;
        for(int i =0; i<n; i++){
            if(s.empty()){
                ans.push_back(-1);
                s.push(arr[i]);
            }
            else if(s.top()>arr[i]){
                ans.push_back(s.top());
                s.push(arr[i]);
            }
            else{
                while(s.top() <= arr[i]){
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                if(s.empty()){
                    ans.push_back(-1);
                    s.push(arr[i]);
                }
                else{
                    ans.push_back(s.top());
                    s.push(arr[i]);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


The code first reverses the arr vector using the reverse function from the <algorithm> library. This allows for a more convenient processing order.
It initializes an empty vector ans to store the next larger elements.
It uses a stack s to keep track of elements in a decreasing order from bottom to top.
It iterates through each element of the reversed arr vector.
If the stack is empty, it means there are no larger elements to the right of the current element. So, it pushes -1 into the ans vector and pushes the current element onto the stack.
If the top element of the stack is larger than the current element, it means it is the next larger element. So, it pushes the top element onto the ans vector and then pushes the current element onto the stack.
If the top element of the stack is not larger than the current element, it means there is a larger element further to the right. In this case, it keeps popping elements from the stack until it finds a larger element or the stack becomes empty.
If the stack becomes empty, it means there is no larger element to the right. So, it pushes -1 into the ans vector and pushes the current element onto the stack.
If the stack is not empty, it means a larger element is found. So, it pushes the top element of the stack onto the ans vector and pushes the current element onto the stack.
After processing all elements, the ans vector contains the next larger elements in reverse order.
To obtain the correct order, it reverses the ans vector using the reverse function.
Finally, it returns the ans vector
