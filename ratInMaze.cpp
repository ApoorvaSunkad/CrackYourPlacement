/*
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. 
It has to reach the destination at (n - 1, n - 1). Find all possible 
paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. 
If the source cell is 0, the rat cannot move to any other cell. 
In case of no path, return an empty list. The driver will output "-1" 
automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) 
by two paths - DRDDRR and DDRDRR, when printed in sorted order we get 
DDRDRR DRDDRR.

Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1


*/

#include<iostream>
#include<vector>
using namespace std;

vector<string> res;
    bool isSafe(int i, int j, int n) {
      return i >= 0 && i < n && j >= 0 && j < n;
    }
    void solve(int i, int j, vector<vector<int>> &mat, int n, string &path) {
    // Base case: if out of bounds or on a blocked cell, return
        if (!isSafe(i, j, n) || mat[i][j] == 0) {
            return;
        }
    
        // If destination is reached, add the path to the result
        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }
    
        // Mark the current cell as visited
        mat[i][j] = 0;
    
        // Move Down
        path.push_back('D');
        solve(i + 1, j, mat, n, path);
        path.pop_back();
    
        // Move Right
        path.push_back('R');
        solve(i, j + 1, mat, n, path);
        path.pop_back();
    
        // Move Up
        path.push_back('U');
        solve(i - 1, j, mat, n, path);
        path.pop_back();
    
        // Move Left
        path.push_back('L');
        solve(i, j - 1, mat, n, path);
        path.pop_back();
    
        // Unmark the current cell as visited (backtrack)
        mat[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        res.clear();  // Clear any previous results
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) {
            return res;  // Return empty list if start or end is blocked
        }

        string path = "";
        solve(0, 0, mat, n, path);
    
        return res;
        
}
