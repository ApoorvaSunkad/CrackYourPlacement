/*
Write a function to find the longest common prefix string amongst an 
array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//T.C = O(nlogn) + o(n)
//S.C = O(n)

string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end());

    string s1 = strs[0];
    string s2 = strs[strs.size()-1];
    int i = 0, j = 0;

    string ans = "";
    
    while(i<s1.size() && j<s2.size()){
        if(s1[i]==s2[j]){
            ans+=s1[i];
            i++,j++;
        }
        else{
            break;
        }
    }
    
    return ans;
    
}