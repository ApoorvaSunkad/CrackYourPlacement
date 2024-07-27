/*
Given a string S, the task is to print all the duplicate characters 
with their occurrences in the given string.

Example:

Input: S = “geeksforgeeks”
Output:
e, count = 4
g, count = 2
k, count = 2
s, count = 2

*/

#include <algorithm>
#include <iostream>
#include <string>

//T.C = O(N*logN)
//S.C = O(1)
using namespace std;
void printDuplicates(string str)
{
    int len = str.length();

    // Sorting the string
    sort(str.begin(), str.end());

    // Loop through the sorted string to find duplicates
    for (int i = 0; i < len; i++) {
        int count = 1;

        // Counting the occurrences of each character
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Printing the duplicate character and its count
        if (count > 1) {
            cout << str[i] << ", count = " << count << endl;
        }
    }
}
int main()
{
    string str = "test string";
    printDuplicates(str);
    return 0;
}

#include <iostream>
#include<unordered_map>
using namespace std;

//T.C = O(N)
//S.C = O(N)
void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        // increase the count of character str[i] by 1
        count[str[i]]++;
    }
    // iterating through the unordered map
    for (auto it : count) {
        // if the count of characters is greater than 1 then
        // duplicate found
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}
/* Driver code*/
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}