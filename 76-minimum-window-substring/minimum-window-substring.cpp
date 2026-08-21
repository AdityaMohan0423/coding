class Solution {
public:
    string minWindow(string s, string t) {

        int start = -1;
        int end = -1;

        int n = s.size();
        unordered_set<char> st;

        int posCnt = 0;
        unordered_map<char,int> mpp;

        for(int i = 0; i < t.size(); i++){
            st.insert(t[i]);
            mpp[t[i]]++;
            posCnt++;
        } 


        int i = 0, j = 0;
        while(j < n){
            if(posCnt == 0) break;
            if(mpp.find(s[j]) != mpp.end()){
                if(mpp[s[j]] > 0) posCnt--;
                mpp[s[j]]--;
                
            }
            j++;
        }
        if(posCnt != 0) return "";

        start = i;
        end = j-1;

        while(j < n){
            while(posCnt == 0 && i < j){
                if(end-start+1 > j-i){
                    start = i;
                    end = j-1;
                }

                if(st.count(s[i])){
                    mpp[s[i]]++;
                    if(mpp[s[i]] > 0) posCnt++;
                }
                
                i++;
            }

            if(st.count(s[j])){
                if(mpp[s[j]] > 0) posCnt--;
                mpp[s[j]]--;
            }
            j++;
        }
        
        while(posCnt == 0 && i < j){
                if(end-start+1 > j-i){
                    start = i;
                    end = j-1;
                }

                if(st.count(s[i])){
                    mpp[s[i]]++;
                    if(mpp[s[i]] > 0) posCnt++;
                }
                
                i++;
        }

        return s.substr(start,end-start+1);
    }
};