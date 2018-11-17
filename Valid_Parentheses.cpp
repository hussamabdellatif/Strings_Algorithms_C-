// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
//
// Example 1:
//
// Input: "()"
// Output: true
// Example 2:
//
// Input: "()[]{}"
// Output: true
// Example 3:
//
// Input: "(]"
// Output: false
// Example 4:
//
// Input: "([)]"
// Output: false
// Example 5:
//
// Input: "{[]}"
// Output: true

#include<string>
#include<stack>
using namespace std;


class Solution {
public:

    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> c_holder;
        char temp;
        for(int i=0;i<s.length();i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '(' ){
                c_holder.push(s[i]);
            }else{
                if(c_holder.empty()) return false;
                if(c_holder.top() == '{' || c_holder.top() == '[') temp = c_holder.top() +2;
                if(c_holder.top() == '(' ) temp = c_holder.top() +1;
                if(temp == s[i]) c_holder.pop();
                else return false;
            }
        }
        return c_holder.empty();

    }



};
