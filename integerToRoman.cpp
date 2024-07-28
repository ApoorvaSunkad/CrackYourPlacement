/*



*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//T.C = O(Logn) worst case
//S.C = O(1)

string intToRoman(int num) {
    static vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
    static vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string result = "";

    for(int i = 0; i<13; i++){

        if(num == 0){
            break;
        }

        int times = num/val[i];
        while(times--){
            result+=sym[i];
        }

        num = num%val[i];
    }
    return result;
}