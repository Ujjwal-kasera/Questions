class RandomizedSet {
    vector<int> vec;
    unordered_map<int,int> mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)!=0)
            return 0;
        mp[val]=vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)==0)
            return false;
        vec[mp[val]]=vec.back();
        mp[vec.back()]=mp[val];
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */