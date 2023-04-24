class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> h;
        unordered_map<int,int> m;
        for(auto i:nums)
            m[i]++;
        for(auto i:m)
            h.push({i.second,i.first});
        vector<int> res;
        while(k--){
            res.push_back(h.top().second);
            h.pop();
        }
        return res;
    }
};