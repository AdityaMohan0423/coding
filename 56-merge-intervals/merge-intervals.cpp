class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(ans.empty()){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }else{
                vector<int>&back = ans.back();
                int* last = &back[1];

                if(*last >= intervals[i][0]){
                    if(*last <= intervals[i][1]) *last = intervals[i][1];
                }else{
                    ans.push_back({intervals[i][0],intervals[i][1]});
                }
            }
        }

        return ans;
    }
};