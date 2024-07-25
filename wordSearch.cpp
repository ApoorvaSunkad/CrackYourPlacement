/*
Given an m x n grid of characters board and a string word, return true 
if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 
word = "ABCCED"

Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 
word = "SEE"

Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 
word = "ABCB"

Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15

board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a 
larger board?


*/

#include<iostream>
#include<vector>
using namespace std;

int m,n;
vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
bool findWord(vector<vector<char>>& board,int i, int j, int idx,string word){

    if(idx==word.length()) return true;
    if(i < 0 || j < 0 || i>=m || j>=n || board[i][j]=='$'){
        return false;
    }
    if(board[i][j]!=word[idx]){
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '$';

    for(auto&dir:directions){
        int new_i = i+dir[0];
        int new_j = j+dir[1];

        if(findWord(board,new_i,new_j,idx+1,word)){
            return true;
        }
    }
    board[i][j] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    n = board[0].size();

    for(int i = 0; i<m;i++){
        for(int j = 0; j<n; j++){
            if(board[i][j]==word[0] && findWord(board,i,j,0,word)){
                return true;
            }
        }
    }
    return false;
}