#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {

        int i = 0, j = s.size()-1;
        char c;

        while(i < j){
            while(i < s.size() && !((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)))
                i++;
            if(i == s.size())
                break;

            while(i >=0 && !((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122)))
                j--;
            if(j == -1)
                break;

            if(i < j){
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
            }
        }

        return s;
        
    }
};