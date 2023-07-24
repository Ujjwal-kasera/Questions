class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0,start=0,zero=0;
        int len=nums.size();
        for(int i=0;i<len;i++){
            zero+=nums[i]==0?1:0;
            while(zero>k)
                if(nums[start++]==0)
                    zero--;
            res=max(res,i-start+1);
        }
        return res;
    }
    
    // Bruteforce Apporach
    // TC=O(N2)
    // int longestOnes(vector<int>& nums, int k) {
    //     int res=0,ans=0;
    //     int zero=0;
    //     int len=nums.size();
    //     for(int i=0;i<len;i++){
    //         zero=0,ans=0;
    //         for(int j=i;j<len;j++){
    //             if(nums[j]==0)
    //                 zero++;
    //             if(zero>k)
    //                 break;
    //             ans++;
    //         }
    //         res=max(res,ans);
    //     }
    //     return res;
    // }
};