class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        int len=nums.size();
        deque<int> q;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        for(int i=k;i<len;i++){
            while(!q.empty() && i-q.front()>=k)
                q.pop_front();
            while(!q.empty() && nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};