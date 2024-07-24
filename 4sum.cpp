/*
Given an array nums of n integers, return an array of all the unique 
quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109


*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//T.C = O(N^4)
//S.C = O(N* LOGN)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> st;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    for(int l = k+1; l<n; l++){
                        long long sum = nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum == target){
                            vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }


        vector<vector<int>> ans(st.begin(),st.end());
        return ans;

}

//Better approach
//T.C = O(N^3)
//S.C = O(N*logN)

 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> st;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                set<long long> hashset;
                for(int k = j+1; k<n; k++){
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth = target - sum;

                    if(hashset.find(fourth)!=hashset.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }


        vector<vector<int>> ans(st.begin(),st.end());
        return ans;

}


//Optimal approach - sorting and 2-pointer approach
//T.C = O(N^2 * N)
//S.C = O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>>ans;

        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            for(int j = i+1; j<n; j++){
                if(j!=i+1 &&nums[j]==nums[j-1]){
                    continue;
                }
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++,l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                        while(k<l && nums[l]==nums[l+1])l--;

                    }else if(sum<target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return ans;

}