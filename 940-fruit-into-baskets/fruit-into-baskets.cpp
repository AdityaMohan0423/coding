class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxi = 0;
        map<int,int> mpp;

        int i = 0, j = 0;
        while(j < n){
            mpp[fruits[j]]++;
            if(mpp.size() > 2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};