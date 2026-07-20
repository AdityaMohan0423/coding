class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int totalProfit = 0;
        int buyPrice = prices[0];

        for(int i = 0; i < n; i++){
            if(prices[i] > buyPrice){
                totalProfit += prices[i]-buyPrice;
            }
            buyPrice = prices[i];
        }

        return totalProfit;
    }
};