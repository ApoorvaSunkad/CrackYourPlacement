/*
Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//T.C = O(N) + O(2^2*N)
//S.C = O(N)
vector<string> result;
bool isValidParantheses(string &str){
    int cnt = 0;

    for(char &ch:str){
        if(ch == '('){
            cnt++;
        }else{
            cnt--;
            if(cnt<0){
                return false;
            }
        }
    }
    return cnt==0;
}
void solve(string &curr, int n){
    if(curr.length()==2*n){
        if(isValidParantheses(curr)){
            result.push_back(curr);
        }
        return;
    }

    curr.push_back('(');
    solve(curr,n);
    curr.pop_back();

    curr.push_back(')');
    solve(curr,n);
    curr.pop_back();
}
vector<string> generateParenthesis(int n) {
    string curr = "";
    solve(curr,n);
    return result;
}


//Optimal approach
//T.C = O(2^2*N)
//S.C = O(N)


vector<string> result;

void solve(string &curr, int n, int open, int close){
    if(curr.length()==2*n){
        result.push_back(curr);
        return;
    }

    if(open < n){
        curr.push_back('(');
        solve(curr,n,open+1,close);
        curr.pop_back();
    }

    if(close < open){
        curr.push_back(')');
        solve(curr,n,open, close+1);
        curr.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    string curr = "";
    int open = 0, close = 0;
    solve(curr,n, open, close);
    return result;
}