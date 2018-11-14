// Given a string, find the length of the longest substring without repeating characters.
//
// Example 1:
//
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.



#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.length() == 1) return 1;
        string temp;
        int max = 0;
        int local_max =0;
        int found = 0;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<temp.length();j++){
                if(temp[j] == s[i]) {found =1; break;}
            }
        if(found){
            local_max = temp.length();
            max = (local_max>max) ? local_max:max;
            temp.clear();
            found = 0;
            i = (i-local_max >= 0 ) ? i-local_max + 1:0;
        }
            temp.push_back(s[i]);



        }

        if(temp.length() > max) return temp.length();
        return max;




    }
};
