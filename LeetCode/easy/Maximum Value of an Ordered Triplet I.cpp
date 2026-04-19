#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    long long maximumTripletValue(vector<int>& nums){

        int n = nums.size();

        if(n < 3) return 0;

        vector<int> LeftSide(n), RightSide(n);

        LeftSide[0] = nums[0];
        RightSide[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            LeftSide[i] = max(nums[i-1], LeftSide[i-1]);

            RightSide[n-i-1] = max(nums[n-i], RightSide[n-i]);
        }

        long long res = (long long)(nums[0] - nums[1] )*nums[2];
        long long buf;

        for(int i = 1; i < n-1; i++){

            buf = (long long)(LeftSide[i] - nums[i])*RightSide[i];
            res = max(res, buf);

        }

        if (res < 0) res = 0;

        return res;   

    }

};