class Solution {
public:

    int reverse(int num){

        int out = 0;
        while(num > 0){
            out = out* 10 + num % 10;
            num = num / 10;
        }

        return out;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        

        unordered_map<int,int> hash;
        int res = nums.size();

        for(int i = 0; i < nums.size(); i++){

            if(hash.find(nums[i]) != hash.end()){
                res = min(res, i - hash[nums[i]]);
            }

            int num = reverse(nums[i]);

            hash[num] = i;
        }

        if(res == nums.size())
            res = -1;

        return res;
    }
};