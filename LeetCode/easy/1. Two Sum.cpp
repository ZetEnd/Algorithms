#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> m;

        vector<int> v(2);

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int rn = target - nums[i];

            if(m.find(rn) != m.end() && m[rn] != i) {
                
                v[0] = min(i, m[rn]);
                v[1] = max(i, m[rn]);
            };
        }

        return v;
    }
};