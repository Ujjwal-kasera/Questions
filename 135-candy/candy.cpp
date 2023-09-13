class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        vector<int> left(len,1);
        for(int i=1;i<len;++i){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }else{

            }
        }
        vector<int>right(len,1);
        for(int i=len-2;i>=0;--i){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<len;i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};