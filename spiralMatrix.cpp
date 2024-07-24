/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/
#include<iostream>
#include<vector>
using namespace std;

//T.C = O(M*N)
//S.C = O(1)

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> ans;

    int dir = 0;
    /*
        dir 0 - left to right (const top)
        dir 1 - top to down (const right)
        dir 2 - right to left (const down)
        dir 3 - down to top (const left)
    */
    int top   = 0;
    int down  = m-1;
    int left  = 0;
    int right = n-1;
    while(top <= down && left <= right){
        if(dir == 0){
            for(int i = left; i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
        }
        if(dir == 1){
            for(int i = top; i<=down;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
        }
        if(dir == 2){
            for(int i = right; i>=left;i--){
                ans.push_back(matrix[down][i]);
            }
            down--;
        }
        if(dir == 3){
            for(int i = down; i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        dir++;

        if(dir == 4){
            dir = 0;
        }
    }
    return ans;
}