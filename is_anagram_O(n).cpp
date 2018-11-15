#include<string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        int size = 'z' - 'a';

        int* array1 = new int[size+1]();
        int* array2 = new int[size+1]();

        int* temp1 = array1;
        int* temp2 = array2;

        for(int i=0;i<s.size();i++){
            array1[s[i] - 97] += 1;
            array2[t[i] - 97] += 1;
        }


        bool to_ret = true;
        int counter = 0;
        while(counter<size){
            counter++;
            if( *temp1 != *temp2){to_ret = false;break;}
            temp1++;
            temp2++;
        }

        delete[] array1,array2;
        return to_ret;


    }
};
