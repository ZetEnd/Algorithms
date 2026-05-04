#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        
        stack<char> ch;
        char lowest = s[0];

        unordered_map<int,int> um;

        for(int i = 0; i < s.size(); i++){
            um[s[i]] += 1;
            lowest = min(lowest, s[i]);
        }

        string res = "";
        for(int i = 0; i < s.size(); i++){
            ch.push(s[i]);
            um[s[i]]--;

            while(lowest != 'z' && um[lowest] == 0){
                lowest++;
            }

            while(ch.size() != 0 && lowest >= ch.top()){
                res += ch.top();
                ch.pop();
            }

        }

        while(ch.size() != 0){
                res += ch.top();
                ch.pop();
            }

        return res;
    }
};