/*
Given an integer array nums, move all 0's to the end of it while maintaining 
the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?

*/

#include<iostream>
#include<vector>
using namespace std;

//T.C = O(2N)
//S.C = O(N)

void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    vector<int> temp;

    for(int i = 0; i<n; i++){
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }

    for(int i = 0; i<temp.size(); i++){
        nums[i] = temp[i];
    }

    for(int i = temp.size();i<n; i++){
        nums[i] = 0;
    }
}

//Optimal solution: Using 2 pointer approach
//T.C = O(N)
//S.C = O(1)

void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    int i = 0, j = i+1;

    while(j<n){
        if(nums[i]!=0 && nums[j]!=0){
            i++;
            j++;
        }else if(nums[i]==0 && nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;
            j++;
        }else if(nums[i]==0 && nums[j]==0){
            j++;
        }
        else if(nums[j]==0){
            i++;
            j++;
        }
    }
}