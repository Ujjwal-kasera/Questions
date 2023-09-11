class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>mp;
        for(int i=0;i<groupSizes.size();++i){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        vector<int> temp;
        for(auto [len,vec]:mp){
            cout<<len<<endl;
            while(vec.size()>0){
                temp.clear();
                for(int i=0;i<len;++i){
                    temp.push_back(vec.back());
                    vec.pop_back();
                }
                cout<<"HI"<<endl;
                res.push_back(temp);
            }
        }
        return res;
    }
};