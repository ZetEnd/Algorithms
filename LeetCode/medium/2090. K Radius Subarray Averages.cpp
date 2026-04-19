#include <vector>
#include <iostream>
#include <deque>

using namespace std;


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> v(n);

        vector<long long> ps{0};


        for(int i = 0; i < n; i++){
            ps.push_back(ps[i] + nums[i]);
        }

        for(int i = 0; i < n; i++){

            if(i-k < 0 || i+k >= n)
                v[i] = -1;
            else{

                v[i] = (ps[i+k+1] - ps[i-k]) / (2*k+1);

            }
        }

        return v;
    }
};