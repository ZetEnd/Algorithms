class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int, int> hash;

        hash[0] = 1;

        int count_odd = 0;
        int res = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] % 2 != 0)
                count_odd++;

            if(hash.find(count_odd-k) != hash.end())
                res += hash[count_odd - k];
            
            hash[count_odd] += 1;
        }

        return res;
    }
};