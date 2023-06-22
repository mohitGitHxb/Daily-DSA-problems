// PROBLEM: Leetcode 1456
// Maximum Number of Vowels in a Substring of Given Length

// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'. 

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.

// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Overall Time Complexity O(n), n = s.length()
    // because we did just single iteration
    // Space Complexity O(1)

    // a bool function which checks whether the current character is vowel not in O(1) time
    bool isVowel(char ch) {
        return (
            ch == 'a' ||
            ch == 'e' ||
            ch == 'i' ||
            ch == 'o' ||
            ch == 'u'
        );
    }

    int maxVowels(string s, int k) {
        // Using Sliding Window to count max no of vowels in a substring of length of 'k'
        // initialze the left and right pointer with 0
        // along with a variable cnt -> counts no of vowels in the curretn window
        // vairable res which stores the max count of vowels found found in a window

        int left = 0, right = 0, cnt = 0, res = 0;

        // iterate on the string s with the right pointer
        while(right < s.length()) {

            // while adding a new character to the window, 
            // check if it is vowel
            // if yes increment the cnt variable

            if(isVowel(s[right])) {
                cnt++;
            }

            // if the size of the window becomes greater than 'k'
            // we need to remove the leftmost character and increment left pointer
            // but before incrementing the left pointer:
            // check if that character is a vowel,
            // if yes,then decrement the cnt

            if(right - left + 1 > k) {
                if(isVowel(s[left])) {
                    cnt--;
                }
                left++;
            }
            // update the res variable with max(res, cnt)
            res = max(res, cnt);
            // increment the right pointer
            right++;
        }
        return res;
    }
};

