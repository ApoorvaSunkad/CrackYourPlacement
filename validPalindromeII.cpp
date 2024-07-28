/*
Given a string s, return true if the s can be palindrome after deleting 
at most one character from it.

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.


*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//T.C = O(N)
//S.C = O(1)

bool isPalindrome(string str, int i, int j){
    while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s) {
    int i = 0;
    int j = s.length()-1;

    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
        }
    }
    return true;
}   