/*
Given an array nums with n objects colored red, white, or blue, sort them 
in-place so that objects of the same color are adjacent, with the colors in 
the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, 
and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only 
constant extra space?

*/

//Brute force
//Just sort the array

//Better approach
//Count 0's, 1's, 2's

//T.C = O(2N)
//S.C = O(1)

#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(nums[i]==0){
                count0++;
            }else if(nums[i]==1){
                count1++;
            }else{
                count2++;
            }
        }

        for(int i = 0; i<count0; i++){
            nums[i] = 0;
        }
        for(int i = count0; i<count0+count1;i++){
            nums[i] = 1;
        }

        for(int i = count0+count1; i<n; i++){
            nums[i] = 2;
        }
}

//Optimal solution: Using Dutch national flag algorithm

//T.C = O(N)
//S.C = O(1)

void sortColors(vector<int>& nums) {
    int n = nums.size();

    int i = 0, j = 0, k = n-1;

    while(j<=k){
        if(nums[j]==1){
            j++;
        }else if(nums[j]==2){
            swap(nums[j],nums[k]);
            k--;
        }else{
            swap(nums[i],nums[j]);
            i++;
            j++;
        }
    }
}