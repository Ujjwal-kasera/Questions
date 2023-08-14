#define ll long long
class compare{
    public:
    bool operator()(vector<int> &a,vector<int> &b){
        return a[1]>b[1];
    }
}cmp;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int len=nums1.size();
        vector<vector<int>> vec(len,vector<int>(2));
        for(int i=0;i<len;i++){
            vec[i][0]=nums1[i];
            vec[i][1]=nums2[i];
        }
        sort(vec.begin(),vec.end(),cmp);
        priority_queue<int,vector<int>,greater<int>> minHeap;
        ll sum=0;
        for(int i=0;i<k;i++){
            sum+=vec[i][0];
            minHeap.push(vec[i][0]);
        }
        ll pro=sum*vec[k-1][1];
        for(int i=k;i<len;i++){
            sum-=minHeap.top();
            minHeap.pop();
            sum+=vec[i][0];
            minHeap.push(vec[i][0]);
            pro=max(pro,sum*vec[i][1]);
        }
        return pro;
    }
};