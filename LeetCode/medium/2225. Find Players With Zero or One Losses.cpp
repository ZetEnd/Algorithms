#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        unordered_map<int,int> l;

        for(int i = 0; i < matches.size(); i++){
            
            if(l.find(matches[i][0]) == l.end())
                l[matches[i][0]] = 0;
            l[matches[i][1]] += 1;
        }
        vector<vector<int>> res;
        res.push_back({});
        res.push_back({});

        for(auto& x : l){
            if(x.second == 1){
                res[1].push_back(x.first);
            } else if(x.second == 0)
                res[0].push_back(x.first);
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};