class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buyPrice = prices[0];

        for(int i = 0; i < n; i++){
            if(buyPrice > prices[i]) buyPrice = prices[i];
            else{
                maxProfit = max(maxProfit,prices[i]-buyPrice);
            }
        }

        return maxProfit;
    }
};