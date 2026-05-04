#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        string word = "balloon";
        map<char,int> m;

        for(char c: word)
            m[c] += 1;

        map<char, int> rn;
        for(char c: text){
            if(m[c] >= 1)
                rn[c] += 1;
        }

        int count = rn[word[0]]/m[word[0]];

        for(char c : word){
            count = min(count, rn[c] / m[c]);
        }

        return count;
    }
};