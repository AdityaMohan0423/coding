class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i <= numRows; i++){
            vector<int> temp(i,1);

            if(i <= 2){
                ans.push_back(temp);
                continue;
            }

            vector<int> back = ans.back();
            int l = 0, r = 1;

            for(int j = 1; j < i-1; j++){
                if(l >= i-1 || j >= i-1) break;
                temp[j] = back[l]+back[r];
                l++;
                r++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};