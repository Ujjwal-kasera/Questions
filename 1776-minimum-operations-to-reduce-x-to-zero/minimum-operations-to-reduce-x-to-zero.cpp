class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len=nums.size(),totalSum=0,sum=0,count=-1,tmp;
        for(int i=0;i<len;++i)
            totalSum+=nums[i];
        deque<int> q;
        for(int i=0;i<len;++i){
            sum+=nums[i];
            q.push_back(nums[i]);
            while(!q.empty() && sum>(totalSum-x)){
                sum-=q.front();
                q.pop_front();
            }
            if(sum==(totalSum-x)){
                tmp=q.size();
                count=max(count,tmp);
            }
        }
        return count==-1?-1:len-count;
    }
};