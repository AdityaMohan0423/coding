class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        
        int minEl = citations[0];
        int maxEl = citations[n-1];

        int maxi = 0;

        for(int i = 1; i <= maxEl; i++){
            int ind = lower_bound(citations.begin(),citations.end(),i)-citations.begin();

            if(i <= n-ind) maxi = max(maxi,i);
        }

        return maxi;
    }
};