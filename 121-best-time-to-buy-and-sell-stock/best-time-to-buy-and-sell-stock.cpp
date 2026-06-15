class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < n; i++){
            if(prices[i] > buyPrice){
                maxProfit = max(maxProfit,prices[i]-buyPrice);
            }else{
                buyPrice = prices[i];
            }
        }

        return maxProfit;
    }
};