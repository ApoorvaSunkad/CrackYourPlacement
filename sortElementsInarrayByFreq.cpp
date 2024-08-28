/*
Given an array of integers arr, sort the array according to the frequency 
of elements, i.e. elements that have higher frequency comes first. 
If the frequencies of two elements are the same, then the smaller 
number comes first.

Examples :

Input: arr[] = [5, 5, 4, 6, 4]
Output: [4, 4, 5, 5, 6]
Explanation: The highest frequency here is 2. Both 5 and 4 have that 
frequency. Now since the frequencies are the same the smaller element 
comes first. So 4 4 comes first then comes 5 5. Finally comes 6. 
The output is 4 4 5 5 6.

Input: arr[] = [9, 9, 9, 2, 5]
Output: [9, 9, 9, 2, 5]

Explanation: The highest frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first. Now both 2 and 5 have the same frequency. So we print smaller elements first. The output is 9 9 9 2 5.
Expected Time Complexity: O(n*logn)
Expected Space Complexity: O(n)

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i]≤ 105


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

static bool cmp(pair<int,int>&a, pair<int,int>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second  > b.second;
}
vector<int> sortByFreq(vector<int>& arr) {
    
    int n = arr.size();
    vector<pair<int,int>> ans;
    
    unordered_map<int, int> mp;
    for(int i = 0; i<n; i++){
        mp[arr[i]]++;
    }
    
    for(int i = 0; i<n; i++){
        ans.push_back({arr[i],mp[arr[i]]});
    }
    
    sort(ans.begin(),ans.end(),cmp);
    
    vector<int> v;
    
    for(int i = 0; i<n; i++){
        v.push_back(ans[i].first);
    }
    return v;
}