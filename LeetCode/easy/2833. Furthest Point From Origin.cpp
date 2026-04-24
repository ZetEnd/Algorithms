#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int count = 0, rem = 0;
        for(char c : moves){

            if(c == 'R')
                count++;
            if(c == 'L')
                count--;
            if(c == '_')
                rem++;
        }

        return abs(count) + rem;
    }
};