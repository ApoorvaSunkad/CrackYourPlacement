/*


*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//T.C = O(NlogN)
//S.C = O(1)
int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        return max(nums[n-1]*nums[n-2]* nums[n-3], nums[0]*nums[1]*nums[n-1]);
}