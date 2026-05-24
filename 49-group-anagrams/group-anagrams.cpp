class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> ans;
        int n = strs.size();
        for(int i = 0; i < n; i++){
            vector<int> chArr(26,0);

            for(int j = 0; j < strs[i].size(); j++){
                chArr[strs[i][j]-'a']++;
            }

            string s = "";
            for(int k = 0; k < 26; k++){
                if(chArr[k] != 0){
                    for(int l = 0; l < chArr[k]; l++){
                        s += k +'a';
                    }
                }
            }

            mpp[s].push_back(strs[i]);
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};