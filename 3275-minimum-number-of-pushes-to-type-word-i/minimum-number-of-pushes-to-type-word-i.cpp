class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mpp;
        for(int i = 0; i < word.size(); i++) mpp[word[i]]++;
        int uni = mpp.size();

        if(uni <= 8) return uni;
        else if(uni > 8 && uni <= 16) return 8 + 2*(uni-8);
        else if(uni > 16 && uni <= 24) return 8 + 16 + 3*(uni-16);
        else return 8 + 16 + 24 + 4*(uni-24);

        return -1;
    }
};