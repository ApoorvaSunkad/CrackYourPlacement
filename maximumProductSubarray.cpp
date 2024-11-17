/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.


*/

#include<iostream>
#include<vector>
using namespace std;

//T.C = O(N+N) = O(2N)
//S.C = O(1)

int maxProduct(vector<int>& nums) {
    int maxP = INT_MIN;

    int n = nums.size();

    int curr = 1;
    for(int i = 0; i<n; i++){
        curr = curr*nums[i];
        maxP = max(curr,maxP);
        if(curr == 0){
            curr = 1;
        }
    }

    curr = 1;
    for(int i = n-1; i>=0;i--){
        curr = curr*nums[i];
        maxP = max(curr,maxP);
        if(curr == 0){
            curr = 1;
        }
    }
    return maxP;
}