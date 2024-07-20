/*
Given an integer array nums of length n where all the integers of nums 
are in the range [1, n] and each integer appears once or twice, return 
an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only 
constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.


*/

//Brute force
//T.C = O(N)
//S.C = O(N)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> v;

    int n = nums.size();

    unordered_map<int,int> mp;

    for(int i = 0; i<n; i++){
        mp[nums[i]]++;
    }

    for(auto it:mp){
        if(it.second == 2){
            v.push_back(it.first);
        }
    }
    return v;
}
//optimal solution

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> v;

    int n = nums.size();

    //using indexes
    for(int i = 0; i<n; i++){
        int num = abs(nums[i]);

        int idx = num-1;

        if(nums[idx]<0){
            v.push_back(num);
        }else{
            nums[idx]*= -1;
        }
    }
    return v;
}