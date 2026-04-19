#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        vector<int> v{0};
        int cmax = v[0];
        for(int i = 0; i < gain.size(); i++){

            v.push_back(gain[i] + v[i]);

            cmax = max(cmax, v[i+1]);
        }

        return cmax;
    }
};