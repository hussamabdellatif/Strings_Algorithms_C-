// //Isomorphic Strings.cpp
//
// Given two strings s and t, determine if they are isomorphic.
//
// Two strings are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character
// while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
// Example 1:
//
// Input: s = "egg", t = "add"
// Output: true
// Example 2:
//
// Input: s = "foo", t = "bar"
// Output: false
// Example 3:
//
// Input: s = "paper", t = "title"
// Output: true



#include<cstdio>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string s1;
    bool isIsomorphic(string s, string t) {
        vector<char> s1(256,'*');
        vector<char> s2(256,'*');
        for(int i=0;i<s.size();i++){
            if(s1[s[i]] == '*' && s2[t[i]] == '*'){
                s1[s[i]] = t[i];
                s2[t[i]] = s[i];
            }else{
                if(s1[s[i]] != t[i] || s2[t[i]] != s[i] ) return false;
            }
        }
        return true;
    }
};
