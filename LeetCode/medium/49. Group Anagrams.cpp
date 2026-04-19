#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<map<char,int>> v(strs.size());

        for(int i = 0; i < strs.size(); i++){
            for(int j = 0; j < strs[i].size(); j++){

                v[i][strs[i][j]] +=1;
            }
        }

        vector<vector<string>> s;
        vector<int> used(strs.size());

        map<char,int> null = {{-1,-1}};

        for(int i = 0; i < v.size(); i++){

            if(used[i] == 0){
                s.push_back({strs[i]});
                used[i] = 1;
            }
            for(int j = i+1; j < v.size(); j++){

                if(v[i] == v[j] && v[j] != null) {
                    used[j] = 1;
                    s[s.size()-1].push_back(strs[j]);

                    v[j] = null;
                }
            }

            v[i] = null;
            
        }

        return s;

    }
};