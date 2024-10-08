/*
Given an array arr[], check whether it is sorted in non-decreasing order. 
Return true if it is sorted otherwise false.

Examples:

Input: arr[] = [10, 20, 30, 40, 50]
Output: true

Explanation: The given array is sorted.
Input: arr[] = [90, 80, 100, 70, 40, 30]
Output: false

Explanation: The given array is not sorted.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size ≤ 106
- 109 ≤ arr[i] ≤ 109

*/

#include<iostream>
#include<vector>
using namespace std;
//T.C = O(N)
//S.C = O(1)

bool arraySortedOrNot(vector<int>& arr) {
        // code here
        int n = arr.size();
        // Array has one or no element
        if (n == 0 || n == 1)
            return true;

        for (int i = 1; i < n; i++)
            // Unsorted pair found
            if (arr[i - 1] > arr[i])
                return false;

        // No unsorted pair found
        return true;
}