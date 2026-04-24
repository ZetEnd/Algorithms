class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int i;
        set<int> s {nums.begin(), nums.end()};
        for(i = 0; i <= nums.size(); i++)
            if (s.find(i) == s.end()) break;

        return i;
    }
};