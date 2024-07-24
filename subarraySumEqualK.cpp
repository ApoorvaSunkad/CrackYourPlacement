/*
Given an array of integers nums and an integer k, return the total 
number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107



*/

//Brute force
//T.C = O(N^3)
//S.C = O(1)

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int cnt = 0;
    int n = nums.size();

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            int sum = 0;
            for(int m = i; m<=j;m++){
                sum+=nums[m];
            }
            if(sum==k){
                cnt++;
            }
        }
    }

    return cnt;
}

//Better approach - 2 loops
//T.C = O(N^2)
//S.C = O(1)

int subarraySum(vector<int>& nums, int k) {
    int cnt = 0;
    int n = nums.size();

    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){\
            sum+=nums[j];
            if(sum==k){
                cnt++;
            }
        }
    }

    return cnt;
}

//Optimal approach
//T.C = O(N)
//S.C = O(N)

int subarraySum(vector<int>& nums, int k) {
    int cnt = 0, preSum = 0;
    map<int,int> mp;

    mp[0] = 1;

    for(int i = 0; i<nums.size(); i++){
        preSum+=nums[i];
        int remove = preSum-k;
        cnt+=mp[remove];

        mp[preSum]+=1;
    }
    return cnt;
}