class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int len=nums.size();
        for(int i=0;i<len;i++){
            mp[nums[i]]++;
        }
        int res=0;
        int num,count;
        for(auto i=mp.begin();i!=mp.end();++i){
            num=i->first;
            count=i->second;
            if(mp.count(k-num)){
                res+=min(count,mp[k-num]);
            }
        }
        return (res>>1);
    }
};