class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &a,vector<int> &b){
            return a[1] > b[1];
        });

        int sum = 0;

        for(int i = 0; i < n; i++){
            if(truckSize == 0) break;
            if(boxTypes[i][0] <= truckSize){
                sum += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }else{
                sum += truckSize*boxTypes[i][1];
                break;
            }
        }

        return sum;
    }
};