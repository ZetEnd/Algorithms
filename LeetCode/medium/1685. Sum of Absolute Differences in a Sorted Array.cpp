#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        vector<int> v{0};
        int n = nums.size();

        for(int i = 0; i < n; i++){
            v.push_back(v[i] + nums[i]);
        }

        vector<int> res(n);

        for(int i = 0; i < n; i++){

            res[i] = i*nums[i] - v[i] + (v[n] - v[i+1] - (n-i-1) * nums[i]);
        }

        return res;
        
    }
};