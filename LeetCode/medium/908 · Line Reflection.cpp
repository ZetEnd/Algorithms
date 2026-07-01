#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param points: n points on a 2D plane
     * @return: if there is such a line parallel to y-axis that reflect the given points
     */
    bool isReflected(vector<vector<int>> &points) {
        // Write your code here

        if(points.empty()) return true;

        int maxX = points[0][0];
        int minX = points[0][0];
        unordered_map<int,unordered_set<int>> hash;

        for(size_t i = 0; i < points.size(); ++i){
            if(points[i][0] < minX) minX = points[i][0];
            if(points[i][0] > maxX) maxX = points[i][0];

            hash[points[i][1]].insert(points[i][0]);
        }

        double reflectX = maxX/2 + minX/2;

        for(size_t i = 0; i < points.size(); ++i){
            if(!hash[points[i][1]].count(maxX+minX-points[i][0]))
                return false;
        }

        return true;
    }
};