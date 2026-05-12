class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int res = 0;

        int l = 0, codd = 0, count = 0;

        for(int r = 0; r < nums.size(); r++){
            if(nums[r] % 2 != 0){
                codd += 1;
                count = 0;
            }

            while(codd == k){
                count++;
                if(nums[l] % 2 != 0)
                    codd--;
                l++;
            }

            res+= count;
        }

        return res;
    }
};