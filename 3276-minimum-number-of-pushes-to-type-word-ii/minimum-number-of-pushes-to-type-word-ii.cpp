class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> v(26,0);

        for(int i = 0; i < n; i++){
            v[word[i]-'a']++;
        }

        sort(v.begin(),v.end(),[](int &a, int &b){
            return a > b;
        });

        int total = 0;
        for(int i = 0; i < 8; i++){
            if(v[i] == 0) break;
            if(v[i] != 0) total += v[i];
        }
        for(int i = 8; i < 16; i++){
            if(v[i] == 0) break;
            if(v[i] != 0) total += 2*v[i];
        }
        for(int i = 16; i < 24; i++){
            if(v[i] == 0) break;
            if(v[i] != 0) total += 3*v[i];
        }
        for(int i = 24; i < 26; i++){
            if(v[i] == 0) break;
            if(v[i] != 0) total += 4*v[i];
        }


        return total;
    }
};