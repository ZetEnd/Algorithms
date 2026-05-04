#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> visited;

        for(int i = 0; i < paths.size(); i++){
            visited.insert(paths[i][0]);
        }

        string res;
        for(int i = 0; i < paths.size(); i++){
            if( visited.find(paths[i][1]) == visited.end()){
                res = paths[i][1];
                break;
            }
        }

        return res;
    }
};