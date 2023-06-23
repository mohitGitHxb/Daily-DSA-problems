https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1?page=3&curated[]=1&sortBy=submissions

T.C O(26 * n)
S.C O(26)

The solve function takes a string str as input and returns the modified string as the result.
It initializes a queue named q, an empty string named ans, and an array freq of size 26, which represents the frequencies of characters from 'a' to 'z'.
It iterates through each character in the input string str.
For each character, it increments its frequency in the freq array and adds the character to the queue.
It then enters a while loop that processes the characters in the queue to find the first non-repeating character.
Inside the while loop, it checks if the frequency of the character at the front of the queue is greater than 1.
If the frequency is greater than 1, it means the character is repeating, so it is removed from the queue using q.pop().
If the frequency is 1, it means it is the first non-repeating character encountered so far. In this case, the character is appended to the ans string using ans.push_back(q.front()), and the loop is terminated using break.
If the queue becomes empty after processing all the characters, it means that there are no non-repeating characters encountered so far. In this case, a '#' character is appended to the ans string using ans.push_back('#').
Finally, the modified string ans is returned as the result of the solve function.


class Solution {
	public:
	
	string solve(string str){
	    queue<char> q;
	    string ans = "";
	    int freq[26] = {0};
	    for(int i =0; i<str.size(); i++){
	        char ch = str[i];
	        freq[ch-'a']++;
	        q.push(ch);
	        while(!q.empty()){
	            if(freq[q.front()-'a'] > 1){
	                q.pop();
	            }
	            else{
	                ans.push_back(q.front());
	                break;
	            }
	        }
	        if(q.empty()){
	            ans.push_back('#');
	        }
	        
	    }
	    return ans;
	}
		string FirstNonRepeating(string A){
		    // Code here
		    return solve(A);
		}

};
