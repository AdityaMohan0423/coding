class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        vector<int> freq(26);
        for(int i = 0; i < n; i++){
            freq[text[i]-97] += 1;
        }  

        string s = "balloon";
        int cnt = freq['b'-97];
        cnt = min(freq['a'-97],cnt);
        cnt = min(freq['l'-97]/2,cnt);
        cnt = min(freq['o'-97]/2,cnt);
        cnt = min(freq['n'-97],cnt);

        return cnt;

    }
};