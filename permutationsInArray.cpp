/*
Given two arrays arr1[], arr2[], and an integer k. The task is to check if 
after permuting both arrays in such a way, we get the sum of their 
corresponding element greater than or equal to k 
i.e. arr1i + arr2i >= k for all i (from 0 to n-1). Return true if possible, 
else false. 

Examples:

Input: k = 10, arr1[] = [2, 1, 3], arr2[] = [7, 8, 9]. 
Output: true
Explanation: Permutation  arr1[] = [1, 2, 3] and arr2[] = [9, 8, 7] satisfy 
the condition arr1[i] + arr2[i] >= k

Input: k = 5, arr1[] = [1, 2, 2, 1], arr2[] = [3, 3, 3, 4].
Output: false

Explanation: Since any permutation won't give the answer.
Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ 105
0 ≤ arr1i, arr2i ≤ 2*105

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(int k, vector<int> &arr1, vector<int> &arr2) {
        // Your code goes here
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end(),greater<int>());
        
        for(int i = 0; i<arr1.size();i++){
            if(arr1[i]+arr2[i] < k){
                return false;
            }
        }
        return true;
}