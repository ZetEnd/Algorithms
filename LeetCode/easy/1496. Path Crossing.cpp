#include <iostream>
#include <set>
#include <string>

using namespace std;


class Solution {
public:
    bool isPathCrossing(string path) {
        
        set<pair<int,int>> visited;

        int x = 0, y = 0;
        bool flag = false;
        visited.insert({x,y});
        for(char c : path){
            if (c == 'N') y++;
            if (c == 'S') y--;
            if (c == 'E') x++;
            if (c == 'W') x--;

            if(visited.find({x,y}) != visited.end()){
                flag = true;
                break;
            }

            visited.insert({x,y});

        }

        return flag;
    }
};