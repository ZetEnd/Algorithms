#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int cmax = nums[0];
        int l = 0;
        int count = 0;
        long long res = 0;

        for(int r = 1; r < nums.size(); r++){
            cmax = max(cmax, nums[r]);
        }

        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == cmax)
                count++;

            while(count >= k){

                if(nums[l] == cmax)
                    count--;
                l++;
            }

            res+=l;

        }

        cout << res;

        return res;
    }
};