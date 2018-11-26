// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard
//
// Example:
//
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//
//
// Note:
//
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.

#include<string>
#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;



class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        vector<string> to_ret;
        size_t find1;size_t find2;size_t find3;
        for(int i=0; i<words.size();i++){
            string temp = words[i];
            find1 = row1.find(tolower(temp[0]));
            if(find1 != string::npos){
                if(cmp(temp, row1)) to_ret.push_back(temp);
                continue;
            }
            find2 = row2.find(tolower(temp[0]));
            if(find2 != string::npos){
                if(cmp(temp, row2)) to_ret.push_back(temp);
                continue;
            }
            find3 = row3.find(tolower(temp[0]));
            if(find3 != string::npos){
                if(cmp(temp, row3)) to_ret.push_back(temp);
                continue;
            }
        }

        return to_ret;
    }

    bool cmp (string word1, string word2){
        size_t f;
        for(int i=1;i<word1.length();i++){
            f = word2.find(tolower(word1[i]));
            if(f==string::npos) return false;
        }
        return true;
    }


};
