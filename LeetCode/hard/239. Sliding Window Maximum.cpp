#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        deque<int> d;

        for(int i = 0; i < nums.size(); i++){

            while(d.size() !=0 && nums[i] > nums[d.back()])
                d.pop_back();
            d.push_back(i);

            if(d.front() <= i-k)
                d.pop_front();

            if(i+1 >= k)
                res.push_back(nums[d.front()]);
                
        }


        return res;
    }
};