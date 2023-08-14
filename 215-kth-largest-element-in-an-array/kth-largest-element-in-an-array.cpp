class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        int len=nums.size();
        for(int i=0;i<k;i++){
            q.push(nums[i]);
        }
        for(int i=k;i<len;i++){
            if(nums[i]>q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};