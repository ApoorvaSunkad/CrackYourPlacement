/*
Given an integer array nums, return an array answer such that answer[i] 
is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 
32-bit integer.

You must write an algorithm that runs in O(n) time and without using 
the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 
32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? 
(The output array does not count as extra space for space complexity 
analysis.)

*/
#include<iostream>
#include<vector>
using namespace std;

//Approach 1
vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int prod = 1;
        int cnt = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                cnt++;
            }else{
                prod*=nums[i];
            }
        }

        for(int i = 0; i<n; i++){
            if(nums[i]!=0){
                if(cnt > 0){
                    ans[i] = 0;
                }
                else{
                    ans[i] = prod/nums[i];
                }
            }else{
                if(cnt > 1){
                    ans[i] = 0;
                }else{
                    ans[i] = prod;
                }
            }
        }
        return ans;
}

//Approach 2
vector<int> productExceptSelf(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans(n,1);

    for(int i = 1; i<n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    int suffProd = 1;
    for(int i = n-2; i>=0; i--){

        suffProd = suffProd*nums[i+1];

        ans[i] = ans[i]*suffProd;
    }

    return ans;
}

//Approach 3
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    result[0] = 1;

    for(int i = 1; i<n;i++){
        result[i] = result[i-1] * nums[i-1];
    }
    int right_product = 1;
    for(int i = n-1; i>=0; i--){
        result[i] = result[i] * right_product;
        right_product*=nums[i];

    }
    return result;

}