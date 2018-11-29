// //Valid Palindrome.cpp
//
// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:
//
// Input: "race a car"
// Output: false

#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty() || s.size()==1) return true;
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(!isalpha(s[l]) && !isdigit(s[l])){
                l++;
            }else if(!isalpha(s[r]) && !isdigit(s[r])){
                r--;
            }else{
                if(toupper(s[l]) != toupper(s[r])) return false;
                l++;r--;
            }
        }
        return true;
    }
};
