#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size()-1;

        int val = 0;
        int max_val = -1;

        while(i < j){

            val = min(height[i], height[j]) * (j-i);
            max_val = max(max_val, val);

            if(height[i] < height[j])
            {
                int cur_h = height[i];
                while(height[i] <= cur_h && i < j){
                    i++;
                }
            }
            else {
                int cur_h = height[j];
                while(height[j] <= cur_h && i < j){
                    j--;
                }
            }


        }

        return max_val;
    }
};