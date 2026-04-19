class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int minlen = nums.size()+1, j = 0;
        long sumrn = 0;
        

        for(int i = 0; i < nums.size(); i++){
            while(j < nums.size() && sumrn < target){
                sumrn+= nums[j];
                j++;
            }
            if(j == nums.size() && sumrn < target)
            continue;
            minlen = min(minlen, j - i);

            sumrn -= nums[i];
        }

        if (minlen == nums.size()+1)
            minlen = 0;

        return minlen;
    }
};