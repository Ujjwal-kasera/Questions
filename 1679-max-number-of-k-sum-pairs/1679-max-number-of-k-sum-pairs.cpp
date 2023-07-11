class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int len=nums.size();
        for(int i=0;i<len;i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(auto i:mp){
            count+=min(i.second,mp[k-i.first]);
        }
        return floor(count/2);
        
    }
};