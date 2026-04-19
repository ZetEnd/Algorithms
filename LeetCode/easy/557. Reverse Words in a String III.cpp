#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
        int i = 0, j = 0, rn;
        char c;

        while(j < s.size()){

            j++;
            if(s[j] == ' ' || j == s.size()){
                rn = j-1;
                while(i < rn){
                c = s[i];
                s[i] = s[rn];
                s[rn] = c;
                i++;
                rn--;
                }

                i = j+1;
            }

        }

        return s;
    }
};