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
//     int maxOperations(vector<int>& nums, int k) {
//         map<int,int> mp;
//         int len=nums.size();
//         for(int i=0;i<len;i++){
//             mp[nums[i]]++;
//         }
//         int count=0;
//         for(auto i:mp){
//             count+=min(i.second,mp[k-i.first]);
//         }
//         return floor(count/2);
//     }
};