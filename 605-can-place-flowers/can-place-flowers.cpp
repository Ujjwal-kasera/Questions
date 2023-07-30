class Solution {
public:
    int len;
    bool isSafe(int index,vector<int>&flowerbed){
        if((index-1<0 || flowerbed[index-1]==0) && (index+1>=len || flowerbed[index+1]==0)){
            return 1;
        }
        return 0;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        len=flowerbed.size();
        for(int i=0;i<len;i++){
            if(flowerbed[i]==1)
                continue;
            if(isSafe(i,flowerbed)){
                flowerbed[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};