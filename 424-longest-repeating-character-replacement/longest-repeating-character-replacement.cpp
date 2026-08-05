class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int total = 0;
        int maxi = 0;
        vector<int> freq(26,0);

        int i = 0, j = 0;

        while(j < n){
            freq[s[j]-'A']++;
            total++;

            int maxEl = 0;
            for(int k = 0; k < 26; k++) maxEl = max(maxEl,freq[k]);

            if(total-maxEl <= k){
                maxi = max(maxi,j-i+1);
            }
            while(total-maxEl > k){
                freq[s[i++]-'A']--;
                total--;

                maxEl = 0;
                for(int k = 0; k < 26; k++) maxEl = max(maxEl,freq[k]);
            }
            j++;
        }

        return maxi;
    }
};