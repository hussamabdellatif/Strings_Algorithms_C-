// //Student Attendance Record I.cpp
// You are given a string representing an attendance record for a student. The record only contains the following three characters:
// 'A' : Absent.
// 'L' : Late.
// 'P' : Present.
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
//
// You need to return whether the student could be rewarded according to his attendance record.
//
// Example 1:
// Input: "PPALLP"
// Output: True
// Example 2:
// Input: "PPALLL"
// Output: False

#include <string>
using namespace std;



class Solution {
public:
    bool checkRecord(string s) {
       //return false if:
            //more than one A
            // more than two consectuive Ls
        //use sliding window to speed it up
        int l = 0; int r = s.size()-1;
        int a =0;
        while(l<r){
            if(s[l] == 'A') a++; if(s[r] == 'A') a++;
            if(s[l] == 'L' ){
                if(l+1 < s.size() && l+2 < s.size() ){
                    if(s[l+1] == 'L' && s[l+2] =='L') return false;
                }
            }
            if(s[r] == 'L'){
                if(r-1 > -1 && r-2 > -1 ){
                    if(s[r-1] == 'L' && s[r-2] =='L') return false;
                }
            }
            if(a > 1) return false;
            l++; r--;

        }
        if( l==r && s[l] == 'A' && a+1 >1) return false;
        return true;
    }


};
