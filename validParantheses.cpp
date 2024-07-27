/*
Given a string s containing just the characters '(', ')', '{', '}', 
'[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

#include<iostream>
#include<stack>
using namespace std;
//T.C = O(N)
//S.C = O(N)

bool isValid(string s) {
    int n = s.length();

    stack<char> st;

    for(int i = 0; i<n; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
        }
        else {
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if((s[i]==')' && ch == '(') || (s[i]==']' && ch == '[') || (s[i]=='}' && ch == '{')){
                continue;
            }else {
                return false;
            }
        }
    }

    return st.empty();
}