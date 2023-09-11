class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>mp;
        for(int i=0;i<groupSizes.size();++i){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        int idx;
        vector<int> temp;
        for(auto [len,vec]:mp){
            idx=0;
            while(idx<vec.size()){
                temp.push_back(vec[idx++]);
                if(temp.size()==len){
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
};