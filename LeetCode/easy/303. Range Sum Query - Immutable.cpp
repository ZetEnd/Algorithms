class NumArray {

private:

    vector<int> nums;
    vector<int> prsum;
public:
    NumArray(vector<int>& nums) {
        nums = nums;

        prsum = {0};

        for(int i = 0; i < nums.size(); i++){

            prsum.push_back(prsum[i] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        
        return prsum[right+1] - prsum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */