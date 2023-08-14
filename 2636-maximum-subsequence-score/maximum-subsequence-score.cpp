#define ll long long
class compare{
    public:
    bool operator()(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
}cmp;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int len=nums1.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<len;i++){
            vec.push_back({nums1[i],nums2[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        priority_queue<int,vector<int>,greater<int>> minHeap;
        ll sum=0;
        for(int i=0;i<k;i++){
            sum+=vec[i].first;
            minHeap.push(vec[i].first);
        }
        ll pro=sum*vec[k-1].second;
        for(int i=k;i<len;i++){
            sum+=(vec[i].first-minHeap.top());
            minHeap.pop();
            minHeap.push(vec[i].first);
            pro=max(pro,sum*vec[i].second);
        }
        return pro;
    }
};