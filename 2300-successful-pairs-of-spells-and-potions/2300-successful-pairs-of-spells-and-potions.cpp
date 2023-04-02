class Solution {
public:
    # define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        ll q;
        int beg,end,mid,ans;
        int Slen=spells.size();
        int Plen=potions.size();
        vector<int> res(Slen);
        for(int i=0;i<Slen;i++){
            q=ceil((1.0*success)/spells[i]);
            beg=0,end=Plen-1;
            ans=Plen;
            while(beg<=end){
                mid=beg+(end-beg)/2;
                if(potions[mid]>=q){
                    end=mid-1;
                    ans=mid;
                }else{
                    beg=mid+1;
                }
            }
            res[i]=Plen-ans;
        }
        return res;
    }
};