class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(int i = 0; i < word.size(); i++){
            v[word[i]-'a']++;
        }

        sort(v.begin(),v.end(),[](int &a, int &b){
            return a > b;
        });

        int total = 0;

        for(int i = 0; i < 8; i++){
            if(v[i] > 0) total += 1;
            else break;
        }
        for(int i = 8; i < 16; i++){
            if(v[i] == 0) break;
            total += 2*v[i];
        }
        for(int i = 16; i < 24; i++){
            if(v[i] == 0) break;
            total += 3*v[i];
        }
        for(int i = 24; i < 26; i++){
            if(v[i] == 0) break;
            total += 4*v[i];
        }


        return total;
    }
};