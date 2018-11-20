// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
//
// Note:
//
// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like . or *.
// Example 1:
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:
//
// Input:
// s = "aa"
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:
//
// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
// Example 4:
//
// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
// Example 5:
//
// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false


#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {

        unordered_map<char,int> dic; // key,index_of_occurance_starts_from_1
        if(p.empty() || s.empty()) return false;
        string x;
        int s_index = 0;
        int p_index = 1;

        int s_size = s.size();
        int p_size = p.size();

        char s_char;
        char p_char;

        string to_ret;
        int dic_counter =0;

        while(s_index < s_size){
            s_char = s[s_index];
            while(p_index-1 < p_size){
                p_char = p[p_index-1];
                if(s_char == p_char){to_ret+=p_char;dic[p_char]=(dic[p_char]==0)?p_index:dic[p_char];p_index++;break;}
                if(p_char == '*'){
                    if(dic[s_char]< p_index && dic[s_char] >0){to_ret+=s_char;p_index++;break;}
                    if(dic['.']<p_index && dic['.'] >0){to_ret+=s_char;p_index++;break;}
                }
                if(p_char == '.'){
                    if(dic['.'] == 0) dic['.'] = p_index;
                    to_ret += s_char;
                    dic[s_char] = (!dic[s_char]) ? p_index:dic[s_char];
                    p_index++;
                    break;
                }
                if(s_char != p_char && p_char!='*' && p_index<p_size && p[p_index] != '*') return false;
                if(s_char != p_char && p_index<p_size && p[p_index] == '*'){
                    p_index=p_index+2;
                    continue;
                }
                dic[p_char]=(dic[p_char]==0)?p_index:dic[p_char];
                to_ret += p_char;
                p_index++;
            }
            s_index++;
        }

        if(to_ret == s) return true;
        return false;

    }
};
