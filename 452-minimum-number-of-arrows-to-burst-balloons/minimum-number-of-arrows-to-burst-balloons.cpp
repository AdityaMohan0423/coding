class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());

        int start = points[0][0];
        int end = points[0][1];

        int cnt = 1;

        for(int i = 1; i < n; i++){
            if(end > points[i][1]){
                end = points[i][1];
            }else if(end < points[i][0]){
                cnt++;
                start = points[i][0];
                end = points[i][1];
            }
        }

        return cnt;
    }
};