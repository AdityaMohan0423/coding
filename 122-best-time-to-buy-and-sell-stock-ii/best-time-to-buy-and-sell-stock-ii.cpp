class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxi = 0;

        int sum = 0;
        int buy = prices[0];

        for(int i = 1; i < n; i++){
            if(prices[i] > buy){
                sum += prices[i]-buy;
                buy = prices[i];
            }else buy = prices[i];
            maxi = max(maxi,sum);
        }

        return maxi;
    }
};