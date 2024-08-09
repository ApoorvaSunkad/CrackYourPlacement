/*
Given two strings, one is a text string, txt and other is a pattern string, 
pat. The task is to print the indexes of all the occurences of pattern string 
in the text string. Use one-based indexing while returning the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will 
print -1 in this case.

Example 1:

Input:
txt = "geeksforgeeks"
pat = "geek"
Output: 
1 9
Explanation: 
The string "geek" occurs twice in txt, one starts are index 1 and the other 
at index 9. 

Example 2:

Input: 
txt = "abesdu"
pat = "edu"
Output: 
-1
Explanation: 
There's not substring "edu" present in txt.
Your Task:
You don't need to read input or print anything. Your task is to complete the 
function search() which takes the string txt and the string pat as inputs 
and returns an array denoting the start indices (1-based) of substring pat 
in the string txt. 

Expected Time Complexity: O(|txt|).
Expected Auxiliary Space: O(|txt|).

Constraints:
1 ≤ |txt| ≤ 106
1 ≤ |pat| < |S|
Both the strings consists of lowercase English alphabets.


*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

 void computeLPS(string &pat, vector<int>&LPS, int m){
    int len = 0;
    LPS[0] = 0;
    int i = 1;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            LPS[i] = len;
            i++;
        }else{
            if(len!=0){
                len = LPS[len-1];
            }else{
                LPS[i] = 0;
                i++;
            }
        }
    }     
}
vector <int> search(string pat, string txt)
{
    int n = txt.length();
    int m = pat.length();
    
    vector<int> result;
    
    //Computing LPS
    
    vector<int>LPS(m,0);
    computeLPS(pat,LPS,m);
    
    //KMP code
    int i = 0, j = 0;
    while(i<n){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            result.push_back(i-m+1);
            j = LPS[j-1];
        }else if(txt[i] != pat[j]){
            if(j!=0){
                j = LPS[j-1];
            }else{
                i++;
            }
        }
    }
    return result;
            
}