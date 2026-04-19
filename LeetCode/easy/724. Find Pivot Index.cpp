#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        vector<long> v(n+1);

        for(int i = 0; i < n; i++){

            v[i+1] = v[i] + nums[i];
        }

        long left = 0, right = 0;
        int ind = -1;

        for(int i = 0; i < n; i++){
            
            left = v[i];
            if (i == n-1)
                right = 0;
            else
                right = v[n]-v[i+1];

            if(left == right){
                ind = i;
                break;
            }
        
        }

        return ind;
    }
};