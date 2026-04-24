class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int cmin = prices[0], val = 0;
        for(int i = 0; i < prices.size(); i++){

            if(prices[i] < cmin){
                cmin = prices[i];
            }

            val = max(prices[i]-cmin, val);
        }

        return val;
    }
};