/*
Given an m x n integer matrix matrix, if an element is 0, set its 
entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


*/

#include<iostream>
#include<vector>
using namespace std;

//Brute force
//T.C = O(N*M)*O(N+M)+O(N*M)
//S.C = O(N*M)


void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1000;
            }
        }
}
void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the row i:
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1000;
            }
        }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(matrix[i][j]==0){
                markRow(matrix,n,m,i);
                markCol(matrix,n,m,j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1000) {
                matrix[i][j] = 0;
            }
        }
    }
}


//Better solution
//T.C = O(2*N*M)
//S.C = O(N) + O(M)


void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> col(m,0);
    vector<int> row(n,0);

    for(int i = 0; i<n; i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(row[i] || col[j]){
                matrix[i][j] = 0;
            }
        }
    }

}

