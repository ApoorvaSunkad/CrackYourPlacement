/*
Given an integer array nums and an integer k, return the number of 
non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
2 <= k <= 104

*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//T.C = O(N^2)
//S.C = O(1)
int subarraysDivByK(vector<int>& nums, int k) {
    int cnt = 0;

    int n = nums.size();

    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            
            sum+=nums[j];

            if(sum%k == 0){
                cnt++;
            }
        }
    }
    return cnt;
}


//Optimal solution

//T.C = O(N)
//S.C = O(N)


int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int,int> mp;
    int sum = 0, cnt = 0;
    mp[0] = 1;

    for(int i = 0; i<n; i++){
        sum+=nums[i];
        int rem = sum%k;

        if(rem<0){
            rem+=k;
        }
        if(mp.find(rem)!=mp.end()){
            cnt+=mp[rem];
        }
        mp[rem]++;
    }
    return cnt;
}