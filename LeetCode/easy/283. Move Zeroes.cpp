#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
    int last_not_zero = 0;
    int i = 0;

    while(i < nums.size()){

        if(nums[i] != 0){

            int temp = nums[i];
            nums[i] = nums[last_not_zero];
            nums[last_not_zero] = temp;
            last_not_zero++;
        }

        i++;

    }
}
};