#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int j = 0;
        int cost = 0;
        int maxlen = -1;
        for(int i = 0; i < s.size(); i++){

            while(j < s.size() && cost <= maxCost){
                cost += abs(s[j] - t[j]);
                j++;
            }

            //if (j == s.size())
            if(cost > maxCost){
                j--;
                cost -= abs(s[j] - t[j]);
            }

            maxlen = max(maxlen, j-i);

            cost -= abs(s[i] - t[i]);
        }
        return maxlen;
    }
};