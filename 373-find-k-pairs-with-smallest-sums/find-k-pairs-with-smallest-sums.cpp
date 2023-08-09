class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1=nums1.size();
        int len2=nums2.size();
        int sum,idx1=0,idx2=0;
        vector<vector<int>>res;
        set<pair<int,int>> vis;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({nums1[0]+nums2[0],{0,0}});
        vis.insert({0,0});
        while(!q.empty() && k-->0){
            idx1=q.top().second.first;
            idx2=q.top().second.second;
            q.pop();
            res.push_back({nums1[idx1],nums2[idx2]});
            if((idx1+1)<len1 && vis.find({idx1+1,idx2})==vis.end()){
                q.push({nums1[idx1+1]+nums2[idx2],{idx1+1,idx2}});
                vis.insert({idx1+1,idx2});
            }
            if((idx2+1)<len2 && vis.find({idx1,idx2+1})==vis.end()){
                q.push({nums1[idx1]+nums2[idx2+1],{idx1,idx2+1}});
                vis.insert({idx1,idx2+1});
            }
        }
        return res;
    }
};