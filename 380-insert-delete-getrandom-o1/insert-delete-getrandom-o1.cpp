class RandomizedSet {
public:
    unordered_map<int,int> mpp;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val) != mpp.end() ) return false;
        v.push_back(val);
        mpp[val] = v.size()-1; return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val) != mpp.end()){
            int ind = mpp[val];
            int lastEl = v[v.size()-1];
            mpp[lastEl] = ind;

            swap(v[ind],lastEl);

            v.pop_back();
            mpp.erase(val); return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */