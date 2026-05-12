#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int res = 0;

        if(nums.size() < 3) return 0;

        int diff = nums[1] - nums[0];
        int dp = 0;

        for(int r = 2; r < nums.size(); r++){

            if(nums[r] - nums[r-1] == diff){
                dp += 1;
                res+=dp;
            } else {
                dp = 0;
                diff = nums[r] - nums[r-1];
            }

        }
        return res;
    }
};