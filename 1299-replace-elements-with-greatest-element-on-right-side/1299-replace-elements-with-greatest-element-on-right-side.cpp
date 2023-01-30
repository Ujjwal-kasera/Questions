class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len=arr.size();
        int mx,tmp=-1;
        for(int i=len-1;i>=0;i--){
            mx=max(arr[i],tmp);
            arr[i]=tmp;
            tmp=mx;
        }
        return arr;
    }
};