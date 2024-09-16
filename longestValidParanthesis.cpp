/*
Given a string containing just the characters '(' and ')', return 
the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.

*/

#include<iostream>
#include<math.h>
using namespace std;

//T.C = O(N)
//S.C = O(1)

int longestValidParentheses(string str) {
    int n = str.length();
    
    int left = 0, right = 0, Max = 0;
    
    for(int i = 0; i<n;i++){
        if(str[i]=='('){
            left++;
        }else{
            right++;
        }
        if(left == right){
            Max = max(Max,left*2);
        }else if(right>left){
            left = 0;
            right = 0;
        }
    }
    
    left = 0, right = 0;
    for(int i = n-1; i>=0;i--){
        if(str[i]=='('){
            left++;
        }else{
            right++;
        }
        if(left == right){
            Max = max(Max,left*2);
        }else if(left>right){
            left = 0;
            right = 0;
        }
    }
    
    return Max;
}
